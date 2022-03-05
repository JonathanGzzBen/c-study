#include <stdio.h>
#ifdef _WIN32
#include <stdlib.h>
#endif

#include "cuenta_usuario.h"
#include "input.h"

static const CuentaUsuario cuentas[];

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