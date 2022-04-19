#include "error_functions.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/*
 * Implement dup() and dup2() using fcntl() and where necessary,
 * close(). (You may ignore the fact that dup2() and fcntl()
 * return different errno values for some error cases.) For
 * dup2(), remember to handle the special case where oldfd
 * equals newfd. In this case, you should check whether oldf
 * is valid, which can be done by, for example, checking if
 * fcntl(oldfd, F_GETFL) succeeds. If oldfd is not valid, then
 * the function should return -1 witth errno set to EBADF.
 */

int
dup_fcntl (int oldfd)
{
  return fcntl (oldfd, F_DUPFD, 0);
}

int
dup2_fcntl (int oldfd, int newfd)
{
  if (fcntl (oldfd, F_GETFL) == -1)
    {
      errno = EBADF;
      return -1;
    }

  if (oldfd == newfd)
    return newfd;

  /* newfd is already opened */
  if (fcntl (newfd, F_GETFL) != -1)
    close (newfd);

  return fcntl (oldfd, F_DUPFD, newfd);
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    usageErr ("%s DEST MESSAGE", argv[0]);

  const int destFd = open (argv[1], O_WRONLY | O_CREAT,
                           S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                               | S_IWOTH); /* rw-rw-rw- */
  if (destFd == -1)
    errExit ("open");

  const int MAX_LEN = 100;
  const size_t MESSAGE_LEN = strnlen (argv[2], MAX_LEN);
  if (write (destFd, argv[2], MESSAGE_LEN) != MESSAGE_LEN)
    errExit ("write");

  const int dupFd = dup_fcntl (destFd);
  if (dupFd == -1)
    errExit ("dup");

  if (write (dupFd, argv[2], MESSAGE_LEN) != MESSAGE_LEN)
    errExit ("write");

  const int dup2Fd = dup2_fcntl (destFd, dupFd);
  if (dup2Fd == -1)
    errExit ("dup");

  if (write (dup2Fd, argv[2], MESSAGE_LEN) != MESSAGE_LEN)
    errExit ("write");

  printf ("destFd = %d\ndupFd=%d\ndup2Fd=%d\n", destFd, dupFd, dup2Fd);

  return 0;
}