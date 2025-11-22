#include <stdio.h>
int main(){
    int a,b,c;
    int n[9];
    int i,x,y,z;
    for (i=123;i<=999;i++){
        a=i;
        b=2*a;
        c=3*a;
        for (x=1;x<=3;x++){
            if (x%3==1){
                n[x-1]=a/100;
            }
            else if (x%3==2){
                n[x-1]=a%100/10;
            }
            else if (x%3==0){
                n[x-1]=a%10;
            }  
        }
        for (y=4;y<=6;y++){
            if (y%3==1){
                n[y-1]=b/100;
            }
            else if (y%3==2){
                n[y-1]=b%100/10;
            }
            else if (y%3==0){
                n[y-1]=b%10;
            }
        }
            for (z=7;z<=9;z++){
            if (z%3==1){
                n[z-1]=c/100;
            }
            else if (z%3==2){
                n[z-1]=c%100/10;
            }
            else if (z%3==0){
                n[z-1]=c%10;
            }
        }
        if (n[0]+n[1]+n[2]+n[3]+n[4]+n[5]+n[6]+n[7]+n[8]==45&&n[0]*n[1]*n[2]*n[3]*n[4]*n[5]*n[6]*n[7]*n[8]==1*2*3*4*5*6*7*8*9){
            printf("%d %d %d\n",a,b,c);
        }
    }
    return 0;
}
