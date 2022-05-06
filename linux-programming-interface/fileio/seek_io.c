#include "error_functions.h"
#include "get_num.h"
#include <ctype.h>
#include <fcntl.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

int
main (int argc, char *argv[])
{
  if (argc < 3 || strncmp (argv[1], "--help", 6) == 0)
    usageErr ("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",
              argv[0]);

  int fd = open (argv[1], O_RDWR | O_CREAT,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                     | S_IWOTH); /* rw-rw-rw- */

  if (fd == -1)
    errExit ("open");

  for (int ap = 2; ap < argc; ++ap)
    {
      switch (argv[ap][0])
        {
        case 'r':
        case 'R':
          {
            size_t len = getLong (&argv[ap][1], GN_ANY_BASE, argv[ap]);
            unsigned char *buf = malloc (len);
            if (buf == NULL)
              errExit ("malloc");

            ssize_t numRead = read (fd, buf, len);
            if (numRead == -1)
              errExit ("read");

            if (numRead == 0)
              {
                printf ("%s: end-of-file\n", argv[ap]);
              }
            else
              {
                printf ("%s: ", argv[ap]);
                for (int j = 0; j < numRead; ++j)
                  {
                    if (argv[ap][0] == 'r')
                      printf ("%c", isprint (buf[j]) ? buf[j] : '?');
                    else
                      printf ("%02x", buf[j]);
                  }
                printf ("\n");
              }
            free (buf);
            break;
          }
        case 'w':
          {
            ssize_t numWritten
                = write (fd, &argv[ap][1], strlen (&argv[ap][1]));

            if (numWritten == -1)
              errExit ("write");

            printf ("%s: wrote %ld bytes\n", argv[ap], (long)numWritten);

            break;
          }
        case 's':
          {
            off_t offset = getLong (&argv[ap][1], GN_ANY_BASE, argv[ap]);
            if (lseek (fd, offset, SEEK_SET) == -1)
              errExit ("lseek");
            printf ("%s: seek succeeded, offset: %ld\n", argv[ap],
                    (long)offset);
            break;
          }
        default:
          cmdLineErr ("Argument must start with [rRws]: %s\n", argv[ap]);
        }
    }
  exit (EXIT_SUCCESS);
}