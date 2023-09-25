#include <iostream>
#include "algorithms/intertionSort.h"
#include "algorithms/mergeSort.h"
#include <random>
#include <cmath>
#include <chrono>
#include <fstream>
using namespace std;
using namespace chrono;
int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-10000, 10000);
    ofstream archivoMerge("data/merge.txt");
    ofstream archivoInsertion("data/insertion.txt");
    vector<int> longitud = {10, 200, 1000, 5000, 10000, 20000, 50000};

    for (int i = 0; i < longitud.size(); i++)
    {
        vector<double> mergeArray;
        vector<double> insertionArray;

        for (int j = 0; j < longitud[i]; ++j)
        {
            double punto = dis(gen);
            mergeArray.push_back(punto);
            insertionArray.push_back(punto);
        }

        auto start1 = high_resolution_clock::now();
        mergeSort(mergeArray, 0, longitud[i] - 1);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        cout << "Tiempo de ejecución con n = " << longitud[i] << endl;
        cout << "MergeSort: " << duration1.count() << " microsegundos" << endl;
        archivoMerge << duration1.count() << endl;
        auto start2 = high_resolution_clock::now();
        insertionSort(insertionArray);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout << "InsertionSort: " << duration2.count() << " microsegundos" << endl
             << endl;
        archivoInsertion << duration2.count() << endl;
    }

    return 0;
}