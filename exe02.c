#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;

  pid = fork();

  if(pid != 0)
  {
    printf("Eu sou o pai e meu pid é %d\n", getpid());
    pid = wait(0);
  }

  else if(pid == 0)
  {
    printf("Eu sou o filho, meu pid é %d e do meu pai é %d\n", getpid(), getppid());
    pid = wait(0);
  }

  else
  {
    printf("Não consigo criar filhos\n");
    pid = wait(0);
  }
}
