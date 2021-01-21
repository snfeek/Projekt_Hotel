#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
#include <Windows.h>
using namespace std;



class User {  //klasa uzytkownika
public:
	string login;
	string haslo;
	

public:
	User() {}

	User(string login1, string haslo1) {		//konstruktor uzytkownika
		login = login1;
		haslo = haslo1;
	}
};

bool rejestracja()
{
	cout << "\n\t\t\t\t*************";
	cout <<"\n\t\t\t\t Podaj login: ";

	string login;
	cin >> login;
	cout << "\n\t\t\t\t Podaj haslo: ";
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
			cout << "\n\t\t\t\tJest juz taki uzytykownik! Login zajety" << endl;
		return 0;
	}

	return 1;
}

void menu_admin()				//po zalogowaniu
{


}

bool zalogowany = false;  //zmienna do nawigowania w menu, nie pozwala zarezerwowac pokoju jezeli uzytkownik nie jest zalogowany

bool logowanie()
{
	string login, haslo;
	system("cls");
	cout << "\n\t\t\t\tPodaj login: ";
	cin >> login;
	cout << "\n\t\t\t\tPodaj haslo: ";
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
				zalogowany = true;
			}
			//cout << tempLogin << " " << tempHaslo << " " << tempHaslo.size() <<  endl;
		}

		if (zalogowano == true) {
			zalogowany = true;
		}
		else {
			cout << "\n\t\t\t\tnie  zalogowany" << endl;
			return 0;
		}

		
		plik.close();
	}
	return 1;
}





void menu_user()
{
	for (;;)
	{
		system("cls");
		int wybor;
		cout << "\n\t\t\t\t*************";			//gwiazdki przy menu maja charakter czysto wizualny
		cout << "\n\t\t\t\t  ** Menu **";
		cout << "\n\t\t\t\t*************";
		cout << "\n\t\t\t\t(1) Zarezerwuj pokoj" << endl;
		
		

		cin >> wybor;
		cin.clear();
		cin.ignore();
		system("cls");	//czyszczenie ekranu

		switch (wybor)
		{
		case 1:
		{
			//zarezerwuj_pokoj();
			break;
		}
		case 2:
		{
			
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
	
		if (wybor == 1)
		{
			break;
		}
	}
}



void menu() {
	for (;;)
	{
		int wybor;
		cout << "\n\t\t\t\t*******************";
		cout << "\n\t\t\t\t** Witaj w menu! **" ;			//gwiazdki przy menu maja charakter czysto wizualny
		cout << "\n\t\t\t\t*******************";
		cout << "\n\t\t\t\tCo chcesz zrobic?" << endl;
		cout << "\n\t\t\t\t(1) Zaloguj sie" << endl;
		cout << "\n\t\t\t\t(2) Zarejestruj sie" << endl;
		cout << "\n\t\t\t\t(3) Zarezerwuj pokoj" << endl;

		cin >> wybor;
		cin.clear();
		cin.ignore();
		system("cls");		 //czyszczenie ekranu

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
			rejestracja();					//wywolanie rejestracji
			
			
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
			if (zalogowany)			//ograniczenie do rezerwacji
				break;
			else
				cout << "\n\t\t\t\tMusisz sie zalogowac" << endl;
		}
	}
}


int main()
{
	
	Pokoj p[10];						 //tworzenie obiektów pokoi 
	for (int i = 0; i < 10; i++)
	{
		p[i].numer_pokoju = i + 1;		//nadawanie pokojom numerów
	}
	for (int i = 0; i < 3; i++)
	{
		p[i].standard = 1;				//standard
		p[i].pietro = 0;				//3 pierwsze pokoje na parterze
		p[i].liczba_lozek = 2;			// 1 standard pokoju ma po dwa ³ó¿ka i oba pojedynce
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
		p[i].pokaz_dane();   //wyswietlenie pokoi
	}
	cout << endl << "\n\t\t\t\t Wybierz pokoj do zarezerwowania: "; //wyjscie z menu, rezerwowanie
	int choice;
	cin >> choice;
	cin.clear();
	cin.ignore();
	
	p[choice-1].rezerwowanie(); // choice -1 poniewa¿ u¿ytkownik wpisuje od 1 do 10, a tablica ma wartosci od 0 do 9
	
	
	

	system("cls");
	cout << "\n\t\t\t\t(1) Informacje o rezerwacji" << endl;			//dalsze operacje na rezerwacji
	cout << "\n\t\t\t\t(2) Edycja rezerwacji" << endl;
	int wybor2;
	cin >> wybor2;
	cin.clear();
	cin.ignore();

	switch (wybor2)
	{
	case 1:
	{
		system("cls");
		cout << "\n\t\t\t\t*************";				//gwiazdki maja charakter czysto wizualny
		cout  << "\n\t\t\t\tInformacje o rezerwacji" ;
		cout << "\n\t\t\t\t*************";
		cout << "\n\t\t/t/tZarezerwowany pokoj: pokoj numer " << p[choice - 1].numer_pokoju << endl;			//wyswietla informacje o rezerwacji takie jak numer pokoju i rachunek za rezerwacje
		p[choice - 1].rachunek();																	
		Sleep(10000);								//sleep aby system przez 10 sekund pokaza³ dan¹ informacje a potem wróci³ do menu
		system("cls");
		break;
	}
	case 2:
	{
		cout << "\n\t\t\t\t*************";					//gwiazdki maja charakter czysto wizualny
		cout << "\n\t\t\t\t(1) zmiana pokoju" ;
		cout << "\n\t\t\t\t(2) zmiana terminu rezerwacji";
		cout << "\n\t\t\t\t*************";
		int wybor3;
		cin >> wybor3;
		cin.clear();
		cin.ignore();
		switch (wybor3)
		{
		case 1:
			{

			system("cls");
			cout << "\n\t\t\t\t*************";						//gwiazdki maja charakter czysto wizualny
			cout << "\n\t\t\t\tzmiana pokoju" << endl;
			cout << "\n\t\t\t\t*************";
			for (int i = 0; i < 10; i++)
				{
					p[i].pokaz_dane();   //wyswietlenie pokoi
					
				}
			cout << endl << endl << "\n\t\t\t\tWybierz nowy pokoj" << endl;				//wybieranie nowego pokoju
			int wybor4;
			cin >> wybor4;
			choice = wybor4;
			cin.clear();
			cin.ignore();
			p[choice - 1].rezerwowanie();
			cout << "\n\t\t\t\tUdalo sie zmienic pokoj" << endl;
			Sleep(10000);
			system("cls");
			break;
			}
		case 2:
			{
			system("cls");
			cout << "\n\t\t\t\t*************";					//gwiazdki maja charakter czysto wizualny
			cout << "\n\t\t\t\tzmiana terminu rezerwacji"  ;
			cout << "\n\t\t\t\t*************";
			p[choice - 1].rezerwowanie();
			cout << "\n\t\t\t\tudalo sie zmienic termin rezerwacji" << endl;				//wybieranie nowego terminu dla rezerwacji
			Sleep(10000);	
			system("cls");
			break;
			}
		}
		Sleep(10000);
		system("cls");
		break;
	}
	}
		
	menu();

	system("pause");
	return 0;
}

