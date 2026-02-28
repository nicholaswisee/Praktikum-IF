#include "Penganan.hpp"
#include <cstdio>
#include <iostream>

// Inisialisasi static member
int Penganan::uang = 0;
int Penganan::n_rumah = 0;

// Constructor
Penganan::Penganan() : keik(0), panekuk(0) {}
Penganan::Penganan(int k, int p) : keik(k), panekuk(p) {}

// Getter & Setter
int Penganan::GetKeik() const { return keik; }
int Penganan::GetPanekuk() const { return panekuk; }
void Penganan::SetKeik(int k) { keik = k; }
void Penganan::SetPanekuk(int p) { panekuk = p; }

// Operator +
Penganan operator+(const Penganan &p1, const Penganan &p2) {
  Penganan::n_rumah++;
  return Penganan(p1.keik + p2.keik, p1.panekuk + p2.panekuk);
}

// Operator -
Penganan operator-(const Penganan &p1, const Penganan &p2) {
  int jualK = (p1.keik >= p2.keik) ? p2.keik : p1.keik;
  int jualP = (p1.panekuk >= p2.panekuk) ? p2.panekuk : p1.panekuk;

  Penganan::uang += (jualK * 51 + jualP * 37); // Gunakan +=

  return Penganan(p1.keik - jualK, p1.panekuk - jualP);
}

// Operator ^ (Donasi)
Penganan operator^(const Penganan &p, const int n) {
  // Hitung sisa stok
  int sisaK = (p.keik - n < 0) ? 0 : p.keik - n;
  int sisaP = (p.panekuk - n < 0) ? 0 : p.panekuk - n;

  // Hitung hutang (jika stok < n, maka sisa negatif = hutang)
  int defK = (p.keik - n < 0) ? (p.keik - n) : 0;
  int defP = (p.panekuk - n < 0) ? (p.panekuk - n) : 0;

  Penganan::uang += (defK * 51 + defP * 37);

  return Penganan(sisaK, sisaP);
}

// Operator ^ (Komutatif)
Penganan operator^(const int n, const Penganan &p) {
  return p ^ n; // Panggil fungsi yang sudah dibuat
}

// Statistik
int Penganan::JumlahUang() { return uang; }
int Penganan::HitungNRumah() { return n_rumah; }

// Print
void Penganan::Print() {
  printf("%dkeik-%dpanekuk\n", keik, panekuk); // Tambahkan \n
}
