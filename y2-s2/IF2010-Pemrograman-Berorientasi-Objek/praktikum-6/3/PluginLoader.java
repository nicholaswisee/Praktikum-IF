public class PluginLoader {

    /**
     * Me-load kelas plugin secara dinamis berdasarkan nama kelas yang diberikan.
     * Kelas yang di-load harus merupakan implementasi dari interface Plugin.
     * Jika kelas tersebut tidak mengimplementasikan interface Plugin, method ini
     * harus melempar IllegalArgumentException dengan pesan:
     * "Kelas <className> tidak mengimplementasikan interface Plugin"
     * 
     * @param className Nama lengkap kelas yang akan di-load.
     * @return Instance dari kelas plugin yang berhasil di-load.
     * @throws Exception Jika terjadi error saat proses pemuatan kelas atau instansiasi.
     */
    public static Plugin loadPlugin(String className) throws Exception {
        // TODO: Implementasi

        Class c = Class.forName(className);
        Class p = Class.forName("Plugin");

        
        // System.out.println(p.isInterface());

        Class<?>[] interfaces = c.getInterfaces();
        boolean imp = false;
        for (Class<?> i : interfaces) {
            if (i == p) {
                imp = true;
            }
        }

        if (!imp) {
            throw new IllegalArgumentException("Kelas " + className + " tidak mengimplementasikan interface Plugin");
        }

        Object a = c.getDeclaredConstructor().newInstance();
        Plugin res = (Plugin) a;

        return res;

        
    }
}
