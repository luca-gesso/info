/*
 * SOLUZIONE Esercizio 1 - Consumi energetici dei laboratori (C++)
 */
#include <iostream>
using namespace std;

const int N = 6;   // numero di laboratori

// Somma di tutti i consumi
double totale(double v[]) {
    double somma = 0;
    for (int i = 0; i < N; i++) {
        somma += v[i];
    }
    return somma;
}

// Media: riuso la funzione totale
double media(double v[]) {
    return totale(v) / N;
}

// Conta i laboratori sopra soglia
int contaSopra(double v[], double soglia) {
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] > soglia) {
            cont++;
        }
    }
    return cont;
}

// Indice del valore massimo
int posizioneMassimo(double v[]) {
    int posMax = 0;
    for (int i = 1; i < N; i++) {
        if (v[i] > v[posMax]) {
            posMax = i;
        }
    }
    return posMax;
}

// Voci 1 e 2
void inserisci(double v[], string settimana) {
    cout << "Consumi settimana " << settimana << endl;
    for (int i = 0; i < N; i++) {
        cout << "Laboratorio " << i + 1 << " (kWh): ";
        cin >> v[i];
    }
}

// Voce 3
void totaliEMedie(double prima[], double dopo[]) {
    cout << "PRIMA -> totale: " << totale(prima) << " kWh, media: " << media(prima) << " kWh" << endl;
    cout << "DOPO  -> totale: " << totale(dopo) << " kWh, media: " << media(dopo) << " kWh" << endl;
}

// Voce 4
void confrontaMedie(double prima[], double dopo[]) {
    double mPrima = media(prima);
    double mDopo = media(dopo);
    cout << "Differenza (prima - dopo): " << mPrima - mDopo << " kWh" << endl;

    if (mPrima == 0) {   // evito la divisione per zero
        cout << "Impossibile calcolare la percentuale (media prima = 0)" << endl;
    } else {
        double risparmio = (mPrima - mDopo) / mPrima * 100;
        cout << "Risparmio percentuale: " << risparmio << " %" << endl;
    }
}

// Voce 5
void confrontaLaboratori(double prima[], double dopo[]) {
    for (int i = 0; i < N; i++) {
        double diff = dopo[i] - prima[i];
        cout << "Lab " << i + 1 << ": differenza " << diff << " kWh -> ";
        if (diff < 0) {
            cout << "RISPARMIO" << endl;
        } else if (diff > 0) {
            cout << "AUMENTO" << endl;
        } else {
            cout << "INVARIATO" << endl;
        }
    }
}

// Voce 6
void laboratoriSopraSoglia(double prima[], double dopo[]) {
    double soglia;
    cout << "Soglia (kWh): ";
    cin >> soglia;
    cout << "PRIMA: " << contaSopra(prima, soglia) << " laboratori sopra soglia" << endl;
    cout << "DOPO : " << contaSopra(dopo, soglia) << " laboratori sopra soglia" << endl;
}

// Voce 7
void visualizzaMassimi(double prima[], double dopo[]) {
    int p1 = posizioneMassimo(prima);
    int p2 = posizioneMassimo(dopo);
    cout << "Massimo PRIMA: " << prima[p1] << " kWh (laboratorio " << p1 + 1 << ")" << endl;
    cout << "Massimo DOPO : " << dopo[p2] << " kWh (laboratorio " << p2 + 1 << ")" << endl;
}

int main() {
    double prima[N] = {0};
    double dopo[N] = {0};
    int scelta;

    do {
        cout << "\n===== CONSUMI LABORATORI =====" << endl;
        cout << "1. Inserisci consumi PRIMA" << endl;
        cout << "2. Inserisci consumi DOPO" << endl;
        cout << "3. Totale e media di ciascuna settimana" << endl;
        cout << "4. Confronta medie e risparmio %" << endl;
        cout << "5. Confronto laboratorio per laboratorio" << endl;
        cout << "6. Laboratori sopra soglia" << endl;
        cout << "7. Consumo massimo" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: inserisci(prima, "PRIMA"); break;
            case 2: inserisci(dopo, "DOPO"); break;
            case 3: totaliEMedie(prima, dopo); break;
            case 4: confrontaMedie(prima, dopo); break;
            case 5: confrontaLaboratori(prima, dopo); break;
            case 6: laboratoriSopraSoglia(prima, dopo); break;
            case 7: visualizzaMassimi(prima, dopo); break;
            case 0: cout << "Fine" << endl; break;
            default: cout << "Scelta non valida" << endl;
        }
    } while (scelta != 0);

    return 0;
}
