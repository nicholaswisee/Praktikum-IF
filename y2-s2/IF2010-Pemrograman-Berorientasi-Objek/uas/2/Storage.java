import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Storage<T> {
    private Map<String, T> data;
    private int capacity;

    public Storage(int capacity) {
        this.capacity = capacity;
        this.data = new LinkedHashMap<>();
    }

    public void store(String id, T item)
        throws DuplicateIdException, StorageFullException {
        // TODO:
        // Tambahkan item ke dalam data dengan id sebagai key.
        // Jika kapasitas sudah penuh, lemparkan StorageFullException.
        // Jika kapasitas belum penuh namun id sudah ada di dalam data,
        // lemparkan DuplicateIdException.

        if (data.containsKey(id) == true) {
            throw new DuplicateIdException(id);
        }

        if (this.getSize() == capacity) {
            throw new StorageFullException();
        }

        data.put(id, item);
    }

    public T retrieve(String id) throws DataNotFoundException {
        // TODO:
        // Kembalikan item yang sesuai dengan id.
        // Jika id tidak ditemukan, lemparkan DataNotFoundException.

        if (data.containsKey(id) == false) {
            throw new DataNotFoundException(id);
        }

        return data.get(id);
    }

    public void remove(String id) throws DataNotFoundException {
        // TODO:
        // Hapus item dengan id dari dalam data.
        // Jika id tidak ditemukan, lemparkan DataNotFoundException.
        if (data.containsKey(id) == false) {
            throw new DataNotFoundException(id);
        }

        data.remove(id);
    }

    public List<T> getAll() {
        // TODO:
        // Kembalikan semua item di dalam data dalam bentuk List.
        //
        //
        return data.entrySet()
            .stream()
            .map(Map.Entry::getValue)
            .collect(Collectors.toList());
    }

    public int getCapacity() { return this.capacity; }

    public int getSize() {
        if (this.data == null) {
            return 0;
        }
        return this.data.size();
    }
}
