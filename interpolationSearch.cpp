/*La ricerca per interpolazione è un miglioramento rispetto alla ricerca binaria per casi in cui i valori in un array ordinato sono distribuiti uniformemente.
L'interpolazione costruisce nuovi punti di dati all'interno dell'intervallo di un insieme discreto di punti di dati noti. 
La ricerca binaria va sempre all'elemento centrale per verificare. 
D'altra parte, la ricerca per interpolazione può andare in posizioni diverse a seconda del valore della chiave che viene cercata. 
Ad esempio, se il valore della chiave è più vicino all'ultimo elemento, è probabile che la ricerca per interpolazione inizi la ricerca verso la fine.*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
int interpolationSearch(T arr[], int lo, int hi, int x) {
    int pos;

    // Poiché l'array è ordinato, un elemento presente
    // nell'array deve essere nell'intervallo definito da corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

        // Sondare la posizione
        pos = lo
            + ((double)(hi - lo) / (arr[hi] - arr[lo]))
            * (x - arr[lo]);

        // Condizione del target trovato
        if (arr[pos] == x) {
            return pos;
        }

        // Se x è più grande, x è nel sottoarray destro
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, hi, x);
        }

        // Se x è più piccolo, x è nel sottoarray sinistro
        if (arr[pos] > x) {
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;
}