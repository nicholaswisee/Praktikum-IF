public class Umandana {
    /**
     * Mengembalikan kata yang telah diubah menjadi bahasa Umandana Huruf a
     * menjadi "aiden" Huruf i menjadi "ipri" Huruf u menjadi "upru" Huruf e
     * menjadi "epre" Huruf o menjadi "opro" Huruf mati yang tidak diikuti huruf
     * vokal menjadi huruf tersebut + "es" Suku kata "ng" yang tidak diikuti
     * huruf vokal menjadi "strengen" Suku kata "ng" yang diikuti huruf vokal
     * tetap menjadi "ng" Suku kata "ny" yang diikuti huruf vokal tetap menjadi
     * "ny" Selain ketentuan di atas, huruf/karakter tidak diubah *
     *
     * @param words
     * @return kata yang telah diubah menjadi bahasa Umandana
     *
     */
    public static String toUmandana(String words) {
        if (words == null)
            return null;

        StringBuilder result = new StringBuilder();
        int len = words.length();

        for (int i = 0; i < len; i++) {
            char ch = words.charAt(i);
            char lowerChar = java.lang.Character.toLowerCase(ch);

            // Lookahead karakter ke-1 dan ke-2 di depan
            char nextChar = (i + 1 < len) ? words.charAt(i + 1) : '\0';
            char lowerNextChar = java.lang.Character.toLowerCase(nextChar);
            char nextNextChar = (i + 2 < len) ? words.charAt(i + 2) : '\0';
            char lowerNextNextChar =
                java.lang.Character.toLowerCase(nextNextChar);

            boolean isNextNextCharVowel =
                (lowerNextNextChar == 'a' || lowerNextNextChar == 'i' ||
                 lowerNextNextChar == 'u' || lowerNextNextChar == 'e' ||
                 lowerNextNextChar == 'o');
            boolean isNextCharVowel =
                (lowerNextChar == 'a' || lowerNextChar == 'i' ||
                 lowerNextChar == 'u' || lowerNextChar == 'e' ||
                 lowerNextChar == 'o');
            boolean isCharVowel =
                (lowerChar == 'a' || lowerChar == 'i' || lowerChar == 'u' ||
                 lowerChar == 'e' || lowerChar == 'o');

            boolean isCharConsonant =
                (lowerChar >= 'a' && lowerChar <= 'z') && !isCharVowel;

            if (lowerChar == 'n' && lowerNextChar == 'g') {
                if (isNextNextCharVowel) {
                    // "ng" diikuti vokal tetap "ng"
                    result.append(ch).append(nextChar);
                } else {
                    // "ng" tidak diikuti vokal
                    result.append("strengen");
                }
                i++; // Skip huruf 'g'
                continue;
            }

            if (lowerChar == 'n' && lowerNextChar == 'y' &&
                isNextNextCharVowel) {
                result.append(ch).append(nextChar);
                i++; // Skip huruf 'y'
                continue;
            }

            // Aturan: Huruf Vokal
            if (isCharVowel) {
                switch (lowerChar) {
                case 'a':
                    result.append("aiden");
                    break;
                case 'i':
                    result.append("ipri");
                    break;
                case 'u':
                    result.append("upru");
                    break;
                case 'e':
                    result.append("epre");
                    break;
                case 'o':
                    result.append("opro");
                    break;
                }
                continue;
            }

            if (isCharConsonant) {
                if (isNextCharVowel) {
                    // Huruf mati diikuti vokal tidak ditambah "es"
                    result.append(ch);
                } else {
                    // Huruf mati TIDAK diikuti vokal ditambah "es"
                    result.append(ch).append("es");
                }
                continue;
            }

            result.append(ch);
        }

        return result.toString();
    }

    /**
     * Mengembalikan kata Umandana ke bentuk normal *
     *
     * @param words kata dalam bahasa Umandana
     * @return kata telah diubah ke bentuk normal
     */
    public static String deUmandana(String words) {

        if (words == null)
            return null;

        String result = words;

        result = result.replace("strengen", "ng");

        result = result.replace("aiden", "a");
        result = result.replace("ipri", "i");
        result = result.replace("upru", "u");
        result = result.replace("epre", "e");
        result = result.replace("opro", "o");
        result = result.replaceAll(
            "([bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ])es", "$1");

        return result;
    }
}
