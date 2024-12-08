#include<iostream>

struct ATM{
  int pin = 1234;
  double saldo = 0;
};

void menuUtama(){
  std::cout << "===================================" << std::endl;
  std::cout << " SELAMAT DATANG DI ATM " << std::endl;
  std::cout << "===================================" << std::endl << std::endl;
  std::cout << " Silahkan pilih Transaksi yang ingin anda lakukan! " << std::endl << std::endl;
  std::cout << "===================================" << std::endl << std::endl;
  std::cout << " cek saldo   (1) " << std::endl;
  std::cout << " setor tunai (2) " << std::endl;
  std::cout << " Tarik Tunai (3) " << std::endl;
  std::cout << " Keluar      (4) " << std::endl << std::endl;
  std::cout << "===================================" << std::endl << std::endl;
  std::cout << " silahkan masukkan pilihan anda =  ";
  
}

bool autentikasiPIN (ATM atm){
  int inputPIN;
  int maxPIN = 3;

  for (int i = 0; i < maxPIN; i++){
    std::cout << " Masukkan PIN! : ";
    std::cin >> inputPIN;
    if (inputPIN == atm.pin){
      return true;
    } else {
      std::cout << " PIN salah! kesempatan memasukkan pin anda = " << (maxPIN - i - 1);
    }
  }
return false;

}

int main(){
 
  ATM atm = {1234, 0};
  int pilihan;

  if (!autentikasiPIN(atm)){
    std::cout << " Anda telah memaukan PIN yang salah sebanyak 3 kali, Kart anda di blokir" << std::endl;
    return 0;
  }

  do { 
    menuUtama();
    std::cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      std::cout << " Saldo anda : Rp." << atm.saldo << std::endl;
      break;

    case 2:
      double setor;
      std::cout << " Masukkan jumlah tunai!" << std::endl;
      std::cout << " Minimum jumlah setor adalah Rp.100.000 " << std::endl;
      std::cin >> setor;
      if (setor >= 100000) {
         atm.saldo +=  setor;
         std::cout << " Teransaksi Berhasil!";
        } else {
          std::cout << " Jumlah setor tidak memenuhi syarat!" << std::endl;
          std::cout << " Teransaksi gagal! " << std::endl;
          break; 
        }
    case 3:
      double tarik;
      std::cout << " Masukkan jumlah tunai : RP.";
      std::cin >> tarik;
        if (tarik <= atm.saldo)
        {
        atm.saldo -= tarik;
        std::cout << " Teransaksi berhasil!" << std::endl;
        std::cout << " Saldo Anda : Rp." << atm.saldo << std::endl;
        break;
        }
    case 4: 
      std::cout << " Terimakasih sudah menggubakan layanana ATM!" << std::endl;
      break;

    default:
    std::cout << " Pilihan tidak tersedia, silahkan coba lagi!" << std::endl;
    }
   }while (pilihan != 4);
  std::cout << " SELESAI!";

  return 0;
}

  