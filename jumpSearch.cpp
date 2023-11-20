/*
Meglio della ricerca lineare per array dove gli elementi sono distribuiti uniformemente.
Ha una complessità temporale inferiore rispetto alla ricerca lineare per array di grandi dimensioni.
Il numero di passaggi eseguiti nel jump search è proporzionale alla radice quadrata della dimensione dell'array, rendendolo più efficiente per array di grandi dimensioni.
È più facile da implementare rispetto ad altri algoritmi di ricerca come la ricerca binaria o la ricerca ternaria.
Funziona bene per array in cui gli elementi sono in ordine e distribuiti uniformemente, 
poiché può saltare a una posizione più vicina nell'array ad ogni iterazione.
Funziona solo con array ordinati.
La dimensione ottimale di un blocco da saltare è (sqrt n). Ciò rende la complessità temporale di Jump Search O(sqrt n).
La complessità temporale di Jump Search è compresa tra Linear Search (O(n)) e Binary Search (O(Log n)).
La ricerca binaria è migliore del jump search, ma quest'ultimo ha il vantaggio di attraversare solo una volta all'indietro 
(la ricerca binaria potrebbe richiedere fino a O(Log n) salti.
Considera una situazione in cui l'elemento da cercare è l'elemento più piccolo o appena più grande del più piccolo).
Quindi, in un sistema in cui la ricerca binaria è costosa, utilizziamo Jump Search.
*/

#include <bits/stdc++.h>

template <typename T>
int jumpSearch(T arr[], int x, int n) {

    // Determinare la dimensione del blocco da saltare
    int step = sqrt(n);

    // Trovare il blocco in cui è presente l'elemento (se è presente)
    int prev = 0;
    while (arr[std::min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    // Eseguire una ricerca lineare per x nel blocco a partire da prev.
    while (arr[prev] < x) {
        prev++;

        // Se si raggiunge il blocco successivo o la fine dell'array, l'elemento non è presente.
        if (prev == std::min(step, n)) {
            return -1;
        }
    }

    // Se l'elemento viene trovato
    if (arr[prev] == x) {
        return prev;
    }
    
    return -1;
}
