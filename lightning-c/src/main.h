#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

typedef struct {
  char* nombre;
  char* usuario;
  char* password;
  int edad;
} CuentaUsuario;

char* leer_cadena(const size_t len);
CuentaUsuario leer_cuenta();
void print_cuenta(const CuentaUsuario* cuenta);
int leer_numero();
bool is_str_numeric(char* str);

#endif  // MAIN_H
