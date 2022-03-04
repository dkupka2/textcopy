#include <stdio.h>
#include <stdlib.h>
#include "textcopy.h"

#define FILE_IN argv[1] 
#define DEFAULT_FILE_OUT "file.out"
#define MODE_READ "r"
#define MODE_WRITE "w"

int main(int argc, char *argv[]) {
  char file_out[256];
  FILE *ifptr,
       *ofptr;

  check_args(file_out, argv, argc);

  if ((ifptr = check_file(ifptr, FILE_IN)) == NULL) {
    perror("fopen() ");
    exit(EXIT_FAILURE);
  }

  if ((ofptr = check_file(ofptr, file_out)) == NULL) {
    printf("Creating file %s...\n", file_out);
    ofptr = create_file(ofptr, file_out);
  } else {
    open_file(ofptr, file_out, MODE_WRITE);
  }

  copy_file_data(ofptr, ifptr);

  ofptr = close_file(ofptr);
  ifptr = close_file(ifptr);

  exit(EXIT_SUCCESS);
}
