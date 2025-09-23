#ifndef ONEGIN_H
#define ONEGIN_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

enum Errors {
    NO_ERROR        = 0,
    OPENFILE_ERROR  = 1,
    MEMORY_ERROR    = 2
};

void failed_funk(Errors failed);
Errors counting_strings(char ** buffer, int * line_cnt);
Errors array_filling(char ** buffer, int line_cnt, char ***text);
int swap (char **ptr1, char **ptr2);
int compare(const void * x1, const void * x2);
void buble_sort(void * ptr, size_t count_lines, int ( * compare) (const void * x1, const void * x2));

#endif