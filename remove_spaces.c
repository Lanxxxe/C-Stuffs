#include <stdio.h>
#include <string.h>

int main(void){
    char string[100];
    char noSpace[100];
    int counter = 0, sep = 0;

    printf("Enter the strings: ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0 ; i < strlen(string) ; i++){
        if (string[i] != ' '){
            noSpace[counter] = string[i];
            counter++;
        }
    }
    noSpace[counter] = '\0';

    printf("%s", noSpace);

}