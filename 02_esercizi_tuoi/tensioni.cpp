/*
 * Esercizio 1 - Tensioni misurate in un impianto (C++)
 * Collaudo: 8 punti di presa misurati PRIMA e DOPO un intervento.
 *
 * Schema generale (uguale per tutti gli esercizi "menu + array"):
 *   - costante N per la dimensione degli array
 *   - una funzione per ogni voce del menu
 *   - main con do-while + switch che si ripete finche' scelta != 0
 */
#include <iostream>
using namespace std;

const int N = 8;   // numero di punti di presa (dimensione fissa degli array)

// ---------- funzioni di supporto ----------

// Calcola la media di un array di N elementi
double media(double v[]) {
    double somma = 0;
    for (int i = 0; i < N; i++) {
        somma += v[i];
    }
    return somma / N;
}

// Restituisce la POSIZIONE (indice) del valore minimo dell'array
int posizioneMinimo(double v[]) {
    int posMin = 0;                 // ipotizzo che il minimo sia il primo
    for (int i = 1; i < N; i++) {
        if (v[i] < v[posMin]) {
            posMin = i;
        }
    }
    return posMin;
}

// Conta quanti valori sono FUORI dall'intervallo [min, max]
int contaFuori(double v[], double min, double max) {
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] < min || v[i] > max) {
            cont++;
        }
    }
    return cont;
}

// ---------- funzioni del menu ----------

// Voci 1 e 2: inserimento (la stessa funzione serve per entrambi gli array)
void inserisci(double v[], string nome) {
    cout << "Inserimento tensioni " << nome << endl;
    for (int i = 0; i < N; i++) {
        cout << "Punto " << i + 1 << " (V): ";
        cin >> v[i];
    }
}

// Voce 3: media di ciascuna serie
void visualizzaMedie(double prima[], double dopo[]) {
    cout << "Media PRIMA: " << media(prima) << " V" << endl;
    cout << "Media DOPO : " << media(dopo) << " V" << endl;
}

// Voce 4: confronto delle medie
void confrontaMedie(double prima[], double dopo[]) {
    double mPrima = media(prima);
    double mDopo = media(dopo);
    double diff = mDopo - mPrima;

    cout << "Differenza (dopo - prima): " << diff << " V" << endl;
    if (mDopo > mPrima) {
        cout << "La media piu' alta e' quella DOPO l'intervento" << endl;
    } else if (mPrima > mDopo) {
        cout << "La media piu' alta e' quella PRIMA dell'intervento" << endl;
    } else {
        cout << "Le due medie sono uguali" << endl;
    }
}

// Voce 5: confronto punto per punto
void confrontaPunti(double prima[], double dopo[]) {
    for (int i = 0; i < N; i++) {
        cout << "Punto " << i + 1 << ": prima " << prima[i]
             << " V, dopo " << dopo[i]
             << " V, differenza " << dopo[i] - prima[i] << " V" << endl;
    }
}

// Voce 6: conteggio punti fuori intervallo
void contaFuoriIntervallo(double prima[], double dopo[]) {
    double min, max;
    cout << "Tensione minima accettabile (V): ";
    cin >> min;
    cout << "Tensione massima accettabile (V): ";
    cin >> max;

    cout << "Punti fuori intervallo PRIMA: " << contaFuori(prima, min, max) << endl;
    cout << "Punti fuori intervallo DOPO : " << contaFuori(dopo, min, max) << endl;
}

// Voce 7: tensione minima e punto in cui e' stata misurata
void visualizzaMinimi(double prima[], double dopo[]) {
    int p1 = posizioneMinimo(prima);
    int p2 = posizioneMinimo(dopo);
    // +1 perche' l'utente conta i punti da 1, l'array parte da 0
    cout << "Minimo PRIMA: " << prima[p1] << " V al punto " << p1 + 1 << endl;
    cout << "Minimo DOPO : " << dopo[p2] << " V al punto " << p2 + 1 << endl;
}

int main() {
    double prima[N] = {0};   // inizializzo a 0 per evitare valori "sporchi"
    double dopo[N] = {0};
    int scelta;

    do {
        cout << "\n===== MENU TENSIONI =====" << endl;
        cout << "1. Inserisci tensioni PRIMA dell'intervento" << endl;
        cout << "2. Inserisci tensioni DOPO l'intervento" << endl;
        cout << "3. Visualizza media di ciascuna serie" << endl;
        cout << "4. Confronta le due medie" << endl;
        cout << "5. Confronta punto per punto" << endl;
        cout << "6. Conta punti fuori intervallo" << endl;
        cout << "7. Tensione minima di ciascuna serie" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: inserisci(prima, "PRIMA"); break;
            case 2: inserisci(dopo, "DOPO"); break;
            case 3: visualizzaMedie(prima, dopo); break;
            case 4: confrontaMedie(prima, dopo); break;
            case 5: confrontaPunti(prima, dopo); break;
            case 6: contaFuoriIntervallo(prima, dopo); break;
            case 7: visualizzaMinimi(prima, dopo); break;
            case 0: cout << "Arrivederci!" << endl; break;
            default: cout << "Scelta non valida" << endl;
        }
    } while (scelta != 0);

    return 0;
}
