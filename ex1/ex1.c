// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int x = 100;
  printf("x = %d\n", x); //should be 100

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    puts("Inside child");
    printf("x = %d\n", x); //should be 100
    x += 5;
    printf("x = %d\n", x); //should be 105
  } else {
    puts("Inside parent");
    printf("x = %d\n", x); //should be 100
    x += 15;
    printf("x = %d\n", x); //should be 115
  }
  return 0;
}
