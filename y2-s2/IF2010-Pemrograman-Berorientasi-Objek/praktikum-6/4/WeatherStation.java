import java.util.ArrayList;
import java.util.List;

public class WeatherStation {
    // TODO:
    // Deklarasikan field berikut:
    private List<WeatherObserver> observers;
    private double temperature;
    private double humidity;

    public WeatherStation() {
        // TODO:
        // Inisialisasi observers sebagai ArrayList kosong.
        // Set temperature = 0.0 dan humidity = 0.0.
        this.observers = new ArrayList<WeatherObserver>();
        this.temperature = 0.0;
        this.humidity = 0.0;
    }

    public void addObserver(WeatherObserver observer) {
        // TODO:
        // Tambahkan observer ke dalam daftar observers.
        observers.add(observer);
    }

    public boolean removeObserver(String name) {
        // TODO:
        // Cari observer dengan nama yang sesuai di dalam daftar.
        // Jika ditemukan, hapus dan kembalikan true.
        // Jika tidak ditemukan, kembalikan false.

        for (int i = 0; i < observers.size(); i++) {
            if (observers.get(i).getName().equals(name)) {
                observers.remove(i);
                return true;
            }
        }

        return false;
    }

    public boolean hasObserver(String name) {
        // TODO:
        // Kembalikan true jika terdapat observer dengan nama tersebut
        // di dalam daftar, false jika tidak.

        for (WeatherObserver obs : observers) {
            if (obs.getName().equals(name))
                return true;
        }

        return false;
    }

    public void setMeasurements(double temperature, double humidity) {
        // TODO:
        // Perbarui nilai temperature dan humidity.
        // Setelah diperbarui, panggil notifyObservers() untuk
        // memberitahu semua observer yang terdaftar.

        this.temperature = temperature;
        this.humidity = humidity;
        notifyObservers();
    }

    private void notifyObservers() {
        // TODO:
        // Iterasi seluruh observer dalam daftar (sesuai urutan pendaftaran)
        // dan panggil update(temperature, humidity) pada masing-masing
        // observer.
        for (WeatherObserver obs : observers) {
            obs.update(temperature, humidity);
        }
    }

    public double getTemperature() {
        // TODO:
        // Kembalikan nilai temperature saat ini.

        return temperature;
    }

    public double getHumidity() {
        // TODO:
        // Kembalikan nilai humidity saat ini.

        return humidity;
    }

    public int getObserverCount() {
        // TODO:
        // Kembalikan jumlah observer yang saat ini terdaftar.

        return observers.size();
    }
}
