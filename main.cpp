#include <stdio.h> 
#include <string.h>
#include <math.h>
#include <assert.h>

#include "onegin.h"

int main() {
    size_t line_cnt = 0;
    char **text = NULL; 
    char *buffer = NULL;
    
    Errors failed = counting_strings(&buffer, &line_cnt);
    failed = array_filling(&buffer, line_cnt, &text);

    if (failed != NO_ERROR) {
        failed_funk(failed);
        exit(EXIT_FAILURE);
    }

    if (failed != NO_ERROR) {
        failed_funk(failed);
        exit(EXIT_FAILURE);
    }
   
    buble_sort(text, line_cnt, compare);

    for (size_t i = 0; i < line_cnt; i++) {
        printf("%s\n", text[i]);

    }
    free(text);
    free(buffer);  
    
    return 0;
}
