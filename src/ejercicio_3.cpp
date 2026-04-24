#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::string rotarIzquierda(std::string entrada, int n);
std::string rotarDerecha(std::string entrada, int n);
void mostrarBits(char c);
void mostrarBitsDeString(const std::string& entrada);
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

    string izq = rotarIzquierda(entrada, n_rotaciones);
    string der = rotarDerecha(izq, n_rotaciones);

    cout << "Original:  " << entrada << endl;
    cout << "Izquierda: " << izq << " (Binario alterado)" << endl;
    cout << "Derecha:   " << der << " (Binario alterado)" << endl;

    cout << "\n\n\n";

    // Mostrar Bytes de strings
    cout << "Bits de Entrada" << endl;
    mostrarBitsDeString(entrada);
    cout << "Bits de Entrada rotado a la izquierda" << endl;
    mostrarBitsDeString(izq);


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

void mostrarBits(char c) {
    unsigned char byte = static_cast<unsigned char>(c);

    for (int i = 7; i >= 0; --i) {
        // Desplazamos el bit deseado a la posición 0 y aplicamos máscara 1
        int bit = (byte >> i) & 1;
        std::cout << bit;
    }
}

void mostrarBitsDeString(const std::string& entrada) {
    std::cout << "Representación binaria (" << entrada.length() << " bytes):" << std::endl;

    for (size_t i = 0; i < entrada.length(); ++i) {
        mostrarBits(entrada[i]);

        // Añadimos un espacio entre bytes para que sea legible
        std::cout << " ";
    }
    std::cout << std::endl; // Salto de línea al final
}

void encriptarXOR(){

}

void desencriptarXOR(){

}
