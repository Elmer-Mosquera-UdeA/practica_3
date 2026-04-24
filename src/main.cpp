#include "enlace.h"
#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

void imprimirMenu();
void ejecutar_ejercicio(int entrada);
void pausarEjecucion();
void salir();

int main(){
    int entrada = 0;

    do {
        if (entrada != 0){
            pausarEjecucion();
        }
        imprimirMenu();
        cin >> entrada;
        cin.clear();
        ejecutar_ejercicio(entrada);
    } while (true);
    return 0;
}

void ejecutar_ejercicio(int entrada){

    switch (entrada) {
    case 1:
        ejercicio_1();
        cout << "\033[32mEjercicio 1 ejecutado.\033[0m" << endl;
        break;
    case 2:
        ejercicio_2();
        cout << "\033[32mEjercicio 2 ejecutado.\033[0m" << endl;
        break;
    case 3:
        ejercicio_3();
        cout << "\033[32mEjercicio 3 ejecutado.\033[0m" << endl;
        break;
    case 4:
        ejercicio_4();
        cout << "\033[32mEjercicio 4 ejecutado.\033[0m" << endl;
        break;
    case 0:
        salir();
        break;
    default:
        cout << "\033[31mEntrada no valida.\033[0m" << endl;
        break;
    }
}

void imprimirMenu(){
    cout << "|-----------------------------------|" << endl;
    cout << "|         Ingrese un numero         |" << endl;
    cout << "| 1 - 4 para ejecutar un ejercicio  |" << endl;
    cout << "|            0 para salir           |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "=> ";
}

void salir() {
    cout << "Saliendo..." << endl;
    exit(0);
}

void pausarEjecucion(){
    std::cout << "Presiona Enter para continuar...";

    // Limpia cualquier residuo en el búfer de entrada
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Espera a que el usuario presione Enter
    std::cin.get();
}
