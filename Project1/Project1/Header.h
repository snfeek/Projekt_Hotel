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
	int dzien_konca_r, miesiac_konca_r, rok_konca_r, dzien_poczatku_r, miesiac_poczatku_r, rok_poczatku_r;
	int dzien_konca_n, miesiac_konca_n, rok_konca_n, dzien_poczatku_n, miesiac_poczatku_n, rok_poczatku_n;
	bool czy_zarezerowany;
	void rezerwowanie();
	void rezerwacja();
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
	dzien_poczatku_r = dzien_poczatku_n;
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

