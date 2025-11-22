#include <stdio.h>
long long int power(long long int base,long long int n){
    long long int result=1;
    for (int i=0;i<n;i++){
        result *=base;
    }
    return result;
}
void solve(long long int num){
    if (num==0){
        return;
    }
    if (num==1){
        printf("2(0)");
        return;
    }
    if (num==2){
        printf("2");
        return;
    }
    long long int i=0;
    while (power(2,i+1)<=num){
            i++;
        }
        long long int remain=num-power(2,i);
        if (i==1){
            printf("2");
        }
        else {
            printf("2(");
            solve(i);
            printf(")");
        }
        if (remain>0){
            printf("+");
            solve(remain);
        }
    }
int main(){
    long long int num;
    scanf("%lld",&num);
    solve(num);
    return 0;
}