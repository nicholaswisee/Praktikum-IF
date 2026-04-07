#ifndef WEAPON_INVENTORY_HPP
#define WEAPON_INVENTORY_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct Weapon {
    string id;
    string name;
    string type;
    int damage;
    int rarity;

    Weapon(const string &id, const string &name, const string &type, int damage,
           int rarity)
        : id(id), name(name), type(type), damage(damage), rarity(rarity) {}
};

class WeaponInventory {
  private:
    vector<Weapon> weapons;

  public:
    /**
     * @brief Menambahkan senjata baru ke inventaris.
     * @param id ID unik senjata.
     * @param name Nama senjata.
     * @param type Tipe senjata (Sword/Bow/Staff).
     * @param damage Nilai damage senjata.
     * @param rarity Tingkat kelangkaan (1-5).
     */
    void add(const string &id, const string &name, const string &type,
             int damage, int rarity);

    /**
     * @brief Menghapus senjata berdasarkan id.
     * @param id ID senjata yang akan dihapus.
     * @return true jika senjata ditemukan dan dihapus, false jika tidak
     * ditemukan.
     */
    bool remove(const string &id);

    /**
     * @brief Mencari senjata berdasarkan id.
     * @param id ID senjata yang dicari.
     */
    const Weapon *find(const string &id) const;

    /**
     * @brief Memperbarui data senjata yang sudah ada berdasarkan id.
     * @param id ID senjata target.
     * @param name Nama baru.
     * @param type Tipe baru.
     * @param damage Damage baru.
     * @param rarity Rarity baru.
     */
    void update(const string &id, const string &name, const string &type,
                int damage, int rarity);

    /**
     * @brief Mengurutkan senjata.
     * @details Urutan: rarity menurun, jika sama damage menurun, jika masih
     * sama id menaik (leksikografis).
     */
    void sort();

    /**
     * @brief Menghitung total damage semua senjata bertipe tertentu.
     * @param type Tipe senjata yang dihitung.
     * @return Total damage.
     */
    long long totalDamage(const string &type) const;

    /**
     * @brief Menghitung jumlah senjata dengan rarity >= minRarity.
     * @param minRarity Batas minimum rarity.
     * @return Jumlah senjata yang memenuhi syarat.
     */
    int countByRarity(int minRarity) const;

    /**
     * @brief Menampilkan semua senjata bertipe tertentu menggunakan iterator.
     * @param type Tipe senjata yang ditampilkan.
     * @details Cetak "EMPTY" jika tidak ada senjata bertipe tersebut.
     */
    void printByType(const string &type) const;

    /**
     * @brief Menampilkan seluruh senjata sesuai urutan saat ini di container.
     * @details Cetak "EMPTY" jika container kosong.
     */
    void print() const;

    /**
     * @brief Menambahkan bonus damage ke semua senjata bertipe tertentu.
     * @param type Tipe senjata yang di-upgrade.
     * @param bonusDamage Nilai tambahan damage.
     * @return Jumlah senjata yang ter-upgrade.
     */
    int upgradeAll(const string &type, int bonusDamage);
};

#endif
