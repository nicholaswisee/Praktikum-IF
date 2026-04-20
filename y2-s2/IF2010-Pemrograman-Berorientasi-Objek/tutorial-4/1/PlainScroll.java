public class PlainScroll extends Scroll {
	public PlainScroll(String content) {
		super(content);
	}

	@Override
	public String process() {
		String trimmed = getContent().trim().replaceAll("\\s+", " ");
		if (trimmed.isEmpty()) {
			return "";
		}

		String[] words = trimmed.split(" ");
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < words.length; i++) {
			String w = words[i];
			if (!w.isEmpty()) {
				builder.append(java.lang.Character.toUpperCase(w.charAt(0)));
				if (w.length() > 1) {
					builder.append(w.substring(1).toLowerCase());
				}
			}
			if (i < words.length - 1) {
				builder.append(' ');
			}
		}
		return builder.toString();
	}

	@Override
	public String toString() {
		return "[PLAIN] " + getContent();
	}
}
