#include "Authenticator.hpp"
#include "AdminUser.hpp"
#include "User.hpp"
#include <iostream>

using namespace std;

Authenticator::Authenticator() {
  currentUser = nullptr;
  userCount = 0;
  secretResource = "Ini adalah data rahasia!";

  for (int i = 0; i < MAX_USERS; i++) {
    users[i] = nullptr;
  }
}
void Authenticator::registerUser(const string &username, const string &password,
                                 bool isAdmin) {
  if (userCount >= MAX_USERS) {
    cout << "Gagal: Kapasitas user penuh!" << endl;
    return;
  }

  // iterate list to validate username
  for (int i = 0; i < userCount; i++) {

    if (users[i]->getUsername() == username) {
      cout << "Gagal: Username sudah digunakan!" << endl;
      return;
    }
  }

  // create user based on role
  User *newUser;

  if (isAdmin)
    newUser = new AdminUser(username, password);
  else
    newUser = new User(username, password);

  users[userCount++] = newUser;
  cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
}

void Authenticator::login(const string &username, const string &password) {
  for (int i = 0; i < userCount; i++) {
    if (users[i]->getUsername() == username &&
        users[i]->checkPassword(password)) {
      currentUser = users[i];
      cout << "Sukses: Login berhasil! Selamat datang, " << username << "."
           << endl;
      return;
    }
  }

  cout << "Gagal: Username atau password salah!" << endl;
}

void Authenticator::logout() {
  if (currentUser == nullptr) {
    cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    return;
  }

  string username = currentUser->getUsername();
  cout << "Sukses: User " << username << " telah logout." << endl;
  currentUser = nullptr;
}

void Authenticator::accessResource() const {
  if (currentUser == nullptr) {
    cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    return;
  }

  cout << "Resource: " << secretResource << endl;
}

void Authenticator::setResource(const string &newResource) {
  if (currentUser == nullptr) {
    cout
        << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu."
        << endl;
    return;
  }
  if (!currentUser->isAdmin()) {
    cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat "
            "melakukan ini."
         << endl;
    return;
  }

  this->secretResource = newResource;
  cout << "Sukses: Resource telah diperbarui oleh "
       << currentUser->getUsername() << "." << endl;
}

Authenticator::~Authenticator() {
  for (int i = 0; i < userCount; ++i) {
    delete users[i];
  }
}
