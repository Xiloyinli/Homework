#include <stdio.h>
int main(void){
    int A[100]={0},B[100]={0};
    A[0]=1;
    int i,n,x,temp;
    scanf("%d",&i);
    for (n=1;n<=i;n++){
        for (x=0;x<=99;x++){
            A[x]*=n;
        }
        for (x=0;x<=99;x++){
            A[x+1]+=A[x]/10;
            A[x]%=10;
        }
        for (x=0;x<=99;x++){
            B[x]+=A[x];
        }
        for (x=0;x<=99;x++){
            B[x+1]+=B[x]/10;
            B[x]%=10;
        }
    }
    for (n=99;n>=0;n--){
        if (B[n]==0){
            continue;
        }
        else {
            temp=n;
            break;
        }
    }
    for (;temp>=0;temp--){
        printf("%d",B[temp]);
    }
    return 0;
}