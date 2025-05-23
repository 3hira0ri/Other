#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include<string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
struct przedmiot {
    int wartosc;
    int objetosc;
    string nazwa;

};
struct plecak {
    int pojemnosc;
    int wolne_miejsce;
    int wartosc;
    list<przedmiot> zawartosc;
};
//pobranie uchwytu konsoli
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void metoda_zachlanna(list<przedmiot>* muzeum, plecak* plecak1, list<przedmiot> muzeum2) {
    list<przedmiot>::iterator tmp_iter = muzeum2.begin();
    list<przedmiot>::iterator tmp_iter2 = muzeum->begin();
    while (muzeum2.size() > 0) {
        int  tmp_wart = 0;
        list<przedmiot>::iterator it = muzeum->begin();
        bool inside = 0;
        for (list<przedmiot>::iterator it2 = muzeum2.begin(); it2 != muzeum2.end(); it2++) {

            while (it->nazwa != it2->nazwa) {
                it++;
            }
            //for( int i =0; i<muzeum.size();i++){

              // int tmp_obj = 0;

            if (tmp_wart <= it2->wartosc) {
                tmp_iter = it2;
                tmp_wart = it2->wartosc;
                tmp_iter2 = it;
                // tmp_obj = it->objetosc;
                inside = true;
            }
        }
        if (inside == true && plecak1->wolne_miejsce >= tmp_iter->objetosc) {
            plecak1->zawartosc.push_back(*tmp_iter);
            plecak1->wolne_miejsce = plecak1->wolne_miejsce - tmp_iter->objetosc;
            plecak1->wartosc = plecak1->wartosc + tmp_iter->wartosc;
            muzeum->erase(tmp_iter2++);
        }
        muzeum2.erase(tmp_iter++);
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "                                           Algorytm zachlanny\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "       Zawartosc plecaka(Wolne miejsce: " << plecak1->wolne_miejsce << ", wartosc:" << plecak1->wartosc << ")       " << endl;
    cout << "_______________________________________________________________________" << endl;
    cout << "|                  Przedmiot                 |  Wartosc  |  Objetosc  |";
    for (list<przedmiot>::iterator i = plecak1->zawartosc.begin(); i != plecak1->zawartosc.end(); i++) {
        float licz = i->nazwa.size();
        float nazwa = ceil((42 - licz) / 2);
        //int nazwa = ceil(licz);
        cout << endl << "|";
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << i->nazwa;
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << "|    " << i->wartosc;
        if (i->wartosc >= 10000) {
            cout << "  |";
        }
        else if (i->wartosc >= 1000) {
            cout << "   |";
        }
        else if (i->wartosc >= 100) {
            cout << "    |";
        }
        else if (i->wartosc >= 10) {
            cout << "     |";
        }


        cout << "    " << i->objetosc;
        if (i->objetosc >= 10) {
            cout << "      |";
        }
        else if (i->objetosc < 10) {
            cout << "       |";
        }
        cout << endl << "|_____________________________________________________________________|";
    }

    //zmiana atrybutu tekstu poprzez flagi
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "\n\n       Zawartosc muzeum:       " << endl;
    cout << "_______________________________________________________________________" << endl;
    cout << "|                  Przedmiot                 |  Wartosc  |  Objetosc  |";
    for (list<przedmiot>::iterator i = muzeum->begin(); i != muzeum->end(); i++) {
        float licz = i->nazwa.size();
        float nazwa = ceil((42 - licz) / 2);
        //int nazwa = ceil(licz);
        cout << endl << "|";
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << i->nazwa;
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << "|    " << i->wartosc;
        if (i->wartosc >= 10000) {
            cout << "  |";
        }
        else if (i->wartosc >= 1000) {
            cout << "   |";
        }
        else if (i->wartosc >= 100) {
            cout << "    |";
        }
        else if (i->wartosc >= 10) {
            cout << "     |";
        }


        cout << "    " << i->objetosc;
        if (i->objetosc >= 10) {
            cout << "      |";
        }
        else if (i->objetosc < 10) {
            cout << "       |";
        }
        cout << endl << "|_____________________________________________________________________|";
    }
};
void metoda_plecakowa(list<przedmiot>* muzeum, plecak* plecak1, list<przedmiot> muzeum2) {
    list<przedmiot>::iterator tmp_iter = muzeum2.begin();
    list<przedmiot>::iterator tmp_iter2 = muzeum->begin();
    while (muzeum2.size() > 0) {
        float tmp_wart = 0;
        float wsk = 0;
        list<przedmiot>::iterator it = muzeum->begin();
        bool inside = 0;
        for (list<przedmiot>::iterator it2 = muzeum2.begin(); it2 != muzeum2.end(); it2++) {
            while (it->nazwa != it2->nazwa) {
                it++;
            }
            float wartosc = it2->wartosc;
            float objetosc = it2->objetosc;
            wsk = wartosc / objetosc;

            if (tmp_wart <= wsk) {
                tmp_iter = it2;
                tmp_wart = wsk;
                tmp_iter2 = it;
                inside = true;
            }
        }
        if (inside == true && plecak1->wolne_miejsce >= tmp_iter->objetosc) {
            plecak1->zawartosc.push_back(*tmp_iter);
            plecak1->wolne_miejsce = plecak1->wolne_miejsce - tmp_iter->objetosc;
            plecak1->wartosc = plecak1->wartosc + tmp_iter->wartosc;
            muzeum->erase(tmp_iter2++);
        }
        muzeum2.erase(tmp_iter++);
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\n                                           Algorytm plecakowy\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "       Zawartosc plecaka(Wolne miejsce: " << plecak1->wolne_miejsce << ", wartosc:" << plecak1->wartosc << ")       " << endl;
    cout << "____________________________________________________________________________________" << endl;
    cout << "|                  Przedmiot                 |  Wartosc  |  Objetosc  |  Wskaznik  |";
    for (list<przedmiot>::iterator i = plecak1->zawartosc.begin(); i != plecak1->zawartosc.end(); i++) {
        float wartosc = i->wartosc;
        float objetosc = i->objetosc;
        float wsk = wartosc / objetosc;
        float licz = i->nazwa.size();
        float nazwa = ceil((42 - licz) / 2);
        //int nazwa = ceil(licz);
        cout << endl << "|";
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << i->nazwa;
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << "|    " << i->wartosc;
        if (i->wartosc >= 10000) {
            cout << "  |";
        }
        else if (i->wartosc >= 1000) {
            cout << "   |";
        }
        else if (i->wartosc >= 100) {
            cout << "    |";
        }
        else if (i->wartosc >= 10) {
            cout << "     |";
        }


        cout << "     " << i->objetosc;
        if (i->objetosc >= 10) {
            cout << "     |";
        }
        else if (i->objetosc < 10) {
            cout << "      |";
        }


        cout << "    " << wsk;
        cout << endl << "|__________________________________________________________________________________|";
    }

    //zmiana atrybutu tekstu poprzez flagi
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "\n\n       Zawartosc muzeum:       " << endl;
    cout << "____________________________________________________________________________________" << endl;
    cout << "|                  Przedmiot                 |  Wartosc  |  Objetosc  |  Wskaznik  |";
    for (list<przedmiot>::iterator i = muzeum->begin(); i != muzeum->end(); i++) {
        float licz = i->nazwa.size();
        float nazwa = ceil((42 - licz) / 2);
        float wartosc = i->wartosc;
        float objetosc = i->objetosc;
        float wsk = wartosc / objetosc;

        cout << endl << "|";
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << i->nazwa;
        for (int a = nazwa; a >= 0; a--)
            cout << " ";
        cout << "|    " << i->wartosc;
        if (i->wartosc >= 10000) {
            cout << "  |";
        }
        else if (i->wartosc >= 1000) {
            cout << "   |";
        }
        else if (i->wartosc >= 100) {
            cout << "    |";
        }
        else if (i->wartosc >= 10) {
            cout << "     |";
        }


        cout << "    " << i->objetosc;
        if (i->objetosc >= 10) {
            cout << "      |";
        }
        else if (i->objetosc < 10) {
            cout << "       |";
        }
        cout << "    " << wsk;
        cout << endl << "|__________________________________________________________________________________|";
    }
};
int main()
{
    srand(time(0));
    list<przedmiot> muzeum;
    list<przedmiot> muzeum2;
    przedmiot Waza;
    Waza.nazwa = "Waza portlandzka";
    Waza.wartosc = rand();
    Waza.objetosc = rand() % 50 + 1;
    muzeum.push_back(Waza);
    muzeum2.push_back(Waza);
    przedmiot chelm;
    chelm.nazwa = "Skarb z Sutton Hoo";
    chelm.wartosc = rand();
    chelm.objetosc = rand() % 50 + 1;
    muzeum.push_back(chelm);
    muzeum2.push_back(chelm);
    przedmiot ceramika;
    ceramika.nazwa = "Chinska ceramika z okresu Ming";
    ceramika.wartosc = rand();
    ceramika.objetosc = rand() % 40 + 1;
    muzeum.push_back(ceramika);
    muzeum2.push_back(ceramika);
    przedmiot widelec;
    widelec.nazwa = "A Fork from Catherine de Medici's Hometown";
    widelec.wartosc = rand();
    widelec.objetosc = rand() % 5 + 1;
    muzeum.push_back(widelec);
    muzeum2.push_back(widelec);
    przedmiot piuro; //b³ad specjalnie
    piuro.nazwa = "Adolescent Shakespeare's Pen";
    piuro.wartosc = rand();
    piuro.objetosc = rand() % 5 + 1;
    muzeum.push_back(piuro);
    muzeum2.push_back(piuro);
    przedmiot anhk;
    anhk.nazwa = "Anubis's Ankh Cross ";
    anhk.wartosc = rand();
    anhk.objetosc = rand() % 25 + 1;
    muzeum.push_back(anhk);
    muzeum2.push_back(anhk);
    przedmiot torba;
    torba.nazwa = "Torba Finn'a MacCool'a";
    torba.wartosc = rand();
    torba.objetosc = rand() % 10 + 1;
    muzeum.push_back(torba);
    muzeum2.push_back(torba);
    przedmiot mapa;
    mapa.nazwa = "Barbarossa's Pirate Map ";
    mapa.wartosc = rand();
    mapa.objetosc = rand() % 7 + 1;
    muzeum.push_back(mapa);
    muzeum2.push_back(mapa);
    przedmiot noz;
    noz.nazwa = "Egyptian Funeral Knife";
    noz.wartosc = rand();
    noz.objetosc = rand() % 7 + 1;
    muzeum.push_back(noz);
    muzeum2.push_back(noz);
    przedmiot lza;
    lza.nazwa = "Muninn's Tears";
    lza.wartosc = rand();
    lza.objetosc = rand() % 7 + 1;
    muzeum.push_back(lza);
    muzeum2.push_back(lza);
    plecak plecak1;
    plecak1.pojemnosc = 50;
    plecak1.wolne_miejsce = plecak1.pojemnosc;
    plecak1.wartosc = 0;
    auto start = high_resolution_clock::now();
    metoda_zachlanna(&muzeum, &plecak1, muzeum);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Funkcja 'Metoda Zachlanna' zajela (mniej wiecej):" << duration.count() << "ms" << endl;
    if (duration.count() > 30000) {
        cout << "ochrona zareagowala i zlodziej zostal zlapany";
    }
    // METODA PLECAKOWA
    plecak plecak2;
    plecak2.pojemnosc = 50;
    plecak2.wolne_miejsce = plecak2.pojemnosc;
    plecak2.wartosc = 0;
    SetConsoleTextAttribute(hConsole, 15);
    start = high_resolution_clock::now();
    metoda_plecakowa(&muzeum2, &plecak2, muzeum2);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Funkcja 'Metoda Plecakowa' zajela (mniej wiecej):" << duration.count() << "ms" << endl;
    if (duration.count() > 25000) {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "ochrona zareagowala, zlodziej zostal zlapany\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
    SetConsoleTextAttribute(hConsole, 15);
}
