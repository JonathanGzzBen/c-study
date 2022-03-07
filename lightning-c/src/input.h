#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>
#include <stdio.h>

#include "cuenta_usuario.h"

extern const size_t LONGITUD_CUENTA_NOMBRE;
extern const size_t LONGITUD_CUENTA_USUARIO;
extern const size_t LONGITUD_CUENTA_PASSWORD;

char* leer_cadena(char* prompt, const size_t len);
CuentaUsuario leer_cuenta();
bool is_str_int(char* str);
bool is_str_double(char* str);
int leer_int(char* prompt);
double leer_double(char* prompt);

#endif  // INPUT_H