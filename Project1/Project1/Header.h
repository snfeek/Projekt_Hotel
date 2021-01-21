#pragma once
#include <string>
#include <iostream>
using namespace std;



class Hotel {
public:
	string nazwa = "Sasin";
	string adres = "milionow 70";
	string www = "www.MorawieckiTyChujuZdradziecki.pl";
	int liczba_pokoi[10];
	int liczba_gosci;
	int liczba_pracownikow; // liczba pracowników (42 pracownikow)
};

class Recepcja {
	int nr_tel = 648842167;
};

class Pokoj {
public:
	string rodzaj_lozek;
	int numer_pokoju=1;
	int pietro=1;
	int liczba_lozek =1;	
	int standard = 0;
	int cena_za_noc=100;
	int dzien_konca_r =2, miesiac_konca_r=1, rok_konca_r=2021, dzien_poczatku_r=1, miesiac_poczatku_r=1, rok_poczatku_r=2021; // dzien konca n -dzien konca nowej rezerwacji itd
	int dzien_konca_n, miesiac_konca_n, rok_konca_n, dzien_poczatku_n, miesiac_poczatku_n, rok_poczatku_n; // dzien poczatku r - dzien poczatku starej rezerwacji
	bool czy_zarezerowany = false;
	void rezerwowanie();
	void rezerwacja();
	void rachunek();
	void pokaz_dane();
public:

	//Pokoj() {}
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

void Pokoj::pokaz_dane()
{
	cout << "numer pokoju: " << numer_pokoju << ", pietro: " << pietro << ", liczba lozek: " << liczba_lozek << ", rodzaj lozek: " << rodzaj_lozek << ", cena za noc: " << cena_za_noc << endl << endl;
	
}

void Pokoj::rezerwacja()
{

	rok_konca_r = rok_konca_n;
	rok_poczatku_r = rok_poczatku_n;
	dzien_poczatku_r = dzien_poczatku_n; 
	dzien_konca_r = dzien_konca_n;
	miesiac_konca_r = miesiac_konca_n;
	miesiac_poczatku_r = miesiac_poczatku_n;
	czy_zarezerowany = true; //tudaj daje true bo to czy_zarezerwowany to w kontekscie tego czy TERAZ zarezerwowany, myœlê ¿e tak jest ok
	cout << "\n\t\t\t\tUdalo sie zarezerwowac pokoj!" << endl;
}

void Pokoj::rezerwowanie() {

	cout << "\n\t\t\t\tPodaj dzien, miesiac, rok twojego planowanego zameldowania." << endl << endl;				//wpisywanie dat rozpoczecia i zakonczenia pobytu
	cout << "Dzien: ";
	cin >> dzien_poczatku_n;
	if (dzien_poczatku_n > 31)					//ograniczenia przed niepoprawnymi danymi
	{
		while (dzien_poczatku_n > 31)
		{
			cout << "\n\t\t\t\tzaden miesiac nie ma tyle dni! wpisz ponownie." << endl;
			cout << "Dzien: ";
			cin >> dzien_poczatku_n;
			
		}
	}else
	
	
	cout << "Miesiac: ";
	cin >> miesiac_poczatku_n;
	if (miesiac_poczatku_n > 12)
	{
		while (miesiac_poczatku_n > 12)
		{
			cout << "\n\t\t\t\tZaden rok nie ma tylu miesiecy! wpisz ponownie." << endl;
			cin >> miesiac_poczatku_n;
			

		}
	} 
	
	else if (dzien_poczatku_n > 29 && miesiac_poczatku_n == 2)				//ograniczenia ciag dalszy
	{
		while (dzien_poczatku_n <= 29)
		
			{
				cout << "\n\t\t\t\tluty nie ma az tyle dni, wpisz ponownie" << endl;
				cout << "Dzien: ";
				cin >> dzien_poczatku_n;
				
				cout << "Miesiac: ";
				cin >> miesiac_poczatku_n;
				
			}
		
	}else
	


	cout << "Rok: ";
	cin >> rok_poczatku_n;
	if (rok_poczatku_n < 2021)
	{
		while (rok_poczatku_n < 2021)
		{
			cout << "Jezeli masz maszyne czasu to spoko, ale jak nie to wpisz prosze date przyszla :)" << endl;
			cin >> rok_poczatku_n;
			
		}
	}else
	cout << endl << endl;
	


	cout << "\n\t\t\t\tTeraz podaj dzien, miesiac i rok twojego wymeldowania" << endl;
	cin >> dzien_konca_n;
	if (dzien_konca_n > 31)
	{
		while (dzien_konca_n> 31)
		{
			cout << "\n\t\t\t\tzaden miesiac nie ma tyle dni! wpisz ponownie." << endl;
			cout << "Dzien: ";
			cin >> dzien_konca_n;
		}
	}
	else

	cout << "Miesiac: ";
	cin >> miesiac_konca_n;
	if (miesiac_konca_n > 12)
	{
		while (miesiac_konca_n > 12)
		{
			cout << "\n\t\t\t\tZaden rok nie ma tylu miesiecy! wpisz ponownie." << endl;
			cin >> miesiac_konca_n;

		}
	}
	else
	if (dzien_konca_n > 29 && miesiac_konca_n == 2)
	{
		while (dzien_konca_n <= 29)

		{
			cout << "\n\t\t\t\tluty nie ma az tyle dni, wpisz ponownie" << endl;
			cout << "Dzien: ";
			cin >> dzien_konca_n;
			cout << "Miesiac: ";
			cin >> miesiac_konca_n;
		}

	}
	else


		cout << "Rok: ";
	cin >> rok_konca_n;
	if (rok_konca_n < 2021)
	{
		while (rok_konca_n < 2021)
		{
			cout << "Jezeli masz maszyne czasu to spoko, ale jak nie to wpisz prosze date przyszla :)" << endl;
			cin >> rok_konca_n;
		}
	}
	else
		cout << endl << endl;


	if (rok_poczatku_n == rok_konca_n == rok_konca_r == rok_poczatku_r)				//caly sens istnienia tych warunków to sprawdzanie czy rezerwacja nie pokrywa siê z poprzedni¹, aby nie mo¿na by³o zarezerwowaæ pokoju na dni, w których ktoœ tam ju¿ bêdzie
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
				cout << "\n\t\t\t\tPokoj jest wtedy zarezerwowany!" << endl;
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
				cout << "\n\t\t\t\tPokoj jest wtedy zarezerwowany!" << endl;
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
				cout << "\n\t\t\t\tPokoj jest wtedy zarezerwowany!" << endl;
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
				cout << "\n\t\t\t\tPokoj jest wtedy zarezerwowany!" << endl;
			}
		}
		else
		{
			cout << "\n\t\t\t\tPokoj jest wtedy zarezerwowany!" << endl;
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
				cout << "\n\t\t\t\tPokoj jest wtedy zarezerwowany!" << endl;
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
	int ilosc_dni = 0;




	switch (miesiac_konca_n - miesiac_poczatku_n)  //niezbêdne do obliczenia prawid³owej liczby dni podczas gdy rezerwacja nie odbywa siê tylko w ,,ramkach" jednego miesi¹ca
	{
	case 0:
		ilosc_dni = dzien_konca_n - dzien_poczatku_n;
		break;
	case 1:
		ilosc_dni = 30 - dzien_poczatku_n + dzien_konca_n; // na zmiane dodaje 30/31 zeby miesiac sie zmienial a dni sie zgadzaly
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
		ilosc_dni = 308 - dzien_poczatku_n + dzien_konca_n; 
		break;
	}



	rachunek_do_zaplacenia = ilosc_dni * cena_za_noc;
	cout << "\n\t\t\t\tRachunek wynosi: " << rachunek_do_zaplacenia << "zl. " << endl;
}


void user::rejestracja()
{

	cout << "----Rejestracja----\nLogin:";
	cin >> login;
	cout << "Haslo: " << endl;
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




