# "Cosa stampa?" — i due esercizi che mi hai mandato

## 1) `misterioso(4)` in C++ (ricorsione)

```cpp
int misterioso(int n){
  if (n<=1) return 1;          // caso base
  return n*misterioso(n-1);    // passo ricorsivo
}
```

**Stampa:** `Risultato: 24`

**Ragionamento:** la funzione richiama sé stessa con `n-1` finché `n` arriva a 1 (caso base, restituisce 1). Poi le chiamate "tornano indietro" moltiplicando:

```
misterioso(4) = 4 * misterioso(3)
              = 4 * 3 * misterioso(2)
              = 4 * 3 * 2 * misterioso(1)
              = 4 * 3 * 2 * 1 = 24
```

È il **fattoriale** di n (4! = 24).

> Trucco per la verifica: scrivi sempre la "scala" delle chiamate come sopra. Il prof vuole vedere che hai capito il **caso base** e il **passo ricorsivo**.

---

## 2) Ciclo con `%` in Java

Il testo che hai incollato ha un problema: la `println` è **dentro** il `for` e manca una `}` (graffe sbilanciate → **errore di compilazione**). Conviene scriverlo nella risposta! Poi si ragiona sulle due versioni che il prof potrebbe aver voluto.

### Tabella di traccia (la cosa più importante da saper fare)

| i | i%2==0 ? | operazione | somma |
|---|----------|------------|-------|
| – | –        | inizio     | 0     |
| 1 | no (dispari) | somma -= 1 | -1 |
| 2 | sì (pari)    | somma += 2 | 1  |
| 3 | no           | somma -= 3 | -2 |
| 4 | sì           | somma += 4 | 2  |
| 5 | no           | somma -= 5 | **-3** |

**Versione A – `println` FUORI dal for** (quella "giusta" visto il testo "somma finale"):
```
somma finale: -3
```

**Versione B – `println` DENTRO il for** (come è indentato nel testo):
```
somma finale: -1
somma finale: 1
somma finale: -2
somma finale: 2
somma finale: -3
```

**Ragionamento:** `i%2==0` è vero se `i` è pari. I pari (2, 4) vengono sommati: +6. I dispari (1, 3, 5) sottratti: −9. Totale 6 − 9 = −3.

> Attenzione all'errore classico: in Java `"somma: " + somma` concatena; se invece scrivi `"x" + 1 + 2` ottieni `"x12"`, non `"x3"`!
