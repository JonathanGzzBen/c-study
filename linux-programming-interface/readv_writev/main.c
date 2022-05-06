#include "error_functions.h"
#include <fcntl.h>
#include <malloc.h>
#include <memory.h>
#include <sys/uio.h>
#include <unistd.h>
/*
 * Implement readv() and writev() using read(), write(),
 * and suitable functions from the malloc package
 */

ssize_t
writev_malloc (int fd, const struct iovec *iov, int iovcnt)
{
  size_t totalLength = 0;
  for (int i = 0; i < iovcnt; ++i)
    totalLength += iov[i].iov_len;

  char *buf = (char *)malloc (totalLength);
  memset (buf, '\0', totalLength);
  size_t copied_bytes = 0;
  for (int i = 0; i < iovcnt; ++i)
    {
      memcpy (buf + copied_bytes, iov[i].iov_base, iov[i].iov_len);
      copied_bytes += iov[i].iov_len;
    }
  if (write (fd, buf, totalLength) == -1)
    errExit ("write");

  free (buf);
  return 0;
}

ssize_t
readv_malloc (int fd, const struct iovec *iov, int iovcnt)
{
  size_t totalLength = 0;
  for (int i = 0; i < iovcnt; ++i)
    totalLength += iov[i].iov_len;

  char *buf = (char *)malloc (totalLength);
  memset (buf, '\0', totalLength);
  if (read (fd, buf, totalLength) == -1)
    errExit ("read");

  size_t copied_bytes = 0;
  for (int i = 0; i < iovcnt; ++i)
    {
      memcpy (iov[i].iov_base, buf + copied_bytes, iov[i].iov_len);
      copied_bytes += iov[i].iov_len;
    }

  free (buf);
  return 0;
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    usageErr ("%s SOURCE DEST", argv[0]);

  char buf1[20];
  memset (buf1, '\0', 20);
  char buf2[20];
  memset (buf2, '\0', 20);
  char buf3[20];
  memset (buf3, '\0', 20);
  struct iovec iov[] = { { .iov_base = buf1, .iov_len = 20 },
                         { .iov_base = buf2, .iov_len = 20 },
                         { .iov_base = buf3, .iov_len = 20 } };

  int sourceFd = open (argv[1], O_RDONLY);
  if (sourceFd == -1)
    errExit ("open");

  const int IOV_LEN = sizeof (iov) / sizeof (iov[0]);
  readv_malloc (sourceFd, iov, IOV_LEN);

  int destFd = open (argv[2], O_WRONLY | O_TRUNC | O_CREAT,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                         | S_IWOTH); /* rw-rw-rw- */
  if (destFd == -1)
    errExit ("open");

  writev_malloc (destFd, iov, IOV_LEN);
  for (int i = 0; i < IOV_LEN; ++i)
    printf ("iov[%d] = %s\n", i, (char *)iov[i].iov_base);
  return 0;
}