//
// Created by oz on 04/12/22.
//
#include <stdio.h>
#include "my_mat.h"
#define Len 10


int main()
{
    int mat[Len][Len];
    char command;
    scanf("%c",&command);
    while(command!='D')
    {
        if(command=='A')
        {
            build_mat(mat);

        }
        else if(command=='B')
        {

            int i, j;
            scanf("%d%d", &i, &j);
            if(way(mat,i,j)!=0)
                printf("True\n");
            else
                printf("False\n");

        }
        else
        {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%d\n",length_way(mat,i,j));
        }
    }
    return 0;
}