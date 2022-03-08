#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>
#include <stdio.h>

#include "cuenta_usuario.h"

extern const size_t LONGITUD_CUENTA_NOMBRE;
extern const size_t LONGITUD_CUENTA_USUARIO;
extern const size_t LONGITUD_CUENTA_PASSWORD;

char* leer_cadena(const char* const prompt, const size_t len);
CuentaUsuario leer_cuenta();
bool is_str_int(const char* const str);
bool is_str_double(const char* const str);
int leer_int(const char* const prompt);
double leer_double(const char* const prompt);

#endif  // INPUT_H