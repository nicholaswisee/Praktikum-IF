import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

public class LibraryIterator<T> implements Iterator<T> {

    private final List<T> items;
    private int cursor;

    public LibraryIterator(List<T> items) {
        this.items = items;
        this.cursor = 0;
    }

    @Override
    public boolean hasNext() {
        return cursor < items.size();
    }

    @Override
    public T next() {
        if (!hasNext()) {
            throw new NoSuchElementException(
                "No more elements in the library.");
        }
        return items.get(cursor++);
    }

    public boolean hasPrevious() { return cursor > 0; }

    public T previous() {
        if (!hasPrevious()) {
            throw new NoSuchElementException(
                "Already at the beginning of the library.");
        }
        return items.get(--cursor);
    }

    public void reset() { cursor = 0; }
}
