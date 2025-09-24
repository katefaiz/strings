#ifndef ONEGIN_H
#define ONEGIN_H

enum Errors {
    NO_ERROR        = 0,
    OPENFILE_ERROR  = 1,
    MEMORY_ERROR    = 2,
    FILE_SIZE_ERROR = 3
};

void failed_funk(Errors failed);
Errors counting_strings(char ** buffer, size_t * line_cnt);
Errors array_filling(char ** buffer, size_t line_cnt, char ***text);
int swap (char **ptr1, char **ptr2);
int compare(const void * x1, const void * x2);
void buble_sort(void * ptr, size_t count_lines, int ( * compare) (const void * x1, const void * x2));

#endif // ONEGIN_H