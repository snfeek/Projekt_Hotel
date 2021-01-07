#pragma once
#include <string>
using namespace std;

class Hotel {
public:
	string nazwa;
	string adres;
	string www;
	string nr_tel; //do usuniecia
	int liczba_pokoi;
	int liczba_gosci;
	int liczba_pracownikow;
};

class Recepcja {
//	string nr_tel;
};

class Pokoj {
public: 
	const int numer_pokoju;
	const int pietro;

	bool czy_zarezerowany();
};
class user {
public:
	string login;
	string haslo;
	void rejestracja();
};

bool Pokoj::czy_zarezerowany() {
	return true;
}

void user::rejestracja()
{
	
	cout << "----Rejestracja----\nLogin:";
	cin >> login;
	cout << "Haslo: ";
	cin >> haslo;

}