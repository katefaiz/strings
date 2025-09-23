#include "onegin.h"

int main() {
    int line_cnt = 0;
    char **text = NULL; 
    char *buffer = NULL;
    
    Errors failed = counting_strings(&buffer, &line_cnt);
    if (failed == NO_ERROR)
        failed = array_filling(&buffer, line_cnt, &text);
    else {
        exit(EXIT_FAILURE);
    }
    if (failed != NO_ERROR)
        exit(EXIT_FAILURE);
    failed_funk(failed); 

    buble_sort(text, line_cnt, compare);

    if (failed == NO_ERROR) {
        for (int i = 0; i < line_cnt; i++) {
            printf("%s\n", text[i]);
           
        }
        free(text);
        free(buffer); 
        
    }
    return 0;
}
