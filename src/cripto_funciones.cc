#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "cripto_funciones.h"

/** Muestra como funciona el programa.
 *
 *  @param[in] argc parametro por linea de comando
 *  @param[in] argv Vector que contiene (char*) 
 */
void Usage(int argc, char* argv[]) {
  
  if (argc == 1 && argc != 6) {
    std::cout << argv[0] << ": faltan parámetros" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 2){
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != 6){
    std::cout << argv[0] << ": faltan parámetros" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}
/** Comprueba que los parámetros introducidos
 *  son correctos para el encriptado,
 *  si da error te lo muestra en pantalla. 
 * */
void ComprobarParametros(char* argv[]){
  if (argv[3][0] != '1' && argv[3][0] != '2'){
    std::cout << "Error en el método de encriptado" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[3][0] == '2'){
    std::string k{argv[4][0]};
    if(IsInteger(k)){

    }
    else{
      std::cout << "Error en el método de encriptado" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  if (argv[5][0] != '+' && argv[5][0] != '-'){
    std::cout << "Error en la operación" << std::endl;
    exit(EXIT_FAILURE);
  }
  
}
/**
 * IsInteger dice si
 * k es un numero entero.
 * */ 
bool IsInteger(std::string str) {
  for(auto c: str){
    if(c < 48 || c > 57)
      return false;
  }

  return true;
} 
/**
 * EncriptadoXor encripta usando el metodo xor. 
 *  */
std::string EncriptadoXor(std::string contenido, std::string clave){
  std::string contenido_encriptado{""};
  std::string clave_encriptada{""};
  for (auto i : clave){
    clave_encriptada += (clave[i]^128);
    std::cout << clave_encriptada;
  }
  for (int i : contenido){
    contenido_encriptado += (contenido[i]^clave_encriptada[i%clave_encriptada.length()]);
  }
  return contenido_encriptado;
}
/**
 * EncriptadoCesar es una funcion que utiliza el metodo de encriptacion
 * Cesar
 *  */
std::string EncriptadoCesar(std::string contenido, const int k){
  std::string contenido_encriptado;
  for (int i = 0; i < contenido.length(); ++i){
    char caracter_evaluar = contenido[i];
    int caracter = caracter_evaluar;
    caracter += k;
    char caracter_nuevo{caracter};
    contenido_encriptado += caracter_nuevo;
  }
  return contenido_encriptado;
}
/**
 * Al contrario de EncriptadoCesar, DesencriptadoCesar desencrita 
 * un archivo
 *  */
std::string DesencriptadoCesar(std::string contenido, const int k){
  std::string contenido_desencriptado;
  for (int i = 0; i < contenido.length(); ++i){
    char caracter_evaluar = contenido[i];
    int caracter = caracter_evaluar;
    caracter -= k;
    char caracter_nuevo{caracter};
    contenido_desencriptado += caracter_nuevo;
  }
  return contenido_desencriptado;
}
