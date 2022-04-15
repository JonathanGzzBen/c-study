#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ename.c.inc"
#include "error_functions.h"
#include "tlpi_hdr.h"

NORETURN static void
terminate (Boolean useExit3)
{
  char *s = getenv ("EF_DUMPCORE");

  if (s != NULL && *s != '\0')
    {
      abort ();
    }
  else if (useExit3)
    {
      exit (EXIT_FAILURE);
    }
  else
    {
      _exit (EXIT_FAILURE);
    }
}

static void
outputError (Boolean useErr, int err, Boolean flushStdout, const char *format,
             va_list ap)
{
#define BUF_SIZE 500
  char userMsg[BUF_SIZE];
  vsnprintf (userMsg, BUF_SIZE, format, ap);

  char errText[BUF_SIZE];
  if (useErr)
    {
      snprintf (errText, BUF_SIZE, " [%s %s]",
                (err > 0) && (err <= MAX_ENAME) ? ename[err] : "?UNKNOWN?",
                strerror (err));
    }
  else
    {
      snprintf (errText, BUF_SIZE, ":");
    }

  char buf[BUF_SIZE];
  snprintf (buf, BUF_SIZE, "ERROR%s %s\n", errText, userMsg);

  if (flushStdout)
    {
      fflush (stdout);
    }
  fputs (buf, stderr);
  fflush (stderr);
}

void
errMsg (const char *format, ...)
{
  int savedErrno = errno;
  va_list argList;
  va_start (argList, format);
  outputError (TRUE, errno, TRUE, format, argList);
  va_end (argList);
  errno = savedErrno;
}

void
errExit (const char *format, ...)
{
  va_list argList;
  va_start (argList, format);
  outputError (TRUE, errno, TRUE, format, argList);
  va_end (argList);
  terminate (TRUE);
}

void
err_exit (const char *format, ...)
{
  va_list argList;
  va_start (argList, format);
  outputError (TRUE, errno, FALSE, format, argList);
  va_end (argList);
  terminate (FALSE);
}

void
errExitEN (int errnum, const char *format, ...)
{
  va_list argList;
  va_start (argList, format);
  outputError (TRUE, errnum, TRUE, format, argList);
  va_end (argList);
  terminate (TRUE);
}

void
fatal (const char *format, ...)
{
  va_list argList;
  va_start (argList, format);
  outputError (FALSE, 0, TRUE, format, argList);
  va_end (argList);
  terminate (TRUE);
}

void
usageErr (const char *format, ...)
{
  fflush (stdout);
  fputs ("Usage: ", stderr);
  va_list argList;
  va_start (argList, format);
  vfprintf (stderr, format, argList);
  va_end (argList);
  fflush (stderr);
  exit (EXIT_FAILURE);
}

void
cmdLineErr (const char *format, ...)
{
  fflush (stdout);
  fputs ("Command-line usage error: ", stderr);

  va_list argList;
  va_start (argList, format);
  vfprintf (stderr, format, argList);
  va_end (argList);

  fflush (stderr);
  exit (EXIT_FAILURE);
}