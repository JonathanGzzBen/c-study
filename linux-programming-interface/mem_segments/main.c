#include <stdio.h>
#include <stdlib.h>
/*
 * Compile the program in Listing 6-1 (mem_segments.c), and list its
 * size using ls -l. Although the program contains an array (mbuf)
 * that is around 10 MB in size, the executable file is much smaller
 * than this, Why is this?
 */

char globBuf[65536];
int primes[] = { 2, 3, 5, 7 };

static int
square (int x)
{
  int result;
  result = x * x;
  return result;
}

static void
doCalc (int val)
{
  printf ("The square of %d is %d\n", val, square (val));
  if (val < 1000)
    {
      int t = val * val * val;
      printf ("The cube of %d is %d\n", val, t);
    }
}

int
main (void)
{
  static int key = 9973;
  static char mbuf[10240000];
  char const *p = (char *)malloc (1024);
  doCalc (key);
  exit (EXIT_SUCCESS);
}