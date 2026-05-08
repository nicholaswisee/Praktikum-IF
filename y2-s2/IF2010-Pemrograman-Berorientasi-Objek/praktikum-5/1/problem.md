Kebin sedang mendalami konsep Interface dalam Object Oriented Programming. Setelah memahami teori tentang abstraksi dan polymorphism, ia mencoba mempraktikkannya dengan membuat sebuah sistem pembayaran sederhana menggunakan konsep Payment Strategy. Dalam proses belajarnya, Kebin ingin merancang sistem checkout yang fleksibel sehingga metode pembayaran dapat diganti kapan saja tanpa perlu mengubah logika utama program.

Bantulah Kebin mengimplementasikan fitur pembayaran ini dengan melengkapi kelas-kelas dan antarmuka (interface) berikut:

PaymentStrategy (Interface): Memiliki metode void pay(int amount).
CardPayment: Implementasi PaymentStrategy. Output pay adalah Paid $<amount> using Credit Card.
BankTransferPayment: Implementasi PaymentStrategy. Output pay adalah Paid $<amount> using Bank Transfer.
EWalletPayment: Implementasi PaymentStrategy. Output pay adalah Paid $<amount> using E-Wallet.
Checkout: Memiliki atribut paymentStrategy (tipe PaymentStrategy), dengan metode void setPaymentStrategy(PaymentStrategy) dan void processPayment(int amount) yang memanggil metode pay. Jika paymentStrategy masih null saat processPayment dipanggil, output adalah: No payment method selected.
Driver tersedia pada Main.java

Input:

Baris pertama berisi N yang merepresentasikan jumlah perintah (N baris setelahnya).

Perintah dapat berupa:

SET CARD
SET EWALLET
SET BANK
PAY <amount>
Contoh Input:

2
SET CARD
PAY 100
Contoh Output:

Paid $100 using Credit Card

Pengumpulan:

Kumpulkan Checkout.java, PaymentStrategy.java, BankTransferPayment.java, EWalletPayment.java, CardPayment.java pada Checkout.zip

Setiap output harus menggunakan newline
