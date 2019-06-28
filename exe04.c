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
    pid = fork();

    if(pid != 0)
    {
      printf("Eu sou o pai e meu pid é %d\n", getpid());
      pid = wait(0);
    }

    else if(pid == 0)
    {
      pid = fork();

      if (pid != 0)
      {
        printf("Eu sou o filho e meu pid %d, e o meu pai %d\n", getpid(), getppid());
        pid = wait(0);
      }

      else if(pid == 0)
      {
        printf("Eu sou o neto e meu pid %d, e o meu pai %d\n", getpid(), getppid());
        //pid = wait(0);
      }

      else
      {
        printf("Não consigo criar os filhos\n");
        exit(-1);
      }
      pid = wait(0);
    }
  }
  else if(pid == 0)
  {
    pid = fork();

    if(pid != 0)
    {
      printf("Eu sou o outro filho, meu pid é %d e o meu pai é %d\n", getpid(), getppid());
      pid = wait(0);
    }
    else if(pid == 0)
    {
      printf("Eu sou outro neto e meu pid é %d, e o meu pai é %d\n", getpid(), getppid());
    }

    else
    {
      printf("Não consigo criar filhos\n");
      exit(-1);
    }
    pid = wait(0);
  }

  else
  {
    printf("Não consigo criar filhos\n");
    exit(-1);
  }
}
