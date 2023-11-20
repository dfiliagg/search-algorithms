/*La ricerca di Fibonacci ha una complessità temporale di O(log n).
È più efficiente della ricerca binaria per array di grandi dimensioni, ma è meno efficiente per array di piccole dimensioni.
La ricerca di Fibonacci è un algoritmo semplice da implementare e può essere utile per trovare elementi in array ordinati di grandi dimensioni.*/

#include <bits/stdc++.h>
using namespace std;

// Funzione di utilità per trovare il minimo di due elementi
template <typename T>
int fibonacci_min(T x, T y) { return (x <= y) ? x : y; }

/* Restituisce l'indice di x se presente, altrimenti restituisce -1 */
template <typename T>
int fibonacciSearch(T arr[], int x, int n) {

/* Inizializza i numeri di Fibonacci */
int fibMMm2 = 0; // m-2° numero di Fibonacci
int fibMMm1 = 1; // m-1° numero di Fibonacci
int fibM = fibMMm2 + fibMMm1; // m° numero di Fibonacci

/* fibM conterrà il numero di Fibonacci più piccolo maggiore o uguale a n */
while (fibM < n) {
    fibMMm2 = fibMMm1;
    fibMMm1 = fibM;
    fibM = fibMMm2 + fibMMm1;
}

// Segnala l'intervallo eliminato dalla parte anteriore
int offset = -1;

/* Fintanto che ci sono elementi da ispezionare. Nota che confrontiamo arr[fibMm2] con x. Quando fibM diventa 1, fibMm2 diventa 0 */
while (fibM > 1) {

    // Verifica se fibMm2 è una posizione valida
    int i = fibonacci_min(offset + fibMMm2, n - 1);

    /* Se x è maggiore del valore all'indice fibMm2, taglia il sottoarray arr da offset a i */
    if (arr[i] < x) {
        fibM = fibMMm1;
        fibMMm1 = fibMMm2;
        fibMMm2 = fibM - fibMMm1;
        offset = i;
    }

    /* Se x è maggiore del valore all'indice fibMm2, taglia il sottoarray dopo i+1 */
    else if (arr[i] > x) {
        fibM = fibMMm2;
        fibMMm1 = fibMMm1 - fibMMm2;
        fibMMm2 = fibM - fibMMm1;
    }

    /* Elemento trovato. Restituisce l'indice */
    else {
        return i;
    }
}

/* Confrontare l'ultimo elemento con x */
if (fibMMm1 && arr[offset + 1] == x) {
    return offset + 1;
}

/* Elemento non trovato. Restituisce -1 */
return -1;
}