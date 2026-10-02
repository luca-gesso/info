# Guida di studio – Verifica pratica 4^ Inf

La verifica ha **sempre 4 tipi di esercizio**. Ognuno ha uno "stampo": impara lo stampo e cambi solo i nomi.

| Tipo | Linguaggio | Punti | Cosa imparare |
|------|-----------|-------|---------------|
| Menu + 2 array | C++ | 10 | Schemi 1–6 qui sotto |
| Stringhe con metodi | Java | 10 | Schemi 7–11 |
| Debug | C++ / Java | 6 | Lista "errori classici" |
| Cosa stampa? | C++ / Java | 4 | Tabella di traccia + ricorsione |

---

## PARTE C++ – Menu con due array

### Schema 1 – Lo scheletro (scrivilo per primo, sempre uguale)
```cpp
#include <iostream>
using namespace std;

const int N = 8;          // cambia solo il numero (8 punti, 7 giorni, 6 lab...)

// ... qui le funzioni ...

int main() {
    double a[N] = {0};
    double b[N] = {0};
    int scelta;
    do {
        cout << "1. ..." << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;
        switch (scelta) {
            case 1: inserisci(a, "PRIMA"); break;
            case 2: inserisci(b, "DOPO"); break;
            // ...
            case 0: cout << "Fine" << endl; break;
            default: cout << "Scelta non valida" << endl;
        }
    } while (scelta != 0);
    return 0;
}
```
- `do-while` perché il menu va mostrato **almeno una volta**.
- Non dimenticare i `break;` nello switch (altrimenti "cade" nel case successivo!).

### Schema 2 – Inserimento
```cpp
void inserisci(double v[], string nome) {
    for (int i = 0; i < N; i++) {
        cout << "Valore " << i + 1 << ": ";   // i+1: l'utente conta da 1
        cin >> v[i];
    }
}
```
Gli array in C++ si modificano anche **senza `&`** (si passa l'indirizzo).

### Schema 3 – Somma / Media
```cpp
double media(double v[]) {
    double somma = 0;                 // double! (se int → divisione intera)
    for (int i = 0; i < N; i++) somma += v[i];
    return somma / N;
}
```

### Schema 4 – Contare con una condizione
```cpp
int conta(double v[], double soglia) {
    int cont = 0;
    for (int i = 0; i < N; i++)
        if (v[i] > soglia)            // cambia SOLO la condizione
            cont++;
    return cont;
}
```
Condizioni tipiche:
- sopra soglia: `v[i] > soglia`
- **fuori** intervallo: `v[i] < min || v[i] > max` (con **OR**)
- **dentro** intervallo: `v[i] >= min && v[i] <= max` (con **AND**)

### Schema 5 – Minimo / Massimo **con posizione**
```cpp
int posMinimo(double v[]) {
    int pos = 0;                      // parto dal PRIMO elemento, MAI da 0 come valore
    for (int i = 1; i < N; i++)
        if (v[i] < v[pos])            // per il massimo: >
            pos = i;
    return pos;
}
// uso: int p = posMinimo(a);  cout << a[p] << " al punto " << p + 1;
```
Restituendo la posizione hai **entrambe** le cose: il valore è `v[pos]`.

### Schema 6 – Confronti
```cpp
// medie
double diff = media(b) - media(a);
if (diff > 0) ...  else if (diff < 0) ...  else ...   // ricorda il caso "uguali"!

// elemento per elemento
for (int i = 0; i < N; i++)
    cout << "Punto " << i + 1 << ": " << b[i] - a[i] << endl;

// percentuale (attenzione divisione per zero)
double perc = (vecchio - nuovo) / vecchio * 100;
```

---

## PARTE Java – Stringhe

### Struttura del file
```java
public class NomeFile {          // DEVE essere uguale al nome del file .java
    public static int metodo(String frase) { ... }
    public static void main(String[] args) { ... }
}
```
- I metodi chiamati dal `main` devono essere `static`.
- Stampa: `System.out.println("testo " + variabile);` → **+**, non `<<`!
- Lettura: `Scanner in = new Scanner(System.in); String s = in.nextLine();` (+ `import java.util.Scanner;` in cima)

### Schema 7 – Scorrere carattere per carattere
```java
String f = frase.toLowerCase();
for (int i = 0; i < f.length(); i++) {
    char c = f.charAt(i);
    // controlla c
}
```
- vocale: `c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'`
- lettera: `c >= 'a' && c <= 'z'`
- cifra: `c >= '0' && c <= '9'`
- maiuscola (sulla frase originale): `c >= 'A' && c <= 'Z'`
- spazio: `c == ' '`
- Attenzione: `char` usa apici singoli `'a'`, `String` doppi `"a"`.

### Schema 8 – Contare le parole
```java
String[] parole = frase.trim().split(" ");
int n = parole.length;           // nr. parole (se non ci sono doppi spazi)
```
`parole.length` (array, **senza** parentesi) vs `frase.length()` (stringa, **con** parentesi)!

### Schema 9 – Palindroma
```java
String f = frase.toLowerCase().replace(" ", "");
int sx = 0, dx = f.length() - 1;
while (sx < dx) {
    if (f.charAt(sx) != f.charAt(dx)) return false;
    sx++; dx--;
}
return true;
```
Alternativa facile: `return f.equals(inverti(f));`

### Schema 10 – Invertire
```java
String r = "";
for (int i = frase.length() - 1; i >= 0; i--)
    r = r + frase.charAt(i);
return r;
```

### Schema 11 – Confrontare stringhe
`s1.equals(s2)` ✅  `s1 == s2` ❌ (confronta i riferimenti, non il contenuto)

---

## Errori classici (= esercizio di DEBUG)

| Errore | Sintomo | Correzione |
|--------|---------|------------|
| `i <= v.length` / `i <= N` | Java: `ArrayIndexOutOfBoundsException`; C++: valore spazzatura | `i < N` |
| Parametro per valore in C++ | la funzione non modifica le variabili del main | `int &a` |
| `int / int` | media troncata (6 invece di 6.67) | `double somma` o `(double) somma / N` |
| `max = 0` / `min = 0` iniziale | sbagliato con negativi (o min con tutti positivi!) | `max = v[0]` |
| `==` tra String in Java | non entra mai nell'if | `.equals()` |
| `<<` in Java | errore di compilazione | `+` |
| `=` invece di `==` nell'if | condizione sempre vera/assegnazione | `==` |
| `;` dopo `for(...)` o `if(...)` | il corpo viene eseguito una volta sola | togliere `;` |
| manca `break` nello switch | esegue anche i case successivi | aggiungere `break;` |
| funzione senza `return` | valore indefinito | aggiungere `return` |
| ricorsione senza caso base | stack overflow | aggiungere `if (n<=...) return ...;` |

---

## "Cosa stampa?" – metodo

1. **Tabella di traccia**: una colonna per ogni variabile, una riga per ogni giro del ciclo.
2. Guarda **dove** sta la `println`/`cout`: dentro il ciclo = stampa ad ogni giro; fuori = una volta.
3. **Ricorsione**: scrivi la "scala" delle chiamate fino al caso base, poi risali.
   - `n * f(n-1)`, base 1 → fattoriale (f(4)=24)
   - `n + f(n-1)`, base 0 → somma 1..n (f(5)=15)
4. Trappole:
   - `%`: `i % 2 == 0` → pari
   - `i += 2` → salta di due
   - Java `"x" + 1 + 2` = `"x12"`; `1 + 2 + "x"` = `"3x"` (da sinistra a destra)
   - `while` controlla **prima**, `do-while` **dopo**
   - divisione tra `int` tronca: `7 / 2 = 3`, `7 % 2 = 1`

---

## Piano per stasera (≈ 3 ore, tutta pratica)

1. **(30 min)** Riscrivi **da zero, senza guardare**, `02_esercizi_tuoi/tensioni.cpp`. Poi confronta. Rifallo finché lo scheletro (Schema 1) ti esce a memoria.
2. **(20 min)** Rifai `01_compito_risolto/esercizio1_temperature.cpp` da zero: noterai che è lo stesso programma.
3. **(30 min)** Java: rifai `AnalisiFrase.java` da zero (vocali, parole, palindroma).
4. **(10 min)** Leggi la tabella "Errori classici" e `esercizio3_debug.md`.
5. **(75 min)** Fai `03_verifica_simulata/VERIFICA.md` **con il timer**, senza soluzioni.
6. **(15 min)** Correggi con `03_verifica_simulata/soluzioni/` e ripassa solo gli errori che hai fatto.
