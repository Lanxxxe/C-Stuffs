#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void generate_sparse(int array[10][10], int max_row, int max_col){
    srand(time(NULL));
    for (int i = 0 ; i < max_row ; i++){
        for (int j = 0 ; j < max_col ; j++){
            array[i][j] = rand() % 2;
        }
    }
}

// void get_matrices(int array[10][10], int new_arr[10][10], int max_row, int max_col, int count){
//     for(int row = 0; row < max_row ; row++){
//         for (int col = 0; col < max_col ; col++){
//             if(array[row][col] != 0){
//                 new_arr[count][0] = row;
//                 new_arr[count][1] = col;
//                 new_arr[count][2] = array[row][col];
//                 count++;
//             }
//         }
//     }
// }

int main(void){
    int array[10][10];
    int new_set[10][10];
    int num_row = 3, num_col = 3, rows = 0;
    int non_zero = 0;

    generate_sparse(array, num_row, num_col);
    for(int x = 0 ; x < num_row ; x++){
        for (int y = 0 ; y < num_col ; y++){
            printf("%4d", array[x][y]);
        }
        printf("\n");
    }
    
    for(int row = 0; row < num_row ; row++){
        for (int col = 0; col < num_col ; col++){
            if(array[row][col] == 1){
                new_set[rows][0] = row+1;
                new_set[rows][1] = col+1;
                new_set[rows][2] = array[row][col];
                rows++;
                non_zero++;
            }

        }
    }
    
    printf("\n\n");

    for(int x = 0 ; x < rows ; x++){
        for (int y = 0 ; y < 3 ; y++){
            printf("%4d", new_set[x][y]);
        }
        printf("\n");
    }
}