// Seleccion_b.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <regex>

using namespace std;

class Seleccion {
private:
    int arr[50];
    int size;

public:
    Seleccion() {
        size = 0;
        arr[0] = 0;
    }

    void setSize(int s) {
        size = s;
    }

    void setElement(int index, int value) {
        arr[index] = value;
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
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida. Por favor ingresa un numero valido: ";
                }
            }
        }
    }

    int getSize() {
        return size;
    }

    int getElement(int index) {
        return arr[index];
    }

    void printArray() {
        cout << "\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void selectionSort() {
        int minIndex, aux;
        for (int i = 0; i < size - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                aux = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = aux;
            }
        }
    }

    void selectionSortIterative() {
        int minIndex, aux;
        printArray();
        for (int i = 0; i < size - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                aux = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = aux;
            }
            // Imprimir el arreglo después de cada iteración
            cout << "iteracion: " << i << ": ";
            printArray();
        }
    }
};

char charMenu() {

    char inputChar;
    bool validInput = false;
    bool printMessage = true;

    // Ordenar áun conjunto de números enteros,la cantidad mínima deberá ser 1 y
    // el máximo 50.

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

int intMenu() {
    int inputNum;
    bool validInput = false;
    bool printMessage = true;

    cout << "ingresa cuantos datos quieres ordenar" << endl;

    while (!validInput) {
        if (printMessage) {
            cout << "Ingresa un numero entre 0 y 50: " << endl;
        }

        cin >> inputNum;

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

    return inputNum;
}

int main()
{
    // tamaño del arreglo
    int size;
    size = intMenu();

    Seleccion myArray;
    myArray.setSize(size);

    // ingresar numeros 
    myArray.agregarNumeros();


    // mostrar iteraciones o directo
    char input;
    input = charMenu();

    if (input == 'a') {
        myArray.selectionSort();
        myArray.printArray();
    }
    else {
        myArray.selectionSortIterative();
    }
}

