#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

const extern size_t LONGITUD_CUENTA_NOMBRE;
const extern size_t LONGITUD_CUENTA_USUARIO;
const extern size_t LONGITUD_CUENTA_PASSWORD;

typedef struct {
  char* nombre;
  char* usuario;
  char* password;
  int edad;
} CuentaUsuario;

void print_cuenta(const CuentaUsuario* cuenta);

#endif  // MAIN_H
