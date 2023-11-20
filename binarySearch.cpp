/*Questi algoritmi funzionano su strutture di dati ordinate. 
L'algoritmo parte dal centro della struttura dati e poi la divide a metà, esaminando prima la metà inferiore e poi quella superiore, 
fino a trovare il valore desiderato. Gli algoritmi di ricerca binaria hanno una complessità temporale pari a O(log n).
Risulta molto più veloce degli algoritmi di ricerca lineare per dati di grandi dimensioni.*/

template <typename T>
int binarySearch(T *arr, int n, T x) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}