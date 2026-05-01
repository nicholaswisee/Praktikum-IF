public class CapsMessage extends Pesan {
    public CapsMessage(String content) { super(content); }

    @Override
    public String process() {
        return content.toUpperCase();
    }

    public int countVowels() {
        int count = 0;
        String lower = content.toLowerCase();
        for (int i = 0; i < lower.length(); i++) {
            char c = lower.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    @Override
    public String toString() {
        return "[CAPS] " + content;
    }
}
