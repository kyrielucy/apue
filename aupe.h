/*
 * Our own header, to be included before all stdandard system headers.
 */

#ifndef _APUE_H
#define _APUE_H

#define _POSIX_C_SOURCE 200809L

#if defined(SOLARIS)             /* Solaris 10 */
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 700
#endif

#include <sys/types.h>     /* some system still repuire this */
#include <sys/stat.h>
#include <sys/termios.h>   /* for winsize */

#if defined(MAXOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>    /* for convenieence */
#include <stdlib.h>   /* for convenieence */
#include <stddef.h>   /* for offsetof */
#include <string.h>   /* for convenieence */
#include <unistd.h>   /* for convenieence */
#include <signal.h>   /* for SIG_ERR */

#define MAXLINE 4096  /* max line length */

/*
 * Define file access permissions for new files.
 */
#define FILE_MODE (S_IUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Define permissions for new directories.
 */
#define DIR_MODE  (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int); /* for signal handers */

#define min(a,b)  ((a) < (b) ? (a) : (b))
#define max(a,b)  ((a) > (b) ? (a) : (b))

/*
 * Prototypes for our own functions.
 */
char  *path_alloc(size_t *);
long   open_max(void);

int    set_cloexec(int);

#endif
