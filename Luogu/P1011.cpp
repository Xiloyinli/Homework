#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
int main(){
    int temp;
    int geton1,geton2;
    int fgeton,fgetoff;
    int stations;
    int station;
    cin >> fgeton >> stations >> fgetoff >> station;
    int a=1,b=0;
    if (stations==2){
        cout << fgeton;
        return 0;
    }
    if (stations==3){
        if (station==1||station==2){
            cout << fgeton;
        }
        else {
            cout << fgetoff;
            return 0;
        }
        return 0;
    }
    int moon=a;
    geton1=a;
    geton2=b;
    if (stations>3){
        for (int i=3;i<=stations-1;i++){
            int newgeton=geton1+geton2;
            int getoff=geton2;
            moon+=newgeton-getoff;
            geton1=geton2;
            geton2=newgeton;
        }
    }
    int A=moon;
    a=0;
    b=1;
    moon=a;
    geton1=a;
    geton2=b;
    if (stations>3){
        for (int i=3;i<=stations-1;i++){
        int newgeton=geton1+geton2;
        int getoff=geton2;
        moon+=newgeton-getoff;
        geton1=geton2;
        geton2=newgeton;
        }
    }
    int B=moon;
    if (B==0){
        cout << fgeton;
        return 0;
    }
    int bgeton=(fgetoff-fgeton*A)/B;
    vector<int> onbus(stations+1);
    geton2=bgeton;
    geton1=fgeton;
    onbus[1]=fgeton;
    onbus[2]=fgeton;
    for (int i=3;i<=station;i++){
        int newgeton=geton1+geton2;
        int getoff=geton2;
        onbus[i]=onbus[i-1]+newgeton-getoff;
        geton1=geton2;
        geton2=newgeton;
    }
    cout << onbus[station];
    return 0;
}