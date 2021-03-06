// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE *fp;
  fp = fopen("text.txt", "w");
  if (fp == NULL) {
    puts("Could not open file");
    exit(1);
	}
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    char child[] = "Hello from the child process\n";
    fwrite(child, 1, sizeof(child), fp);
    fclose(fp);
  } else {
    char parent[] = "Hello from the parent process\n";
    fwrite(parent, 1, sizeof(parent), fp);
    fclose(fp);
  }
  return 0;
}
