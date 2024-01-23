#include <iostream>
#include <fstream>
#include <cmath> //�traukiame bibliotekas

using namespace std; //�i funkcija leid�ia nenaudoti std:: prie� eilutes

int ivestis();
bool tikrinimas();
void atsakymai(); //�vedame funkcijas

int skaicius;  // Global variable

int main() { //pagrindin� funkcija
    //i�kvie�iame kitas funkcijas
    ivestis();
    atsakymai();
    return 0;
}

int ivestis() { //�vestris funkcija
    int kiekis; //kintamasis
    ofstream fout("Duomenys.txt"); //�altinis, � kur� �ra�ysime informacij�

    cout << "Kiek skai�i� j�s norite �vesti?" << endl;
    cin >> kiekis;
    fout << kiekis << endl; //�vedame kiek� � duomen� fail�

    cout << "�veskite skai�ius: ";
    for (int i = 0; i < kiekis; i++) { //ciklas, kuris paklausia sksi�i�
        cin >> skaicius;
        fout << skaicius << endl; //skai�ius �vedamas � duomen� fail�
    }
    fout.close(); //u�darome fail�
}

bool tikrinimas() { //tikrinimo funkcija su atsakymo gra�inimu
    ofstream fout("Rezultatai.txt", ios::app);  //ios:app naudojamas tam, kad informacija i�likt�

    if (skaicius <= 1) { //funkcija, kuri pasako, kad jeigu skai�ius yra 1 arba ma�iau, jis n�ra pirminis
        fout << skaicius << " false" << endl; //� rezultat� fail� �ra�omas atsakymas, kad tas skai�ius n�ra pirminis
        fout.close();  // u�arome fail�
        return false; //gra�iname atsakym�
    }

    for (int i = 2; i <= sqrt(skaicius); i++) { //ciklas, kuris tikrina ar skai�ius yra pirminis
        if (skaicius % i == 0) {
            fout << skaicius << " false" << endl; //�ra�omas atsakymas � atsakym� fail�
            fout.close();  // u�darome fail�
            return false; //gra�iname atsakym�
        }
    }

    fout << skaicius << " true" << endl; //jeigu skai�ius nesutampa su vir�utine s�lyga, jis yra pirminis
    fout.close();  // u�darome fail�
    return true; //gra�iname atsakym�
}

void atsakymai() { //atsikymo funkcija
    int kiekis; //�vedamas kiekis
    ifstream fin("Duomenys.txt"); //failas, i� kurio pasiimsime informacij�

    fin >> kiekis; //nura�omas pirmas skai�ius
    for (int i = 0; i < kiekis; i++) { //ciklas
        fin >> skaicius; //nura�omi skai�iai
        tikrinimas(); //i�kvie�iama funkcija
    }

    fin.close();
}
