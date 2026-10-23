#include <stdio.h>

void acceptmat(int ma[20][20],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&ma[i][j]);    
        }
        
    }
}

int compact(int ma[20][20],int mb[50][3],int m,int n){
    int i,j;
    int count= 1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(ma[i][j]!=0){
                mb[count][0]=i;
                mb[count][1]=j;
                mb[count][2]=ma[i][j];
                count++;

            }

        }

    }
    mb[0][0]=m;
    mb[0][1]=n;
    mb[0][2]=count-1;
  return count;
}

void displaymat(int ma[20][20],int m,int n){
       int i,j;
        printf("Col1   Col2   Col3\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d\t",ma[i][j]);
            }
            printf("\n");
        }
}

void displaycom(int mb[50][3],int count){
    int i,j;
        printf("Col1   Col2   Col3\n");
        for(i=0;i<count;i++){
            for(j=0;j<3;j++){
                printf("%d\t",mb[i][j]);
            }
            printf("\n");
        }

    }




int main(){
    int ma[20][20],mb[50][3],m,n;
    printf("what is order of matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter your matrix:\n");
    acceptmat(ma,m,n);
    printf("\n");
    displaymat(ma,m,n);
    printf("\nYour Compact matrix is:\n\n");
    int count = compact(ma,mb,m,n);
    displaycom(mb,count);
}