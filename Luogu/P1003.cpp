#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
struct Carpet{
    int x,y,len,wid;
};
int main(){
    int n;
    cin >> n;
    vector<Carpet> carpet(n);
    for (int i=0;i<n;i++){
        cin >> carpet[i].x >> carpet[i].y >> carpet[i].len >> carpet[i].wid;
    }
    int qx,qy;
    cin >> qx >> qy;
    int result=-1;
    for (int i=n-1;i>=0;i--){
        Carpet & r=carpet[i];
        bool A=(qx>=r.x)&&(qx<r.x+r.len);
        bool B=(qy>=r.y)&&(qy<r.y+r.wid);
        if (A&&B){
            result=i+1;
            break;
        }
    }
    cout << result;
    return 0;
}
