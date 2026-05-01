public class Pesan {
    protected String content;

    public Pesan(String content) { this.content = content; }

    public String process() { return content; }

    @Override
    public String toString() {
        return "[PESAN] " + content;
    }
}
