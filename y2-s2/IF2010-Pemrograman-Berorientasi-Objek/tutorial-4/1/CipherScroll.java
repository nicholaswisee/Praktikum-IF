public class CipherScroll extends Scroll {
	private final int shift;

	public CipherScroll(String content, int shift) {
		super(content);
		this.shift = normalizeShift(shift);
	}

	private int normalizeShift(int value) {
		int normalized = value % 26;
		if (normalized < 0) {
			normalized += 26;
		}
		return normalized;
	}

	private char shiftChar(char c, int amount) {
		if (c >= 'a' && c <= 'z') {
			return (char) ('a' + (c - 'a' + amount + 26) % 26);
		}
		if (c >= 'A' && c <= 'Z') {
			return (char) ('A' + (c - 'A' + amount + 26) % 26);
		}
		return c;
	}

	private String transform(String text, int amount) {
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < text.length(); i++) {
			builder.append(shiftChar(text.charAt(i), amount));
		}
		return builder.toString();
	}

	@Override
	public String process() {
		return transform(getContent(), shift);
	}

	public String decode() {
		return transform(getContent(), -shift);
	}

	@Override
	public String toString() {
		return "[CIPHER] " + getContent();
	}
}
