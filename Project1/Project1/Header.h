#pragma once
#include <string>
using namespace std;

class Hotel {
public:
	string nazwa;
	string adres;
	string www;
	string nr_tel; //do usuniecia
	int liczba_pokoi[100]; 
	int liczba_gosci;
	int liczba_pracownikow; // liczba pracowników
};

class Recepcja {
//	string nr_tel;
};

class Pokoj {
public: 
	const int numer_pokoju;
	const int pietro;
	int rodzaj_pokoj; //1-jednosobowy, 2-dwuuosobowy,4-czterosobowy
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

