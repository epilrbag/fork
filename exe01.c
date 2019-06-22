#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  int pid;

  pid = fork();

  if (pid != 0)
  {
    pid = fork();

    if (pid != 0)
    {
      printf("%d(P)1: Eu sou o pai e meu pid é %d\n", getpid(), getpid());
      pid = wait(0);
    }
    else if (pid == 0)
    {
      pid == fork();

      if(pid != 0)
      {
        printf("\t%d(F)2: Eu sou o filho, meu pid é %d e meu pai é %d\n", getpid(), getpid(), getppid());
        pid = wait(0);
      }

      else if(pid == 0)
      {
        printf("\t\t%d(N)3: Eu sou o neto e meu pid é %d e meu pai é %d\n", getpid(), getpid(), getppid());
        pid = wait(0);
      }

      else
      {
        printf("Não consigo criar filhos\n");
        exit(-1);
      }
    }
    else
    {
      printf("Não consigo criar filhos\n");
      exit(-1);
    }
  }
  else if(pid == 0)
  {
    pid = fork();

    if(pid != 0)
    {
      pid = fork();

      if(pid != 0)
      {
        printf("%d(F)4: Eu sou o filho, meu pid é %d e meu pai é %d\n", getpid(), getpid(), getppid());
        pid = wait(0);
      }

      else if(pid == 0)
      {
        printf("%d(F)5: Eu sou o filho, meu pid é %d e meu pai é %d\n", getpid(), getpid(), getppid());
        pid = wait(0);
      }
      else
      {
        printf("Não consigo criar filhos\n");
        exit(-1);
      }
    }

    else if(pid == 0)
    {
      pid = fork();

      if(pid != 0)
      {
        printf("%d(F)6: Eu sou o filho, meu pid é %d e meu pai é %d\n", getpid(), getpid(), getppid());
        pid = wait(0);
      }

      else if(pid == 0)
      {
        printf("%d(F)7: Eu sou o filho, meu pid é %d e meu pai é %d\n", getpid(), getpid(), getppid());
        pid = wait(0);
      }

      else
      {
        printf("Não consigo criar filhos\n");
        exit(-1);
      }
    }
    else
    {
      printf("Não consigo criar filhos\n");
      exit(-1);
    }
  }
  else
  {
    printf("Não consigo criar filhos\n");
    exit(-1);
  }
}
