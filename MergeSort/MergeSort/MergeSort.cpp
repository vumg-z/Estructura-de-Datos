#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Array {
public:
    int arr[50];
    int size;

    Array() : arr{}, size{} {}

    // Constructor
    Array(int arr_size) {
        if (arr_size > 50) {
            std::cout << "Error: tamaño de arreglo no válido\n";
            exit(1);
        }
    }

    void merge(int left, int middle, int right) {
        const int MAX_SIZE = 50;
        int size_left = middle - left + 1;
        int size_right = right - middle;

        int left_arr[MAX_SIZE], right_arr[MAX_SIZE];

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
    }

    void mergeSort(int left_index, int right_index) {
        if (left_index < right_index) {
            int middle_index = left_index + (right_index - left_index) / 2;

            // Ordenar los primeros y segundos subarreglos
            mergeSort(left_index, middle_index);
            mergeSort(middle_index + 1, right_index);

            // Combinar los subarreglos ordenados en uno solo
            merge(left_index, middle_index, right_index);
        }
    }

    void printArray(int size) {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

    void setSize() {
        int inputNum;
        bool validInput = false;
        bool printMessage = true;

        while (!validInput) {
            if (printMessage) {
                cout << "Ingresa el tamano del arreglo (un numero entre 0 y 50): ";
            }

            string input;
            cin >> input;

            bool isNumber = true;
            for (char c : input) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            if (!isNumber) {
                cout << "Error: Debe ingresar un numero." << endl;
                cin.clear();
                cin.ignore('\n');
            }
            else {
                inputNum = stoi(input);
                if (inputNum >= 1 && inputNum <= 50) {
                    validInput = true;
                }
                else {
                    if (printMessage) {
                        cout << "El numero no esta en el rango de 1 a 50." << endl;
                        printMessage = false;
                    }
                }
            }
        }
        this->size = inputNum;
    }

    void agregarNumeros() {
        for (int i = 0; i < size; i++) {
            bool validInput = false;
            int input;

            cout << "Ingresa el numero " << " " << ": ";
            while (!validInput) {
                if (cin >> input) {
                    validInput = true;
                    arr[i] = input;
                }
                else {
                    cin.clear();
                    cin.ignore('\n');
                    cout << "Entrada invalida. Por favor ingresa un numero valido: ";
                }
            }
        }
    }

    void mergeSortIterative(int left_index, int right_index, int& iter) {
        if (left_index < right_index) {
            int middle_index = left_index + (right_index - left_index) / 2;

            // Ordenar los primeros y segundos subarreglos
            mergeSortIterative(left_index, middle_index, iter);
            mergeSortIterative(middle_index + 1, right_index, iter);

            // Combinar los subarreglos ordenados en uno solo
            mergeIterative(left_index, middle_index, right_index, iter);
        }
    }

    void mergeIterative(int left, int middle, int right, int& iter) {
        const int MAX_SIZE = 50;
        int size_left = middle - left + 1;
        int size_right = right - middle;

        int left_arr[MAX_SIZE], right_arr[MAX_SIZE];

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

        cout << "Merge Iteracion " << iter << ": ";
        for (int n = left; n <= right; n++) {
            cout << arr[n] << " ";
        }
        cout << endl;
        iter++;
    }
};

char charMenu() {

    char inputChar;
    bool validInput = false;
    bool printMessage = true;

    cout << "A) ordenar directamente (menor a mayor)" << endl;
    cout << "B) ordenar mostrando iteraciones" << endl;

    while (!validInput) {

        if (printMessage)
            cout << "ingresa opcion: " << endl;

        cin >> inputChar;
        inputChar = tolower(inputChar);

        if (regex_match(string(1, inputChar), regex("[ab]"))) {
            validInput = true;
        }
        else {
            if (printMessage) {
                cout << "El caracter no es 'a', 'b'" << endl;
                printMessage = false;
            }
        }
    }

    return inputChar;
}

int main()
{
    // tamaño del arreglo
    
    Array myArray;
    myArray.setSize();

    // ingresar numeros 
    myArray.agregarNumeros();

    // mostrar iteraciones o directo
    char input;
    input = charMenu();

    if (input == 'a') {
        myArray.mergeSort(0, myArray.size-1);
        myArray.printArray(myArray.size);
    }
    else {
        int iter = 1;
        myArray.mergeSortIterative(0, myArray.size-1, iter);
        myArray.printArray(myArray.size);
    }
}
