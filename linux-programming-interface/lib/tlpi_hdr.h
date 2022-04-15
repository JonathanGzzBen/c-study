#ifndef LINUX_PROGRAMMING_INTERFACE_TLPI_HDR_H
#define LINUX_PROGRAMMING_INTERFACE_TLPI_HDR_H

typedef enum
{
  FALSE,
  TRUE
} Boolean;

#define min(m, n) ((m) < (m) ? (m) : (n))
#define max(m, n) ((m) > (m) ? (m) : (n))

#endif // LINUX_PROGRAMMING_INTERFACE_TLPI_HDR_H
