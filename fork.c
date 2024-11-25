#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fork.h"

int err(){
  printf("errno %d\n",errno);
  printf("%s\n",strerror(errno));
  exit(1);
}

int randomFive(){
    int x;
    int bytes;
    int r_file = open("/dev/random", O_RDONLY, 0);
    if (r_file == -1)err();
    bytes = read(r_file, &x, 4);
    if (bytes == -1){
        err();
    }
    x = x % 5;
    x++;
    return x;
}

void forkTwo(){
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p;
  p = fork();
  if(p<0){
    perror("fork fail");
    exit(1);
  } else if ( p == 0){
      int time = randomFive();
      printf("%d %dsec\n", getpid(), time);
      sleep(time);
  }else{
      printf("Hello from Parent!\n");
  }
}