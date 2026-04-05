# Practica 3 Informatica

Esta es una actividad desarrollada por:



### Ejercicios
Consiste en desarrollar los siguientes 4 ejercicios.

#### Ejercicio 1 — Compresión y descompresión con RLE
Implemente el algoritmo de Run-Length Encoding (RLE) para comprimir y descomprimir una cadena de texto.  
Para esta parte:
- Se permite el uso de la clase `string`.
- Se pueden utilizar operaciones propias de la clase `string` para recorrer y manipular texto.
- No se permite el uso de librerías de compresión externas.

El programa deberá:
1. Recibir una cadena de texto.
2. Generar su versión comprimida mediante RLE.
3. Implementar el proceso inverso para recuperar la cadena original.
4. Verificar que la descompresión produzca exactamente el texto inicial.

[Se puede usar como referencia el video "Ejemplo codificación RLE"](https://www.youtube.com/watch?v=S8paE-YgtGw).

---

#### Ejercicio 2 — Compresión y descompresión con LZ78
Implemente el algoritmo LZ78 utilizando un diccionario dinámico construido manualmente.  
Para esta parte:
- No se permite el uso de `vector`, `map`, `unordered_map` ni de otros contenedores de la STL.
- No se permite almacenar frases completas en `string`.
- El diccionario debe implementarse mediante arreglos dinámicos y memoria dinámica.
- Cada entrada del diccionario debe representarse como un par (prefijo, carácter).

El programa deberá:
1. Construir el diccionario dinámicamente durante la compresión.
2. Generar como salida pares (índice, carácter).
3. Implementar el proceso de descompresión mediante la reconstrucción del diccionario.
4. Verificar que el texto reconstruido sea idéntico al original.

[Se puede usar como referencia el video "Ejemplo codificación LZ78"](https://www.youtube.com/watch?v=oy_GlgjAFew).

---

#### Ejercicio 3 — Encriptación y desencriptación
Implemente un módulo de encriptación que opere sobre los datos comprimidos.  
El proceso deberá:
1. Aplicar una rotación de bits a la izquierda a cada byte, con un valor `n` definido por el usuario (0 < n < 8).
2. Aplicar posteriormente una operación XOR con una clave de un byte `K`.

Implemente también el proceso inverso que permita recuperar los datos originales.

---

#### Ejercicio 4 — Integración
5.4 Integración  
Desarrolle una aplicación que permita:
- Seleccionar el método de compresión (RLE o LZ78).
- Comprimir un texto leído de un archivo.
- Encriptar el resultado.
- Desencriptar y descomprimir el mensaje.
- Verificar que el texto final coincide con el original después de imprimirlo en un archivo.

---

## Restricciones generales
- El uso de `string` está limitado únicamente a la parte del algoritmo RLE.
- En la implementación de LZ78 se deberá utilizar, de manera justificada, memoria dinámica.
- No se permite el uso de librerías externas de compresión o de encriptación.
- Se solicita que el programa se organice de forma modular mediante funciones.
- Se debe aplicar el manejo de excepciones en el código.
- Se publica junto al enunciado un dataset de prueba que puede usarse durante el desarrollo.

---

## Estado
En desarrollo.

---

## Organización sugerida del repositorio
- `src/` — Código fuente (módulos separados para RLE, LZ78, encriptación y la interfaz principal).
- `include/` — Cabeceras, si aplica.
- `data/` — Archivos de prueba y dataset publicado.
- `bin/` — Ejecutables generados (no versionar en git).
- `docs/` — Documentación adicional y referencias (videos, artículos).
- `tests/` — Pruebas unitarias y de integración.

---

## Ejecución y pruebas (sugerencias)
- Proveer argumentos o un menú para:
  - Seleccionar RLE o LZ78.
  - Indicar archivo de entrada y archivo de salida.
  - Configurar parámetros de encriptación (`n` y `K`).
- Realizar pruebas automatizadas que verifiquen que:
  - compress → encrypt → decrypt → decompress resulta en el archivo original.
  - Los módulos manejan entradas edge-case (cadena vacía, caracteres repetidos, datos binarios en LZ78, etc.).
- Incluir manejo de excepciones y mensajes de error claros (archivo no encontrado, parámetros inválidos, fallos de memoria).

---

## Colaboradores
Desarrollado por:
1. Elmer David Mosquera Martinez

