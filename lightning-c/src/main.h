#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

typedef struct {
  char* nombre;
  char* usuario;
  char* password;
  int edad;
} CuentaUsuario;

void print_cuenta(const CuentaUsuario* cuenta);

#endif  // MAIN_H
