#include <iostream>
#include <ctime>
using namespace std;


const int HARGA_PERTEMUAN = 100000;
const int HARGA_SEBULAN = 300000;
const int HARGA_TIGA_BULAN = 900000;
const int HARGA_ENAM_BULAN = 1800000;
const int HARGA_SETAHUN = 3600000;
const int CASHBACK_TIGA = 150000;
const int CASHBACK_ENAM = 540000;
const int CASHBACK_DUA_BELAS = 1680000;
const int HARGA_LATIHAN_HARIAN = 45000;

// Function to display the list of prices
void displayPriceList() {
    cout << "\nList Harga:\n";
    
    cout << "1. Harga 1 Bulan: Rp " << HARGA_SEBULAN << endl;
    cout << "2. Harga 3 Bulan: Rp " << HARGA_TIGA_BULAN << " (Cashback Rp " << CASHBACK_TIGA << ")\n";
    cout << "3. Harga 6 Bulan: Rp " << HARGA_ENAM_BULAN << " (Cashback Rp " << CASHBACK_ENAM << ")\n";
    cout << "4. Harga 1 Tahun: Rp " << HARGA_SETAHUN << " (Cashback Rp " << CASHBACK_DUA_BELAS << ")\n";
    cout << "5. Harga Latihan Harian: Rp " << HARGA_LATIHAN_HARIAN << endl;
    cout<<endl;
    cout<< "Pricelist Trainer"<<endl;
    cout<<"Harga Trainer per Pertemuan: Rp " << HARGA_PERTEMUAN << endl;
    cout<<"8 Pertemuan = "<<HARGA_PERTEMUAN*8<<endl;
    cout<<"12 Pertemuan = "<<HARGA_PERTEMUAN*12<<endl;
    cout<<"16 Pertemuan = "<<HARGA_PERTEMUAN*16<<endl;
    cout<<"20 Pertemuan = "<<HARGA_PERTEMUAN*20<<endl;
}


int main()
{
    displayPriceList();
    cout<<endl;
    string nama;
    char pendaftaranMember, trainer;
    double nohp, nokartu = 123456;

    // pendaftaran member atau tidak
    cout << "Mau Daftar Member (y/n) : ";
    cin >> pendaftaranMember;

    // input biodata
    if (pendaftaranMember == 'y')
    {
        cout << "Masukkan nama lengkap Anda : ";
        cin >> nama;
        cout << "Masukan no hp : ";
        cin >> nohp;
        cout << "Masukkan nomor kartu member yang diberikan : ";
        cin >> nokartu;

        // harga pertemuan, harga jangka waktu perbulan, banyaknya cashback
        int hargaPertemuan = 100000, pertemuan, bulan;
        int satuBulan = 300000, tigaBulan = 900000, enamBulan = 1800000, satuTahun = 3600000;
        int tigaCashback = 150000, enamCashback = 540000, duaBelasCashback = 1680000;
        char perpanjangMember;
        bool repeat = false;

        while (true) {

            

            // Mengambil waktu saat ini
            time_t now = time(0);
            tm *ltm = localtime(&now);

            // Menampilkan tanggal, bulan, dan tahun saat ini
            cout << "Tanggal saat ini: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;

            menu:
            cout << "Mau pakai trainer (y/n) : ";
            cin >> trainer;

            // dengan trainer
            if (trainer == 'y')
            {
                cout << "Pilih jumlah pertemuan yang anda inginkan [8/12/16/20] : "; // pilih pertemuan yang diinginkan
                cin >> pertemuan;

                if (pertemuan == 8)
                {
                    cout << "Mau berapa bulan? (1/3/6/12) : ";
                    cin >> bulan;

                    // Mengupdate bulan
                    ltm->tm_mon += bulan;

                    // Menyesuaikan tahun jika melewati Desember
                    if (ltm->tm_mon > 11) {
                        ltm->tm_mon %= 12;
                        ltm->tm_year++;
                    }
                    cout << endl;
                    // harga sudah dikali 8 pertemuan
                    int trainerDelapan = hargaPertemuan * 8;
                    if (bulan == 1)
                    {
                        cout << "Harga menjadi : " << trainerDelapan * 1 + satuBulan << endl;
                    }
                    else if (bulan == 3)
                    {
                        cout << "dapat Cashback Rp150.000" << endl;
                        cout << "Harga menjadi : " << trainerDelapan * 3 + (tigaBulan - tigaCashback) << endl;
                    }
                    else if (bulan == 6)
                    {
                        cout << "dapat Cashback Rp540.000" << endl;
                        cout << "Harga menjadi : " << trainerDelapan * 6 + (enamBulan - enamCashback) << endl;
                    }
                    else if (bulan == 12)
                    {
                        cout << "dapat Cashback Rp1.680.000" << endl;
                        cout << "Harga menjadi : " << trainerDelapan * 12 + (satuTahun - duaBelasCashback) << endl;
                    }
                }
                else if (pertemuan == 12)
                {
                    cout << "Mau berapa bulan? (1/3/6/12) : ";
                    cin >> bulan;
                    // Mengupdate bulan
                    ltm->tm_mon += bulan;

                    // Menyesuaikan tahun jika melewati Desember
                    if (ltm->tm_mon > 11) {
                        ltm->tm_mon %= 12;
                        ltm->tm_year++;
                    }
                    cout << endl;

                    // harga sudah dikali 12 pertemuan
                    int trainerDuabelas = hargaPertemuan * 12;
                    if (bulan == 1)
                    {
                        cout << "Harga menjadi : " << trainerDuabelas * 1 + satuBulan << endl;
                    }
                    else if (bulan == 3)
                    {
                        cout << "dapat Cashback Rp150.000" << endl;
                        cout << "Harga menjadi : " << trainerDuabelas * 3 + (tigaBulan - tigaCashback) << endl;
                    }
                    else if (bulan == 6)
                    {
                        cout << "dapat Cashback Rp540.000" << endl;
                        cout << "Harga menjadi : " << trainerDuabelas * 6 + (enamBulan - enamCashback) << endl;
                    }
                    else if (bulan == 12)
                    {
                        cout << "dapat Cashback Rp1.680.000" << endl;
                        cout << "Harga menjadi : " << trainerDuabelas * 12 + (satuTahun - duaBelasCashback) << endl;
                    }
                }
                else if (pertemuan == 16)
                {
                    cout << "Mau berapa bulan? (1/3/6/12) : "; // pilih bulan
                    cin >> bulan;
                    // Mengupdate bulan
                    ltm->tm_mon += bulan;

                    // Menyesuaikan tahun jika melewati Desember
                    if (ltm->tm_mon > 11) {
                        ltm->tm_mon %= 12;
                        ltm->tm_year++;
                    }
                    cout << endl;
                    // harga sudah dikali 16 pertemuan
                    int trainerEnambelas = hargaPertemuan * 16;
                    if (bulan == 1)
                    {
                        cout << "Harga menjadi : " << trainerEnambelas * 1 + satuBulan << endl;
                    }
                    else if (bulan == 3)
                    {
                        cout << "dapat Cashback Rp150.000" << endl;
                        cout << "Harga menjadi : " << trainerEnambelas * 3 + (tigaBulan - tigaCashback) << endl;
                    }
                    else if (bulan == 6)
                    {
                        cout << "dapat Cashback Rp540.000" << endl;
                        cout << "Harga menjadi : " << trainerEnambelas * 6 + (enamBulan - enamCashback) << endl;
                    }
                    else if (bulan == 12)
                    {
                        cout << "dapat Cashback Rp1.680.000" << endl;
                        cout << "Harga menjadi : " << trainerEnambelas * 12 + (satuTahun - duaBelasCashback) << endl;
                    }
                }
                else if (pertemuan == 20)
                {
                    cout << "Mau berapa bulan? (1/3/6/12) : ";
                    cin >> bulan;
                    // Mengupdate bulan
                    ltm->tm_mon += bulan;

                    // Menyesuaikan tahun jika melewati Desember
                    if (ltm->tm_mon > 11) {
                        ltm->tm_mon %= 12;
                        ltm->tm_year++;
                    }
                    cout << endl;
                    // harga sudah dikali 20 pertemuan
                    int trainerDuapuluh = hargaPertemuan * 20;
                    if (bulan == 1)
                    {
                        cout << "Harga menjadi : " << trainerDuapuluh * 1 + satuBulan << endl;
                    }
                    else if (bulan == 3)
                    {
                        cout << "dapat Cashback Rp150.000" << endl;
                        cout << "Harga menjadi : " << trainerDuapuluh * 3 + (tigaBulan - tigaCashback) << endl;
                    }
                    else if (bulan == 6)
                    {
                        cout << "dapat Cashback Rp540.000" << endl;
                        cout << "Harga menjadi : " << trainerDuapuluh * 6 + (enamBulan - enamCashback) << endl;
                    }
                    else if (bulan == 12)
                    {
                        cout << "dapat Cashback Rp1.680.000" << endl;
                        cout << "Harga menjadi : " << trainerDuapuluh * 12 + (satuTahun - duaBelasCashback) << endl;
                    }
                }
            }
            else if (trainer == 'n')
            {
                int tigaCashback = 150000, enamCashback = 540000, duaBelasCashback = 1680000, bulan, totalHarga;
                int satuBulan = 300000, tigaBulan = 900000, enamBulan = 1800000, satuTahun = 3600000;
                int monthsToUpdate;

                cout << "Mau berapa Bulan? (1/3/6/12) : ";
                cin >> bulan;
                // Mengupdate bulan
                ltm->tm_mon += bulan;

                // Menyesuaikan tahun jika melewati Desember
                if (ltm->tm_mon > 11) {
                    ltm->tm_mon %= 12;
                    ltm->tm_year++;
                }
                if (bulan == 1)
                {
                    cout << "Harga : " << satuBulan;
                }
                else if (bulan == 3)
                {
                    totalHarga = tigaBulan - tigaCashback;
                    cout << "Harga menjadi : " << totalHarga << endl;
                }
                else if (bulan == 6)
                {
                    totalHarga = enamBulan - enamCashback;
                    cout << "Harga menjadi : " << totalHarga << endl;
                }
                else if (bulan == 12)
                {
                    totalHarga = satuTahun - duaBelasCashback;
                    cout << "Harga menjadi : " << totalHarga << endl;
                }
            }

            // percobaan

            int noMember;
            char selesaiLatihan;
            bool presensi = false;

            presence:
            // Menampilkan tanggal, bulan, dan tahun setelah diupdate
            cout << "\nMasa berakhir member: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;

            // absen validasi untuk yang sudah menjadi memeber
            cout << "Presensi dulu ya" << endl;
            do
            {
                cout << "Masukkan Nomor Kartu Member Anda : ";
                cin >> noMember;
                if (noMember != nokartu)
                {
                    cout << "Wah, nomor member tidak terdaftar, silahkan coba lagi ya" << endl;
                }
            } while (noMember != nokartu);

            if (ltm->tm_year >= 1900 && ltm->tm_mon == 1 && ltm->tm_mday >= 1) {
            // Jika sudah, menampilkan opsi untuk update bulan
            char jawaban;
            cout << "Member sudah habis! Apakah Anda ingin perpanjang member? (y/n): ";
            cin >> jawaban;

            // Jika jawaban 'y', lanjutkan ke iterasi berikutnya untuk mengupdate bulan
            if (jawaban == 'y' || jawaban == 'Y') {
                continue;
            } else {
                cout << "Sampai jumpa kapan-kapan!" << endl;
                break;
            }
            } else {
                // Jika belum sampai waktu update, memberikan keterangan
                cout << "Selamat Berlatih!" << endl;
                cout << "Sudah selesai Latihan?\n";
                cout << "*hanya diisi saat sdh selesai (y) : ";
                cin >> selesaiLatihan;
                if (selesaiLatihan == 'y')
                {
                    presensi = true;
                    if (presensi)
                    {
                        goto presence;
                    }
                }
                else if (selesaiLatihan == 'n')
                {
                    presensi = false;
                    return 0;
                }
            }
        }
    }
    else if (pendaftaranMember == 'n')
    {
        char bayarPerhari;

        cout << "Masukkan nama lengkap Anda : ";
        cin >> nama;
        cout << "Masukan no hp : ";
        cin >> nohp;
        hari:
        cout << "Harganya Rp 45.000. Sudah dibayar?";
        cout << "(y/n) : ";
        cin >> bayarPerhari;
        if (bayarPerhari == 'y')
        {
            cout << "Selamat Berlatih!";
        }
        else if (bayarPerhari == 'n')
        {
            cout << "Kamu harus membayar dulu!";
            goto hari;
        }
    }
}