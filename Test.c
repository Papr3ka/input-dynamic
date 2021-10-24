#include "Input-Dynamic.h"

int main(){
    printf("Enter Text\n");
    char* text = input_dynamic();
    printf("%s\n", text);
    free(text);

    return 0;
}