#include <stdio.h>
#include <stdlib.h>

char* input_dynamic_base(FILE* fbuffer, size_t size, size_t increment){
    char* str;
    str = realloc(NULL, sizeof(*str)*size);
    int ch;

    size_t len = 0;

    if(!str){
        return str;
    }

    while((ch = fgetc(fbuffer)) != '\n'){

        if(ch == EOF){
            exit(1);
        }

        str[len++] = ch;

        if(len >= size){
            str = realloc(str, sizeof(*str)*(size += increment));

            if(!str){
                return str;
            }
        }

    }

    str[len++] = '\0';

    return realloc(str, sizeof(*str)*len);
}

char* input_dynamic(){
    return input_dynamic_base(stdin, 16, 8);
}

