#include <iostream>
#include <vector>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;

int partition(vector<int> &vec, int low, int high) {
    // Selecciona un pivote aleatorio
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = vec[pivotIndex];
    swap(vec[pivotIndex], vec[high]); // Mueve el pivote al final

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
