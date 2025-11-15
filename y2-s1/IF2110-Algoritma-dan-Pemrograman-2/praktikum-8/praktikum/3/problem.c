/* File: problem.c */
/* Implementasi fungsi untuk mengecek apakah kalimat sesuai grammar dengan daftar objek */

/* Grammar yang digunakan:
 * <Kalimat> ::= <Subjek> <Predikat> <Objek> {, <Objek>}*
 *
 * Contoh kalimat valid:
 * - "aku beli buku."
 * - "aku beli buku, pensil, penggaris."
 * - "dia ambil tas, buku."
 *
 * Contoh tidak valid:
 * - "aku beli."
 * - "beli buku."
 * - "aku beli , pensil."
 */

 #include "mesinkata.h"
 #include "boolean.h"
 #include <stdio.h>

 /* ====== FSM Parser ====== */
typedef enum {
    S_EXPECT_SUBJECT = 0,
    S_EXPECT_PREDICATE,
    S_EXPECT_FIRST_OBJECT,
    S_EXPECT_SEPARATOR_OR_END,
    S_EXPECT_OBJECT_AFTER_COMMA 
} State;

/* ====== Helper ====== */
/* Membandingkan dua kata secara case-insensitive */
int eqWordCStrInsensitive(Word w, const char *s) {
    int n = (int)strlen(s);
    if (w.Length != n) return 0;
    for (int i = 0; i < n; i++) {
        char cw = w.TabWord[i];
        if ('A' <= cw && cw <= 'Z') cw = (char)(cw - 'A' + 'a');
        char cs = s[i];
        if ('A' <= cs && cs <= 'Z') cs = (char)(cs - 'A' + 'a');
        if (cw != cs) return 0;
    }
    return 1;
}

int isSubjek(const Word w) {
    return eqWordCStrInsensitive(w, "aku")
        || eqWordCStrInsensitive(w, "kamu")
        || eqWordCStrInsensitive(w, "dia");
}

int isPredikat(const Word w) {
    return eqWordCStrInsensitive(w, "beli")
        || eqWordCStrInsensitive(w, "ambil");
}

 /* Silahkan tambahkan fungsi-fungsi helper lainnya jika perlu */
 
 /*
  * Fungsi utama untuk mengecek apakah kalimat sesuai grammar daftar objek
  * I.S. Mesin kata sudah siap digunakan (panggil STARTWORD() sebelumnya)
  * F.S. Mengembalikan true (1) jika kalimat valid, false (0) jika tidak
  *
  * Grammar: <Kalimat> ::= <Subjek> <Predikat> <Objek> {, <Objek>}*
  *
  * Contoh:
  *   Input  : "aku beli buku, pensil, penggaris."
  *   Output : 1
  *
  *   Input  : "aku beli , pensil."
  *   Output : 0 // tidak valid karena tidak ada objek setelah kata beli

  *   CONTOH LEBIH JELAS LIHAT PADA OLYMPIA
  *
  * Hint: Gunakan STARTWORD() untuk memulai pembacaan kata dan
  *       ADVWORD() untuk pindah ke kata berikutnya
  */
 
 /*
  * Hint (secukupnya):
  *
  * A. Pakai FSM (Finite State Machine) seperti yang sudah didefinisikan di atas
  *
  * B. Transisi inti:
  *    SUBJEK → PREDIKAT → OBJEK
  *
  *    Setelah objek:
  *    - Jika objek berkoma (melekat) → S_EXPECT_OBJECT_AFTER_COMMA
  *    - Jika tanpa koma → S_EXPECT_SEPARATOR_OR_END
  *
  *    Di S_EXPECT_SEPARATOR_OR_END, satu-satunya token valid
  *    (kalau belum MARK) adalah koma → lanjut ke S_EXPECT_OBJECT_AFTER_COMMA.
  *
  *    Di S_EXPECT_OBJECT_AFTER_COMMA, token wajib objek (boleh lagi berkoma).
  *
  * C. Kondisi akhir valid:
  *    Loop selesai (MARK terbaca → EndWord == true) dan state terakhir adalah
  *    S_EXPECT_SEPARATOR_OR_END serta setidaknya satu objek sudah terbaca.
  *
  * D. Helper minimal yang disarankan:
  *    - isCommaToken(Word w) → w.Length == 1 && w.TabWord[0] == ','.
  *    - isObjToken(Word w, int *hasTrailingComma):
  *        * Jika token berakhir ',', set *hasTrailingComma = 1.
  *        * Jika tidak berakhir ',', set *hasTrailingComma = 0.
  *        * Token "," bukan objek.
  */
 
 
int isCommaToken(Word w) {
    return (w.Length == 1 && w.TabWord[0] == ',');
}

int isValidObject(Word w, int *hasTrailingComma) {
    if (w.Length == 0) return 0;

    *hasTrailingComma = 0;

    /* Jika token berakhir koma */
    if (w.TabWord[w.Length - 1] == ',') {
        *hasTrailingComma = 1;

        if (w.Length == 1) return 0;  /* token "," bukan objek */
        
        /* Semua karakter sebelum koma harus alphabet */
        for (int i = 0; i < w.Length - 1; i++) {
            char c = w.TabWord[i];
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
                return 0;
        }
        return 1;
    }

    /* Tidak berakhir koma → semua harus alphabet */
    for (int i = 0; i < w.Length; i++) {
        char c = w.TabWord[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
            return 0;
    }

    return 1;
}

int cfg_parser() {
    STARTWORD();
    
    State state = S_EXPECT_SUBJECT;
    int hasObj = 0; // minimal satu objek wajib ada
    
    while (!EndWord) {
        Word w = currentWord;

        switch (state) {

        case S_EXPECT_SUBJECT:
            if (isSubjek(w)) {
                state = S_EXPECT_PREDICATE;
            } else {
                return 0;
            }
            break;

        case S_EXPECT_PREDICATE:
            if (isPredikat(w)) {
                state = S_EXPECT_FIRST_OBJECT;
            } else {
                return 0;
            }
            break;

        case S_EXPECT_FIRST_OBJECT: {
            int trailingComma;
            if (isValidObject(w, &trailingComma)) {
                hasObj = 1;
                if (trailingComma)
                    state = S_EXPECT_OBJECT_AFTER_COMMA;
                else
                    state = S_EXPECT_SEPARATOR_OR_END;
            } else {
                return 0;
            }
            break;
        }

        case S_EXPECT_SEPARATOR_OR_END:
            if (isCommaToken(w)) {
                state = S_EXPECT_OBJECT_AFTER_COMMA;
            } else {
                return 0;
            }
            break;

        case S_EXPECT_OBJECT_AFTER_COMMA: {
            int trailingComma;
            if (isValidObject(w, &trailingComma)) {
                if (trailingComma)
                    state = S_EXPECT_OBJECT_AFTER_COMMA;
                else
                    state = S_EXPECT_SEPARATOR_OR_END;
            } else {
                return 0;
            }
            break;
        }

        default:
            return 0;
        }

        ADVWORD();
    }

    if (state == S_EXPECT_SEPARATOR_OR_END && hasObj)
        return 1;
    return 0;
 }