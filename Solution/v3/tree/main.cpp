#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <clocale>
#include <ctime>
#include "Tree.h"

using std::cin;

Tree tree;
char hsTab[2] = { '<',' ' };
char menuTab[7] = { '<',' ',' ',' ',' ',' ',' ' };
char relTab[13] = { '<',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };

void startScreen()
{
	cout << "Stworz drzewo  " << hsTab[0] << endl;
	cout << "Wczytaj drzewo " << hsTab[1] << endl;
}

void printMenu()
{
	cout << "Dodaj czlonka rodziny     " << menuTab[0] << endl;
	cout << "Wyszukaj czlonka rodziny  " << menuTab[1] << endl;
	cout << "Edytuj czlonka rodziny    " << menuTab[2] << endl;
	cout << "Powiaz osoby              " << menuTab[3] << endl;
	cout << "Usun czlonka rodziny      " << menuTab[4] << endl;
	cout << "Wyswietl drzewo           " << menuTab[5] << endl;
	cout << "Zapisz drzewo do pliku    " << menuTab[6] << endl;
	cout << endl << "ESC aby wyjsc";
}

void formUser()
{
	string imie, nazwisko, data;
	string rodowe = " ";
	bool gender;
	char rod, plec;
	cout << "Wprowadz imie: ";
	cin >> imie;
	cout << "Wprowadz nazwisko: ";
	cin >> nazwisko;
	cout << "Czy Twoje nazwisko rodowe jest inne niz obecne? (t/n): ";
	cin >> rod;
	if (rod == 't') {
		cout << "Wprowadz nazwisko rodowe: ";
		cin >> rodowe;
	}
	bool ok;
	do{
        time_t czas;
        tm* aktualnyCzas;

        time(&czas);
        aktualnyCzas = localtime(&czas);

        cout << "Wprowadz date urodzenia (DD-MM-RRRR): ";
        cin >> data;
        Date d(data);

        if(aktualnyCzas->tm_year+1900 < d.getYear() || d.getYear() == 0){
            ok=false;
        }
        else if(aktualnyCzas->tm_year+1900==d.getYear()){
            if (aktualnyCzas->tm_mon+1 < d.getMonth() || d.getMonth() == 0){
                ok = false;
            }
            else if(aktualnyCzas->tm_mon+1 == d.getMonth()){
                if (aktualnyCzas->tm_mday < d.getDay() || d.getDay() == 0 ){
                    ok = false;
            }
                else{
                    ok=true;
                }
            }
            else{
                ok = true;
            }
        }
        else{
            ok = true;
        }

        if(d.getMonth()>12 || d.getDay()>31){
            ok=false;
        }

        if ((d.getMonth()==1 && d.getDay()>31)||(d.getMonth()==2 && d.getDay()>29)||(d.getMonth()==3 && d.getDay()>31)
            ||(d.getMonth()==4 && d.getDay()>30)||(d.getMonth()==5 && d.getDay()>31)||(d.getMonth()==6 && d.getDay()>30)
            ||(d.getMonth()==7 && d.getDay()>31)||(d.getMonth()==8 && d.getDay()>31)||(d.getMonth()==9 && d.getDay()>30)
            ||(d.getMonth()==10 && d.getDay()>31)||(d.getMonth()==11 && d.getDay()>30)||(d.getMonth()==12 && d.getDay()>31))
            ok=false;

        if(!ok){
            system("cls");
            cout<<"Blad! Sprobuj ponownie"<<endl;
        }

	}while(!ok);

	cout << "Wprowadz plec (k/m): ";
	cin >> plec;

	if (plec == 'k')
		gender = 0;
	else gender = 1;

	tree.addUser(Person(imie, nazwisko, rodowe, Date(data),Date("00-00-0000"), gender));
}

void form(int rel, bool gender)
{
	string imie, nazwisko, data;
	string rodowe = " ";
	char rod;
	cout << "Wprowadz imie: ";
	cin >> imie;
	cout << "Wprowadz nazwisko: ";
	cin >> nazwisko;
	cout << "Czy nazwisko rodowe jest inne niz obecne? (t/n): ";
	cin >> rod;
	if (rod == 't') {
		cout << "Wprowadz nazwisko rodowe: ";
		cin >> rodowe;
	}
	bool ok;
	do{
        time_t czas;
        tm* aktualnyCzas;

        time(&czas);
        aktualnyCzas = localtime(&czas);

        cout << "Wprowadz date urodzenia (DD-MM-RRRR): ";
        cin >> data;
        Date d(data);

        if(aktualnyCzas->tm_year+1900 < d.getYear() || d.getYear() == 0){
            ok=false;
        }
        else if(aktualnyCzas->tm_year+1900==d.getYear()){
            if (aktualnyCzas->tm_mon+1 < d.getMonth() || d.getMonth() == 0){
                ok = false;
            }
            else if(aktualnyCzas->tm_mon+1 == d.getMonth()){
                if (aktualnyCzas->tm_mday < d.getDay() || d.getDay() == 0 ){
                    ok = false;
            }
                else{
                    ok=true;
                }
            }
            else{
                ok = true;
            }
        }
        else{
            ok = true;
        }

        if(d.getMonth()>12 || d.getDay()>31){
            ok=false;
        }

        if ((d.getMonth()==1 && d.getDay()>31)||(d.getMonth()==2 && d.getDay()>29)||(d.getMonth()==3 && d.getDay()>31)
            ||(d.getMonth()==4 && d.getDay()>30)||(d.getMonth()==5 && d.getDay()>31)||(d.getMonth()==6 && d.getDay()>30)
            ||(d.getMonth()==7 && d.getDay()>31)||(d.getMonth()==8 && d.getDay()>31)||(d.getMonth()==9 && d.getDay()>30)
            ||(d.getMonth()==10 && d.getDay()>31)||(d.getMonth()==11 && d.getDay()>30)||(d.getMonth()==12 && d.getDay()>31))
            ok=false;

        if(!ok){
            system("cls");
            cout<<"Blad! Sprobuj ponownie"<<endl;
        }

	}while(!ok);
	tree.addPerson(Person(imie,nazwisko,rodowe,Date(data), Date("00-00-0000"),gender), rel);
}

void otherForm(int map, string rel)
{
	string imie, nazwisko, data;
	string rodowe = " ";
	char rod, plec;
	bool gender;
	cout << "Wprowadz imie: ";
	cin >> imie;
	cout << "Wprowadz nazwisko: ";
	cin >> nazwisko;
	cout << "Czy nazwisko rodowe jest inne niz obecne? (t/n): ";
	cin >> rod;
	if (rod == 't') {
		cout << "Wprowadz nazwisko rodowe: ";
		cin >> rodowe;
	}
	bool ok;
	do{
        time_t czas;
        tm* aktualnyCzas;

        time(&czas);
        aktualnyCzas = localtime(&czas);

        cout << "Wprowadz date urodzenia (DD-MM-RRRR): ";
        cin >> data;
        Date d(data);

        if(aktualnyCzas->tm_year+1900 < d.getYear() || d.getYear() == 0){
            ok=false;
        }
        else if(aktualnyCzas->tm_year+1900==d.getYear()){
            if (aktualnyCzas->tm_mon+1 < d.getMonth() || d.getMonth() == 0){
                ok = false;
            }
            else if(aktualnyCzas->tm_mon+1 == d.getMonth()){
                if (aktualnyCzas->tm_mday < d.getDay() || d.getDay() == 0 ){
                    ok = false;
            }
                else{
                    ok=true;
                }
            }
            else{
                ok = true;
            }
        }
        else{
            ok = true;
        }

        if(d.getMonth()>12 || d.getDay()>31){
            ok=false;
        }

        if ((d.getMonth()==1 && d.getDay()>31)||(d.getMonth()==2 && d.getDay()>29)||(d.getMonth()==3 && d.getDay()>31)
            ||(d.getMonth()==4 && d.getDay()>30)||(d.getMonth()==5 && d.getDay()>31)||(d.getMonth()==6 && d.getDay()>30)
            ||(d.getMonth()==7 && d.getDay()>31)||(d.getMonth()==8 && d.getDay()>31)||(d.getMonth()==9 && d.getDay()>30)
            ||(d.getMonth()==10 && d.getDay()>31)||(d.getMonth()==11 && d.getDay()>30)||(d.getMonth()==12 && d.getDay()>31))
            ok=false;

        if(!ok){
            system("cls");
            cout<<"Blad! Sprobuj ponownie"<<endl;
        }

	}while(!ok);
	cout << "Wprowadz plec (k/m): ";
	cin >> plec;

	if (plec == 'k')
		gender = 0;
	else gender = 1;

	tree.addPerson(Person(imie, nazwisko, rodowe, Date(data), Date("00-00-0000"), gender, rel), map);
}

void relation()
{
	cout << "matka   " << relTab[0] << endl;
	cout << "ojciec  " << relTab[1] << endl;
	cout << "siostra " << relTab[2] << endl;
	cout << "brat    " << relTab[3] << endl;
	cout << "zona    " << relTab[4] << endl;
	cout << "maz     " << relTab[5] << endl;
	cout << "corka   " << relTab[6] << endl;
	cout << "syn     " << relTab[7] << endl;
	cout << "babcia  " << relTab[8] << endl;
	cout << "dziadek " << relTab[9] << endl;
	cout << "wnuczka " << relTab[10] << endl;
	cout << "wnuk    " << relTab[11] << endl;
	cout << "inny    " << relTab[12] << endl;
}


void moveDown(char tab[], int i)
{
	tab[i] = ' ';
	tab[i + 1] = '<';
}

void moveUP(char tab[], int i)
{
	tab[i] = ' ';
	tab[i - 1] = '<';
}

void menu(int &i, char &x)
{
	system("cls");
	i = 0;
	printMenu();
	do {
		x = _getch();
		switch (x) {
		case 72: //up
			if (i > 0) {
				moveUP(menuTab, i);
				system("cls");
				printMenu();
				i--;
			}
			break;
		case 80: //down
			if (i < 6) {
				moveDown(menuTab, i);
				system("cls");
				printMenu();
				i++;
			}
			break;
		case 13: //enter
			if (i == 0) { //dodaj czlonka rodziny
				system("cls");
				i = 0;
				relation();
				do {
					x = _getch();
					switch (x) {
					case 72: //up
						if (i > 0) {
							moveUP(relTab, i);
							system("cls");
							relation();
							i--;
						}
						break;
					case 80: //down
						if (i < 12) {
							moveDown(relTab, i);
							system("cls");
							relation();
							i++;
						}
						break;
					case 13: //enter
						if (i == 0) {		//matka
							system("cls");
							form(-1, 0);
						}
						if (i == 1) {		//ojciec
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(-1, 1);
						}
						if (i == 2) {		//siostra
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(3, 0);
						}
						if (i == 3) {		//brat
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(3, 1);
						}
						if (i == 4) {		//zona
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(1, 0);
						}
						if (i == 5) {		//maz
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(1, 1);
						}
						if (i == 6) {		//corka
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(2, 0);
						}
						if (i == 7) {		//syn
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(2, 1);
						}
						if (i == 8) {		//babcia
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(-2, 0);
						}
						if (i == 9) {		//dziadek
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(-2, 1);
						}
						if (i == 10) {		//wnuczka
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(4, 0);
						}
						if (i == 11) {		//wnuk
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(4, 1);
						}
						if (i == 12) {		//inny
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							cout << "Dla kogo z Twojej rodziny ta osoba jest w blizszej relacji?" << endl;
							string firstName, lastName;
							cout << "Podaj imie: ";
							cin >> firstName;
							cout << "Podaj nazwisko: ";
							cin >> lastName;
							system("cls");
							Pointer seek = tree.findMember(firstName, lastName);
							if (seek.map == 404)
								cout << "Nie znaleziono" << endl;
							else {
								cout << endl << "Kim ta osoba jest dla Ciebie?: ";
								string rel;
								cin >> rel;
								system("cls");
								otherForm(seek.map, rel);
							}
						}
						system("cls");
						i = 0;
						x = 25;
						break;
					default:
						break;
					}
				} while (x != 25);
				system("cls");
				printMenu();
			}
			if (i == 1) {								//wyszukaj czlonka rodziny
				system("cls");
				string firstName, lastName;
				cout << "Podaj imie: ";
				cin >> firstName;
				cout << "Podaj nazwisko: ";
				cin >> lastName;
				system("cls");
				if (tree.findMember(firstName, lastName).map == 404)
					cout << "Nie znaleziono" << endl;
				else {
					tree.memberTree(tree.findMember(firstName, lastName));
				}
				cout << endl << "Strzalka w gore aby wrocic";
			}
			if (i == 2) {								//edytuj czlonka rodziny
				system("cls");
				string firstName, lastName;
				cout << "Podaj imie: ";
				cin >> firstName;
				cout << "Podaj nazwisko: ";
				cin >> lastName;
				system("cls");
				Pointer seek = tree.findMember(firstName, lastName);
				if (seek.map == 404)
					cout << "Nie znaleziono" << endl;
				else {
					cout << endl << "Czy na pewno chcesz edytowac tego czlonka rodziny? (t/n) ";
					char dec;
					cin >> dec;
					if (dec == 't') {

						string imie, nazwisko, dataU, dataS;
						string rodowe = " ";
						bool gender;
						char dec, plec;
						cout << "Wprowadz imie: ";
						cin >> imie;
						cout << "Wprowadz nazwisko: ";
						cin >> nazwisko;
						cout << "Czy nazwisko rodowe jest inne niz obecne? (t/n): ";
						cin >> dec;
						if (dec == 't') {
							cout << "Wprowadz nazwisko rodowe: ";
							cin >> rodowe;
						}
						cout << "Wprowadz date urodzenia (DD-MM-RRRR): ";
						cin >> dataU;

						cout << "Czy osoba nadal zyje? (t/n): ";
						cin >> dec;
						if (dec == 'n') {
							cout << "Podaj date smierci (DD-MM-RRRR): ";
							cin >> dataS;
						}
						else
							dataS = "00-00-0000";

						cout << "Wprowadz plec (k/m): ";
						cin >> plec;

						if (plec == 'k')
							gender = 0;
						else gender = 1;


						tree.editRelative(seek,Person(imie, nazwisko, rodowe, Date(dataU), Date(dataS), gender));

					}
				}
				cout << endl << "Strzalka w gore aby wrocic";
			}
			if (i == 3) {								//powi¹¿ osoby
				system("cls");
				string firstName, lastName, firstName2;
				Pointer seek1, seek2;
				seek1.map = 404;
				seek2.map = 404;
				cout<<"Wyszukaj osobe (jesli to relacja rodzic-dziecko, wyszukaj dziecka)"<<endl;
				while (seek1.map == 404) {
					cout << "Podaj imie: ";
					cin >> firstName;
					cout << "Podaj nazwisko: ";
					cin >> lastName;
					system("cls");
					seek1 = tree.findMember(firstName, lastName);
					if (seek1.map == 404)
						cout << "Nie znaleziono, sprobuj ponownie" << endl;
				}
				cout << "Z kim chcesz powiazac " << firstName << "?" << endl;
				while (seek2.map == 404) {
					cout << "Podaj imie: ";
					cin >> firstName2;
					cout << "Podaj nazwisko: ";
					cin >> lastName;
					system("cls");
					seek2 = tree.findMember(firstName2, lastName);
					if (seek2.map == 404)
						cout << "Nie znaleziono, sprobuj ponownie" << endl;
				}
					bool ok = false;
					string rel;

					system("cls");
					cout << "Kim " << firstName2 << " jest dla " << firstName << "?" << endl;
					cout << "matka / ojciec / partner(ka)" << endl;

					while (!ok) {

						cin >> rel;
						if (rel == "partner" || rel == "partnerka") {
							tree.setRelative(seek1, seek2, 1);
							tree.setRelative(seek2, seek1, 1);
							ok = true;
							system("cls");
							cout << "Powiazano";
						}
						else if (rel == "matka") {
							tree.setRelative(seek1, seek2, 2);
							ok = true;
							system("cls");
							cout << "Powiazano";
						}
						else if (rel == "ojciec") {
							tree.setRelative(seek1, seek2, 3);
							ok = true;
							system("cls");
							cout << "Powiazano";
						}
						else {
							system("cls");
							cout << "Cos poszlo nie tak, sprobuj ponownie" << endl;
							cout << "Kim " << firstName << " jest dla " << firstName2 << "?" << endl;
							cout << "matka / ojciec / partner(ka)" << endl;
						}
					}
				cout << endl << "Strzalka w gore aby wrocic";

			}
			if (i == 4) {								//usun czlonka rodziny

				system("cls");
				string firstName, lastName;
				cout << "Podaj imie: ";
				cin >> firstName;
				cout << "Podaj nazwisko: ";
				cin >> lastName;
				system("cls");
				Pointer seek = tree.findMember(firstName, lastName);
				if (seek.map == 404)
					cout << "Nie znaleziono" << endl;
				else {
					cout << endl << "Czy na pewno chcesz usunac? (t/n) ";
					char dec;
					cin >> dec;
					if (dec == 't')
						tree.deleteReative(seek);
				}
				cout << endl << "Strzalka w gore aby wrocic";

			}
			if (i == 5) {//wyswietl drzewo
			system("cls");
			tree.printTree(tree.getTree());
			cout << endl << "Strzalka w gore aby wrocic";
			}

			if (i == 6) {//eksportuj drzewo
				system("cls");
				cout << "Podaj nazwe pliku: ";
				string filename;
				cin >> filename;
				tree.exportTree(filename);
				cout << "Drzewo wyeksportowano";
				cout << endl << "Strzalka w gore aby wrocic";
			}
			break;
		default:
			break;
		}
	} while (x != 27);
}

int main() {
	//setlocale(LC_ALL, "");
	//SetConsoleCP(1250); // input
	//SetConsoleOutputCP(1250); // output

	char x;
	int i = 0;

	startScreen();
	do {
		x = _getch();
		switch (x) {
		case 72: //up
			if (i > 0) {
				moveUP(hsTab, i);
				system("cls");
				startScreen();
				i--;
			}
			break;
		case 80: //down
			if (i < 1) {
				moveDown(hsTab, i);
				system("cls");
				startScreen();
				i++;
			}
			break;
		case 13: //enter
			if (i == 0) {//stworz drzewo
				system("cls");
				formUser();
				menu(i, x);
			}
			if (i == 1) {//wczytaj drzewo
				system("cls");
				string filename;
				cout << "Wprowadz nazwe pliku: ";
				cin >> filename;
				if (tree.importTree(filename))
					menu(i, x);
				else {
					system("cls");
					startScreen();

					cout << endl << "Blad wczytania pliku, sprobuj ponownie";
				}
			}
			break;
		default:
			break;
		}
	} while (x != 27);
	return 0;
}
