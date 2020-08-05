#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *escape(char *str) {
  char *buf = malloc(strlen(str) + 1);
  char *q = buf;

  for (char *p = str; *p != '\0'; p++) {
    if (*p != '\\') {
      *q++ = *p;
      continue;
    }
    p++;
    if (*p == '\0') {
      *q++ = '\\';
      break;
    } else if (*p == 't') {
      *q++ = '\t';
    } else if (*p == 'n') {
      *q++ = '\n';
    } else {
      *q++ = *p;
    }
  }
  *q = '\0';

  return buf;
}

int main(int argc, char **argv) {
  char **args = argv + 1;
  bool escape_flg = false;

  // read option
  if (*args != NULL && strcmp(*args, "-e") == 0) {
    escape_flg = true;
    args++;
  }

  // echo args
  char *delim = "";
  for (char **p = args; *p != NULL; p++) {
    printf("%s%s", delim, escape_flg ? escape(*p) : *p);
    delim = " ";
  }
  printf("\n");

  return 0;
}
