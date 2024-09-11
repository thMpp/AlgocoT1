#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "insertionsort.cpp"
#include "quicksort.cpp"
#include "mergesort.cpp"
using namespace std;
using namespace std::chrono;

vector<int> leerDatos(const string& nombreArchivo) {
    ifstream datos(nombreArchivo);  
    int tam;
    datos >> tam;  // Leer el tamaño del arreglo
    vector<int> arr(tam);
    for (int i = 0; i < tam; i++) {
        datos >> arr[i];  // Leer cada valor
    }
    datos.close(); 
    return arr;  // Retorna el vector con los datos
}

void escribirResultado(ofstream& archivo, const string& nombreAlgoritmo, const vector<int>& arr) {
    archivo << "Resultado Ordenamiento " << nombreAlgoritmo << endl;
    
    archivo << "[";
    for (int i = 0; i < arr.size(); i++) {
        archivo << arr[i];
        if (i < arr.size() - 1) {
            archivo << ",";
        }
    }
    archivo << "]" << endl << endl;
    
}


int main() {

    ofstream resultados("resultados.txt");  /* Archivo donde escribir los vectores ya ordenados,
    recomendación usar un array pequeño si se quiere comparar que todos los ordenamientos
    sean iguales */

    vector<int> arr,arr2,arr3,arr4,arr5,arr6,arr7,arr8,arr9,arr10,arr11,arr12;
    duration<double> tiempo_ejecucion,tiempo_ejecucion2,tiempo_ejecucion3,tiempo_ejecucion4,tiempo_ejecucion5,tiempo_ejecucion6,tiempo_ejecucion7,tiempo_ejecucion8,tiempo_ejecucion9,tiempo_ejecucion10,tiempo_ejecucion11,tiempo_ejecucion12;
    vector<int> arr0 = leerDatos("aleatorios.txt");
    vector<int> arr13 = leerDatos("semiorden.txt");
    vector<int> arr14 = leerDatos("orden.txt");
    for(int i = 0; i < 10; i++){

    arr = arr0;
    arr2 = arr0;
    arr3 = arr0;
    arr4 = arr0;
    arr5 = arr13;
    arr6 = arr13;
    arr7 = arr13;
    arr8 = arr13;
    arr9 = arr14;
    arr10 = arr14;
    arr11 = arr14;
    arr12 = arr14;

    // Ordenamiento InsertionSort
    auto inicio = high_resolution_clock::now();  // Tiempo inicial
    insertionSort(arr);
    auto fin = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion += duration_cast<duration<double>>(fin - inicio);

    // Ordenamiento MergeSort
    auto inicio2 = high_resolution_clock::now();  // Tiempo inicial
    mergeSort(arr2, 0, arr2.size()-1);
    auto fin2 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion2 += duration_cast<duration<double>>(fin2 - inicio2);

    // Ordenamiento QuickSort
    auto inicio3 = high_resolution_clock::now();  // Tiempo inicial
    quickSort(arr3, 0, arr3.size()-1);
    auto fin3 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion3 += duration_cast<duration<double>>(fin3 - inicio3);

    // Ordenamiento std::sort
    auto inicio4 = high_resolution_clock::now();  // Tiempo inicial
    sort(arr4.begin(), arr4.end());
    auto fin4 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion4 += duration_cast<duration<double>>(fin4 - inicio4);

    // SemiOrdenados InsertionSort
    auto inicio5 = high_resolution_clock::now();  // Tiempo inicial
    insertionSort(arr5);
    auto fin5 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion5 += duration_cast<duration<double>>(fin5 - inicio5);

    // SemiOrdenados MergeSort
    auto inicio6 = high_resolution_clock::now();  // Tiempo inicial
    mergeSort(arr6, 0, arr6.size()-1);
    auto fin6 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion6 += duration_cast<duration<double>>(fin6 - inicio6);

    // SemiOrdenados QuickSort
    auto inicio7 = high_resolution_clock::now();  // Tiempo inicial
    quickSort(arr7, 0, arr7.size()-1);
    auto fin7 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion7 += duration_cast<duration<double>>(fin7 - inicio7);

    // SemiOrdenados std::sort
    auto inicio8 = high_resolution_clock::now();  // Tiempo inicial
    sort(arr8.begin(), arr8.end());
    auto fin8 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion8 += duration_cast<duration<double>>(fin8 - inicio8);
    
    // Ordenados InsertionSort
    auto inicio9 = high_resolution_clock::now();  // Tiempo inicial
    insertionSort(arr9);
    auto fin9 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion9 += duration_cast<duration<double>>(fin9 - inicio9);

    // Ordenados MergeSort
    auto inicio10 = high_resolution_clock::now();  // Tiempo inicial
    mergeSort(arr10, 0, arr10.size()-1);
    auto fin10 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion10 += duration_cast<duration<double>>(fin10 - inicio10);

    // Ordenados QuickSort
    auto inicio11 = high_resolution_clock::now();  // Tiempo inicial
    quickSort(arr11, 0, arr11.size()-1);
    auto fin11 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion11 += duration_cast<duration<double>>(fin11 - inicio11);

    // Ordenados std::sort
    auto inicio12 = high_resolution_clock::now();  // Tiempo inicial
    sort(arr12.begin(), arr12.end());
    auto fin12 = high_resolution_clock::now();  // Tiempo final
    tiempo_ejecucion12 += duration_cast<duration<double>>(fin12 - inicio12);
    }
    
    cout << "Tiempo de ejecucion InsertionSort: " << tiempo_ejecucion.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "Insertion", arr);

    cout << "Tiempo de ejecucion MergeSort: " << tiempo_ejecucion2.count() /10 << " segundos." << endl;
    escribirResultado(resultados, "Merge", arr2);

    cout << "Tiempo de ejecucion QuickSort: " << tiempo_ejecucion3.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "Quick", arr3);

    cout << "Tiempo de ejecucion stdSort: " << tiempo_ejecucion4.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "stdSort", arr4);

    resultados << "----------------------------------------------------------------" << endl;
    resultados << "Pasando con SemiOrdenados" << endl;
    resultados << "----------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Pasando con SemiOrdenados" << endl;
    cout << "----------------------------------------------------------------" << endl;

    cout << "Tiempo de ejecucion InsertionSort: " << tiempo_ejecucion5.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "Insertion", arr5);

    cout << "Tiempo de ejecucion MergeSort: " << tiempo_ejecucion6.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "Merge", arr6);

    cout << "Tiempo de ejecucion QuickSort: " << tiempo_ejecucion7.count() / 10  << " segundos." << endl;
    escribirResultado(resultados, "Quick", arr7);

    cout << "Tiempo de ejecucion stdSort: " << tiempo_ejecucion8.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "stdSort", arr8);

    resultados << "----------------------------------------------------------------" << endl;
    resultados << "Pasando con Ordenados" << endl;
    resultados << "----------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Pasando con Ordenados" << endl;
    cout << "----------------------------------------------------------------" << endl;

    cout << "Tiempo de ejecucion InsertionSort: " << tiempo_ejecucion9.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "Insertion", arr9);

    cout << "Tiempo de ejecucion MergeSort: " << tiempo_ejecucion10.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "Merge", arr10);

    cout << "Tiempo de ejecucion QuickSort: " << tiempo_ejecucion11.count() / 10  << " segundos." << endl;
    escribirResultado(resultados, "Quick", arr11);

    cout << "Tiempo de ejecucion stdSort: " << tiempo_ejecucion12.count() / 10 << " segundos." << endl;
    escribirResultado(resultados, "stdSort", arr12);
    resultados.close();
    return 0;
}


