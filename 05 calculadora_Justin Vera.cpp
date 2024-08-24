#include <iostream>

using namespace std;

double Add(double a, double b) {
    return a + b;
}

double Subtract(double a, double b) {
    return a - b;
}

double Multiply(double a, double b) {
    return a * b;
}

double Divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        cerr << "Error: División por cero" << endl;
        return 0;
    }
}

typedef double (*Operation)(double, double);

// Función para mostrar el menú de operaciones
void ShowMenu() {
    cout << "Calculadora Simple" << endl;
    cout << "Selecciona una operación:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Salir" << endl;
}

int main() {
    int choice;
    double num1, num2;
    Operation op = nullptr;

    while (true) {
        ShowMenu();
        cout << "Opcion: ";
        cin >> choice;

        if (choice == 5) {
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Opción no valida. Intentalo de nuevo." << endl;
            continue;
        }

        cout << "Introduce el primer numero: ";
        cin >> num1;
        cout << "Introduce el segundo numero: ";
        cin >> num2;

        // Seleccionar la operación según la opción del usuario
        switch (choice) {
        case 1:
            op = Add;
            break;
        case 2:
            op = Subtract;
            break;
        case 3:
            op = Multiply;
            break;
        case 4:
            op = Divide;
            break;
        }

        // Realizar la operación y mostrar el resultado
        if (op) {
            double result = op(num1, num2);
            cout << "Resultado: " << result << endl;
        }
    }

    cout << "Saliendo de la calculadora..." << endl;
    return 0;
}
