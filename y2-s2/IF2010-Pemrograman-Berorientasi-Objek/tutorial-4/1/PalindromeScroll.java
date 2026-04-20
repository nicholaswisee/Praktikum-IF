public class PalindromeScroll extends Scroll {
    public PalindromeScroll(String content) { super(content); }

    @Override
    public String process() {
        return new StringBuilder(getContent()).reverse().toString();
    }

    public boolean isPalindrome() {
        StringBuilder cleaned = new StringBuilder();
        String content = getContent();

        for (int i = 0; i < content.length(); i++) {
            char c = content.charAt(i);
            if (!java.lang.Character.isWhitespace(c)) {
                cleaned.append(java.lang.Character.toLowerCase(c));
            }
        }

        int left = 0;
        int right = cleaned.length() - 1;
        while (left < right) {
            if (cleaned.charAt(left) != cleaned.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    @Override
    public String toString() {
        return "[PALINDROME] " + getContent();
    }
}
