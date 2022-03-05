#include <stdio.h>

static const size_t LONGITUD_CUENTA_NOMBRE = 20;
static const size_t LONGITUD_CUENTA_USUARIO = 20;
static const size_t LONGITUD_CUENTA_PASSWORD = 20;

typedef struct {
  char* nombre;
  char* usuario;
  char* password;
  int edad;
} CuentaUsuario;

void print_cuenta(const CuentaUsuario* cuenta) {
  printf("Nombre: %s\tUsuario: %s\tEdad: %d\n", cuenta->nombre, cuenta->usuario,
         cuenta->edad);
}

int main() {
  CuentaUsuario primeraCuenta = {.edad = 18,
                                 .nombre = "Jonathan Gonzalez",
                                 .usuario = "jonark",
                                 .password = "comer"};
  print_cuenta(&primeraCuenta);
  return 0;
}