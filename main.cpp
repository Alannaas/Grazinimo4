#include <iostream>
#include <fstream>
#include <cmath> //átraukiame bibliotekas

using namespace std; //ði funkcija leidþia nenaudoti std:: prieð eilutes

int ivestis();
bool tikrinimas();
void atsakymai(); //ávedame funkcijas

int skaicius;  // Global variable

int main() { //pagrindinë funkcija
    //iðkvieèiame kitas funkcijas
    ivestis();
    atsakymai();
    return 0;
}

int ivestis() { //ávestris funkcija
    int kiekis; //kintamasis
    ofstream fout("Duomenys.txt"); //ðaltinis, á kurá áraðysime informacijà

    cout << "Kiek skaièiø jûs norite ávesti?" << endl;
    cin >> kiekis;
    fout << kiekis << endl; //ávedame kieká á duomenø failà

    cout << "Áveskite skaièius: ";
    for (int i = 0; i < kiekis; i++) { //ciklas, kuris paklausia sksièiø
        cin >> skaicius;
        fout << skaicius << endl; //skaièius ávedamas á duomenø failà
    }
    fout.close(); //uþdarome failà
}

bool tikrinimas() { //tikrinimo funkcija su atsakymo graþinimu
    ofstream fout("Rezultatai.txt", ios::app);  //ios:app naudojamas tam, kad informacija iðliktø

    if (skaicius <= 1) { //funkcija, kuri pasako, kad jeigu skaièius yra 1 arba maþiau, jis nëra pirminis
        fout << skaicius << " false" << endl; //á rezultatø failè áraðomas atsakymas, kad tas skaièius nëra pirminis
        fout.close();  // uþarome failà
        return false; //graþiname atsakymà
    }

    for (int i = 2; i <= sqrt(skaicius); i++) { //ciklas, kuris tikrina ar skaièius yra pirminis
        if (skaicius % i == 0) {
            fout << skaicius << " false" << endl; //áraðomas atsakymas á atsakymø failà
            fout.close();  // uþdarome failà
            return false; //graþiname atsakymà
        }
    }

    fout << skaicius << " true" << endl; //jeigu skaièius nesutampa su virðutine sàlyga, jis yra pirminis
    fout.close();  // uþdarome failà
    return true; //graþiname atsakymà
}

void atsakymai() { //atsikymo funkcija
    int kiekis; //ávedamas kiekis
    ifstream fin("Duomenys.txt"); //failas, ið kurio pasiimsime informacijà

    fin >> kiekis; //nuraðomas pirmas skaièius
    for (int i = 0; i < kiekis; i++) { //ciklas
        fin >> skaicius; //nuraðomi skaièiai
        tikrinimas(); //iðkvieèiama funkcija
    }

    fin.close();
}
