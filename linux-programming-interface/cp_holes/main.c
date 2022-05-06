#include "error_functions.h"
#include <fcntl.h>
#include <unistd.h>
/*
 * Write a program like cp that, when used to copy a regular
 * file that contains holes (sequences of null bytes), also
 * creates corresponding holes in the target file.
 */

int
main (int argc, char *argv[])
{
  if (argc != 3)
    usageErr ("%s SOURCE DEST", argv[0]);

  int sourceFd = open (argv[1], O_RDONLY);
  if (sourceFd == -1)
    errExit ("Could not open source file %s", argv[1]);

  int destFd = open (argv[2], O_WRONLY | O_CREAT | O_TRUNC,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                         | S_IWOTH); /* rw-rw-rw- */
  if (destFd == -1)
    errExit ("Could not open dest file %s", argv[1]);

  const int BUF_SIZE = 20;
  char buf[BUF_SIZE];
  ssize_t numRead;
  while ((numRead = read (sourceFd, buf, BUF_SIZE)) > 0)
    if ((write (destFd, buf, numRead)) != numRead)
      errExit ("Could not write to dest file %s", argv[2]);

  return 0;
}