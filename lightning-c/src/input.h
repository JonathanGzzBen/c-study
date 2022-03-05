#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>
#include <stdio.h>

#include "cuenta_usuario.h"

char* leer_cadena(const size_t len);
CuentaUsuario leer_cuenta();
int leer_numero();
bool is_str_numeric(char* str);

#endif  // INPUT_H