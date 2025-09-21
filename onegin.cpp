#include "onegin.h"

Errors counting_strings(char ** buffer, int * line_cnt) {
    assert(buffer != 0);
    assert(line_cnt != 0);

    FILE * filestream = fopen("data_for_str.txt", "r");
    if (filestream == NULL) 
        return OPENFILE_ERROR;
    
    fseek(filestream, 0, SEEK_END); 
    long fsize = ftell(filestream); 
    fseek(filestream, 0, SEEK_SET); 

    *buffer = (char*)calloc(fsize + 1, sizeof(char));
    if (*buffer == 0)
        return MEMORY_ERROR;  

    fread(*buffer, sizeof(char), fsize, filestream); 
    (*buffer)[fsize] = '\0';
    *line_cnt = 1; 
    for (int i = 0; (*buffer)[i] != '\0'; i++) {
        if ((*buffer)[i] == '\n')
            (*line_cnt)++;
    }
    fclose(filestream);
    return NO_ERROR;
}

Errors array_filling(char ** buffer, int line_cnt, char ***text) { 
    assert(line_cnt != 0);
    assert(text != 0);

    //size_t count_lines = counting_strings(&(*buffer));
   
    *text = (char **)calloc(line_cnt, sizeof(char*)); 
    if (*text == NULL) 
        return MEMORY_ERROR;

    char *ptr = *buffer; 
    int i = 0;
    while ( *ptr != '\0' && i < line_cnt) { 
        (*text)[i] = ptr;
        i++;
        while(*ptr != '\0' && *ptr != '\n')
            ptr++;
        if (*ptr == '\n') {
            *ptr = '\0';
            ptr++;
        }
        else
            break;  
    }
    return NO_ERROR;
}

void failed_funk(Errors failed) {
    switch(failed) {
        case OPENFILE_ERROR:
            printf("File reading error\n");
            break;
        case NO_ERROR:
            break;
        case MEMORY_ERROR:
            printf("Memory allocation error\n");
            break;
        default: 
            printf("Error\n");
        
    }
    return;
}
 
int swap (char **ptr1, char **ptr2) {
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    char *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    return 0;
}

int compare(const void * x1, const void * x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    const char * ptr_str1 = *(const char **)x1; // получаю указатели на строки 
    const char * ptr_str2 = *(const char **)x2;
    return strcmp(ptr_str1, ptr_str2);
}

void buble_sort(void * ptr, size_t count_lines, size_t size, int ( * compare) (const void * x1, const void * x2)) {
    char ** text = (char **)ptr; 

    for (int i = 0; i < count_lines - 1; i++) {
        for (int j = 0; j < count_lines - 1 - i; j++) {
            if (compare((const void *)&text[j], (const void *)&text[j + 1]) > 0)
                swap(&text[j], &text[j + 1]);
        }
    }

    return;
}
