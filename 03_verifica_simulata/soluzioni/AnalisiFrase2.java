/*
 * SOLUZIONE Esercizio 2 - Analisi di una frase, parte 2 (Java)
 */
public class AnalisiFrase2 {

    // true se c e' una vocale minuscola
    public static boolean eVocale(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    // Conta le consonanti: lettere che non sono vocali
    public static int contaConsonanti(String frase) {
        String f = frase.toLowerCase();
        int cont = 0;
        for (int i = 0; i < f.length(); i++) {
            char c = f.charAt(i);
            if (c >= 'a' && c <= 'z' && !eVocale(c)) {   // e' una lettera E non e' vocale
                cont++;
            }
        }
        return cont;
    }

    // Conta quante volte compare il carattere c (senza distinguere maiuscole/minuscole)
    public static int contaCarattere(String frase, char c) {
        String f = frase.toLowerCase();
        char cercato = Character.toLowerCase(c);
        int cont = 0;
        for (int i = 0; i < f.length(); i++) {
            if (f.charAt(i) == cercato) {
                cont++;
            }
        }
        return cont;
    }

    // Restituisce la frase al contrario: scorro dall'ultimo carattere al primo
    public static String inverti(String frase) {
        String risultato = "";
        for (int i = frase.length() - 1; i >= 0; i--) {
            risultato = risultato + frase.charAt(i);
        }
        return risultato;
    }

    // Restituisce la parola piu' lunga (la prima in caso di parita')
    public static String parolaPiuLunga(String frase) {
        String[] parole = frase.trim().split(" ");
        String piuLunga = parole[0];
        for (int i = 1; i < parole.length; i++) {
            if (parole[i].length() > piuLunga.length()) {   // > e non >= : in parita' tengo la prima
                piuLunga = parole[i];
            }
        }
        return piuLunga;
    }

    public static void analizza(String frase) {
        System.out.println("Frase: \"" + frase + "\"");
        System.out.println("  Consonanti: " + contaConsonanti(frase));
        System.out.println("  Quante 'a': " + contaCarattere(frase, 'a'));
        System.out.println("  Al contrario: " + inverti(frase));
        System.out.println("  Parola piu' lunga: " + parolaPiuLunga(frase));
    }

    public static void main(String[] args) {
        analizza("Oggi ho la verifica di Informatica");
        analizza("Ama Roma");
    }
}
