// Burbuha.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Array {
private:
    int arr[50];
    int size;
    friend class Burbuja;
public:

    Array() : arr{}, size{} {}
    
    int getSize() {
        return size;
    }

    void setSize() {

        int inputNum;
        bool validInput = false;
        bool printMessage = true;

        cout << "ingresa el tamano del array";

        while (!validInput) {
            if (printMessage) {
                cout << " (ingresa un numero entre 0 y 50): " << endl;
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
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida. Por favor ingresa un numero valido: ";
                }
            }
        }
    }

    void printArray() {
        cout << "Arreglo: \n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

class Burbuja : public Array {

public:

    void burbujaSort() {
        for (int i = 0; i < size -1; i++) {
            if (arr[i] > arr[i + 1]) {
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
          }
    }


};

int main()
{
    Burbuja array;
    array.setSize();

    array.agregarNumeros();
    array.burbujaSort();
    array.printArray();
}

