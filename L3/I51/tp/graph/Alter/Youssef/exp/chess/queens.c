#include <stdio.h>
#include <stdlib.h>
#define num_r(i, j) ((int)i-(int)j+(size-1))
#define num_l(i, j) (i+j)

typedef unsigned int uint;
typedef enum{false = 0, true = 1} bool;

uint* arr;
uint* columns;
uint* diag_r;
uint* diag_l;
uint size;

/* int num_r(uint i, uint j){ */
/*     return ((int)i-(int)j+(size-1)); */
/* } */

/* uint num_l(uint i, uint j){ */
/*   return i+j; */
/* } */

bool valid(uint line, uint col, uint arr[], uint size) {
    uint i;
    for(i = 0; i < line; i++) {
        if (arr[i] == col)
            return false;
    }
    for (i = 0; i < line; i++) {
        if(abs((int)arr[i] - (int)col) == abs((int)i-(int)line))
            return false;
    }
    return true;
}

bool valid2(uint line, uint col) {
    if(columns[col])
        return false;
    if(diag_r[num_r(line, col)] || diag_l[num_l(line,col)])
        return false;
    return true;
}

void print_chessboard(uint arr[], uint size) {
    int i, j;
    for(j = 0; j < size; j++) {
        printf("==");
    }
    printf("=\n");
    for(i= 0; i < size; i++) {
        printf("|");
        for(j = 0; j < size; j++) {
            if(j == arr[i]) {
                printf("Q|");
            } else {
               printf(" |");
            }
        }
        printf("\n");
    }
    for(j = 0; j < size; j++) {
        printf("==");
    }
    printf("=\n");
}

void queen(uint line) {
    if(line == size) {
      printf("One solution is : ");
      printf("[");
      for(uint i = 0; i < size-1; i++) {
          printf("%d,",arr[i]);
      }
      printf("%d]\n", arr[size-1]);
      print_chessboard(arr, size);
      return;
    }
    for(uint col = 0; col < size; col++) {
        if(valid2(line, col)) {
            arr[line] = col;
            columns[col] = true;
            diag_r[num_r(line, col)] = true;
            diag_l[num_l(line, col)] = true;

            queen(line+1);

            arr[line] = -1;
            columns[col] = false;
            diag_r[(int)line-(int)col + (size-1)] = false;
            diag_l[line+col] = false;

        }
    }
}

void print_all_solutions(uint size_bis) {
    size = size_bis;
    arr = calloc(size, sizeof(uint));
    columns = calloc(size, sizeof(uint));
    diag_r = calloc(2*size - 1, sizeof(uint));
    diag_l = calloc(2*size - 1, sizeof(uint));

    queen(0);

    free(diag_r);
    free(diag_l);
    free(columns);
    free(arr);
}


int main(void) {
    print_all_solutions(8);
    return 0;
}
