#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Prototipos
char* rotarIzquierda(char* entrada, int longitud, int n);
char* rotarDerecha(char* entrada, int longitud, int n);
void mostrarBits(char c);
void mostrarBitsDeString(const char* entrada, int longitud);
void aplicarXOR(char* datos, int longitud, unsigned char llave);
void desencriptar(char* entrada, int longitud, int n, unsigned char llave);

void ejercicio_3() {
    int capacidad = 1000;
    char* entrada = new char[capacidad];
    int n_rotaciones = 0;
    unsigned char llaveXOR = 0b01010110;

    cout << "Ingrese un texto a encriptar" << endl;
    cin.ignore(1000, '\n');

    // Lectura manual para no usar getline(cin, string)
    int longitud = 0;
    char c;
    while (cin.get(c) && c != '\n' && longitud < capacidad - 1) {
        entrada[longitud++] = c;
    }
    entrada[longitud] = '\0';

    do {
        cout << "Ingrese n de rotaciones (1-7): " << endl;
        cin >> n_rotaciones;
    } while (n_rotaciones < 0 || n_rotaciones > 8);

    // ======= PROCESO DE ENCRIPTACION ==== ---
    // Paso 1: Rotar
    char* encriptado = rotarIzquierda(entrada, longitud, n_rotaciones);
    // Paso 2: XOR
    aplicarXOR(encriptado, longitud, llaveXOR);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Original:   " << entrada << endl;
    mostrarBitsDeString(entrada, longitud);

    cout << "Encriptado: " << encriptado << " (Binario alterado)" << endl;
    mostrarBitsDeString(encriptado, longitud);

    // === PROCESO DE DESENCRIPTACION =======
    char* recuperado = new char[longitud + 1];
    for(int i = 0; i <= longitud; ++i) recuperado[i] = encriptado[i];

    desencriptar(recuperado, longitud, n_rotaciones, llaveXOR);

    cout << "Recuperado: " << recuperado << endl;
    mostrarBitsDeString(recuperado, longitud);

    // Limpieza de memoria dinámica
    delete[] entrada;
    delete[] encriptado;
    delete[] recuperado;
}

unsigned char aplicarRotacion(unsigned char byte, int n, bool izquierda) {
    if (izquierda) {
        return (byte << n) | (byte >> (8 - n));
    } else {
        return (byte >> n) | (byte << (8 - n));
    }
}

char* rotarIzquierda(char* entrada, int longitud, int n) {
    char* resultado = new char[longitud + 1];
    for (int i = 0; i < longitud; ++i) {
        resultado[i] = aplicarRotacion(static_cast<unsigned char>(entrada[i]), n, true);
    }
    resultado[longitud] = '\0';
    return resultado;
}

char* rotarDerecha(char* entrada, int longitud, int n) {
    char* resultado = new char[longitud + 1];
    for (int i = 0; i < longitud; ++i) {
        resultado[i] = aplicarRotacion(static_cast<unsigned char>(entrada[i]), n, false);
    }
    resultado[longitud] = '\0';
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

void mostrarBitsDeString(const char* entrada, int longitud) {
    std::cout << "Representación binaria (" << longitud << " bytes):" << std::endl;
    for (int i = 0; i < longitud; ++i) {
        mostrarBits(entrada[i]);

        // Añadimos un espacio entre bytes para que sea legible
        std::cout << " ";
    }
    std::cout << std::endl; // Salto de línea al final
}

void aplicarXOR(char* entrada, int longitud, unsigned char llave) {
    for (int i = 0; i < longitud; ++i) {
        entrada[i] = static_cast<char>(static_cast<unsigned char>(entrada[i]) ^ llave);
    }
}

void desencriptar(char* entrada, int longitud, int n, unsigned char llave){
    // 1. Revertir XOR
    aplicarXOR(entrada, longitud, llave);
    // 2. Revertir rotacion
    char* temporal = rotarDerecha(entrada, longitud, n);
    for(int i = 0; i < longitud; ++i) entrada[i] = temporal[i];
    delete[] temporal;
}
