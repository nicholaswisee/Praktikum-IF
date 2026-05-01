public class RepeatMessage extends Pesan {
    private int n;

    public RepeatMessage(String content, int n) {
        super(content);
        this.n = n;
    }

    @Override
    public String process() {
        String[] words = content.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < n; j++) {
                if (sb.length() > 0) {
                    sb.append(" ");
                }
                sb.append(words[i]);
            }
        }
        return sb.toString();
    }

    public int getN() { return n; }

    @Override
    public String toString() {
        return "[REPEAT] " + content;
    }
}
