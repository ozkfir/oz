//
// Created by oz on 28/11/22.
//


#include <stdio.h>

#define Len 10

int length_way(int[Len][Len], int, int);

int way(int[Len][Len], int, int);

void build_mat(int[Len][Len]);


int way(int mat[Len][Len], int i, int j) {
    return (mat[i][j] > 0);
}

void build_mat(int mat[Len][Len]) {
    for (int i = 0; i < Len; i++) {
        for (int j = 0; j < Len; j++) {
            scanf(" %d", &mat[i][j]);
            if (mat[i][j] == 0 && i != j)
                mat[i][j] = -1;
        }
    }
    for (int k = 0; k < Len; k++) {
        for (int i = 0; i < Len; i++) {
            for (int j = 0; j < Len; j++) {
                if ((mat[i][j] < 0 || mat[i][j] > mat[i][k] + mat[k][j]) && mat[i][k] > 0 && mat[k][j] > 0) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
}

int length_way(int mat[Len][Len], int l, int m) {
    if (mat[l][m]<=0)
        return -1;
    return mat[l][m];
}
