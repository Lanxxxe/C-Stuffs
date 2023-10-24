// To DO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    void *next;
    int data;
    char noteData[512];
} Node;
 
Node *head = NULL;
 
//add
Node *addNode(int data, const char noteData[512]) {
    Node *new = NULL;
 
    if (head == NULL) {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        
        new->data = data;
        strcpy(new->noteData, noteData);
        head = new;
        new->next = NULL;
    }
    else {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        
        new->data = data;
        strcpy(new->noteData, noteData);
        new->next = head;
        head = new;
    }
    
    return new;
}
 
 
//delete
int removeNode(int data) {
    Node *current = head;
    Node *prev = head;
    while (current != NULL) {
        if (current->data == data) {
            //if current is head
            if (current == head) {
                head = current->next;
            }
            else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            
            return 1;
        }
        prev = current;
        current = current->next;
    }
    
    return 0;
}
 
//print node
void printList() {
    printf("\nTO DOS:\n");
    printf("------------------------\n");
    Node *current = head;
    while (current != NULL) {
        printf("ID: %d - %s\n", current->data, current->noteData);
        current = current->next;
    }
    printf("------------------------\n");
    printf("\n\n\n\n");
    return;
}
 
//menu options
void printMenu() {
    printf("1. Add New To Do\n");
    printf("2. Delete To Do\n");
    printf("3. Quit\n");
    printf(">> ");
    return;
    
}
 
//header
void printHeader() {
    printf("------------TO DO-------------");
    printf("\n\n\n\n");
}
 
int main() {
    
    printHeader();
    
    int option = 1;
    int arg1 = 0;
    int arg2 = 0;
    int toDoCount = 1;
    char toDo[512];
    
    while (option != 3) {
        printf("\n\n\n\n");
        printList();
        printMenu();
        
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1:
                //add
                printf("Enter to Do: ");
                scanf("%511[^\n]", toDo);
                getchar();
                Node *new = addNode(toDoCount,toDo);
                toDoCount++;
                printf("\n\n");
                break;
                    
            case 2:
                //delete
                printf("Enter to do ID to delete: ");
                scanf("%d", &arg1);
                int success = removeNode(arg1);
                if (!success) {
                    printf("to do ID not found!");
                }
                printf("\n\n");
                break;
            case 3:
                break;
                
            default:
                break;
        }
    }
 
    return 0;
}