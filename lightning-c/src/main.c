#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* nombre;
  char* usuario;
  char* password;
  int edad;
} CuentaUsuario;

static const size_t LONGITUD_CUENTA_NOMBRE = 20;
static const size_t LONGITUD_CUENTA_USUARIO = 20;
static const size_t LONGITUD_CUENTA_PASSWORD = 20;

static const CuentaUsuario cuentas[];

char* leer_cadena(const size_t len);
CuentaUsuario leer_cuenta();
void print_cuenta(const CuentaUsuario* cuenta);

char* leer_cadena(const size_t len) {
  char* cadena;
  cadena = (char*)malloc(len);
  fgets(cadena, len, stdin);
  cadena[strcspn(cadena, "\n")] = 0;
  return cadena;
}

CuentaUsuario leer_cuenta() {
  CuentaUsuario cuenta = {.edad = 18};
  printf("Ingrese su nombre: ");
  cuenta.nombre = leer_cadena(LONGITUD_CUENTA_NOMBRE);
  printf("Ingrese un usuario: ");
  cuenta.usuario = leer_cadena(LONGITUD_CUENTA_USUARIO);
  printf("Ingrese una contraseña: ");
  cuenta.password = leer_cadena(LONGITUD_CUENTA_PASSWORD);
  return cuenta;
}

void print_cuenta(const CuentaUsuario* cuenta) {
  printf("Nombre: %-25sUsuario: %-25sPassword: %-25sEdad: %-3d\n",
         cuenta->nombre, cuenta->usuario, cuenta->password, cuenta->edad);
}

int main() {
  CuentaUsuario cuenta = leer_cuenta();
  print_cuenta(&cuenta);
  return 0;
}