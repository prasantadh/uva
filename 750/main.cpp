#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int rowgrp[8] = {0};
int count = 0;
int N, frow, fcol; //testcases, fixed row, fixed column

// return 
//      true if a queen can be placed in row, col
//      false otherwise 
bool place(int row, int col) {
    for(int c = 0; c < col; ++c) {
        if (rowgrp[c] == row) return false;
        if (abs(c - col) == abs(rowgrp[c] - row))
            return false;
    }
    return true;
}

// try to place a queen on the col-th column
// by trying out all rows
void backtrack(int col) {
    if (col == fcol && rowgrp[fcol - 1] != frow - 1) return;
    if (col == 8) {
        printf("%2d      ", ++count);
        for(unsigned int c = 0; c < col - 1; ++c)
            printf("%d ", rowgrp[c] + 1);
        printf("%d\n", rowgrp[col-1] + 1);
        return;
    }
    for(int row = 0; row < 8; ++row)
        if (place(row, col)) {
            rowgrp[col] = row;
            backtrack(col+1);
        }

    return;
}

int main(int argc, char **argv) {
    cin >> N;
    while(N--) {
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n") ;
        cin >> frow >> fcol;
        count = 0;
        backtrack(0);
        if (N != 0)
            printf("\n");
    }
    return 0;
}
