public class Mage extends Character {
    private int magicalAtk;

    public Mage(String name, int level, double powerBase, int magicalAtk) {
        super(name, level, powerBase);
        this.magicalAtk = magicalAtk;
    }

    public int getMagicalAtk() {
        return this.magicalAtk;
    }

    public double calculatePower() {
        return getPowerBase() + (getMagicalAtk() * 0.5);
    }

    @Override
    public void printInfo() {
        System.out.println("Nama: " + getName());
        System.out.println("Nama Kapital: " + getName().toUpperCase());
        System.out.println("Inisial: " + getName().toUpperCase().charAt(0));
        System.out.println("Panjang Nama: " + getName().length());
        System.out.println("Level: " + getLevel());
        System.out.println("Power Akhir: " + calculatePower());
        System.out.println("Jenis: Mage");
    }
}