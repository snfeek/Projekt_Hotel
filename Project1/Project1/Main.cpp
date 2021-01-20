#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
using namespace std;



class User {
public:
	string login;
	string haslo;
	

public:
	User() {}

	User(string login1, string haslo1) {
		login = login1;
		haslo = haslo1;
	}
};

bool rejestracja()
{
	cout << "Podaj login: ";

	string login;
	cin >> login;
	cout << "\nPodaj haslo: ";
	string haslo;
	cin >> haslo;

	bool moznaZarejestrowac = 1;
	string line;
	ifstream plik("Text.txt");			//otwarcie pliku
	if (plik.is_open()) {			//otwieram do odczytu
		while (getline(plik, line)) {		//petla pobierania linie z pliku plik=skad, line=dokad
			size_t spacja = line.find(' ');			//szukanie spacji
			string tempLogin = line.substr(0, spacja);	//zapisywanie

			if (login.compare(tempLogin) == 0) {			//porownanie loginu, jest taki login
				//cout << "Jestes zalogowany" << endl;
				moznaZarejestrowac = false;
			}
			plik.close();
		}

		if (moznaZarejestrowac == true) { //gdy nie znaleziono takiego loginu
			ofstream plik("Text.txt", ios_base::app);
			if (plik.is_open()) {
				plik << login << " " << haslo << endl;
				plik.close();
			}
		}

		else
			cout << "Jest juz taki uzytykownik! Login zajety" << endl;
		return 0;
	}

	return 1;
}

void menu_admin()				//po zalogowaniu
{


}

bool logowanie()
{
	string login, haslo;
	cout << "Podaj login: ";
	cin >> login;
	cout << "\nPodaj haslo: ";
	cin >> haslo;

	if (login.compare("admin") == 0 && haslo.compare("admin") == 0)
	{
		menu_admin();
	}
	bool zalogowano = 0;

	string line;
	ifstream plik("Text.txt");			//otwarcie pliku
	if (plik.is_open()) {
		while (getline(plik, line)) {		//petla pobierania linie z pliku plik=skad, line=dokad
			size_t spacja = line.find(' ');			//szukanie spacji
			string tempLogin = line.substr(0, spacja);	//dzielenie na login i haslo
			string tempHaslo = line.substr(spacja + 1);


			if (login.compare(tempLogin) == 0 && haslo.compare(tempHaslo) == 0) {			//porownanie loginu i hasla uzytkownika z tymi z pliku
				//cout << "Jestes zalogowany" << endl;
				zalogowano = true;
			}
			//cout << tempLogin << " " << tempHaslo << " " << tempHaslo.size() <<  endl;
		}

		if (zalogowano == true) {

		}
		else {
			cout << "nie  zalogowany" << endl;
			return 0;
		}

		
		plik.close();
	}
	return 1;
}

void zarzadzanie_pokojem()
{

}

void menu_user()
{
	for (;;)
	{
		system("cls");
		int wybor;
		cout << "** Menu **"<<endl;
		cout << "(1) Zarezerwuj pokoj" << endl;
		cout << "(2) Zarezerwowane pokoje" << endl;
		cout << "(3) Wyjdz" << endl;

		cin >> wybor;
		cin.clear();
		cin.ignore();
		system("cls"); //czyszczenie ekranu

		switch (wybor)
		{
		case 1:
		{
			//zarezerwuj_pokoj();
			break;
		}
		case 2:
		{
			//zarzadzanie_pokojem();
			break;
		}
		case 3:
		{

			break;
		}
		default:
		{
			break;
		}
		}
		if (wybor == 3)
		{
			break;
		}
	}
}



void menu() {
	for (;;)
	{
		int wybor;
		cout << "Witaj w menu!" << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "(1) Zaloguj sie" << endl;
		cout << "(2) Zarejestruj sie" << endl;
		cout << "(3) Zarezerwuj pokoj" << endl;

		cin >> wybor;
		cin.clear();
		cin.ignore();
		system("cls"); //czyszczenie ekranu

		switch (wybor)
		{
		case 1:
		{
			bool stan = 0;
			while (stan == 0) {
				system("cls");
				stan = logowanie();
			}
			menu_user();
			break;
		}
		case 2:
		{
			rejestracja();
			
			
			break;
		}
		case 3:
		{
			break;
		}
		default:
		{
			break;
		}
		}
		if (wybor == 3)
		{
			break;
		}
	}
}

int main()
{
	
	Pokoj p[10];
	for (int i = 0; i < 10; i++)
	{
		p[i].numer_pokoju = i + 1;
	}
	for (int i = 0; i < 3; i++)
	{
		p[i].standard = 1;
		p[i].pietro = 0;
		p[i].liczba_lozek = 2;
		p[i].rodzaj_lozek = "Pojedyncze";
		p[i].cena_za_noc = 150;

	}
	for (int i = 3; i < 6; i++)
	{
		p[i].standard = 2;
		p[i].pietro = 1;
		p[i].liczba_lozek = 1;
		p[i].rodzaj_lozek = "Podwojne";
		p[i].cena_za_noc = 250;
	}
	for (int i = 6; i < 9; i++)
	{
		p[i].standard = 3;
		p[i].pietro = 4;
		p[i].liczba_lozek = 2;
		p[i].rodzaj_lozek = "Podwojne";
		p[i].cena_za_noc = 400;
	}
	p[9].standard = 4;
	p[9].pietro = 5;
	p[9].liczba_lozek = 3;
	p[9].rodzaj_lozek = "Krolewskie";
	p[9].cena_za_noc = 600;
	



	
	menu();


	for (int i = 0; i < 10; i++)
	{
		p[i].pokaz_dane();
	}
	cout << endl << " Wybierz pokoj do zarezerwowania: ";
	int choice;
	cin >> choice;
	p[choice-1].rezerwowanie();
	p[choice-1].rachunek();


	system("pause");
	return 0;
}

