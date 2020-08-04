#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char* fmt = "%s";
  for(argv++; *argv != NULL; argv++) {
    printf(fmt, *argv);
    fmt = " %s";
  }
  printf("\n");
      
  return 0;
}
