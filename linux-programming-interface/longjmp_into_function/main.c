#include <setjmp.h>
#include <stdio.h>
/*
 * Write a program to see what happens if we try to longjmp()
 * into a function that has already returned.
 */
static jmp_buf env;
void
theFunction (void)
{
  if (setjmp (env) == 0)
  {
    puts ("Inside theFunction()");
  }
  else
  {
    puts ("Inside theFunction() after jump");
  }
}

int
main (void)
{
  theFunction();
  longjmp (env, 1);
  return 0;
}