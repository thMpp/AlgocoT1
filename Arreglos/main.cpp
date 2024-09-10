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
    ifstream datos(nombreArchivo);  // Abrir el archivo
    if (!datos.is_open()) {  // Verificar si el archivo se abrió correctamente
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return {};  // Retornar un vector vacío en caso de error
    }
    int tam;
    datos >> tam;  // Leer el tamaño del arreglo
    vector<int> arr(tam);
    for (int i = 0; i < tam; i++) {
        datos >> arr[i];  // Leer cada valor
    }
    datos.close();  // Cerrar el archivo
    return arr;  // Retornar el vector lleno con los datos
}

void escribirResultado(ofstream& archivo, const string& nombreAlgoritmo, const vector<int>& arr) {
    archivo << "Resultado Ordenamiento " << nombreAlgoritmo << endl;
    archivo << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        archivo << arr[i];
        if (i < arr.size() - 1) {
            archivo << ",";
        }
    }
    archivo << "]" << endl << endl;
}


int main() {

    ofstream resultados("resultados.txt");  // Archivo para escribir los resultados

    // Ordenamiento InsertionSort
    vector<int> arr = leerDatos("datos.txt");
    auto inicio = high_resolution_clock::now();  // Tiempo inicial
    insertionSort(arr);
    auto fin = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion = duration_cast<duration<double>>(fin - inicio);
    cout << "Tiempo de ejecucion InsertionSort: " << tiempo_ejecucion.count() << " segundos." << endl;
    escribirResultado(resultados, "Insertion", arr);

    // Ordenamiento MergeSort
    vector<int> arr2 = leerDatos("datos.txt");
    auto inicio2 = high_resolution_clock::now();  // Tiempo inicial
    mergeSort(arr2, 0, arr2.size());
    auto fin2 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion2 = duration_cast<duration<double>>(fin2 - inicio2);
    cout << "Tiempo de ejecucion MergeSort: " << tiempo_ejecucion2.count() << " segundos." << endl;
    escribirResultado(resultados, "Merge", arr2);

    // Ordenamiento QuickSort
    vector<int> arr3 = leerDatos("datos.txt");
    auto inicio3 = high_resolution_clock::now();  // Tiempo inicial
    quickSort(arr3, 0, arr3.size());
    auto fin3 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion3 = duration_cast<duration<double>>(fin3 - inicio3);
    cout << "Tiempo de ejecucion QuickSort: " << tiempo_ejecucion3.count() << " segundos." << endl;
    escribirResultado(resultados, "Quick", arr3);

    // Ordenamiento std::sort
    vector<int> arr4 = leerDatos("datos.txt");
    auto inicio4 = high_resolution_clock::now();  // Tiempo inicial
    sort(arr4.begin(), arr4.end());
    auto fin4 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion4 = duration_cast<duration<double>>(fin4 - inicio4);
    cout << "Tiempo de ejecucion stdSort: " << tiempo_ejecucion4.count() << " segundos." << endl;
    escribirResultado(resultados, "stdSort", arr4);

    resultados << "----------------------------------------------------------------" << endl;
    resultados << "Pasando con SemiOrdenados" << endl;
    resultados << "----------------------------------------------------------------" << endl;

    // SemiOrdenados InsertionSort
    vector<int> arr5 = leerDatos("semiorden.txt");
    auto inicio5 = high_resolution_clock::now();  // Tiempo inicial
    insertionSort(arr5);
    auto fin5 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion5 = duration_cast<duration<double>>(fin5 - inicio5);
    cout << "Tiempo de ejecucion InsertionSort: " << tiempo_ejecucion5.count() << " segundos." << endl;
    escribirResultado(resultados, "Insertion (SemiOrdenados)", arr5);

    // SemiOrdenados MergeSort
    vector<int> arr6 = leerDatos("semiorden.txt");
    auto inicio6 = high_resolution_clock::now();  // Tiempo inicial
    mergeSort(arr6, 0, arr6.size());
    auto fin6 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion6 = duration_cast<duration<double>>(fin6 - inicio6);
    cout << "Tiempo de ejecucion MergeSort: " << tiempo_ejecucion6.count() << " segundos." << endl;
    escribirResultado(resultados, "Merge (SemiOrdenados)", arr6);

    // SemiOrdenados QuickSort
    vector<int> arr7 = leerDatos("semiorden.txt");
    auto inicio7 = high_resolution_clock::now();  // Tiempo inicial
    quickSort(arr7, 0, arr7.size());
    auto fin7 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion7 = duration_cast<duration<double>>(fin7 - inicio7);
    cout << "Tiempo de ejecucion QuickSort: " << tiempo_ejecucion7.count() << " segundos." << endl;
    escribirResultado(resultados, "Quick (SemiOrdenados)", arr7);

    // SemiOrdenados std::sort
    vector<int> arr8 = leerDatos("semiorden.txt");
    auto inicio8 = high_resolution_clock::now();  // Tiempo inicial
    sort(arr8.begin(), arr8.end());
    auto fin8 = high_resolution_clock::now();  // Tiempo final
    duration<double> tiempo_ejecucion8 = duration_cast<duration<double>>(fin8 - inicio8);
    cout << "Tiempo de ejecucion stdSort: " << tiempo_ejecucion8.count() << " segundos." << endl;
    escribirResultado(resultados, "stdSort (SemiOrdenados)", arr8);

    resultados.close();  // Cerrar el archivo de resultados
    return 0;
}


