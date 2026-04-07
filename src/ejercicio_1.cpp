#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::getline;
using std::stoi;

/*

Ejercicio 1 — Compresión y descompresión con RLE

Implemente el algoritmo de Run-Length Encoding (RLE) para comprimir y descomprimir una cadena de texto.

Para esta parte:
    - Se permite el uso de la clase string.
    - Se pueden utilizar operaciones propias de la clase string para recorrer y manipular texto.
    - No se permite el uso de librerías de compresión externas.
El programa deberá:
    - Recibir una cadena de texto.
    - Generar su versión comprimida mediante RLE.
    - Implementar el proceso inverso para recuperar la cadena original.
    - Verificar que la descompresión produzca exactamente el texto inicial.

*/

string comprimirRLE(string texto);
string descomprimirRLE(string comprimido);

void ejercicio_1() {
    string entrada;
    cout << "Ingrese una cadena de texto: ";
    getline(cin >> std::ws, entrada); // ws elimina espacios en blanco previos

    // 1. Generar versión comprimida
    string comprimido = comprimirRLE(entrada);
    cout << "Texto Comprimido: " << comprimido << endl;

    // 2. Proceso inverso
    string recuperado = descomprimirRLE(comprimido);
    cout << "Texto Recuperado: " << recuperado << endl;

    // 3. Verificación
    if (entrada == recuperado) {
        cout << "VERIFICACION EXITOSA: El texto coincide perfectamente." << endl;
    } else {
        cout << "ERROR: El texto recuperado es diferente." << endl;
    }
}

// Función para comprimir
string comprimirRLE(string texto) {
    if (texto.empty()) return "";
    string comprimido = "";
    int n = texto.length();

    for (int i = 0; i < n; i++) {
        int contador = 1;
        while (i < n - 1 && texto[i] == texto[i + 1]) {
            contador++;
            i++;
        }
        comprimido += to_string(contador) + texto[i];
    }
    return comprimido;
}

// Función para comprimir
string descomprimirRLE(string comprimido) {
    string descomprimido = "";
    string numStr = "";

    for (char caracter : comprimido) {
        if (caracter >= '0' && caracter <= '9') {
            numStr += caracter;
        } else {
            int repeticiones = stoi(numStr);
            descomprimido.append(repeticiones, caracter);

            numStr = "";
        }
    }
    return descomprimido;
}

