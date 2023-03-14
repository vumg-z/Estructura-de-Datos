#include <iostream>
#include <cstdlib> // Necesario para utilizar la función rand()
#include <chrono>  // Necesario para medir tiempo

void arrayFiller(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Genera un número aleatorio entre 0 y 999
    }
}

void merge(int* arr, int left, int middle, int right) {
    int size_left = middle - left + 1;
    int size_right = right - middle;

    int* left_arr = new int[size_left];
    int* right_arr = new int[size_right];

    for (int i = 0; i < size_left; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < size_right; j++)
        right_arr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < size_left && j < size_right) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < size_left) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < size_right) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void mergeSort(int* arr, int left_index, int right_index) {
    if (left_index < right_index) {
        int middle_index = left_index + (right_index - left_index) / 2;

        // Ordenar los primeros y segundos subarreglos
        mergeSort(arr, left_index, middle_index);
        mergeSort(arr, middle_index + 1, right_index);

        // Combinar los subarreglos ordenados en uno solo
        merge(arr, left_index, middle_index, right_index);
    }
}

int main() {
    int n = 1000000; // Tamaño del arreglo
    int* arr = new int[n]; // Declaración del arreglo dinámico

    // Llamada a la función arrayFiller para llenar el arreglo con elementos aleatorios
    arrayFiller(arr, n);

    // Medir el tiempo de ejecución de mergeSort
    auto start = std::chrono::high_resolution_clock::now(); // Tiempo de inicio
    mergeSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now(); // Tiempo de finalización

    // Calcular el tiempo total de ejecución en segundos
    std::chrono::duration<double> elapsed_time = end - start;
    double seconds = elapsed_time.count();

    // Imprimir el arreglo ordenado y el tiempo de ejecución
    /*for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }*/
    std::cout << std::endl << "Tiempo de ejecucion: " << seconds << " segundos" << std::endl;

    delete[] arr; // Liberación de la memoria asignada
    return 0;
}