#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

// Array of CuentaUsuario
CuentaUsuario *cuentas = NULL;
static int cuentas_len = 0;
CuentaUsuario *cuenta_activa = NULL;

int run_menu() {
  bool done = false;
  do {
    puts(
        "Opciones\n1.-Crear Cuenta\n2.-Iniciar "
        "Sesión\n3.-Depositar\n4.-Retirar\n5.-Consultar saldo "
        "actual\n6.-Cerrar Sesión\n7.-Salir");

    int option = leer_int("Ingrese opcion: ");
    switch (option) {
      case 1:
        crear_cuenta();
        break;
      case 2:
        iniciar_sesion();
        break;
      case 3:
        depositar();
        break;
      case 4:
        retirar();
        break;
      case 5:
        consultar_saldo_actual();
        break;
      case 6:
        cerrar_sesion();
        break;
      case 7:
        done = true;
        break;
      case 8:
        imprimir_cuentas();
        break;
      default:
        break;
    }
  } while (!done);
  puts("\nGracias por usar este servicio.");
  for (int i = 0; i < cuentas_len; i++) {
    free(cuentas[i].nombre);
    free(cuentas[i].usuario);
    free(cuentas[i].password);
  }
  return 0;
}

void crear_cuenta() {
  if (cuenta_activa != NULL) {
    puts("\nNo puede crear una cuenta mientras tiene su sesión activa.\n");
    return;
  }
  CuentaUsuario nueva_cuenta = leer_cuenta();
  cuentas_len += 1;
  cuentas =
      (CuentaUsuario *)realloc(cuentas, sizeof(CuentaUsuario) * cuentas_len);
  cuentas[cuentas_len - 1] = nueva_cuenta;
  puts("Cuenta registrada\n");
}

void iniciar_sesion() {
  if (cuenta_activa != NULL) {
    puts("\nSesión ya activa.\n");
    return;
  }
  char *usuario = leer_cadena("Ingrese usuario: ", LONGITUD_CUENTA_USUARIO);
  char *password = leer_cadena("Ingrese password: ", LONGITUD_CUENTA_PASSWORD);
  for (int i = 0; i < cuentas_len; ++i) {
    if (strncmp(cuentas[i].usuario, usuario, LONGITUD_CUENTA_USUARIO) == 0 &&
        strncmp(cuentas[i].password, password, LONGITUD_CUENTA_USUARIO) == 0) {
      cuenta_activa = &cuentas[i];
      printf("\nHa iniciado sesión con el usuario: %-25s\n\n",
             cuenta_activa->usuario);
      return;
    }
  }
  puts("\nUsuario o contraseña incorrectos.\n");
}

void depositar() {
  if (cuenta_activa == NULL) {
    puts("\nNecesita iniciar sesion antes de depositar.\n");
    return;
  }
  double monto_a_depositar = leer_double("Ingrese monto a depositar: ");
  cuenta_activa->saldo += monto_a_depositar;
  printf("\n$%.2lf depositados\n\n", monto_a_depositar);
}

void retirar() {
  if (cuenta_activa == NULL) {
    puts("\nNecesita iniciar sesion antes de retirar.\n");
    return;
  }
  double monto_a_retirar = leer_double("Ingrese monto a retirar: ");
  if (cuenta_activa->saldo - monto_a_retirar < 0) {
    puts("\nSaldo insuficiente\n");
  } else {
    cuenta_activa->saldo += monto_a_retirar;
    printf("\n$%.2lf retirados\n\n", monto_a_retirar);
  }
}

void consultar_saldo_actual() {
  if (cuenta_activa == NULL) {
    puts("\nNecesita iniciar sesión para consultar su saldo actual.\n");
    return;
  }
  printf("\nUsuario: %-25s\nSaldo: $%-10.2f\n\n", cuenta_activa->usuario,
         cuenta_activa->saldo);
}

void print_cuenta(const CuentaUsuario const *cuenta) {
  printf(
      "Nombre: %-25sUsuario: %-25sContraseña: %-25sEdad: %-5dSaldo: %-10.2f\n",
      cuenta->nombre, cuenta->usuario, cuenta->password, cuenta->edad,
      cuenta->saldo);
}

void cerrar_sesion() {
  if (cuenta_activa == NULL) {
    puts("\nNo hay ninguna sesión iniciada.\n");
    return;
  }
  cuenta_activa = NULL;
  puts("\nSe ha cerrado la sesión\n");
}

void imprimir_cuentas() {
  for (int i = 0; i < cuentas_len; ++i) {
    print_cuenta(&cuentas[i]);
  }
}