# Soluzioni – Esercizi 3 e 4

## Esercizio 3 – Debug

### a) Divisione intera
**Output reale:** `Media: 6`

**Perché:** `somma` è `int` e `N` è `int` → `somma / N` è una **divisione intera** (20 / 3 = 6, la parte decimale viene troncata). Il fatto che la funzione restituisca `double` non aiuta: la divisione è già stata fatta tra interi, poi il 6 viene convertito in 6.0.

**Correzione** (basta che uno dei due operandi sia `double`):
```cpp
double media(int v[]) {
    double somma = 0;          // oppure: return (double) somma / N;
    for (int i = 0; i < N; i++)
        somma += v[i];
    return somma / N;
}
```

### b) Massimo inizializzato a 0
**Restituisce:** `0` — che **non è nemmeno nell'array**!

**Perché:** `max` parte da 0; tutti i valori sono negativi quindi nessuno è `> 0` e `max` non viene mai aggiornato.

**Correzione:** inizializzare con il **primo elemento** dell'array:
```cpp
int massimo(int v[], int n) {
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;      // con {-5,-2,-9,-3} restituisce -2
}
```

### c) Stringhe confrontate con `==`
**Cosa succede:** stampa `Accesso negato` anche se si scrive `admin`.

**Perché:** in Java `==` tra oggetti (e `String` è un oggetto) confronta i **riferimenti** (se sono lo stesso oggetto in memoria), non il contenuto. La stringa letta da tastiera è un oggetto diverso dal letterale `"admin"`.

**Correzione:**
```java
if (utente.equals("admin"))
```

---

## Esercizio 4 – Cosa stampa?

### a) `f(5)` → `Risultato: 15`
```
f(5) = 5 + f(4)
     = 5 + 4 + f(3)
     = 5 + 4 + 3 + f(2)
     = 5 + 4 + 3 + 2 + f(1)
     = 5 + 4 + 3 + 2 + 1 + f(0)      f(0) = 0 (caso base)
     = 15
```
Somma dei numeri da 1 a n.

### b) → `x = 81, conta = 4`
| giro | x prima | condizione x<50 | x dopo | conta |
|------|---------|-----------------|--------|-------|
| 1 | 1  | vera  | 3  | 1 |
| 2 | 3  | vera  | 9  | 2 |
| 3 | 9  | vera  | 27 | 3 |
| 4 | 27 | vera  | 81 | 4 |
| –  | 81 | **falsa** → esco | | |

Trappola: x supera 50 (vale 81) perché il controllo si fa **prima** della moltiplicazione.

### c) → `3 6`
`a` è passato **per valore** (copia: `p` resta 3), `b` **per riferimento** (`&`: `q` diventa 6).

### d) → `2 111`
- `i += 2` → controllo solo le posizioni pari: 0 `I`, 2 `f`, 4 `r`, 6 `a`, 8 `i`, 10 `a` → 2 caratteri `'a'`/`'o'` → `c = 2`. (La `o` è in posizione 3, dispari: saltata!)
- `c + " " + s.length() + 1`: si valuta da sinistra a destra. `2 + " "` → `"2 "` (diventa stringa), poi `+ 11` → `"2 11"`, poi `+ 1` → `"2 111"`. **Non** 12!
