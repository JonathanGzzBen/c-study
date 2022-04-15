/*
 * The tee command reads its standard input until end-of-file, writing a
 * copy of the input to standard output and to the file named in the
 * command-line argument.
 *
 * Implement tee using I/O system calls. By default, tee
 * overwrites any existing file with the given name. Implement the -a
 * command-line option (tee -a file), which causes tee to append text
 * to the end of a file if it already exists.
 */

#include "error_functions.h"
#include "tlpi_hdr.h"
#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
  if (!(argc == 2 || argc == 3))
    usageErr ("%s [-a] file\n", argv[0]);

  Boolean append = FALSE;
  int opt;
  while ((opt = getopt (argc, argv, ":a")) != -1)
    {
      switch (opt)
        {
        case 'a':
          append = TRUE;
          break;
        }
    }

  const char *filename = argv[optind];

  int openFlags = O_RDWR | O_CREAT;
  openFlags = append ? (openFlags | O_APPEND) : (openFlags | O_TRUNC);

  int outputFileFd = open (filename, openFlags,
                           S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                               | S_IWOTH); /* rw-rw-rw- */

  const int BUF_MAX_LEN = 20;
  char buf[BUF_MAX_LEN];
  ssize_t numRead;
  while ((numRead = read (STDIN_FILENO, buf, BUF_MAX_LEN)) > 0)
    {
      if (write (STDOUT_FILENO, buf, numRead) != numRead)
        errExit ("write to stdout");

      if (write (outputFileFd, buf, numRead) != numRead)
        errExit ("write to %s file", filename);
    }
  exit (EXIT_SUCCESS);
}