#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::string rotarIzquierda(std::string entrada, int n);
std::string rotarDerecha(std::string entrada, int n);
void encriptarXOR();
void desencriptarXOR();

void ejercicio_3() {
    // Declaracion de variables
    string entrada = "";
    int n_rotaciones = 0;

    cout << "Ingrese un texto a encriptar" << endl;
    cin.ignore(1000, '\n');
    getline(cin, entrada);

    do {
        cout << "Ingrese la cantidad de veces que desea rotar bits de texto ingresado" << endl;
        cout << "El numero debe ser menor a ocho y mayor a cero" << endl;
        cin >> n_rotaciones;
        cin.clear();
    } while (0 > n_rotaciones && n_rotaciones > 8);

    std::string izq = rotarIzquierda(entrada, n_rotaciones);
    std::string der = rotarDerecha(izq, n_rotaciones);

    std::cout << "Original:  " << entrada << std::endl;
    std::cout << "Izquierda: " << izq << " (Binario alterado)" << std::endl;
    std::cout << "Derecha:   " << der << " (Binario alterado)" << std::endl;
}
unsigned char aplicarRotacion(unsigned char byte, int n, bool izquierda) {
    if (izquierda) {
        return (byte << n) | (byte >> (8 - n));
    } else {
        return (byte >> n) | (byte << (8 - n));
    }
}

std::string rotarIzquierda(std::string entrada, int n) {
    std::string resultado = entrada;
    for (size_t i = 0; i < entrada.length(); ++i) {
        resultado[i] = aplicarRotacion(static_cast<unsigned char>(entrada[i]), n, true);
    }
    return resultado;
}

std::string rotarDerecha(std::string entrada, int n) {
    std::string resultado = entrada;
    for (size_t i = 0; i < entrada.length(); ++i) {
        resultado[i] = aplicarRotacion(static_cast<unsigned char>(entrada[i]), n, false);
    }
    return resultado;
}

void encriptarXOR(){

}

void desencriptarXOR(){

}
