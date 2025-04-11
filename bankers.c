#include <stdio.h>
#include <stdlib.h>

void main(){
    int p,r,i,j,alloc[40][40],max[40][40],avail[40];
    printf("\nEnter the no of processes:\n");
    scanf("%d",&p);
    printf("\nEnter the no of resources:\n");
    scanf("%d",&r);
    printf("\nEnter alloc matrix content;\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter max matrix content;\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nEnter available matrix content;\n");
    for(int j=0;j<r;j++){
            scanf("%d",&avail[i]);
    }
    int finish[p],safeseq[p],d=0,work[p
    ],need[p][r];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nneed is\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            printf("%d",need[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        work[i]=avail[i];
    }
    for(int i=0;i<p;i++){
        finish[i]=0;
    }
    for(int k=0;k<p;k++){
        for(int i=0;i<p;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<p;j++){
                    if(need[i][j]>work[i]){
                        flag=1;
                        break;
                    }
                    if(flag==0){
                        safeseq[d++]=i;
                        for(int j=0;j<p;j++){
                            work[j]=work[j]+alloc[i][j];
                        }
                        finish[i]=1;
                    }
                }
            }
        }
    }
    int c=0;
    for(i=0;i<p;i++){
        if(finish[i]==1){
            c++;
        }
    }
    if(c==p){
        for(int i=0;i<p;i++){
            printf("\nSafe");
            printf("%d",safeseq[i]);
        }
    else{
        printf("Not safe");
        }
    }
}













