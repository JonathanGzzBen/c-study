#include "main.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static const size_t LONGITUD_CUENTA_NOMBRE = 20;
static const size_t LONGITUD_CUENTA_USUARIO = 20;
static const size_t LONGITUD_CUENTA_PASSWORD = 20;

static const CuentaUsuario cuentas[];

char* leer_cadena(const size_t len) {
  char* cadena;
  cadena = (char*)malloc(len);
  fgets(cadena, len, stdin);
  cadena[strcspn(cadena, "\n")] = 0;
  return cadena;
}

bool is_str_numeric(char* str) {
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

int leer_numero(char* prompt) {
  char* cadena;
  bool done = false;
  do {
    printf("%s", prompt);
    const size_t input_size = 20;
    cadena = leer_cadena(input_size);
    done = is_str_numeric(cadena);
  } while (done != true);
  return atoi(cadena);
}

CuentaUsuario leer_cuenta() {
  CuentaUsuario cuenta = {.edad = 18};
  printf("Ingrese su nombre: ");
  cuenta.nombre = leer_cadena(LONGITUD_CUENTA_NOMBRE);
  printf("Ingrese un usuario: ");
  cuenta.usuario = leer_cadena(LONGITUD_CUENTA_USUARIO);
  printf("Ingrese una contraseña: ");
  cuenta.password = leer_cadena(LONGITUD_CUENTA_PASSWORD);
  cuenta.edad = leer_numero("Ingrese su edad: ");
  return cuenta;
}

void print_cuenta(const CuentaUsuario* cuenta) {
  printf("Nombre: %-25sUsuario: %-25sContraseña: %-25sEdad: %-3d\n",
         cuenta->nombre, cuenta->usuario, cuenta->password, cuenta->edad);
}

int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif
  CuentaUsuario cuenta = leer_cuenta();
  print_cuenta(&cuenta);
  return 0;
}