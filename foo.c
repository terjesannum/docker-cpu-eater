#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int forks = 0;
  if(argc == 2) {
    if(sscanf(argv[1], "%i", &forks) != 1) {
      fprintf(stderr, "usage: %s <forks>\n", argv[0]);
      return 1;
    }
  }
  int i=0;
  pid_t pid = 1;
  while(1) {
    if(pid>0 && (forks==-1 || i<forks)) {
      printf("forking %d\n", ++i);
      fflush(stdout);
      pid = fork();
      if(pid < 0) {
        fprintf(stderr, "fork failed..\n");
        fflush(stderr);
      }
    }
  }
}
