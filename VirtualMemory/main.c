#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    The purpose of this file is to check whether the dynamically allocated
    variable is located on the low memmory address or high memory address.

    I am using 64-bit machine and printed result on the terminal is
   0x7fdd0d405900. The highest memoryh address possible is '0xffffffffffffffff'
   and the lowest is '0x0'. '0x7fdd0d405900' is small compared to
   '0xffffffffffffffff'.

    That mean as we expected, dynamically allocated variable would be located in
   Heap of the virtual memory.
*/

int main(void) {
  char* s;

  s = strdup("Holberton");
  if (s == NULL) {
    fprintf(stderr, "Can't allocate memory with malloc\n");
    return (EXIT_FAILURE);
  }
  printf("%p\n", (void*)s);
  return (EXIT_SUCCESS);
}