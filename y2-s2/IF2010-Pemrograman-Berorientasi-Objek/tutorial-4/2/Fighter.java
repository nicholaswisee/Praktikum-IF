public class Fighter extends Character {
    private int physicalAtk;

    public Fighter(String name, int level, double powerBase, int physicalAtk) {
        super(name, level, powerBase);
        this.physicalAtk = physicalAtk;
    }

    public int getPhysicalAtk() {
        return this.physicalAtk;
    }

    public double calculatePower() {
        return getPowerBase() + (physicalAtk * 0.7);
    }

    @Override
    public void printInfo() {
        System.out.println("Nama: " + getName());
        System.out.println("Nama Kapital: " + getName().toUpperCase());
        System.out.println("Inisial: " + getName().toUpperCase().charAt(0));
        System.out.println("Panjang Nama: " + getName().length());
        System.out.println("Level: " + getLevel());
        System.out.println("Power Akhir: " + calculatePower());
        System.out.println("Jenis: Fighter");
    }
}