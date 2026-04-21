/**
 * @file BukuSakuSTL.hpp
 * @brief Referensi Lengkap API Kontainer dan Algoritma C++ (Standar C++14).
 *
 * @details
 * File ini adalah buku saku resmi untuk praktikum. Terdiri dari dua bagian
 * utama:
 * 1. `AlgoritmaUniversal`: Kumpulan fungsi STL (<algorithm>) yang dapat
 * menerima Lambda.
 * 2. `Member Functions`: Kumpulan fungsi bawaan (member functions) spesifik
 * milik vector, set, dan map.
 * * Silakan baca deskripsi tiap fungsi untuk menentukan mana yang paling tepat
 * untuk menyelesaikan tugas Anda.
 */

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#pragma once

// =========================================================================
// BAGIAN 1: ALGORITMA UNIVERSAL (<algorithm>)
// =========================================================================
namespace AlgoritmaUniversal {

/**
 * @brief Menjalankan perintah pada setiap elemen di dalam kontainer.
 * @details Pengganti `for` loop tradisional. Sangat cocok untuk mencetak data
 * atau mengubah state dari objek di dalam kontainer.
 * * **Contoh Penggunaan Lambda:**
 * ```cpp
 * std::for_each(v.begin(), v.end(), [](const auto& elemen) {
 * std::cout << elemen << std::endl;
 * });
 * ```
 * @param begin Iterator penunjuk awal.
 * @param end Iterator penunjuk batas akhir.
 * @param func Lambda function yang akan dieksekusi.
 */
template <class Iterator, class Function>
void for_each(Iterator begin, Iterator end, Function func);

/**
 * @brief Mencari elemen secara berurutan (Linear Search).
 * @details Ini adalah cara standar mencari data di dalam `std::vector`.
 * @warning JANGAN gunakan fungsi ini untuk `std::set` atau `std::map`! Gunakan
 * fungsi bawaan `.find()` milik mereka karena jauh lebih cepat.
 * @param begin Iterator awal.
 * @param end Iterator batas akhir.
 * @param value Nilai yang ingin dicari.
 * @return Iterator yang menunjuk ke elemen tersebut, atau `end` jika tidak
 * ketemu.
 */
template <class Iterator, class T>
Iterator find(Iterator begin, Iterator end, const T &value);

/**
 * @brief Mencari elemen PERTAMA yang memenuhi kondisi spesifik.
 * @details Algoritma akan berhenti bekerja (short-circuit) setelah menemukan
 * satu elemen yang membuat lambda mengembalikan `true`.
 * * **Contoh Penggunaan Lambda:**
 * ```cpp
 * auto it = std::find_if(v.begin(), v.end(), [](const auto& elemen) {
 * return elemen.harga > 10000;
 * });
 * ```
 */
template <class Iterator, class Predicate>
Iterator find_if(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Mengecek apakah ADA MINIMAL SATU elemen yang memenuhi kondisi.
 * @return `true` jika ada minimal 1 elemen yang membuat lambda bernilai `true`.
 */
template <class Iterator, class Predicate>
bool any_of(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Mengecek apakah SEMUA elemen memenuhi kondisi.
 * @return `true` HANYA JIKA semua elemen membuat lambda bernilai `true`.
 */
template <class Iterator, class Predicate>
bool all_of(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Menghitung jumlah elemen yang memenuhi kondisi tertentu.
 * @details Berguna untuk rekapitulasi data tanpa memodifikasinya.
 */
template <class Iterator, class Predicate>
int count_if(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Menggeser elemen "sampah" ke bagian belakang kontainer.
 * @details **PERHATIAN:** Ini TIDAK MENGHAPUS data dari memori. Ia hanya
 * mengelompokkan elemen yang memenuhi kondisi lambda (sampah) ke kanan.
 * Anda WAJIB menggabungkannya dengan `.erase()` dari kontainer tersebut
 * (Erase-Remove Idiom) jika ingin benar benar menghapusnya.
 * * **Contoh Penggunaan Lambda C++14:**
 * ```cpp
 * v.erase(std::remove_if(v.begin(), v.end(), [](auto& e) { return e%2==0; }),
 * v.end());
 * ```
 * @return Iterator yang menunjuk ke awal area "sampah".
 */
template <class Iterator, class Predicate>
Iterator remove_if(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Memisahkan data menjadi dua kelompok (Tidak stabil).
 * @details Memindahkan elemen yang membuat lambda bernilai `true` ke kiri, dan
 * `false` ke kanan. Urutan elemen di dalam kelompoknya bisa berubah (teracak).
 * Lebih cepat dari `stable_partition`.
 */
template <class Iterator, class Predicate>
void partition(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Memisahkan data menjadi dua kelompok (Stabil).
 * @details Sama seperti `partition`, namun urutan awal masuk elemen tidak akan
 * berubah (relatif terhadap sesama kelompoknya). Cocok untuk sistem
 * antrean/prioritas.
 */
template <class Iterator, class Predicate>
void stable_partition(Iterator begin, Iterator end, Predicate condition);

/**
 * @brief Mengurutkan elemen (Sorting) secara *In-Place*.
 * @details Kompleksitas O(N log N). Biasa digunakan pada `std::vector`.
 * * **Contoh Penggunaan Lambda (Custom Sort):**
 * ```cpp
 * std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
 * return a.nilai > b.nilai; // Urutkan descending (besar ke kecil)
 * });
 * ```
 */
template <class Iterator, class Compare>
void sort(Iterator begin, Iterator end, Compare comparator);

} // namespace AlgoritmaUniversal

// =========================================================================
// BAGIAN 2: (MEMBER FUNCTIONS)
// =========================================================================
namespace MemberFunctions {

/**
 * @class API_Vector
 * @brief Kumpulan fungsi bawaan untuk `std::vector` (Array Dinamis).
 */
template <typename T> class API_Vector {
  public:
    // Mendefinisikan tipe Iterator internal
    typedef typename std::vector<T>::iterator Iterator;

    /** @brief Mengembalikan iterator ke elemen pertama. */
    Iterator begin();

    /** @brief Mengembalikan iterator ke posisi ruang kosong *setelah* elemen
     * terakhir. */
    Iterator end();

    /** @brief Memasukkan elemen baru tepat di paling belakang vector (O(1)). */
    void push_back(const Type &value);

    /** @brief Menghapus elemen paling belakang vector (O(1)). */
    void pop_back();

    /** * @brief Menyisipkan elemen di posisi mana saja.
     * @warning Lambat (O(N)) jika menyisipkan di depan/tengah karena harus
     * menggeser elemen lain.
     * @param pos Iterator posisi penyisipan.
     * @param value Nilai yang disisipkan.
     */
    void insert(Iterator pos, const Type &value);

    /** * @brief Menghapus elemen atau rentang elemen secara permanen.
     * @details Saat dipadukan dengan `remove_if`, ini mengecilkan ukuran
     * (*size*) vector.
     */
    void erase(Iterator first, Iterator last);

    /** @brief Mengembalikan jumlah elemen saat ini. */
    int size() const;

    /** @brief Mengecek apakah vector kosong (true jika size == 0). */
    bool empty() const;
};

/**
 * @class API_Set
 * @brief Kumpulan fungsi bawaan untuk `std::set` (Himpunan Unik & Terurut).
 * @details Pencarian pada Set memiliki kompleksitas O(log N), sangat cepat!
 */
template <typename T> class API_Set {
  public:
    typedef typename std::set<T>::iterator Iterator;
    /** * @brief Memasukkan data baru.
     * @details Jika data sudah ada, akan otomatis diabaikan. Selalu terurut
     * otomatis.
     */
    void insert(const T &value);

    /** @brief Menghapus data secara langsung menyebutkan nilainya. */
    void erase(const T &value);

    /** * @brief Menghitung kemunculan data.
     * @details Di set, ini bertindak seperti pengecekan eksistensi. Hanya
     * mengembalikan nilai 1 (jika ada) atau 0 (jika tidak ada).
     */
    int count(const T &value) const;

    /** * @brief Mencari letak spesifik data.
     * @return Iterator yang menunjuk ke data, atau `.end()` jika tidak
     * ditemukan.
     */
    Iterator find(const T &value);
};

/**
 * @class API_Map
 * @brief Kumpulan fungsi bawaan untuk `std::map` (Kamus / Key-Value Pair).
 */
template <typename Key, typename Value> class API_Map {
  public:
    typedef typename std::map<Key, Value>::iterator Iterator;

    /** * @brief Set & Get nilai berdasarkan kuncinya (Key).
     * @details
     * - CARA SET: `my_map["Budi"] = 90;`
     * - CARA GET: `int nilai = my_map["Budi"];`
     * @warning JIKA KEY TIDAK ADA saat Anda memanggilnya, Map akan otomatis
     * MENCIPTAKAN elemen baru dengan value default (misal 0). Jika Anda hanya
     * ingin mencari tanpa menciptakan baru, gunakan `.find()`.
     */
    Value &operator[](const Key &key);

    /** * @brief Mencari Key secara spesifik.
     * @details Gunakan ini untuk mengecek apakah data ada tanpa
     * memodifikasinya.
     * @return Iterator. (Cara akses: `it->first` untuk Key, `it->second` untuk
     * Value).
     */
    Iterator find(const Key &key);

    /** @brief Menghapus satu pasang Key-Value berdasarkan kuncinya. */
    void erase(const Key &key);

    /** @brief Mengecek eksistensi Key (Kembalian 1 jika ada, 0 jika tidak ada).
     */
    int count(const Key &key) const;
};

} // namespace MemberFunctions
