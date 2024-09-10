#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int low, int high) {

    // Selecciona el último elemento como pivote
    int pivot = vec[high];

    // Posición del penultimo elemento
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // Si el elemento es menor o igual al pivote
        // se hace el cambio
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Coloca el pivote en su posición
    swap(vec[i + 1], vec[high]);

    // Retorna el punto de partición
    return (i + 1);
    }

    void quickSort(vector<int> &vec, int low, int high) {

        // Esta parte se ejecutará mientras el índice inicial
        // low sea menor que el índice final high
        if (low < high) {

            // pi es la posicion donde se particiona,  
            // el elemento arr[p] ahora está en la posición correcta
            int pi = partition(vec, low, high);

            // Ordena separadamente los elementos antes y después del
            // Índice de Partición pi
            quickSort(vec, low, pi - 1);
            quickSort(vec, pi + 1, high);
        }
}