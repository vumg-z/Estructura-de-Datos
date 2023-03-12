#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Persona {
private:
    int registro;
    char nombre[50];
    char apellido[50];
    int edad;

public:

    int getRegistro() const {
        return registro;
    }

    char* getNombre() {
        return nombre;
    }

    char* getApellido() {
        return apellido;
    }

    int getEdad() {
        return edad;
    }


    void print() {
        cout << "+------------------------------------+\n";
        cout << "| Registro: " << std::setw(10) << registro << "             \n";
        cout << "| Nombre: " << std::setw(14) << nombre << "           \n";
        cout << "| Apellido: " << std::setw(12) << apellido << "         \n";
        cout << "| Edad: " << std::setw(16) << edad << "                 \n";
        cout << "+------------------------------------+\n";
    }

    Persona(int registro, const char nombre[], const char apellido[], int edad);
    Persona() {
        registro = 0;
        nombre[0] = '\0';
        apellido[0] = '\0';
        edad = 0;
    }
};

Persona::Persona(int registro, const char nombre[], const char apellido[], int edad) {
    strcpy_s(this->nombre, nombre);
    strcpy_s(this->apellido, apellido);
    this->registro = registro;
    this->edad = edad;
}

int main() {
    vector<Persona> array[113];

    char opcion;
    do {
        cout << "Ingrese una opcion:" << endl;
        cout << "A) Ingresar datos" << endl;
        cout << "B) Buscar datos" << endl;
        cout << "C) Salir" << endl;

        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
        case 'A': {
            string nuevoRegistro;
            string nuevoNombre;
            string nuevoApellido;
            int nuevaEdad;

            cout << "Ingrese los datos de la nueva persona: " << endl;

            do {
                cout << "Registro (8 digitos): ";
                cin >> nuevoRegistro;
            } while (nuevoRegistro.length() != 8 || nuevoRegistro.find_first_not_of("0123456789") != string::npos || stoi(nuevoRegistro) <= 0);

            cout << "Nombre: ";
            cin.ignore(); // se ignora el salto de línea que queda en el buffer
            getline(cin, nuevoNombre); // se utiliza getline para leer toda la cadena
            cout << "Apellido: ";
            getline(cin, nuevoApellido);

            do {
                cout << "Edad: ";
                cin >> nuevaEdad;
            } while (nuevaEdad <= 0);

            // crear nueva persona
            Persona nuevaPersona(stoi(nuevoRegistro), nuevoNombre.c_str(), nuevoApellido.c_str(), nuevaEdad);

            // agregar la persona al vector correspondiente según el residuo del registro
            int residuo = stoi(nuevoRegistro) % 113; // 113 es un número primo cercano al tamaño deseado del array
            array[residuo].push_back(nuevaPersona);
            break;
        }
        case 'B': {
            int registroBuscado;
            cout << "Ingrese el registro que desea buscar: ";
            cin >> registroBuscado;

            int indice = registroBuscado % 113;
            vector<Persona> personasEncontradas;

            for (int i = 0; i < array[indice].size(); i++) {
                if (array[indice][i].getRegistro() == registroBuscado) {
                    personasEncontradas.push_back(array[indice][i]);
                }
            }

            if (personasEncontradas.empty()) {
                cout << "Persona no encontrada" << endl;
            }
            else {
                cout << "Personas encontradas: ";
                cout << personasEncontradas.size() << endl;
                for (int i = 0; i < personasEncontradas.size(); i++) {
                    personasEncontradas[i].print();
                }
            }
            break;
        }
        case 'C':
            // Salir del programa
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 'C');

    return 0;
}