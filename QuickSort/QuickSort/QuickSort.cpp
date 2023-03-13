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

    void quickSort(int left, int right) {
        int i = left, j = right;
        int pivot = arr[left]; // Pivote es el primer elemento del arreglo

        while (i <= j) {
            while (arr[i] < pivot)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quickSort(left, j);

        if (i < right)
            quickSort(i, right);
    }

    void quickSortIterative(int left, int right, int& iteration) {
        int i = left, j = right;
        int pivot = arr[left];

        cout << "Iteracion " << iteration << ": ";
        printArray(size);

        while (i <= j) {
            while (arr[i] < pivot)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quickSortIterative(left, j, ++iteration);

        if (i < right)
            quickSortIterative(i, right, ++iteration);
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
        myArray.quickSort(0, myArray.size);
        myArray.printArray(myArray.size);
    }
    else {
        int i = 0;
        myArray.quickSortIterative(0, myArray.size, i);
    }
}