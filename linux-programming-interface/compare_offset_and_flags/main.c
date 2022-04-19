#include "error_functions.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/*
 * Write a program to verify that duplicated file descriptors
 * share a file offset value and open file status flags.
 */

off_t
get_offset (int fd)
{
  return lseek (fd, 0, SEEK_CUR);
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    usageErr ("%s DEST MESSAGE", argv[0]);

  int destFd = open (argv[1], O_WRONLY | O_TRUNC | O_CREAT,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                         | S_IWOTH); /* rw-rw-rw- */

  if (destFd == -1)
    errExit ("open");

  int dupFd = dup (destFd);
  if (dupFd == -1)
    errExit ("dup");

  const int MAX_LEN = 100;
  const size_t MESSAGE_LEN = strnlen (argv[2], MAX_LEN);
  if (write (destFd, argv[2], MESSAGE_LEN) != MESSAGE_LEN)
    errExit ("write");
  if (write (dupFd, argv[2], MESSAGE_LEN) != MESSAGE_LEN)
    errExit ("write");

  printf ("destFd=%d\ndupFd=%d\n", destFd, dupFd);
  printf ("destFd Offset=%ld\ndupFd Offset=%ld\n", get_offset (destFd),
          get_offset (dupFd));

  const int destFdFlags = fcntl (destFd, F_GETFL);
  if (destFdFlags == -1)
    errExit ("fcntl F_GETFL");

  const int dupFdFlags = fcntl (dupFd, F_GETFL);
  if (dupFdFlags == -1)
    errExit ("fcntl F_GETFL");

  printf ("destFd flags: %d\ndupFd flags: %d\n", destFdFlags, dupFdFlags);

  return 0;
}