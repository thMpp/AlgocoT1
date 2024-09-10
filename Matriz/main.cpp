#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "strassen.cpp"
using namespace std;
using namespace std::chrono;


int main(){
    ifstream datos("matriz.txt");  
    int n, m;
    datos >> n >> m; //dimensiones de M1
    vector<vector<int>> M1(n, vector<int>(m)); //matriz M1 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            datos >> M1[i][j];
        }
    }
    datos.close();

    ifstream datos2("matriz2.txt");
    int n2, m2; //dimensions de M2
    datos2 >> n2 >> m2;
    vector<vector<int>> M2(n2, vector<int>(m2));  // matriz M2
    vector<vector<int>> MT(n2, vector<int>(m2));  // MT será la traspuesta de M2
    for (int i = 0; i < n2; i++){
        for (int j = 0; j < m2; j++){
            datos2 >> M2[i][j];
            MT[j][i] = M2[i][j];  //se intercambian i por j y se obtiene MT con M2
    }
    }
    datos2.close();
    vector<vector<int>> M3(n, vector<int>(m2));   
    vector<vector<int>> M4(n, vector<int>(m2));   
    vector<vector<int>> result_matrix(n, vector<int>(m2));

    /*Como solo nos interesa el tiempo de los algoritmos, la generación de matrices
    junto con la recolección de datos y obtener la traspuesta no fue medido*/

    // Multiplicación normal
    duration<double> tiempo_ejecucion(0), tiempo_ejecucion2(0), tiempo_ejecucion3(0);
    for(int h = 0; h < 10; h++){ //se hace un ciclo de 10 veces para obtener el tiempo promedio
        fill(M3.begin(), M3.end(), vector<int>(m2, 0)); //se setean las matriz resultado llenas de 0
        fill(M4.begin(), M4.end(), vector<int>(m2, 0)); 
        fill(result_matrix.begin(), result_matrix.end(), vector<int>(m2, 0));

        auto inicio = high_resolution_clock::now();  // Tiempo inicial
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m2; j++){
                for(int k = 0; k < n2; k++){
                    M3[i][j] += M1[i][k] * M2[k][j]; 
                }
            }
        }
        auto fin = high_resolution_clock::now();  // Tiempo final
        tiempo_ejecucion += duration_cast<duration<double>>(fin - inicio);

        // Multiplicación con la transpuesta
        auto inicio2 = high_resolution_clock::now();  // Tiempo inicial
        for (int i = 0; i < n; i++) {         
            for (int j = 0; j < m2; j++) {    
                for (int k = 0; k < m; k++) { 
                    M4[i][j] += M1[i][k] * MT[j][k];
                }
            }
        }
        auto fin2 = high_resolution_clock::now();  // Tiempo final
        tiempo_ejecucion2 += (fin2 - inicio2);

        //Strassen sacado de geeksforgeeks
        auto inicio3 = high_resolution_clock::now();  // Tiempo inicial
        result_matrix = multiply_matrix(M1, M2);
        auto fin3 = high_resolution_clock::now();  // Tiempo final
        tiempo_ejecucion3 += (fin3 - inicio3);

    }
    cout << "Tiempo promedio de ejecucion Multiplicacion normal: " << tiempo_ejecucion.count() / 10 << " segundos." << endl;
    cout << "Tiempo promedio de ejecucion Multiplicacion con transpuesta: " << tiempo_ejecucion2.count() / 10 << " segundos." << endl;
    cout << "Tiempo promedio de ejecucion Strassen: " << tiempo_ejecucion3.count() / 10 << " segundos." << endl;
    
    
    ofstream resultado_normal("resultado_normal.txt");
    resultado_normal << "Multiplicacion Normal:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m2; j++) {
            resultado_normal << M3[i][j] << " ";
        }
        resultado_normal << "\n";
    }
    resultado_normal.close();

    ofstream resultado_transpuesta("resultado_traspuesta.txt");
    resultado_transpuesta << "Multiplicacion por Transpuesta:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m2; j++) {
            resultado_transpuesta << M4[i][j] << " ";
        }
        resultado_transpuesta << "\n";
    }
    resultado_transpuesta.close();

    ofstream resultado_strassen("resultado_strassen.txt");
    resultado_strassen << "Multiplicacion por Transpuesta:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m2; j++) {
            resultado_strassen << result_matrix[i][j] << " ";
        }
        resultado_strassen << "\n";
    }
    resultado_strassen.close();
    return 0;
}
