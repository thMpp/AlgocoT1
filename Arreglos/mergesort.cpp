#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arrays Izquierda/Derecha auxiliares
    vector<int> L(n1), R(n2);

    // Mover los datos a izq o derecha según su posición
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Re-unir los vectores I/R en el inicial
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Asegura que no quede ninguno en I
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Asegura que no quede ninguno en R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// sortea el array arr separandolo por la mitad
//en Izquierda y Derecha, se llama así misma hasta 
//que en todas las sub-mitades los numeros en I sean < que los de D
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}