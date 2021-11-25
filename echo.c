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
  bool escape_flg = false;

  ++argv;

  // read option
  if (*argv != NULL && strcmp(*argv, "-e") == 0) {
    escape_flg = true;
    ++argv;
  }

  // echo args
  char *delim = "";
  for (; *argv != NULL; ++argv) {
    printf("%s%s", delim, escape_flg ? escape(*argv) : *argv);
    delim = " ";
  }
  printf("\n");

  return 0;
}
