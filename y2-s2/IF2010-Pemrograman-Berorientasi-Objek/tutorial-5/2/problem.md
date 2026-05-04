Dalam pengembangan backend modern, pertukaran data antara klien dan server selalu melibatkan Request (permintaan) dan Response (balasan). Tipe data yang dikirim dalam request sering kali berbeda dengan tipe data yang diterima dalam response. Misalnya, Anda mengirimkan request berupa kata kunci pencarian (String), lalu menerima response berupa ID hasil pencarian (Integer).

Tugas Anda:

1. Buat file APIResponse.java
   Berisi public class APIResponse<U> dengan spesifikasi:

Memiliki atribut private int statusCode, String message, dan U data.
Memiliki constructor untuk menginisialisasi ketiga atribut tersebut.
Memiliki method void printResponse() yang mencetak dengan format:
Response [statusCode] - [message] | Data: [data] (Type: [Nama Class dari U]) 2. Buat file APIRequest.java
Berisi public class APIRequest<T> dengan spesifikasi:

Memiliki atribut private String endpoint dan T payload (data yang dikirim).
Memiliki constructor untuk menginisialisasi kedua atribut tersebut.
Memiliki Generic Method bernama execute. Method ini menerima tipe generic baru <U> dengan parameter: int statusCode, String message, dan U responseData.
Method execute ini harus melakukan dua hal:
Mencetak log ke layar: Executing Request to [endpoint] with payload: [payload]
Mengembalikan sebuah objek APIResponse<U> yang baru dibuat berdasarkan parameter yang diterimanya.
Driver
Gunakan kode di bawah ini tanpa mengubah isinya untuk melakukan pengetesan terhadap class yang telah Anda buat.

import java.util.Scanner;

public class Main {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);

        try {
            // Request(String) -> Response(Integer)
            String endpoint1 = scanner.nextLine();
            String payload1 = scanner.nextLine();
            int status1 = scanner.nextInt();
            scanner.nextLine();
            String message1 = scanner.nextLine();
            int resData1 = scanner.nextInt();
            scanner.nextLine();

            APIRequest<String> req1 = new APIRequest<>(endpoint1, payload1);
            APIResponse<Integer> res1 = req1.execute(status1, message1, resData1);
            res1.printResponse();

            // Request(Integer) -> Response(String)
            String endpoint2 = scanner.nextLine();
            int payload2 = scanner.nextInt();
            scanner.nextLine();
            int status2 = scanner.nextInt();
            scanner.nextLine();
            String message2 = scanner.nextLine();
            String resData2 = scanner.nextLine();

            APIRequest<Integer> req2 = new APIRequest<>(endpoint2, payload2);
            APIResponse<String> res2 = req2.execute(status2, message2, resData2);
            res2.printResponse();

        } catch (Exception e) {
            System.out.println("Kesalahan membaca input.");
        } finally {
            scanner.close();
        }
    }

}
Contoh Input:
/api/login
admin_user
200
Success
10543
/api/users/10543
10543
200
OK
admin_user
Contoh Output:
Executing Request to /api/login with payload: admin_user
Response 200 - Success | Data: 10543 (Type: Integer)
Executing Request to /api/users/10543 with payload: 10543
Response 200 - OK | Data: admin_user (Type: String)
