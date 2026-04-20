import java.util.ArrayList;
import java.util.List;

public class Academy {
	private final List<Scroll> scrolls;

	public Academy() {
		this.scrolls = new ArrayList<>();
	}

	public void addScroll(Scroll scroll) {
		scrolls.add(scroll);
	}

	public Scroll getScroll(int index) {
		if (index < 1 || index > scrolls.size()) {
			throw new IllegalArgumentException("Index gulungan tidak valid.");
		}
		return scrolls.get(index - 1);
	}

	public int search(String keyword) {
		int count = 0;
		String target = keyword.toLowerCase();
		for (Scroll scroll : scrolls) {
			if (scroll.getContent().toLowerCase().contains(target)) {
				count++;
			}
		}
		return count;
	}

	public int count() {
		return scrolls.size();
	}
}
