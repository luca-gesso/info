/*
 * Esercizio 1 - Temperature di Ferragosto (C++)
 * 7 giorni (12-18 agosto): scorso anno vs quest'anno.
 * Stessa struttura dell'esercizio delle tensioni: cambiano solo i nomi!
 */
#include <iostream>
using namespace std;

const int GIORNI = 7;   // dimensione fissa degli array

// Calcola la media delle temperature
double media(double t[]) {
    double somma = 0;
    for (int i = 0; i < GIORNI; i++) {
        somma += t[i];
    }
    return somma / GIORNI;
}

// Conta i giorni con temperatura sopra la soglia
int contaSopra(double t[], double soglia) {
    int cont = 0;
    for (int i = 0; i < GIORNI; i++) {
        if (t[i] > soglia) {
            cont++;
        }
    }
    return cont;
}

// Voci 1 e 2: inserimento temperature
void inserisci(double t[], string anno) {
    cout << "Temperature " << anno << endl;
    for (int i = 0; i < GIORNI; i++) {
        cout << i + 12 << " agosto: ";   // giorno 0 -> 12 agosto
        cin >> t[i];
    }
}

// Voce 3: media di ciascun anno
void visualizzaMedie(double scorso[], double attuale[]) {
    cout << "Media scorso anno: " << media(scorso) << " C" << endl;
    cout << "Media quest'anno : " << media(attuale) << " C" << endl;
}

// Voce 4: confronto medie
void confrontaMedie(double scorso[], double attuale[]) {
    double diff = media(attuale) - media(scorso);
    cout << "Differenza: " << diff << " C" << endl;
    if (diff > 0) {
        cout << "Quest'anno e' stato piu' CALDO" << endl;
    } else if (diff < 0) {
        cout << "Quest'anno e' stato piu' FREDDO" << endl;
    } else {
        cout << "Stessa temperatura media" << endl;
    }
}

// Voce 5: confronto giorno per giorno
void confrontaGiorni(double scorso[], double attuale[]) {
    for (int i = 0; i < GIORNI; i++) {
        cout << i + 12 << " agosto: differenza " << attuale[i] - scorso[i] << " C" << endl;
    }
}

// Voce 6: giorni sopra soglia
void giorniSopraSoglia(double scorso[], double attuale[]) {
    double soglia;
    cout << "Soglia (C): ";
    cin >> soglia;
    cout << "Scorso anno: " << contaSopra(scorso, soglia) << " giorni sopra soglia" << endl;
    cout << "Quest'anno : " << contaSopra(attuale, soglia) << " giorni sopra soglia" << endl;
}

int main() {
    double scorso[GIORNI] = {0};
    double attuale[GIORNI] = {0};
    int scelta;

    do {
        cout << "\n--- MENU FERRAGOSTO ---" << endl;
        cout << "1. Inserisci temperature scorso anno" << endl;
        cout << "2. Inserisci temperature quest'anno" << endl;
        cout << "3. Media di ciascun anno" << endl;
        cout << "4. Confronta le medie" << endl;
        cout << "5. Confronto giorno per giorno" << endl;
        cout << "6. Giorni sopra una soglia" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: inserisci(scorso, "scorso anno"); break;
            case 2: inserisci(attuale, "quest'anno"); break;
            case 3: visualizzaMedie(scorso, attuale); break;
            case 4: confrontaMedie(scorso, attuale); break;
            case 5: confrontaGiorni(scorso, attuale); break;
            case 6: giorniSopraSoglia(scorso, attuale); break;
            case 0: cout << "Fine programma" << endl; break;
            default: cout << "Scelta non valida" << endl;
        }
    } while (scelta != 0);

    return 0;
}
