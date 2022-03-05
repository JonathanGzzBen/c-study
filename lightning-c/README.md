# Lightning C

En este lightning (live de bajo presupuesto) les enseñaré a realizar tareas comunes en lenguaje C para construir un pequeño "sistema bancario" con validaciones típicas como revisar que una cadena de texto no incluya números o asegurarnos de que el usuario ingrese un valor numérico.

La especificación (cosas que puede hacer el usuario) de nuestro sistema es el siguiente:

- Crearse una cuenta especificando su nombre y edad, usuario y password.
  - El nombre no debe incluir números y debe tener una longitud mayor a 1.
  - La edad debe de ser un valor entero.
  - El usuario no debe contener espacios y debe tener una longitud mayor a 1.
  - La contraseña debe tener una longitud mayor a 1.
- Iniciar sesion a su cuenta.
  - Debe especificar usuario y password, y tienen que corresponder a una cuenta registrada.
- Depositar dinero a su cuenta.
  - Necesita iniciar sesión.
  - El depósito no puede ser igual o menor a 0.
- Retirar dinero de su cuenta.
  - Necesita iniciar sesión.
  - Tras el retiro de dinero, su saldo en la cuenta no puede ser menor a 0.
- Ver su saldo actual.
  - Necesita iniciar sesión.
