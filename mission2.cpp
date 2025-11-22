#include <iostream>
using std::cout;
using std::endl;
class Shape{
public:
    virtual void calculateArea(int)=0;
    virtual void calculateArea(int,int)=0;
    virtual ~Shape()=default;
};
class Circle:public Shape{
public:
    void calculateArea(int r){
        cout<< "圆的面积为： " << 3.14*r*r <<endl;
    }
    void calculateArea(int,int){
        return;
    }
};
class Rectangle:public Shape{
public:
    void calculateArea(int wid,int len){
        cout<< "矩形的面积为： " << wid*len <<endl;
    }
    void calculateArea(int){
        return;
    }
};
int main(){
    Shape *circle=new Circle();
    Shape *rectangle=new Rectangle();
    circle->calculateArea(5);
    rectangle->calculateArea(5,6);
    return 0;
    delete circle;
    delete rectangle;
}