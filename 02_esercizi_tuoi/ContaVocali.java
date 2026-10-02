import java.util.Scanner;

/*
 * ContaVocali - versione CORRETTA.
 *
 * ERRORE nel codice originale:
 *   System.out.println("Numero di vocali: " << conteggio);
 * In Java NON esiste << per stampare (quello e' il cout del C++).
 * In Java le stringhe si concatenano con il +.
 * (In Java << esiste, ma e' lo shift di bit tra numeri: tra String e int
 *  da' errore di compilazione.)
 */
public class ContaVocali {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Inserisci una frase: ");
        String frase = input.nextLine();

        int conteggio = 0;

        for (int i = 0; i < frase.length(); i++) {
            // porto il carattere in minuscolo cosi' conto anche A, E, I, O, U
            char c = Character.toLowerCase(frase.charAt(i));
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                conteggio++;
            }
        }

        System.out.println("Numero di vocali: " + conteggio);   // + e non <<
        input.close();
    }
}
