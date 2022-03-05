#include <stdio.h>

#include "cuenta_usuario.h"
#include "input.h"

static const CuentaUsuario cuentas[];

int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif
  CuentaUsuario cuenta = leer_cuenta();
  print_cuenta(&cuenta);
  return 0;
}