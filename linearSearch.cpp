/*Questi algoritmi esaminano ogni elemento della struttura dati alla ricerca del valore desiderato. 
Gli algoritmi di ricerca lineare sono semplici da implementare, 
ma hanno una complessità temporale pari a O(n), dove n è la dimensione della struttura dati.*/

template <typename T>
int linearSearch(T *arr, int n, T x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}