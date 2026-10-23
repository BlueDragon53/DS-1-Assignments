#include <stdio.h>

void acceptmat(int mat[10][10],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void displaymat(int mat[10][10],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }
}

void add(int mat1[10][10],int mat2[10][10],int mat3[10][10],int r1,int c1,int r2,int c2){
    int i,j;
    if(r1==r2 && c1==c2){
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                mat3[i][j]=mat1[i][j]+mat2[i][j];
            }
        }
    }
    else{
        printf("invalid input");
    }
}

void sub(int mat1[10][10],int mat2[10][10],int mat3[10][10],int r1,int c1,int r2,int c2){
    int i,j;
    if(r1==r2 && c1==c2){
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                mat3[i][j]=mat1[i][j]-mat2[i][j];
            }
        }
    }
    else{
        printf("invalid input");
    }
}

void transpose(int mat1[10][10],int mat3[10][10],int r1, int c1){
    int i,j;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            mat3[j][i]=mat1[i][j];
        }
    }
}

void multiply(int mat1[10][10], int mat2[10][10],int mat3[10][10],int r1,int c1,int r2,int c2){
    int i,j,k;

    if(c1!=r2){
        printf("invalid input");
        return;
    }

    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            mat3[i][j]=0;
        }
    }

    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<c1;k++){
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
}

int main(){
    int mat1[10][10],mat2[10][10],mat3[10][10],r1,c1,r2,c2,option;
    printf("What is size of matrix 1: ");
    scanf("%d%d",&r1,&c1);
    printf("\n");
    printf("What is size of matrix 2: ");
    scanf("%d%d",&r2,&c2);
    printf("Which operation you want to perform\n1.add\n2.sub\n3.transpose\n4.multiply\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            acceptmat(mat1,r1,c1);
            acceptmat(mat2,r2,c2);
            add(mat1,mat2,mat3,r1,c1,r2,c2);
            displaymat(mat3,r1,c1);
            break;

        case 2:
            acceptmat(mat1,r1,c1);
            acceptmat(mat2,r2,c2);
            sub(mat1,mat2,mat3,r1,c1,r2,c2);
            displaymat(mat3,r1,c1);
            break;

        case 3:
            acceptmat(mat1,r1,c1);
            transpose(mat1,mat3,r1,c1);
            displaymat(mat3,c1,r1);
            break;

        case 4:
            acceptmat(mat1,r1,c1);
            acceptmat(mat2,r2,c2);
            multiply(mat1,mat2,mat3,r1,c1,r2,c2);
            displaymat(mat3,r1,c2);
            break;
        

        default:
            break;
    }

    return 0;
}