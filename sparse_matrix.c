#include <stdio.h>
#define s_row 6
#define s_col 3

void displaySparse(int new_arr[10][10], int sparse_array[s_row][s_col]){
    int count = s_row;
    for(int i = 0; i < count; i++){
        int a = sparse_array[i][0] - 1;
        int b = sparse_array[i][1] - 1;
        new_arr[a][b] = sparse_array[i][2];
    }
}

int main(){
    int array2[10][10] = {0};
    int counter1, counter2;

    int sparse[s_row][s_col] = {
        {4, 4, 5},
        {1, 1, 5},
        {2, 3, 7},
        {3, 4, 5},
        {4, 2, 9},
        {4, 3, 28}
    };

    for(int x = 0 ; x < s_row ; x++){
        for(int y = 0 ; y < s_col; y++){
            printf("%d ", sparse[x][y]);
        }
        printf("\n");
    }

    displaySparse(array2, sparse);
    printf("\n\n");

    for (int i = 0; i < sparse[0][0]; i++){
        for (int j = 0; j < sparse[0][1]; j++){
            printf("%4d", array2[i][j]);
        } 
        printf("\n");
    }
    return 0;
}
