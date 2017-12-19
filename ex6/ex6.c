// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the 
// `clock_gettime` procedure to time how long a single system call takes. It'll 
// do this for one million iterations, and then find the average of all of those 
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
  struct timespec start, end;
  int diff;
  
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  
  for(int i = 0; i < number_iter; i++){
    write(fileno(stdout), NULL, 0);
  }
  
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); 
  
  diff = end.tv_nsec - start.tv_nsec;
  printf("Average is %f nanoseconds\n", (double) diff / number_iter);
  return 0;
}
