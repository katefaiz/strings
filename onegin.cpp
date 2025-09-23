#include "onegin.h"

Errors counting_strings(char ** buffer, int * line_cnt) {
    assert(buffer != 0);
    assert(line_cnt != 0);

    FILE * filestream = fopen("data_for_str.txt", "r");
    if (filestream == NULL) 
        return OPENFILE_ERROR;
    
    fseek(filestream, 0, SEEK_END);  // TODO: ок, так умеешь, теперь сделай с помощью функции stat (так быстрее)
    long fsize = ftell(filestream); 
    fseek(filestream, 0, SEEK_SET); 
    

    *buffer = (char*)calloc(fsize + 1, sizeof(char));
    if (*buffer == 0)
        return MEMORY_ERROR;  

    fread(*buffer, sizeof(char), fsize, filestream); 
    fclose(filestream);
    (*buffer)[fsize] = '\0';

    *line_cnt = 0; 
    char * ptr = * buffer;
    while (*ptr != '\0') {
        if (ptr == *buffer || *(ptr - 1) == '\n') { //если это начало файла или начало новой строки
            if (*ptr != '\n')
                (*line_cnt)++;
        }
        ptr++;
    }
    
    return NO_ERROR;
}

Errors array_filling(char ** buffer, int line_cnt, char ***text) { 
    assert(line_cnt != 0);
    assert(text != 0);

   
    *text = (char **)calloc(line_cnt, sizeof(char*)); 
    if (*text == NULL) 
        return MEMORY_ERROR;

    char *ptr = *buffer; 
    int i = 0;
    while ( *ptr != '\0' && i < line_cnt) { 
        /*if (*ptr == '\n') {
            ptr++;
            continue;
        }*/
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
        case NO_ERROR: 
            break;
        case OPENFILE_ERROR:
            printf("File reading error\n");
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

    const char * ptr_str1 = *(const char * const *)x1; 
    const char * ptr_str2 = *(const char * const *)x2;
    return strcmp(ptr_str1, ptr_str2);
}

void buble_sort(void * ptr, size_t count_lines, int ( * compare) (const void * x1, const void * x2)) {
    assert(ptr != 0);
   

    char ** text = (char **)ptr; 

    for (size_t i = 0; i < count_lines - 1; i++) {
        for (size_t j = 0; j < count_lines - 1 - i; j++) {
            if (compare((const void *)&text[j], (const void *)&text[j + 1]) > 0)
                swap(&text[j], &text[j + 1]);
        }
    }

    return;
}
