#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
void header()
{
    for (int topLine = 1; topLine <= 147; topLine++) {
        printf("%c", 205);
    }
    printf("\n%c", 186);
    for (int space = 1; space <= 7; space++) {
        printf(" ");
    }
    printf("METHOD");
    for (int space = 1; space <= 7; space++) {
        printf(" ");
    }
    printf("%c", 186);
    for (int space = 1; space <= 8; space++) {
        printf(" ");
    }
    printf("SIZE");
    for (int space = 1; space <= 8; space++) {
        printf(" ");
    }
    printf("%c", 186);
    for (int space = 1; space <= 6; space++) {
        printf(" ");
    }
    printf("isEMPTY?");
    for (int space = 1; space <= 6; space++) {
        printf(" ");
    }
    printf("%c", 186);
    for (int space = 1; space <= 4; space++){
        printf(" ");
    }
    printf("RETURN VALUE");
    for (int space = 1; space <= 4; space++){
        printf(" ");
    }
    printf("%c", 186);
    for (int space = 1; space <= 8; space++){
        printf(" ");
    }
    printf("TOP");
    for (int space = 1; space <= 9; space++){
        printf(" ");
    }
    printf("%c", 186);
    for (int space = 1; space <= 13; space++){
        printf(" ");
    }
    printf("STACK CONTENTS");
    for (int space = 1; space <= 13; space++){
        printf(" ");
    }
    printf("%c\n", 186);
    for (int bottomLine = 1; bottomLine <= 147; bottomLine++){
        printf("%c", 205);
    }
}
void table(char all_Process[100][100][100], int spaceOccupied, int methodloops){
    for (int i = 0; i < methodloops; i++){
        printf("\n%c", 186);
        for (int space = 1; space <= 4; space++){
            printf(" ");
        }
        printf("%s", all_Process[i][0]);
        for (int space = 1; space <= 16 - strlen(all_Process[i][0]); space++){
            printf(" ");
        }
        printf("%c", 186);
        for (int space = 1; space <= 4; space++){
            printf(" ");
        }
        printf("%s", all_Process[i][1]);
        for (int space = 1; space <= 16 - strlen(all_Process[i][1]); space++){
            printf(" ");
        }
        printf("%c", 186);
        for (int space = 1; space <= 4; space++){
            printf(" ");
        }
        printf("%s", all_Process[i][3]);
        for (int space = 1; space <= 16 - strlen(all_Process[i][3]); space++){
            printf(" ");
        }
        printf("%c", 186);
        for (int space = 1; space <= 4; space++){
            printf(" ");
        }
        printf("%s", all_Process[i][2]);
        for (int space = 1; space <= 16 - strlen(all_Process[i][2]); space++){
            printf(" ");
        }
        printf("%c", 186);
        for (int space = 1; space <= 4; space++){
            printf(" ");
        }
        printf("%s", all_Process[i][4]);
        for (int space = 1; space <= 16 - strlen(all_Process[i][4]); space++){
            printf(" ");
        }
        printf("%c", 186);
        if (atoi(all_Process[i][1]) != 0){
            for (int space = 1; space <= 3; space++){
                printf(" ");
            }
            printf("(");
            for (int j = 0; j < atoi(all_Process[i][1]); j++){

                printf("%s", all_Process[i][j + 6]);
                if ((j + 1) != atoi(all_Process[i][1])){
                    printf(",");
                }
            }
            printf(")");
            for (int space = 1; space <= 36 - atoi(all_Process[i][5]); space++){
                printf(" ");
            }
            printf("%c\n", 186);
        }else{
            for (int space = 1; space <= 3; space++){
                printf(" ");
            }
            printf("NULL");
            for (int space = 1; space <= 36 - 3; space++){
                printf(" ");
            }
            printf("%c\n", 186);
        }
        for (int bottomLine = 1; bottomLine <= 147; bottomLine++){
            printf("%c", 205);
        }
    }
}
void pop(char records[100][100][100], int stacksize, int methodloops){
    char temp[100];
    strcpy(temp, records[methodloops][stacksize + 5]);
    strcpy(records[methodloops][stacksize + 5], temp);
}
int main(void){
    int userMenu, c;
    int stackSize = 0, spaceOccupied = 0, methodLoops = 0;
    char stackContent[100][10];
    char methodUse[10], returnValue[10], boolValue[10], numInput[10], tempString[10], elementSize[10];
    char recordOfMethods[100][100][100];
    char TopValue[10], StackSize[10];
    bool loop = true;
    while (loop){
        header();
        table(recordOfMethods, spaceOccupied, methodLoops);
        printf("\n\n 1 -> Push \n 2 -> Pop \n 3 -> Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &userMenu);
        while ((c = getchar()) != '\n' && c != EOF);
        switch (userMenu){
        case 1:
            printf("Enter the number: ");
            fgets(numInput, sizeof(numInput), stdin);
            for (int i = 1; i <= strlen(numInput); i++){
                spaceOccupied++;
            }
            snprintf(elementSize, sizeof(spaceOccupied), "%d", spaceOccupied);
            numInput[strcspn(numInput, "\n")] = '\0';
            strcpy(stackContent[stackSize], numInput);
            strcpy(TopValue, numInput);
            stackSize++;
            snprintf(StackSize, sizeof(StackSize), "%d", stackSize);
            sprintf(methodUse, "Push(%s)", numInput);
            strcpy(returnValue, "-");
            if (stackSize == 0){
                strcpy(boolValue, "True");
            }else{
                strcpy(boolValue, "False");
            }
            strcpy(recordOfMethods[methodLoops][0], methodUse);
            strcpy(recordOfMethods[methodLoops][1], StackSize);
            strcpy(recordOfMethods[methodLoops][2], returnValue);
            strcpy(recordOfMethods[methodLoops][3], boolValue);
            strcpy(recordOfMethods[methodLoops][4], TopValue);
            strcpy(recordOfMethods[methodLoops][5], elementSize);
            for (int item = 0; item < stackSize; item++){
                strcpy(recordOfMethods[methodLoops][item + 6], stackContent[item]);
            }
            methodLoops++;
            break;
        case 2:
            if (stackSize == 0){
                printf("Error");
                sleep(3);
                system("cls");
            }
            else{
                stackSize--;
                snprintf(StackSize, sizeof(StackSize), "%d", stackSize);
                if ((stackSize) == 0){
                    spaceOccupied -= 2;
                    snprintf(elementSize, sizeof(elementSize), "%d", spaceOccupied);
                }else{
                    spaceOccupied -= (strlen(stackContent[stackSize]) + 1);
                    snprintf(elementSize, sizeof(elementSize), "%d", spaceOccupied);
                }
                if ((stackSize) == 0){
                    strcpy(TopValue, "-");
                }else{
                    strcpy(TopValue, stackContent[stackSize - 1]);
                }
                strcpy(methodUse, "Pop()");
                strcpy(returnValue, stackContent[stackSize]);
                if ((stackSize) == 0){
                    strcpy(boolValue, "True");
                }else{
                    strcpy(boolValue, "False");
                }
                pop(recordOfMethods, stackSize + 1, methodLoops - 1);
                strcpy(recordOfMethods[methodLoops][0], methodUse);
                strcpy(recordOfMethods[methodLoops][1], StackSize);
                strcpy(recordOfMethods[methodLoops][2], returnValue);
                strcpy(recordOfMethods[methodLoops][3], boolValue);
                strcpy(recordOfMethods[methodLoops][4], TopValue);
                strcpy(recordOfMethods[methodLoops][5], elementSize);
                for (int item = 0; item < stackSize; item++){
                    strcpy(recordOfMethods[methodLoops][item + 6], recordOfMethods[methodLoops - 1][item + 6]);
                }
                methodLoops++;
            }
            break;
        case 3:
            header();
            table(recordOfMethods, spaceOccupied, methodLoops);
            loop = false;
            break;
        default:
            break;
        }
    }
}
