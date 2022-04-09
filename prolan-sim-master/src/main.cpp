#include <iostream>
#include <vector>
#include <sstream>//untuk mengubah int jadi string
#include <string>
#include <conio.h>//untuk getch(system password)

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"


void UsernamePassword();//function void
void EditPassword();//function void
using namespace std;

string check="password";//declare password awal
string check2= "admin" ;//declare username awal

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
	
	cout<<"===================================================================="<<endl;//memperindah menu awal
	cout << "Selamat datang di Universitas Komedi Malam\n";
	cout<<"===================================================================="<<endl;
	UsernamePassword();// memanggil fungsi password

	while(1) {
		cout<<"===================================================================="<<endl;//memperindah menu awal
		cout << "Selamat datang di Universitas Komedi Malam\n";
		cout<<"===================================================================="<<endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tenaga kependidikan" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  7. Edit Data" << endl;//opsi edit data
		cout << "  8. Edit Username dan Password" << endl;//opsi edit password yang sudah ada
		cout << "  9. Log Out" << endl;//opsi log out
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cin.ignore();//

		switch (menu_terpilih) {
			case 1:
			{
				int dd, mm, yy, tahunmasuk, semesterke, skslulus;
				string id, nama, nrp, departemen;

				stringstream ss;//declare ss
				ss << 1 + recMhs.size();//komputer secara otomatis memasukan id orang itu ke ss
				id = ss.str();// data di ss dipindah ke id

				cout << "Nama: ";//output "nama"
				getline(cin, nama);// pakai getline karena mengambil lebih dari 1 kata

				cout << "Tanggal Lahir: ";
				cin >> dd;

				cout << "Bulan Lahir: ";
				cin >> mm;

				cout << "Tahun Lahir: ";
				cin >> yy;

				cout << "NRP: ";
				cin >> nrp;

				cout << "Departemen: ";
				cin.ignore();
				getline(cin, departemen);

				cout << "Semester: ";
				cin >> semesterke;

				cout << "SKS yang telah lulus: ";
				cin >> skslulus;

				vector<float> ipstemp;
				float tempfile;
				for(int p=1; p<semesterke; p++)
				{
					cout << "IPS Semester "<< p<<": ";
					cin >> tempfile;
					ipstemp.push_back(tempfile);
				}	

				cout << "Tahun Masuk Kuliah: ";
				cin >> tahunmasuk;

				mahasiswa mhs(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus);

				for(unsigned u=1; u<=ipstemp.size(); u++)
				{
					mhs.setIPS(u,ipstemp[u-1]);
				}

				mhs.hitungIPK();
				recMhs.push_back(mhs);
				
				system ("cls");
				
			}
				break;
			case 2:
			{
				int dd, mm, yy, pendidikan;
				string id, nama, npp, departemen;

				stringstream ss;
				ss << 1 + recDosen.size();
				id = ss.str();

				cout << "Nama: ";
				getline(cin, nama);

				cout << "Tanggal Lahir: ";
				cin >> dd;

				cout << "Bulan Lahir: ";
				cin >> mm;

				cout << "Tahun Lahir: ";
				cin >> yy;

				cout << "NPP: ";
				cin >> npp;

				cout << "Departemen: ";
				cin.ignore();
				getline(cin, departemen);

				cout << "Pendidikan: ";
				cin >> pendidikan;

				dosen dsn(id, nama, dd, mm, yy, npp, departemen, pendidikan);

				recDosen.push_back(dsn);
				system ("cls");
			}
				break;
			case 3:
			{
				int dd, mm, yy ;
				string id, nama, npp, unit;

				stringstream ss;
				ss << 1 + recTendik.size();
				id = ss.str();

				cout << "Nama: ";
				getline(cin, nama);

				cout << "Tanggal Lahir: ";
				cin >> dd;

				cout << "Bulan Lahir: ";
				cin >> mm;

				cout << "Tahun Lahir: ";
				cin >> yy;

				cout << "NPP: ";
				cin >> npp;

				cout << "Unit: ";
				cin.ignore();
				getline(cin, unit);

				tendik tendik(id, nama, dd, mm, yy, npp, unit);

				recTendik.push_back(tendik);
				system ("cls");

			}
				break;
			case 4:
			{
				cout << endl;
				for(unsigned long i=0; i< recMhs.size(); i++)
				{
					cout<<"===================================================================="<<endl;
					cout << "ID: ";
					string simple=recMhs[i].getId();
					stringstream id_int(simple);
					int count = 0;
					id_int >> count;
					int hitung = 6;
					int x=0;
					while (true)
					{
						int hasil = count / 10;

						if(hasil==0)
							break;
						x++;
					}

					for(int j=0; j<hitung-x; j++)
					{
						cout << "0";
					}
		
					cout << recMhs[i].getId()<< endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
					cout << "Tanggal Lahir: ";
					if(recMhs[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recMhs[i].getTglLahir()<<"/";
					if(recMhs[i].getBulanLahir()<10){
						cout<<"0";
					}
					cout << recMhs[i].getBulanLahir()<<"/"<<recMhs[i].getTahunLahir()<<endl;
					cout << "NRP: "<< recMhs[i].getNRP() << endl;
					cout << "Departemen: "<< recMhs[i].getDepartemen() << endl;
					cout << "Semester ke-"<<recMhs[i].getSemester() << endl;
					cout << "SKS Lulus: "<<recMhs[i].getSKSLulus() << endl;
					cout << "IPK: " <<recMhs[i].getIPK()<<endl;
					cout << "Tahun Masuk: "<< recMhs[i].getThnMsk() << endl;
					cout << endl;
					cout<<"===================================================================="<<endl;
				}
			}
				break;
			case 5:
			{
				cout << endl;
				for(unsigned long i=0; i< recDosen.size(); i++)
				{
					cout<<"===================================================================="<<endl;
					cout << "ID: ";
					string simple=recDosen[i].getId();
					stringstream id_int(simple);
					int count = 0;
					id_int >> count;
					int hitung = 6;
					int x=0;
					while (true)
					{
						int hasil = count / 10;

						if(hasil==0)
							break;
						x++;
					}

					for(int j=0; j<hitung-x; j++)
					{
						cout << "0";
					}
					cout << recDosen[i].getId()<< endl;

					cout << "Nama Dosen: " << recDosen[i].getNama() << endl;
					cout << "Tanggal Lahir: ";
					if(recDosen[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recDosen[i].getTglLahir()<<"/";
					if(recDosen[i].getBulanLahir()<10){
						cout<<"0";
					}
					cout << recDosen[i].getBulanLahir()<<"/"<<recDosen[i].getTahunLahir()<<endl;
					cout << "NPP: "<< recDosen[i].getnpp() << endl;
					cout << "Departemen: "<< recDosen[i].getDepartemen() << endl;
					cout << "Pendidikan: "<< recDosen[i].getPendidikan() << " Tahun" << endl;
					cout << endl;
					cout<<"===================================================================="<<endl;
				}
			}
				break;
			case 6:
			{
				cout << endl;
				for(unsigned long i=0; i< recTendik.size(); i++)
				{
					cout<<"===================================================================="<<endl;
					cout << "ID: ";
					string simple=recTendik[i].getId();
					stringstream id_int(simple);
					int count = 0;
					id_int >> count;
					int hitung = 6;
					int x=0;
					while (true)
					{
						int hasil = count / 10;

						if(hasil==0)
							break;
						x++;
					}

					for(int j=0; j<hitung-x; j++)
					{
						cout << "0";
					}
					cout << recTendik[i].getId()<< endl;

					cout << "Nama Tenaga Kependidikan: " << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir: ";
					if(recTendik[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recTendik[i].getTglLahir() << "/";
					if(recTendik[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recTendik[i].getBulanLahir()<<"/"<<recTendik[i].getTahunLahir()<<endl;
					cout << "NPP: "<< recTendik[i].getNPP() << endl;
					cout << "Unit: "<< recTendik[i].getUnit() << endl;
					cout << endl;
					cout<<"===================================================================="<<endl;
				}
			}
				break;
			case 7:
			{
				system("cls");
				cout << "  1. Edit Data Mahasiswa" << endl;
				cout << "  2. Edit Data Dosen" << endl;
				cout << "  3. Edit Data Tenaga Kependidikan" << endl;

				int bukalapak;
				cin >> bukalapak;

				switch (bukalapak)
				{
					case 1:
					{
						for(unsigned long i=0; i< recMhs.size(); i++)
						{
							cout<<"===================================================================="<<endl;
							cout << "ID: ";
							string simple=recMhs[i].getId();
							stringstream id_int(simple);
							int count = 0;
							id_int >> count;
							int hitung = 6;
							int x=0;
							while (true)
							{
								int hasil = count / 10;

								if(hasil==0)
									break;
								x++;
							}

							for(int j=0; j<hitung-x; j++)
							{
								cout << "0";
							}
				
							cout << recMhs[i].getId()<< endl;
							cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
							cout<<"===================================================================="<<endl;
						}
					}
			}
				break;
			case 8:
			{
				system("cls");
				cout << "Enter Old Username and Password" << endl;
				UsernamePassword();
				EditPassword();

			}
				break;
			case 9:
			{
				system("cls");
				cout<<"===================================================================="<<endl;
				cout << "Selamat datang di Universitas Komedi Malam\n";
				cout<<"===================================================================="<<endl;
				UsernamePassword();

			}
				break;
		}
	}

	return 0;
}


void UsernamePassword(){
	
	while(true)
	{
		string username;
		
		cout<< endl << "Enter Username\t: ";
		cin >> username;
		//cout << username<<endl;
		//cout << check << endl;
		if(username != check2){
			cout << "Wrong Username\nPlease Press Enter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		break;
	}
	while(true)
	{	
		
		//system("cls");
		cout<<"Enter Password\t: ";
		char pass[1000];
		int i = 0;
		char a;
		while(true)
		{
			a=getch();
			if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			{
				pass[i]=a;
				++i;
				cout<<"*";
			}
			if(a=='\b'&&i>=1)	
			{
				cout<<"\b \b";
				--i;
			}
			if(a=='\r')
			{
				pass[i]='\0';
				break;
			}
		}
		//cout<< endl << "You entered : "<<pass;
		if(pass==check){

			system("cls");
			break;
		}
		else{
			cout<< endl << "Wrong Password.\nPlease Press Enter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		
		if(i<=7)
		{
			cout<< endl <<"Minimum 8 digits needed.\nPlease PressEnter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		break;
	}
}


void EditPassword(){
	
	while(true)
	{
		string username;
		
		cout<< endl << "Enter New Username\t: ";
		cin >> username;
		if(username == check2){
			cout << "Same Username Detected, Are You Sure?(y/n)\n";
			string enter;
			cin >> enter;
			if(enter=="y"){
				system("cls");
				check2 = username;
				break;
				
			}
		}
		else
		{
			check2 = username;
			system("cls");
			break;
		}
		continue;
	}
	while(true)
	{	
		cout<<"Enter New Password\t: ";
		char pass[1000];
		int i = 0;
		char a;
		while(true)
		{
			a=getch();
			if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			{
				pass[i]=a;
				++i;
				cout<<"*";
			}
			if(a=='\b'&&i>=1)
			{
				cout<<"\b \b";
				--i;
			}
			if(a=='\r')
			{
				pass[i]='\0';
				break;
			}
		}
		//cout<< endl << "You entered : "<<pass;
		if(pass==check){
			cout << "\nSame Password Detected, Are You Sure ?(y/n)\n";
			string enter;
			cin >> enter;
			if(enter=="y"){
				check = pass;
				break;
				system("cls");
			}
		}
		else
		{
			check = pass;
			system("cls");
			break;
		}
		
		if(i<=7)
		{
			cout<< endl <<"Minimum 8 digits needed.\nPlease Press Enter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		break;
	}
}