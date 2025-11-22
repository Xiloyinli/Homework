#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::vector;
using std::string;
int main(){
    int n,temp;
    cin >> n;
    vector<string> num(n);
    for (int i=0;i<n;i++){
        cin >> num[i];
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            string combine1=num[i]+num[j];
            string combine2=num[j]+num[i];
            if (combine1<combine2){
                string temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << num[i];
    }
    return 0;
}