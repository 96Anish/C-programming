#include<iostream>
using namespace std;
class A {
    public:
    void display(){
        cout<<"\n box class ";
    }
};
class B : public A{
    public:
    void display (){
        cout<<"\n derived class ";
    }
};
int main (){
    B aa;
    aa.display();
    return 0;
}
