#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

FILE * create_file(FILE *fp, char *filename) {
  if (NULL == (fp = fopen(filename, MODE_WRITE))) {
    perror("fopen()");
    exit(EXIT_FAILURE);
  }
  return fp;
}

int open_file(FILE *fp, char *filename, char *mode) {
  int return_value = 0;

  if (NULL == (fp = fopen(filename, mode))) {
    return_value = 1;
  }
  return return_value;
}

FILE * check_file(FILE *fp, char *filename) {
  if (NULL == (fp = fopen(filename, MODE_READ))) {
    printf("function: check_file(\"%s\", \"%s\") \n", filename, MODE_READ);
    perror("error");
  }
  return fp;
}

FILE * close_file(FILE *fp) {
  if (fp != NULL) {
    fclose(fp);
  }
  return fp;
}

int copy_file_data(FILE *out, FILE *in) {
  char ch;

  while ((ch = fgetc(in)) != EOF) {
    fputc((int)ch, out);
  }
  return 0;
}

char * check_args(char *file_out, char **argv, int argc) {
  printf("args count: %d\n", argc - 1);

  if (argc < 2) {
    printf("No input file specified, exiting...\n");
    exit(EXIT_SUCCESS);
  } else if (argc < 3) {
    printf("No output file specified, defaulting to %s\n", DEFAULT_FILE_OUT);
    strcpy(file_out, DEFAULT_FILE_OUT);
  } else {
    strcpy(file_out, argv[2]);
  }
  return file_out;
}

void print_separator(void) {
  printf("==========\n");
}

void print_args(int argc, char *argv[]) {
  int i = argc + 1;
  if (argc > 1) {
    printf("args list:\n");
    print_separator();
    while (i < argc) {
      printf("%s\n", argv[i]);
      i++;
    }
    print_separator();
  }
} 
