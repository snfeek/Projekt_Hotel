#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
	user uzytkownik;
	//MENU
	int i = 0;
	for (;;)
	{
		i++;
		int wybor;
		cout << "1. Login\n2. Rejestracja\n0.Zamknij\n\nWybor:  ";
		cin >> wybor;
		cin.clear();
		cin.ignore();
		switch (wybor)
		{
		case 1://logowanie
		{
			string login, haslo;
			do {
				cout << uzytkownik.login;
				cout << uzytkownik.haslo;
				cout << "----Logowanie----\nLogin: ";
				cin >> login;
				cout << "Haslo: ";
				cin >> haslo;
			} while (login != uzytkownik.login||haslo != uzytkownik.haslo);
			for (int i = 3; i > 0; i--) {
				system("CLS");
				cout << "Pomyslnie zalogowano, przejscie do serwisu..." << i;
				Sleep(1000);
			}
			system("CLS");
			for (;;)
			{
				
				cout << "(1)----Wynajmnij----(1)\n(2)----Zarzadzanie rezerwacjami/pokojami----(2)\n(0)----Wyloguj----(0)\n";
				cin >> wybor;
				switch (wybor)
				{
				case 1:
				{
					int dzien, miesiac, rok;
					system("CLS");
					
					do {
						cout << "----Podaj date----\nDzien (1-31);";
						cin >> dzien;
						cout << "Miesiac (1-12): ";
						cin >> miesiac;
						cout << "Rok (2020-2024): ";
						if (dzien > 31 || dzien < 1 || miesiac>12 || miesiac < 1 || rok < 2020 || rok>2024)
						{
							cout << "Blad w wczytaniu daty...\nSprobuj jeszcze raz";
						}
						Sleep(1000);
					} while (dzien > 31 || dzien < 1 || miesiac>12 || miesiac < 1 || rok < 2020 || rok>2024);
					//pomysl na czas??
					break;
				}
				case 2:
				{
					break;
				}
				case 0:
				{
					break;
				}
				default:
				{
					break;
				}
				}
			}
			//tutaj odpala sie menu po zalogowaniu czyli wynajem, zarzadzanie rezerwacja itd
			break;
		}
		case 2://rejestracja
		{
			
			uzytkownik.rejestracja();
			system("CLS");
			break;
		}
		case 0://wyjscie z programu
		{
		
			break;
		}
		default:
		{
			cout << "Break";
			break;
		}
		}
		if (wybor == 0)
		{
			break;
		}
		
	}
	
	system("pause");
	return 0;
}