/*Questi algoritmi utilizzano la ricorsione per cercare il valore desiderato. L'algoritmo inizia esaminando il primo elemento della struttura dati. 
Se viene trovato il valore desiderato, l'algoritmo termina. 
Altrimenti l'algoritmo si richiama ricorsivamente per cercare il valore desiderato nella restante parte della struttura dati.*/

template <typename T>
int recursiveSearch(T arr[], int n, T x) {
  if (n == 0) {
    return -1;
  }

  int mid = (n - 1) / 2;

  if (arr[mid] == x) {
    return mid;
  } else if (arr[mid] < x) {
    return recursiveSearch(arr + mid + 1, n - mid - 1, x);
  } else {
    return recursiveSearch(arr, mid, x);
  }
}