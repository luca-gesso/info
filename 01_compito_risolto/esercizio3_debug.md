# Esercizio 3 – Debug (soluzione)

## a) C++ – `scambia` non scambia

**Output reale:** `x = 10, y = 20`

**Perché:** `scambia(int a, int b)` riceve i parametri **per valore**: `a` e `b` sono **copie** di `x` e `y`. La funzione scambia le copie, che spariscono quando la funzione termina; `x` e `y` nel main restano uguali.

**Correzione:** passaggio **per riferimento** con `&`:

```cpp
#include <iostream>
using namespace std;

void scambia(int &a, int &b) {   // & = lavoro sulle variabili originali
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    scambia(x, y);
    cout << "x = " << x << ", y = " << y << endl;   // x = 20, y = 10
    return 0;
}
```

> Ricorda: gli **array** in C++ invece sono già passati "per riferimento" (si passa l'indirizzo), per questo `inserisci(double v[])` modifica davvero l'array del main senza `&`.

## b) Java – somma dell'array

**Cosa succede:** il programma va in **errore a runtime**:
`ArrayIndexOutOfBoundsException: Index 6 out of bounds for length 6`. Non stampa nessuna somma.

**Perché:** l'array ha 6 elementi, indici **da 0 a 5**. La condizione `i <= numeri.length` fa arrivare `i` a 6, che non esiste (errore "off by one").

**Correzione:** `<` invece di `<=`:

```java
public class Debug {
    public static void main(String[] args) {
        int[] numeri = {4, 8, 15, 16, 23, 42};
        int somma = 0;
        for (int i = 0; i < numeri.length; i++) {
            somma += numeri[i];
        }
        System.out.println("Somma: " + somma);   // Somma: 108
    }
}
```
