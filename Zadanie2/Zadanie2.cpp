#include <iostream>

using namespace std;

class tablicaInt {
    int tab[49];
    int rozmiar;
public:
    tablicaInt(int);
    void wypisz();
    void losuj();
    void wczytaj(); 
    void ileWspolnych(tablicaInt);
    void sort();
};
tablicaInt::tablicaInt(int rozmiar) {
    this->rozmiar = rozmiar;
}

void tablicaInt::wypisz() {
    for (int i = 0; i < this->rozmiar; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void tablicaInt::losuj() {
    srand(time(NULL));
    int ile = 1, l;
    this->tab[0] = rand() % 49 + 1;
    while (ile < this->rozmiar) {
        l = rand() % 49 + 1;
        int flaga = 0;
        for (int j = 0; j < ile; j++) {
            if (this->tab[j] == l) {
                flaga = 1;
                break;
            }
        }
        if (flaga == 0) {
            this->tab[ile] = l;
            ile++;
        }
    }
}

void tablicaInt::wczytaj() {
    cout << "Podaj sześć liczb z przedziału od 1 do 49:" << endl;
    int liczba, ile = 1;
    bool flaga = true, takaSama = false;
    for (int i = 0; i < this->rozmiar; i++) {
        cin >> liczba;
        if (liczba >= 1 && liczba <= 49) {
            if (flaga == true) {
                this->tab[i] = liczba;
                flaga = false;
            }
            else {
                takaSama = false;
                for (int j = 0; j < ile; j++) {
                    if (this->tab[j] == liczba) {
                        takaSama = true;
                        cout << "Liczby nie mogą się powtarzać!" << endl;
                        i--;
                        break;
                    }
                }
                if (takaSama == false) {
                    this->tab[ile] = liczba;
                    ile++;
                }
            }
        }
        else {
            i--;
            cout << "Liczba nie znajduje się w przedziale!" << endl;
        }
    }
}

void tablicaInt::ileWspolnych(tablicaInt t) {
    int wspolne = 0;
    for (int i = 0; i < this->rozmiar; i++) {
        for (int j = 0; j < t.rozmiar; j++) {
            if (this->tab[i] == t.tab[j]) wspolne++;
        }
    }
    cout << "Trafione liczby: " << wspolne << endl;
}

void tablicaInt::sort() {
    for (int i = 0; i < this->rozmiar - 1; i++) {
        for (int j = 0; j < this->rozmiar - 1 - i; j++) {
            if (this->tab[j] > this->tab[j + 1]) {
                int temp = this->tab[j];
                this->tab[j] = this->tab[j + 1];
                this->tab[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    tablicaInt tLos(6);
    tablicaInt tUser(6);
    tLos.losuj();

    cout << "Program symulujący grę w Totolotka" << endl;
    tUser.wczytaj();
    cout << endl;
    tLos.ileWspolnych(tUser);
    cout << endl;

    tUser.sort();
    tLos.sort();
    cout << "Liczby podane przez użytkownika:" << endl;
    tUser.wypisz();
    cout << "Wylosowane liczby:" << endl;
    tLos.wypisz();

    return 0;
}
