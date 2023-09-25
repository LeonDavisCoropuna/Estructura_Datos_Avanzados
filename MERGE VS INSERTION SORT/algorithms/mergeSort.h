#include <iostream>
#include <vector>

using namespace std;

// Función para combinar dos subvectores ordenados en uno solo
void merge(vector<double> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear vectores temporales
    vector<int> L(n1);
    vector<int> R(n2);

    // Copiar datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    // Combinar los vectores temporales de nuevo en arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(vector<double> &arr, int left, int right)
{
    if (left < right)
    {
        // Encuentra el punto medio del vector
        int mid = left + (right - left) / 2;

        // Ordena la primera mitad y la segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combina las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}
