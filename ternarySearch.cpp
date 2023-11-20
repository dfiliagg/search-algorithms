/*È lo stesso della ricerca binaria. L'unica differenza è che riduce ulteriormente la complessità temporale. 
l'algoritmo prevede passaggi "N". L'intervallo ricercabile sarebbe la dimensione = 3^N. 
Al contrario, il numero di passaggi necessari per trovare l'elemento è pari al logaritmo della dimensione della raccolta. 
Quindi il tempo di esecuzione è O(log N base 3).
La complessità temporale per la ricerca ternaria è in media O (log N base 3 ).
La complessità temporale nel caso migliore è O(1) e la complessità nel caso peggiore è O (log N in base 3).*/

template <typename T>
int ternarySearch(int l, int r, int key, T arr[]) {

    while (r >= l) {

        // Calcola i valori di mid1 e mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Controlla se la chiave è presente in uno qualsiasi dei valori medi
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        // Poiché la chiave non è presente nei valori medi,
        // controlla in quale regione si trova la chiave
        // quindi ripeti l'operazione di ricerca
        // in quella regione

        if (key < arr[mid1]) {

            // La chiave si trova tra l e mid1
            r = mid1 - 1;
        }
        else if (key > arr[mid2]) {

            // La chiave si trova tra mid2 e r
            l = mid2 + 1;
        }
        else {

            // La chiave si trova tra mid1 e mid2
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    // La chiave non è stata trovata
    return -1;
}
