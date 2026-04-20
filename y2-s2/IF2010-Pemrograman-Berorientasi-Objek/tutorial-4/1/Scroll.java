public abstract class Scroll {
    private String content;

    public Scroll(String content) { this.content = content; }

    public String getContent() { return content; }

    public void setContent(String content) { this.content = content; }

    public abstract String process();
}
