#include "stdio.h"
int Ax,Ay,Hx,Hy;
int blocked[21][21]={0};
long long map[21][21]={0};
void block(){
    int dx[8]={1,1,-1,-1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    if (Hx>=0 && Hx<=Ax && Hy>=0 && Hy<=Ay){
        blocked[Hx][Hy]=1;
    }
    for (int i=0;i<8;i++){
        int nx=Hx+dx[i];
        int ny=Hy+dy[i];
        if (nx>=0&&nx<=Ax&&ny>=0&&ny<=Ay){
            blocked[nx][ny]=1;
        }
    }
}
long long int count(){
    if (blocked[0][0]==1){
        return 0;
    }
    map[0][0]=1;
    for (int x=1;x<=Ax;x++){
        if (!blocked[x][0]){
            map[x][0]=map[x-1][0];
        }
    }
    for (int y=1;y<=Ay;y++){
        if (!blocked[0][y]){
            map[0][y]=map[0][y-1];
        }
    }
    for (int i=1;i<=Ax;i++){
        for (int j=1;j<=Ay;j++){
            if (!blocked[i][j]){
                map[i][j]=map[i-1][j]+map[i][j-1];
            }
        }
    }
    return map[Ax][Ay];
}
int main(void){
    scanf("%d %d %d %d",&Ax,&Ay,&Hx,&Hy);
    block();
    printf("%lld",count());
    return 0;
}
