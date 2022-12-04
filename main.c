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
    do
    {
        scanf(" %c",&command);
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
        else if (command=='C')
        {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%d\n",length_way(mat,i,j));
        }
    }while(command!='D');
    return 0;
}