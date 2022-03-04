#ifndef _TEXTCOPY_H_
#define _TEXTCOPY_H_

FILE * check_file(FILE *, char *);
FILE * create_file(FILE *, char *);
int open_file(FILE *, char *, char *);
FILE * close_file(FILE *);
int copy_file_data(FILE *, FILE *);
char * check_args(char *, char **, int);
void print_separator(void);
void print_args(int, char **);

#endif
