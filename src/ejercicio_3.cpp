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
void aplicarXOR(std::string &datos, unsigned char llave);
void desencriptar(std::string &entrada, int n, unsigned char llave);

void ejercicio_3() {
    string entrada = "";
    int n_rotaciones = 0;
    unsigned char llaveXOR = 0b01010110;

    cout << "Ingrese un texto a encriptar" << endl;
    cin.ignore(1000, '\n');
    getline(cin, entrada);

    do {
        cout << "Ingrese n de rotaciones (1-7): " << endl;
        cin >> n_rotaciones;
    } while (n_rotaciones < 0 || n_rotaciones > 8);

    // ======= PROCESO DE ENCRIPTACION ==== ---
    // Paso 1: Rotar
    string encriptado = rotarIzquierda(entrada, n_rotaciones);
    // Paso 2: XOR
    aplicarXOR(encriptado, llaveXOR);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Original:   " << entrada << endl;
    mostrarBitsDeString(entrada);

    cout << "Encriptado: " << encriptado << " (Binario alterado)" << endl;
    mostrarBitsDeString(encriptado);

    // === PROCESO DE DESENCRIPTACION =======
    string recuperado = encriptado;
    desencriptar(recuperado, n_rotaciones, llaveXOR);

    cout << "Recuperado: " << recuperado << endl;
    mostrarBitsDeString(recuperado);
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
        // Desplazamos el bit deseado a la posición 0 y aplicamos mascara 1
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

void aplicarXOR(std::string &entrada, unsigned char llave) {
    for (size_t i = 0; i < entrada.length(); ++i) {
        entrada[i] = static_cast<char>(static_cast<unsigned char>(entrada[i]) ^ llave);
    }
}

void desencriptar(std::string &entrada, int n, unsigned char llave){
    // 1. Revertir XOR
    aplicarXOR(entrada, llave);

    // 2. Revertir rotacion
    entrada = rotarDerecha(entrada, n);
}
