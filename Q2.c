#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
void main() {
  pid_t pid = fork();
  //given the command as input to 'c', here 'ls -l' given manually
  char *c="ls -l";

/*On success, fork() returns the PID of the child process which is greater than 0 in the parent process. 
Inside the child process, the return value is 0. */

  if(pid == 0) {
    printf("Child process:\n");
    system(c);
    exit(0);
  }
  else if(pid > 0) {
    printf("Parent process:\n");

    printf("Waiting for child process to finish.\n");
    wait(NULL);
    printf("Child process has finished execution.\n");
  }
  else {
    printf("Not able to create child process.\n");
  }
}