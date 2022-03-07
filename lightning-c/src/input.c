#include "input.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const size_t LONGITUD_CUENTA_NOMBRE = 20;
const size_t LONGITUD_CUENTA_USUARIO = 20;
const size_t LONGITUD_CUENTA_PASSWORD = 20;

char* leer_cadena(char* prompt, const size_t len) {
  char* cadena;
  cadena = (char*)malloc(len);
  do {
    fputs(prompt, stdout);
    fgets(cadena, len, stdin);
    fflush(stdin);
  } while (cadena[0] == '\n');
  cadena[strcspn(cadena, "\n")] = '\0';
  return cadena;
}

bool is_str_int(char* str) {
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

bool is_str_double(char* str) {
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (!(isdigit(str[i]) || str[i] == '.')) {
      return false;
    }
  }
  return true;
}

int leer_int(char* prompt) {
  char* cadena;
  bool done = false;
  do {
    // printf("%s", prompt);
    const size_t input_size = 4;
    cadena = leer_cadena(prompt, input_size);
    done = is_str_int(cadena);
  } while (done != true);
  return atoi(cadena);
}

double leer_double(char* prompt) {
  char* cadena;
  bool done = false;
  do {
    // printf("%s", prompt);
    const size_t input_size = 10;
    cadena = leer_cadena(prompt, input_size);
    done = is_str_double(cadena);
  } while (done != true);
  return atof(cadena);
}

CuentaUsuario leer_cuenta() {
  CuentaUsuario cuenta = {.edad = 18};
  cuenta.nombre = leer_cadena("Ingrese su nombre: ", LONGITUD_CUENTA_NOMBRE);
  cuenta.usuario = leer_cadena("Ingrese un usuario: ", LONGITUD_CUENTA_USUARIO);
  cuenta.password =
      leer_cadena("Ingrese una contraseña: ", LONGITUD_CUENTA_PASSWORD);
  cuenta.edad = leer_int("Ingrese su edad: ");
  cuenta.saldo = 0;
  return cuenta;
}