#ifndef LINUX_PROGRAMMING_INTERFACE_ERROR_FUNCTIONS_H
#define LINUX_PROGRAMMING_INTERFACE_ERROR_FUNCTIONS_H

void errMsg (const char *format, ...);

#ifdef __GNUC__
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit (const char *format, ...) NORETURN;
void err_exit (const char *format, ...) NORETURN;
void errExitEN (int errnum, const char *format, ...) NORETURN;
void fatal (const char *format, ...) NORETURN;
void usageErr (const char *format, ...) NORETURN;
void cmdLineErr (const char *format, ...) NORETURN;

#endif // LINUX_PROGRAMMING_INTERFACE_ERROR_FUNCTIONS_H
