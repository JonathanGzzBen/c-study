#include "error_functions.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
/*
 * Write a program that opens an existing file for writing with the O_APPEND
 * flag, and then seeks to the beginning of the file before writing some data.
 * Where does the data appear in the file? Why?
 */

int
main (int argc, char *argv[])
{
  if (argc != 3)
    usageErr ("%s DEST DATA", argv[0]);

  int destFd = open (argv[1], O_WRONLY | O_APPEND);
  if (destFd == -1)
    errExit ("open");

  if (lseek (destFd, 0, SEEK_SET) == -1)
    errExit ("lseek");

  if (write (destFd, argv[2], strlen (argv[2])) != strlen (argv[2]))
    errExit ("write");

  return 0;
}