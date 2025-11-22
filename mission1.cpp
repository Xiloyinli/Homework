#include <iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;
class Person{
private:
    string name;
    int age;
public:
    Person(string a,int b){
        name=a;
        age=b;
    }
    void display(){
        cout<< name << " " << age << endl;
    }
};
int main(){
    Person Niko("niko",26);
    Person Zywoo("zywoo",24);
    Niko.display();
    Zywoo.display();
    return 0;
}