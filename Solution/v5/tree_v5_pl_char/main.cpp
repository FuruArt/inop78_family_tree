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
char relTab[14] = { '<',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };

string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string& rtrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string& trim(string& str, const string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

bool validate(string sDate)
{
    if (sDate.length() != 10)
    {
        return false;
    }
    if(sDate[2] != '-' || sDate[5] != '-')
    {
        return false;
    }

    Date date(sDate);

    if (date.getDay() > 31 || date.getMonth() > 12)
    {
        return false;
    }

    time_t czas;
    tm* aktualnyCzas;
    time(&czas);
    aktualnyCzas = localtime(&czas);

    if(aktualnyCzas->tm_year+1900 < date.getYear() || date.getYear() == 0)
    {
        return false;
    }
    else if(aktualnyCzas->tm_year+1900 == date.getYear())
    {
        if (aktualnyCzas->tm_mon+1 < date.getMonth() || date.getMonth() == 0)
        {
            return false;
        }
        else if(aktualnyCzas->tm_mon+1 == date.getMonth())
        {
            if (aktualnyCzas->tm_mday < date.getDay() || date.getDay() == 0 )
            {
                return false;
            }
        }
    }

     if ((date.getMonth()==1 && date.getDay()>31)||(date.getMonth()==2 && date.getDay()>29)||(date.getMonth()==3 && date.getDay()>31)
            ||(date.getMonth()==4 && date.getDay()>30)||(date.getMonth()==5 && date.getDay()>31)||(date.getMonth()==6 && date.getDay()>30)
            ||(date.getMonth()==7 && date.getDay()>31)||(date.getMonth()==8 && date.getDay()>31)||(date.getMonth()==9 && date.getDay()>30)
            ||(date.getMonth()==10 && date.getDay()>31)||(date.getMonth()==11 && date.getDay()>30)||(date.getMonth()==12 && date.getDay()>31))
    {
        return false;
    }

    return true;
}

void startScreen()
{
	cout << "Stw�rz drzewo  " << hsTab[0] << endl;
	cout << "Wczytaj drzewo " << hsTab[1] << endl;
}

void printMenu()
{
	cout << "Dodaj cz�onka rodziny         " << menuTab[0] << endl;
	cout << "Wyszukaj cz�onka rodziny      " << menuTab[1] << endl;
	cout << "Edytuj cz�onka rodziny        " << menuTab[2] << endl;
	cout << "Dodaj relacj� mi�dzy osobami  " << menuTab[3] << endl;
	cout << "Usu� cz�onka rodziny          " << menuTab[4] << endl;
	cout << "Wy�wietl drzewo               " << menuTab[5] << endl;
	cout << "Zapisz drzewo do pliku        " << menuTab[6] << endl;
	cout << endl << "ESC aby wyj�� | Liczba os�b w drzewie: ";
	cout << tree.membersCount();
}

Person formRelative(bool gender)
{
	string firstName, lastName, birthDate;
	string familyName = "n";
	string deathDate = "00-00-0000";
	char decision;
	cout << "Wprowad� imi�: ";
	cin >> firstName;
	cout << "Wprowad� nazwisko: ";
	cin >> lastName;
	cout << "Czy nazwisko rodowe jest inne ni� obecne? (t/n): ";
	cin >> decision;
	if (decision == 't') {
		cout << "Wprowad� nazwisko rodowe: ";
		cin >> familyName;
	}
    cout << "Wprowad� dat� urodzenia (DD-MM-RRRR): ";
    cin >> birthDate;
    while(validate(birthDate) == false)
    {
        system("cls");
        cout<<"B��d, spor�buj ponownie" << endl;
        cout << "Wprowad� dat� urodzenia (DD-MM-RRRR): ";
        cin >> birthDate;
    }
    cout << "Czy ta osoba nadal �yje? (t/n): ";
	cin >> decision;
	if (decision == 'n') {
		cout << "Wprowad� dat� �mierci (DD-MM-RRRR): ";
        cin >> deathDate;
        while(validate(deathDate) == false)
        {
            system("cls");
            cout<<"B��d, spor�buj ponownie" << endl;
            cout << "Wprowad� dat� �mierci (DD-MM-RRRR): ";
            cin >> deathDate;
        }
        while (deathDate<birthDate)
                {
                system("cls");
                cout<<"B��d, spr�buj ponownie" << endl;
                cout << "Wprowad� dat� �mierci (DD-MM-RRRR): ";
                cin >> deathDate;

            }

	}
	return Person(trim(firstName),trim(lastName),trim(familyName),Date(birthDate), Date(deathDate),gender);
}

Person form(string relationsip, bool user)
{
	string firstName, lastName, birthDate;
	string familyName = "n";
	string deathDate = "00-00-0000";
	bool gender;
	char decision;
	cout << "Wprowad� imi�: ";
	cin >> firstName;
	cout << "Wprowad� nazwisko: ";
	cin >> lastName;
	cout << "Czy nazwisko rodowe jest inne ni� obecne? (t/n): ";
	cin >> decision;
	if (decision == 't') {
		cout << "Wprowad� nazwisko rodowe: ";
		cin >> familyName;
	}
    cout << "Wprowad� dat� urodzenia (DD-MM-RRRR): ";
    cin >> birthDate;
    while(!(validate(birthDate)))
    {
        system("cls");
        cout<<"B��d, spr�buj ponownie" << endl;
        cout << "Wprowad� dat� urodzenia (DD-MM-RRRR): ";
        cin >> birthDate;
    }
    if(!user)
    {
        cout << "Czy ta osoba nadal �yje? (t/n): ";
        cin >> decision;
        if (decision == 'n') {
            cout << "Wprowad� dat� �mierci (DD-MM-RRRR): ";
            cin >> deathDate;
            while(!(validate(deathDate)))
            {
                system("cls");
                cout<<"B��d, spr�buj ponownie" << endl;
                cout << "Wprowad� dat� �mierci (DD-MM-RRRR): ";
                cin >> deathDate;
            }
            while (deathDate<birthDate)
                {
                system("cls");
                cout<<"B��d, spr�buj ponownie" << endl;
                cout << "Wprowad� dat� �mierci (DD-MM-RRRR): ";
                cin >> deathDate;

            }
        }
    }
    cout << "Wprowad� p�e� (k/m): ";
	cin >> decision;
	if (decision == 'k')
    {
        gender = false;
    }
    else
    {
        gender = true;
    }
	return Person (trim(firstName), trim(lastName), trim(familyName), Date(birthDate),Date(deathDate), gender, trim(relationsip));
}

void relation()
{
	cout << "matka   " << relTab[0] << endl;
	cout << "ojciec  " << relTab[1] << endl;
	cout << "siostra " << relTab[2] << endl;
	cout << "brat    " << relTab[3] << endl;
	cout << "�ona    " << relTab[4] << endl;
	cout << "m��     " << relTab[5] << endl;
	cout << "c�rka   " << relTab[6] << endl;
	cout << "syn     " << relTab[7] << endl;
	cout << "babcia  " << relTab[8] << endl;
	cout << "dziadek " << relTab[9] << endl;
	cout << "wnuczka " << relTab[10] << endl;
	cout << "wnuk    " << relTab[11] << endl;
	cout << "inny    " << relTab[12] << endl << endl;
	cout << "wr��    " << relTab[13] << endl;
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
	do
    {
		x = _getch();
		switch (x)
		{
		case 72: //up
			if (i > 0)
			{
				moveUP(menuTab, i);
				system("cls");
				printMenu();
				i--;
			}
			break;
		case 80: //down
			if (i < 6)
			{
				moveDown(menuTab, i);
				system("cls");
				printMenu();
				i++;
			}
			break;
		case 13: //enter
			if (i == 0)//dodaj czlonka rodziny
            {
				system("cls");
				i = 0;
				relation();
				do
				{
					x = _getch();
					switch (x)
					{
					case 72: //up
						if (i > 0)
						{
							moveUP(relTab, i);
							system("cls");
							relation();
							i--;
						}
						break;
					case 80: //down
						if (i < 13)
						{
							moveDown(relTab, i);
							system("cls");
							relation();
							i++;
						}
						break;
					case 13: //enter
						if (i == 0)//matka
						{
							system("cls");
							tree.addPerson(formRelative(0), -1);
							tree.exportTree("temp.txt");
						}
						if (i == 1)//ojciec
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(1), -1);
							tree.exportTree("temp.txt");
						}
						if (i == 2)//siostra
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(0), 3);
							tree.exportTree("temp.txt");
						}
						if (i == 3)//brat
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(1), 3);
							tree.exportTree("temp.txt");
						}
						if (i == 4)//zona
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(0), 1);
							tree.exportTree("temp.txt");
						}
						if (i == 5)//maz
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(1), 1);
							tree.exportTree("temp.txt");
						}
						if (i == 6)//corka
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(0), 2);
							tree.exportTree("temp.txt");
						}
						if (i == 7)//syn
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(1), 2);
							tree.exportTree("temp.txt");
						}
						if (i == 8)//babcia
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(0), -2);
							tree.exportTree("temp.txt");
						}
						if (i == 9)//dziadek
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(1), -2);
							tree.exportTree("temp.txt");
						}
						if (i == 10)//wnuczka
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(0), 4);
							tree.exportTree("temp.txt");
						}
						if (i == 11)//wnuk
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							tree.addPerson(formRelative(1), 4);
							tree.exportTree("temp.txt");
						}
						if (i == 12)//inny
						{
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							cout << "Dla kogo z Twojej rodziny ta osoba jest w bli�szej relacji?" << endl;
							string firstName, lastName;
							cout << "Podaj imi�: ";
							cin >> firstName;
							cout << "Podaj nazwisko: ";
							cin >> lastName;
							system("cls");
							Pointer seek = tree.findMember(firstName, lastName);
							if (seek._map == 404)
							{
							    cout << "Nie znaleziono" << endl;
							}

							else
                            {
                                cout << "Kim ta osoba jest dla Ciebie? (podaj w mianowinku) ";
								string rel;
								cin >> rel;
								system("cls");
								tree.addPerson(form(rel, false), seek._map);
								tree.exportTree("temp.txt");
							}
						}
						if (i == 13)//wroc
						{
                            relTab[i] = ' ';
							relTab[0] = '<';
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
			if (i == 1)//wyszukaj czlonka rodziny
            {
				system("cls");
				cout<<"(Aby anulowa�, wci�nij enter nie wprowadzaj�c �adnego znaku)"<<endl;
				string firstName, lastName;
				cout << "Podaj imi�: ";
				cin.clear();
				fflush(stdin);
				getline(cin,firstName);
				if(!(firstName.empty()))
                {
                    system("cls");
                    cout << "Podaj nazwisko: ";
                    cin >> lastName;
                    system("cls");
                    if (tree.findMember(trim(firstName), trim(lastName))._map == 404)
                    {
                        cout << "Nie znaleziono" << endl;
                    }

                    else
                    {
                         tree.memberTree(tree.findMember(trim(firstName), trim(lastName)));
                    }
                    cout << endl << "Strza�ka w g�r� aby wr�ci�";
                }
                else
                {
                    system("cls");
                    printMenu();
                }
			}
			if (i == 2)//edytuj czlonka rodziny
            {
				system("cls");
				cout<<"(Aby anulowa�, wci�nij enter nie wprowadzaj�c �adnego znaku)"<<endl;
				string firstName, lastName;
				cout << "Podaj imi�: ";
				cin.clear();
				fflush(stdin);
				getline(cin,firstName);
				if(!(firstName.empty()))
                {
                    system("cls");
                    cout << "Podaj nazwisko: ";
                    cin >> lastName;
                    system("cls");
                    Pointer seek = tree.findMember(firstName, lastName);
                    if (seek._map == 404)
                        cout << "Nie znaleziono" << endl;
                    else {
                        cout << "Czy na pewno chcesz edytowa� "<<firstName<<"? (t/n): ";
                        char dec;
                        cin >> dec;
                        if (dec == 't') {
                            string rel = tree.getPerson(seek).getRelationship();
                            tree.editRelative(seek,form(rel, false));
                            tree.exportTree("temp.txt");
                        }
                    }
                    cout << endl << "Strza�ka w g�r� aby wr�ci�";
                }
                else
                {
                    system("cls");
                    printMenu();
                }
			}
			if (i == 3)//powi�� osoby
            {
				system("cls");

				string firstName, lastName, firstName2;
				Pointer seek1, seek2;
				seek1._map = 404;
				seek2._map = 404;
				cin.clear();
				fflush(stdin);
				cout<<"(Aby anulowa�, wci�nij enter nie wprowadzaj�c �adnego znaku)"<<endl;
				cout<<"Wyszukaj osob� (je�li to relacja rodzic-dziecko, wyszukaj dziecka)"<<endl;
				cout << "Podaj imi�: ";
				getline(cin,firstName);
				if(!(firstName.empty()))
				{
				    while (seek1._map == 404)
                    {
                        system("cls");
                        cout<< "Podaj nazwisko: ";
                        cin >> lastName;
                        system("cls");
                        seek1 = tree.findMember(trim(firstName), trim(lastName));
                        if (seek1._map == 404)
                        {
                            cout << "Nie znaleziono, spr�buj ponownie" << endl;
                        }
                    }
                    cout << "Z kim chcesz powi�za� " << firstName << "?" << endl;
                    while (seek2._map == 404)
                    {
                        cout << "Podaj imi�: ";
                        cin >> firstName2;
                        cout << "Podaj nazwisko: ";
                        cin >> lastName;
                        system("cls");
                        seek2 = tree.findMember(trim(firstName2), trim(lastName));
                        if (seek2._map == 404)
                        {
                            cout << "Nie znaleziono, spr�buj ponownie" << endl;
                        }

                    }
                        bool ok = false;
                        string rel;

                        system("cls");
                        cout << "Kim " << trim(firstName2) << " jest dla " << trim(firstName) << "?" << endl;
                        cout << "matka / ojciec / partner(ka)" << endl;

                        while (!ok) {

                            cin >> rel;
                            if (trim(rel) == "partner" || trim(rel) == "partnerka")
                            {
                                tree.setRelative(seek1, seek2, 1);
                                tree.setRelative(seek2, seek1, 1);
                                tree.exportTree("temp.txt");
                                ok = true;
                                system("cls");
                                cout << "Powi�zano";
                            }
                            else if (rel == "matka")
                            {
                                tree.setRelative(seek1, seek2, 2);
                                tree.exportTree("temp.txt");
                                ok = true;
                                system("cls");
                                cout << "Powi�zano";
                            }
                            else if (rel == "ojciec")
                            {
                                tree.setRelative(seek1, seek2, 3);
                                tree.exportTree("temp.txt");
                                ok = true;
                                system("cls");
                                cout << "Powi�zano";
                            }
                            else
                            {
                                system("cls");
                                cout << "Co� posz�o nie tak, spr�buj ponownie" << endl;
                                cout << "Kim " << trim(firstName2) << " jest dla " << trim(firstName) << "?" << endl;
                                cout << "matka / ojciec / partner(ka)" << endl;
                            }
                        }
                    cout << endl << "Strza�ka w g�r� aby wr�ci�";
				}
				else
                {
                    system("cls");
                    printMenu();
                }





			}
			if (i == 4)	//usun czlonka rodziny
            {
                system("cls");
				cout<<"(Aby anulowa�, wci�nij enter nie wprowadzaj�c �adnego znaku)"<<endl;
				string firstName, lastName;
				cout << "Podaj imi�: ";

				cin.clear();
				fflush(stdin);
				getline(cin,firstName);
				if(!(firstName.empty()))
                {
                    cout << "Podaj nazwisko: ";
                    cin >> lastName;
                    system("cls");
                    Pointer seek = tree.findMember(trim(firstName), trim(lastName));
                    if (seek._map == 404)
                    {
                        cout << "Nie znaleziono" << endl;
                    }
                    else if (seek._map == 0 && seek._vector == 0)
                    {
                        system("cls");
                        cout<<"Nie mo�esz usun�� siebie"<<endl;
                    }
                    else
                    {
                        cout << "Czy na pewno chcesz usun��? "<<trim(firstName)<<" (t/n) ";
                        char dec;
                        cin >> dec;
                        if (dec == 't')
                        {
					    tree.deleteReative(seek);
					    tree.exportTree("temp.txt");
					    cout << "Poprawnie usuni�to"<<endl;
                        }
                    }
                    cout << "Strza�ka w g�r� aby wr�ci�";
				}
				else
                {
                    system("cls");
                    printMenu();
                }
			}
			if (i == 5)//wyswietl drzewo
            {
                system("cls");
                tree.printTree(tree.getTree());
                cout << endl << "Strza�ka w g�r� aby wr�ci�";
			}
			if (i == 6)//eksportuj drzewo
			{
				system("cls");
				cout<<"(Aby anulowa�, wci�nij enter nie wprowadzaj�c �adnego znaku)"<<endl;
				cout << "Podaj nazw� pliku: ";
				string filename;
				cin.clear();
				fflush(stdin);
				getline(cin,filename);
				if(!(filename.empty()))
                {
                    system("cls");
                    tree.exportTree(trim(filename));
                    cout << "Drzewo wyeksportowano"<<endl;
                    cout << "Strza�ka w g�r� aby wr�ci�";
                }
                else
                {
                    system("cls");
                    printMenu();
                }

			}
			break;
		default:
			break;
		}
	} while (x != 27);
}

int main()
{
    SetConsoleTitle("Drzewo genealogiczne");
	SetConsoleCP(1250); // input
	SetConsoleOutputCP(1250); // output

	char x;
	int i = 0;

	startScreen();
	do
    {
		x = _getch();
		switch (x)
		{
		case 72: //up
			if (i > 0)
			{
				moveUP(hsTab, i);
				system("cls");
				startScreen();
				i--;
			}
			break;
		case 80: //down
			if (i < 1)
			{
				moveDown(hsTab, i);
				system("cls");
				startScreen();
				i++;
			}
			break;
		case 13: //enter
			if (i == 0)//stworz drzewo
			{
				system("cls");
				tree.addUser(form(" ",true));
				menu(i, x);
			}
			if (i == 1)//wczytaj drzewo
			{
				system("cls");
				string filename;
				cout << "Wprowad� nazw� pliku: ";
				cin >> filename;
				if (tree.importTree(trim(filename)))
				{
				    menu(i, x);
				}

				else
                {
					system("cls");
					startScreen();
					cout << endl << "B��d wczytania pliku, spr�buj ponownie";
				}
			}
			break;
		default:
			break;
		}
	} while (x != 27); //esc
	return 0;
}
