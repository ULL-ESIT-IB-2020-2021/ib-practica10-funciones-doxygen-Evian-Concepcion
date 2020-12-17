#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string kHelpText = R"(fichero_input: Fichero a codificar
fichero_salida:  codificado
método:          Elige metodo
                   1: xor
                   2: César
contraseña:        contraseña en el caso de método 1, Valor de K en el método 2
operación:       Operación  en el fichero
                   +: encriptar el fichero
                   -: desencriptar el fichero)";

void Usage(int argc, char *argv[]);
void ComprobarParametros(char *argv[]);
bool IsInteger(string str);
string EncriptadoXor(string contenido, string clave);
string EncriptadoCesar(string contenido, const int k);
string DesencriptadoCesar(string contenido, const int k);
