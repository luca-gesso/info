# Compito in classe – Informatica (SIMULAZIONE)
### PARTE PRATICA – laboratorio (PC senza connessione internet)

**Classe:** 4^ Inf. **Durata:** 135 minuti circa **Totale:** 30 punti

**Istruzioni:** salvare i file come `cognome_esercizioX.cpp` / `cognome_esercizioX.java`. Commentare il codice. L'Esercizio 1 va svolto in C++, l'Esercizio 2 in Java. Gli esercizi 3 e 4 si risolvono su foglio (o in un file `.txt`).

> ⏱ Consiglio: prima di guardare le soluzioni, fai la verifica davvero con un timer. Se sei in difficoltà apri `../GUIDA_STUDIO.md`, non le soluzioni.

---

## Esercizio 1 – Consumi energetici dei laboratori (C++) (punti 10)

**Contesto:** la scuola misura il consumo elettrico (in kWh) di **6 laboratori** in due settimane: la settimana *prima* e quella *dopo* l'installazione di lampade LED.

Realizza un programma con un **menu a scelta multipla** che, tramite **funzioni distinte**, permetta di:

1. Inserire i 6 consumi della settimana PRIMA (in un array);
2. Inserire i 6 consumi della settimana DOPO (in un secondo array);
3. Calcolare e visualizzare il **consumo totale** e il **consumo medio** di ciascuna settimana;
4. Confrontare le due medie indicando la differenza e il **risparmio percentuale** ottenuto  
   (risparmio % = (mediaPrima − mediaDopo) / mediaPrima × 100);
5. Visualizzare, laboratorio per laboratorio, la differenza tra le due settimane, scrivendo accanto `RISPARMIO` se il consumo è diminuito, `AUMENTO` se è aumentato, `INVARIATO` altrimenti;
6. Contare quanti laboratori, in ciascuna settimana, hanno consumato **più di una soglia** inserita dall'utente;
7. Trovare il **consumo massimo** di ciascuna settimana e il **numero del laboratorio** in cui si è registrato;
0. Uscire dal programma.

**Requisiti:** ogni voce del menu corrisponde a una funzione separata richiamata dal main; il menu si ripresenta finché non si sceglie 0; array di dimensione fissa gestita con una **costante**; gestire la scelta non valida.

---

## Esercizio 2 – Analisi di una frase, parte 2 (Java) (punti 10)

Realizza un programma Java con i seguenti **metodi statici**:

- `contaConsonanti(frase)` → restituisce il numero di **consonanti** (lettere che non sono vocali; spazi, numeri e punteggiatura NON contano);
- `contaCarattere(frase, c)` → restituisce quante volte il carattere `c` compare nella frase (ignorando maiuscole/minuscole);
- `inverti(frase)` → restituisce la frase scritta al contrario (es. `"ciao"` → `"oaic"`);
- `parolaPiuLunga(frase)` → restituisce la parola più lunga della frase (se più parole hanno la stessa lunghezza, la prima);
- un `main` che richiami tutti i metodi su **almeno due frasi** diverse, stampando i risultati in modo leggibile.

Metodi String disponibili: `length()`, `charAt(i)`, `toLowerCase()`, `toUpperCase()`, `trim()`, `replace(a,b)`, `split(sep)`, `equals(altra)`.

> Suggerimento: per sapere se un carattere è una lettera puoi controllare `c >= 'a' && c <= 'z'` (dopo aver messo la frase in minuscolo).

---

## Esercizio 3 – Debug (punti 6)

Nei programmi seguenti ci sono degli errori. **Individuali, spiega perché il codice non si comporta come previsto e riscrivi la versione corretta.**

**a) C++** (dovrebbe stampare la media di 3 voti: 6, 7, 8 → atteso `7.0`; e con 6, 7, 7 → atteso `6.66667`)
```cpp
#include <iostream>
using namespace std;

const int N = 3;

double media(int v[]) {
    int somma = 0;
    for (int i = 0; i < N; i++)
        somma += v[i];
    return somma / N;
}

int main() {
    int voti[N] = {6, 7, 7};
    cout << "Media: " << media(voti) << endl;
    return 0;
}
```
Output atteso: `Media: 6.66667` Output reale: ______________

**b) C++** (dovrebbe trovare il valore massimo dell'array)
```cpp
int massimo(int v[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}
// chiamata con: int t[4] = {-5, -2, -9, -3};
```
Cosa restituisce? ______________

**c) Java** (dovrebbe stampare "Accesso consentito" se l'utente scrive admin)
```java
import java.util.Scanner;
public class Login {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String utente = in.nextLine();
        if (utente == "admin")
            System.out.println("Accesso consentito");
        else
            System.out.println("Accesso negato");
    }
}
```
Cosa succede se l'utente scrive `admin`? ______________

---

## Esercizio 4 – Cosa stampa? (punti 4)

Indica cosa stampa ciascun programma, **motivando brevemente** il ragionamento (traccia delle variabili / delle chiamate).

**a) C++**
```cpp
#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0) return 0;
    return n + f(n - 1);
}

int main() {
    cout << "Risultato: " << f(5) << endl;
    return 0;
}
```

**b) Java**
```java
public class Prova {
    public static void main(String[] args) {
        int x = 1;
        int conta = 0;
        while (x < 50) {
            x = x * 3;
            conta++;
        }
        System.out.println("x = " + x + ", conta = " + conta);
    }
}
```

**c) C++**
```cpp
#include <iostream>
using namespace std;

void modifica(int a, int &b) {
    a = a * 2;
    b = b * 2;
}

int main() {
    int p = 3, q = 3;
    modifica(p, q);
    cout << p << " " << q << endl;
    return 0;
}
```

**d) Java**
```java
public class Stringhe {
    public static void main(String[] args) {
        String s = "Informatica";
        int c = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'o') {
                c++;
            }
        }
        System.out.println(c + " " + s.length() + 1);
    }
}
```
