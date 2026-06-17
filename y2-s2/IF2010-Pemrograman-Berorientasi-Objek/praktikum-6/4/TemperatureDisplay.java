public class TemperatureDisplay implements WeatherObserver {
    // TODO:
    // Deklarasikan field private String name.
    private String name;

    public TemperatureDisplay(String name) {
        // TODO:
        // Simpan nama yang diberikan ke field name.
        super();
        this.name = name;
    }

    @Override
    public void update(double temperature, double humidity) {
        // TODO:
        // Cetak baris berikut ke System.out:
        // "Display <name>: Suhu <temperature>"
        //
        // Format temperature menggunakan satu angka desimal (%.1f).
        // Contoh: "Display TempA: Suhu 25.0"
        //
        System.out.printf("Display %s: Suhu %.1f%n", name, temperature);
    }

    @Override
    public String getName() {
        // TODO:
        // Kembalikan nama tampilan ini.
        return this.name;
    }
}
