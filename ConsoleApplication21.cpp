#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;


class History {
protected:
	int YearOfStart;
	int YearOfEnd;
public:
	History() {
		YearOfStart = 0;
		YearOfEnd = 0;
	};
	History(int w, int w1) {
		YearOfStart = w;
		YearOfEnd = w1;
	}
	void showDataYears() {
		cout << " Год начала войны: " << YearOfStart << endl;
		cout << " Год окончания войны: " << YearOfEnd << endl;
	}
	void changeYaerOfStrat(int ptr) {
		YearOfStart = ptr;
	}
	void changeYearOfEnd(int ptr) {
		YearOfEnd = ptr;
	}
	int getYearOfStart() {
		return YearOfStart;
	}
	int getYearOfEnd() {
		return YearOfEnd;
	}
};

class WorldHistory :virtual public History {
protected:
	string WhoAttack;
	string WhoDefense;
public:
	WorldHistory(string ptr1, string ptr2, int w, int w1) :History(w, w1) {
		WhoAttack = ptr1;
		WhoDefense = ptr2;
	}
	WorldHistory() {
		
	};
	void showDataWorld() {
		cout << " Агрессор: " << WhoAttack << endl;
		cout << " Напали на: " << WhoDefense << endl;
		History::showDataYears();
	}
	void changeWhoAtack(string ptr) {
		WhoAttack = ptr;
	}
	void changeWhoDefense(string ptr) {
		WhoDefense = ptr;
	}
	string getWhoAttack() {
		return WhoAttack;
	}
	string getWhoDefense() {
		return WhoDefense;
	}
};

class CountryHistory :virtual public History {
protected:
	int YearOfStartInThisCountry;
	int YearOfEndInThisCountry;
public:
	CountryHistory() {
		YearOfStartInThisCountry = 0;
		YearOfEndInThisCountry = 0;
	};
	CountryHistory(int ptr1, int ptr2, int w, int w1) :History(w, w1) {
		YearOfStartInThisCountry = ptr1;
		YearOfEndInThisCountry = ptr2;
	}
	void showDataCountry() {
		cout << " Год начала войны в стране: " << YearOfStartInThisCountry << endl;
		cout << " Напали на город в стране: " << YearOfEndInThisCountry << endl;
	}
	void changeYearOfStartInThisCountry(int ptr) {
		YearOfStartInThisCountry = ptr;
	}
	void changeYearOfEndInThisCountry(int ptr) {
		YearOfEndInThisCountry = ptr;
	}
	int getYearOfStartInThisCountry() {
		return YearOfStartInThisCountry;
	}
	int getYearOfEndInThisCountry() {
		return YearOfEndInThisCountry;
	}
};

class Country :public WorldHistory, public CountryHistory {
private:
	string President;
	string AttacedTown;
	string country;
public:
	Country() {};
	Country(string c, string p, string p1, int ptr1, int ptr2, string ptr3, string ptr4, int w1, int w2) :CountryHistory(ptr1, ptr2, w1, w2), WorldHistory(ptr3, ptr4, w1, w2), History(w1, w2) {
		President = p;
		AttacedTown = p1;
		country = c;
	}
	void showData() {
		cout << "	Страна: " << country << endl;
		WorldHistory::showDataWorld();
		CountryHistory::showDataCountry();
		cout << " Президент страны: " << President << endl;
		cout << " Город на который напали: " << AttacedTown << endl;
	}
	void changPresident(string ptr) {
		President = ptr;
	}
	void changeAttacedTown(string ptr) {
		AttacedTown = ptr;
	}
	void changeCountry(string ptr) {
		country = ptr;
	}
	string getPresident() {
		return President;
	}
	string getAttacedTown() {
		return AttacedTown;
	}
	string getcountry() {
		return country;
	}
};

int chooseMenu();
string writeWords();
int writeNumbers();
int chooseWhoRed(Country*&, int);
int chooseWhatRed(Country*&, int);

int main() {
	setlocale(0, "rus");
	int nCountrys = 0;
	Country* countrys = new Country[nCountrys];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nCountrys != 0) {
				while (true) {
					int choose1 = chooseWhoRed(countrys, nCountrys);
					if (choose1 == nCountrys) break;
					while (true) {
						int choose2 = chooseWhatRed(countrys, choose1);
						if (choose2 == 8) break;
						if (choose2 == 0) {
							cout << "Введите год начала войны: ";
							int ptr = writeNumbers();
							countrys[choose1].changeYaerOfStrat(ptr);
							system("cls");
						}else
							if (choose2 == 1) {
								cout << "Введите год окончания войны: ";
								int ptr = writeNumbers();
								countrys[choose1].changeYearOfEnd(ptr);
								system("cls");
							}else
								if (choose2 == 2) {
									cout << "Введите страну агрессора: ";
									string ptr = writeWords();
									countrys[choose1].changeWhoAtack(ptr);
									system("cls");
								}else
									if (choose2 == 3) {
										cout << "Введите страну на которую напали: ";
										string ptr = writeWords();
										countrys[choose1].changeWhoDefense(ptr);
										system("cls");
									}else
										if (choose2 == 4) {
											cout << "Введите год начала войны в стране: ";
											int ptr = writeNumbers();
											countrys[choose1].changeYearOfStartInThisCountry(ptr);
											system("cls");
										}else
											if (choose2 == 5) {
												cout << "Введите год окончания войны в стране: ";
												int ptr = writeNumbers();
												countrys[choose1].changeYearOfEndInThisCountry(ptr);
												system("cls");
											}else
												if (choose2 == 6) {
													cout << "Введите Президента: ";
													string ptr = writeWords();
													countrys[choose1].changPresident(ptr);
													system("cls");
												}else
													if (choose2 == 7) {
														cout << "Введите город на который напали: ";
														string ptr = writeWords();
														countrys[choose1].changeAttacedTown(ptr);
														system("cls");
													}
					}
				}
			}
			else {
				cout << "Вы еще не добавили историй" << endl;
				system("pause");
				system("cls");
			}
		}else
			if (choose == 0) {
				Country sum;
				cout << "Введите Страну: ";
				string ptr1 = writeWords();
				sum.changeCountry(ptr1);
				system("cls");
				cout << "Введите год начала войны: ";
				int ptr = writeNumbers();
				sum.changeYaerOfStrat(ptr);
				system("cls");
				cout << "Введите год окончания войны: ";
				ptr = writeNumbers();
				sum.changeYearOfEnd(ptr);
				system("cls");
				cout << "Введите страну агрессора: ";
				ptr1 = writeWords();
				sum.changeWhoAtack(ptr1);
				system("cls");
				cout << "Введите страну на которую напали: ";
				ptr1 = writeWords();
				sum.changeWhoDefense(ptr1);
				system("cls");
				cout << "Введите год начала войны в стране: ";
				ptr = writeNumbers();
				sum.changeYearOfStartInThisCountry(ptr);
				system("cls");
				cout << "Введите год окончания войны в стране: ";
				ptr = writeNumbers();
				sum.changeYearOfEndInThisCountry(ptr);
				system("cls");
				cout << "Введите Президента: ";
				ptr1 = writeWords();
				sum.changPresident(ptr1);
				system("cls");
				cout << "Введите город на который напали: ";
				ptr1 = writeWords();
				sum.changeAttacedTown(ptr1);
				system("cls");
				nCountrys++;
				Country* ptrr = new Country[nCountrys];
				for (int i = 0; i < nCountrys - 1; i++)
					ptrr[i] = countrys[i];
				countrys = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				countrys[nCountrys - 1] = sum;
			}else
				if (choose == 2) {
					for (int i = 0; i < nCountrys; i++) {
						countrys[i].showData();
						cout << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Добавить историю войны в стране" << endl; }
		else { cout << " Добавить историю войны в стране" << endl; }

		if (choose_menu == 1) { cout << " -> Редактировать истории" << endl; }
		else { cout << " Редактировать истории" << endl; }

		if (choose_menu == 2) { cout << " -> Просмотр всех историй" << endl; }
		else { cout << " Просмотр всех историй" << endl; }

		if (choose_menu == 3) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhoRed(Country*& countrys, int nCountrys) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nCountrys + 1)) % (nCountrys + 1);

		for (int i = 0; i < nCountrys; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << countrys[i].getcountry() << endl; }
			else { cout << " " << i + 1 << " - " << countrys[i].getcountry() << endl; }

		if (choose_menu == nCountrys) { cout << " -> Выйти с выбора страны" << endl; }
		else cout << " Выйти с выбора страны" << endl;

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhatRed(Country*& countrys, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 9) % 9;

		if (choose_menu == 0) { cout << " -> Год начала войны: " << countrys[choose].getYearOfStart() << endl; }
		else cout << " Год начала войны: " << countrys[choose].getYearOfStart() << endl;

		if (choose_menu == 1) { cout << " -> Год окончания войны: " << countrys[choose].getYearOfEnd() << endl; }
		else cout << " Год окончания войны: " << countrys[choose].getYearOfEnd() << endl;

		if (choose_menu == 2) { cout << " -> Агрессор: " << countrys[choose].getWhoAttack() << endl; }
		else cout << " Агрессор: " << countrys[choose].getWhoAttack() << endl;
		
		if (choose_menu == 3) { cout << " -> Напали на: " << countrys[choose].getWhoDefense() << endl; }
		else cout << " Напали на: " << countrys[choose].getWhoDefense() << endl;

		if (choose_menu == 4) { cout << " -> Год начала войны в стране: " << countrys[choose].getYearOfStartInThisCountry() << endl; }
		else cout << " Год начала войны в стране: " << countrys[choose].getYearOfStartInThisCountry() << endl;

		if (choose_menu == 5) { cout << " -> Год окончания войны в стране: " << countrys[choose].getYearOfEndInThisCountry() << endl; }
		else cout << " Год окончания войны в стране: " << countrys[choose].getYearOfEndInThisCountry() << endl;

		if (choose_menu == 6) { cout << " -> Президент: " << countrys[choose].getPresident() << endl; }
		else cout << " Президент: " << countrys[choose].getPresident() << endl;

		if (choose_menu == 7) { cout << " -> Напали на город: " << countrys[choose].getAttacedTown() << endl; }
		else cout << " Напали на город: " << countrys[choose].getAttacedTown() << endl;

		if (choose_menu == 8) { cout << " -> Выйти в меню выбора страны " << endl; }
		else cout << " Выйти в меню выбора страны " << endl;


		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}
