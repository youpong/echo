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
    } else if (*p == '\\') {
      *q++ = '\\';
    }
  }
  *q = '\0';

  return buf;
}

int main(int argc, char **argv) {
  bool escape_flg = false;

  if (argc == 1) {
    printf("\n");
    return 0;
  }

  if (strcmp(*(argv + 1), "-e") == 0) {
    escape_flg = true;
    argv++;
  }

  char *fmt = "%s";
  for (argv++; *argv != NULL; argv++) {

    printf(fmt, escape_flg ? escape(*argv) : *argv);
    fmt = " %s";
  }
  printf("\n");

  return 0;
}
