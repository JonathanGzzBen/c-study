#include "output.h"

void print_cuenta(const CuentaUsuario* cuenta) {
  printf("Nombre: %-25sUsuario: %-25sContraseña: %-25sEdad: %-3d\n",
         cuenta->nombre, cuenta->usuario, cuenta->password, cuenta->edad);
}