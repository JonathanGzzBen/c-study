#ifndef CUENTA_USUARIO_H
#define CUENTA_USUARIO_H

typedef struct {
  char* nombre;
  char* usuario;
  char* password;
  int edad;
  double saldo;
} CuentaUsuario;

#endif  // CUENTA_USUARIO_H