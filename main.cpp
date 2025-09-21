#include "onegin.h"

int main() {
    int line_cnt = 0;
    char **text = NULL; 
    char *buffer = NULL;
    
    Errors failed = counting_strings(&buffer, &line_cnt);
    if (failed == NO_ERROR)
        failed = array_filling(&buffer, line_cnt, &text); 

    failed_funk(failed); 

    //qsort(text, line_cnt, sizeof(char*), compare); 
    buble_sort(text, line_cnt, sizeof(char*), compare);

    if (failed == 0) {
        for (int i = 0; i < line_cnt; i++) {
            printf("%s\n", text[i]);
           
        }
        free(text);
        
    }
    return 0;
}
