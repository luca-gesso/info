/*
 * Esercizio 2 - Analisi di una frase (Java)
 * NB: in Java il nome del file DEVE essere uguale al nome della classe public.
 * Se il prof vuole "cognome_esercizio2.java" la classe va chiamata cognome_esercizio2.
 */
public class AnalisiFrase {

    // Conta le vocali (maiuscole e minuscole)
    public static int contaVocali(String frase) {
        String f = frase.toLowerCase();
        int cont = 0;
        for (int i = 0; i < f.length(); i++) {
            char c = f.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cont++;
            }
        }
        return cont;
    }

    // Conta le parole separate da spazi
    public static int contaParole(String frase) {
        String f = frase.trim();            // tolgo spazi iniziali/finali
        if (f.length() == 0) {
            return 0;                        // frase vuota: zero parole
        }
        String[] parole = f.split(" ");
        int cont = 0;
        for (int i = 0; i < parole.length; i++) {
            if (parole[i].length() > 0) {    // salto i "buchi" dovuti a doppi spazi
                cont++;
            }
        }
        return cont;
    }

    // true se la frase e' palindroma ignorando spazi e maiuscole
    public static boolean ePalindroma(String frase) {
        String f = frase.toLowerCase().replace(" ", "");
        int sx = 0;
        int dx = f.length() - 1;
        while (sx < dx) {
            if (f.charAt(sx) != f.charAt(dx)) {
                return false;                // appena trovo una differenza: non palindroma
            }
            sx++;
            dx--;
        }
        return true;
    }

    // Stampa tutti i risultati per una frase
    public static void analizza(String frase) {
        System.out.println("Frase: \"" + frase + "\"");
        System.out.println("  Vocali: " + contaVocali(frase));
        System.out.println("  Parole: " + contaParole(frase));
        System.out.println("  Palindroma: " + (ePalindroma(frase) ? "si" : "no"));
    }

    public static void main(String[] args) {
        analizza("Ciao Mondo");
        analizza("I topi non avevano nipoti");
        analizza("Anna");
    }
}
