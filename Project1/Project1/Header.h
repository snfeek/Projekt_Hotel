#pragma once
#include <string>
#include <iostream>
using namespace std;

class Hotel {
public:
	string nazwa;
	string adres;
	string www;
	string nr_tel; //do usuniecia
	int liczba_pokoi[100]; 
	int liczba_gosci;
	int liczba_pracownikow; // liczba pracowników (42 pracownikow)
};

class Recepcja {
//	string nr_tel;
};

class Pokoj {
public: 
	const int numer_pokoju;
	const int pietro;
	int rodzaj_pokoj; //1-jednosobowy, 2-dwuuosobowy,4-czterosobowy
	int cena_za_noc;
	int dzien_konca_r, miesiac_konca_r, rok_konca_r, dzien_poczatku_r, miesiac_poczatku_r, rok_poczatku_r; // dzien konca n -dzien konca nowej rezerwacji itd
	int dzien_konca_n, miesiac_konca_n, rok_konca_n, dzien_poczatku_n, miesiac_poczatku_n, rok_poczatku_n; // dzien poczatku r - dzien poczatku starej rezerwacji
	bool czy_zarezerowany;
	void rezerwowanie();
	void rezerwacja();
	void rachunek();
};
class user {
public:
	string imie, nazwisko;
	int nr_tel;
	string login;
	string haslo;
	string zarezerwowany_pokoj;
	void rejestracja();
	void logowanie();
};

void Pokoj::rezerwacja()
{

	rok_konca_r = rok_konca_n;
	rok_poczatku_r = rok_poczatku_n;
	dzien_poczatku_r = dzien_poczatku_n; //tylko jak te zmienne maja byc wprowadzane poza metoda klasy to trzeba je przeniesc do maina chyba
	dzien_konca_r = dzien_konca_n;
	miesiac_konca_r = miesiac_konca_n;
	miesiac_poczatku_r = miesiac_poczatku_n;
	czy_zarezerowany = true; //tudaj daje true bo to czy_zarezerwowany to w kontekscie tego czy TERAZ zarezerwowany, myœlê ¿e tak jest ok
}

void Pokoj::rezerwowanie() // tutaj przed wywolaniem tej funkcji dobrze by bylo napisac cos w stlu ,,rezzerwacja pokoju, blablabla, wpisz datê pocz¹tku i koñca twojej rezerwacji
{ // bo nie chce tutaj dawac tych zmiennych bo to w mainie sie wszystko napisze i te ciny do tych zmiennych itd itp

	if (rok_poczatku_n == rok_konca_n == rok_konca_r == rok_poczatku_r) //zapierdole siê kurwa xD patrz ile tych ifów jest
	{
		if (miesiac_konca_n == miesiac_konca_r == miesiac_poczatku_n == miesiac_poczatku_r)
		{
			if (dzien_konca_n < dzien_poczatku_r)
			{
				rezerwacja();
			}
			else if (dzien_poczatku_n > dzien_konca_r)
			{
				rezerwacja();
			}
			else
			{
				cout << "Pokój jest wtedy zarezerwowany!" << endl;
			}
		}
		else if (miesiac_poczatku_n == miesiac_konca_r)
		{
			if (dzien_poczatku_n > dzien_konca_r)
			{
				rezerwacja();
			}
			else
			{
				cout << "Pokój jest wtedy zarezerwowany!" << endl;
			}
		}
		else if (miesiac_konca_n == miesiac_poczatku_r)
		{
			if (dzien_konca_n < dzien_poczatku_r)
			{
				rezerwacja();
			}
			else
			{
				cout << "Pokój jest wtedy zarezerwowany!" << endl;
			}
		}
		else if (miesiac_poczatku_n != miesiac_konca_r)
		{
			rezerwacja();
		}
		else if (miesiac_konca_n != miesiac_poczatku_r)
		{
			rezerwacja();
		}
	}
	else if (rok_poczatku_n == rok_konca_r)
	{
		if (miesiac_poczatku_n > miesiac_konca_r)
		{
			rezerwacja();
		}
		else if (miesiac_poczatku_n == miesiac_konca_r)
		{
			if (dzien_poczatku_n > dzien_konca_r)
			{
				rezerwacja();
			}
			else
			{
				cout << "Pokój jest wtedy zarezerwowany!" << endl;
			}
		}
		else
		{
			cout << "Pokój jest wtedy zarezerwowany!" << endl;
		}
	}
	else if (rok_konca_n == rok_poczatku_r)
	{
		if (miesiac_konca_n < miesiac_poczatku_r)
		{
			rezerwacja();
		}
		else if (miesiac_konca_n == miesiac_poczatku_r)
		{
			if (dzien_konca_n < dzien_poczatku_r)
			{
				rezerwacja();
			}
			else
			{
				cout << "Pokój jest wtedy zarezerwowany!" << endl;
			}
		}
	}
	else if (rok_poczatku_n > rok_konca_r)
	{
		rezerwacja();
	}
	else if (rok_konca_n < rok_poczatku_r)
	{
		rezerwacja();
	}

	
}

void Pokoj::rachunek()
{
	int rachunek_do_zaplacenia;
	int ilosc_dni;
	if (dzien_poczatku_n >= dzien_konca_n)
	{
	

		switch (miesiac_konca_n - miesiac_poczatku_n)
		{
		case 0:
			ilosc_dni = dzien_konca_n - dzien_poczatku_n;
			break;
		case 1:
			ilosc_dni = 30 - dzien_poczatku_n + dzien_konca_n; // na zmiane dodaje 30/31 zeby bylo jakby miesiac sie zmienial a dni sie zgadzaly
			break;
		case 2:
			ilosc_dni = 61 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 3:
			ilosc_dni = 91 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 4:
			ilosc_dni = 122 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 5:
			ilosc_dni = 152 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 6:
			ilosc_dni = 183 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 7:
			ilosc_dni = 213 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 8:
			ilosc_dni = 244 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 9:
			ilosc_dni = 247 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 10:
			ilosc_dni = 278 - dzien_poczatku_n + dzien_konca_n;
			break;
		case 11:
			ilosc_dni = 308 - dzien_poczatku_n + dzien_konca_n; // jak ja to wykombinowalem to do teraz nie wiem xDDD
			break;
		}
	}
	//ilosc_dni = dzien_konca_n - dzien_poczatku_n; //jeszcze musze zrobic ify o to ze jak przechodzi z miesiaca na miesiac to ilosc dni + 30/31 zaleznie od miesiaca UPDATE jest na górze xD
	
	rachunek_do_zaplacenia = ilosc_dni * cena_za_noc;
	cout << "Rachunek wynosi: " << rachunek_do_zaplacenia << "zl. " << endl;
}

void user::rejestracja()
{
	
	cout << "----Rejestracja----\nLogin:";
	cin >> login;
	cout << "Haslo: " <<endl;
	cin >> haslo;
	cout << "Imiê : " << endl;
	cin >> imie;
	cout << "Nazwisko: " << endl;
	cin >> nazwisko;
	cout << "Numer telefonu: " << endl;
	cin >> nr_tel;

}
void user::logowanie()
{
	cout << "----Logowanie----\nLogin: ";
	cin >> login;
	//warunki
	cout << "Haslo: " << endl;
	cin >> haslo;
	//warunki
}

