#ifndef MENU_H
#define MENU_H
#include <stdbool.h>

#include "cuenta_usuario.h"

int run_menu();
void crear_cuenta();
void iniciar_sesion();
void depositar();
void retirar();
void consultar_saldo_actual();
void print_cuenta(const CuentaUsuario* cuenta);
void cerrar_sesion();
void imprimir_cuentas();

#endif  // MENU_H