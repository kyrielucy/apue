#include "apue.h"
#include <sys/wait.h>

static void sig_intr(int); /* our signal-catching function */

int
main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  if (signal(SIGINT, sig_intr) == SIG_ERR)
    err_sys("signal error");

  printf("%% "); /* print prompt */

  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') /* \n\0 */
      buf[strlen(buf) - 1] = '\0';

    if((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid ==0 ) { /* child */
      execlp(buf, buf, (char *)0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    /* parent */
    if ((pid = waitpid(pid, &status, 0)) < 0)
      err_sys("waitpid error");
    printf("%% ");
  }
  exit(0);
}

void
sig_intr(int signo)
{
  printf("interrupt\n%% ");
}
