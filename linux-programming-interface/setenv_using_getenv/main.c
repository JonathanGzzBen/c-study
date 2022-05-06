#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/*
 * Implement setenv() and unsetenv() using getenv(), putenv(), and,
 * where necessary, code that directly modifies environ. Your version
 * of unsetenv() should check to see whether there are multiple
 * definitions of an environment variable, and remove them all (which
 * is what the glibc version of unsetenv() does).
 */
extern char **environ;

int
m_setenv (const char *name, const char *value, int overwrite)
{
  if (overwrite == 0 && getenv (name) != NULL)
    return 0;

  const size_t nameLen = strlen (name);
  const size_t valueLen = strlen (value);

  char *newEnvironmentVariable
      = (char *)malloc (sizeof (char) * (nameLen + valueLen + 1));

  memcpy (newEnvironmentVariable, name, nameLen);
  newEnvironmentVariable[nameLen] = '=';
  memcpy (&newEnvironmentVariable[nameLen + 1], value, valueLen);

  return putenv (newEnvironmentVariable) == 0 ? 0 : -1;
}

int
m_unsetenv (const char *name)
{
  size_t nameLen = strlen (name);
  for (char **ep = environ; *ep != NULL; ep++)
    if (strncmp (*ep, name, nameLen) == 0 && *ep[nameLen] != '=')
      {
        char **moveEnvPointersDown = ep;
        do
          moveEnvPointersDown[0] = moveEnvPointersDown[1];
        while (*moveEnvPointersDown++);
      }
}

void
print_env ()
{
  for (char **ep = environ; *ep != NULL; ep++)
    puts (*ep);
}

int
main (void)
{
  clearenv ();
  m_setenv ("Comes", "dura", 0);
  m_setenv ("Comes", "dura", 0);
  m_setenv ("Comes", "dura", 0);
  m_setenv ("Atelier", "Sophie", 0);
  puts ("Initial environment:");
  print_env ();
  m_unsetenv ("Comes");
  puts ("Final environment:");
  print_env ();
  return 0;
}