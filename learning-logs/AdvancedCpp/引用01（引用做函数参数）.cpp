/*#include<iostream>
using namespace std;
//交换函数

//1.值传递:形参不会修饰实参
void mySwap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "swap01 a=" << a << endl;
    cout << "swap01 b=" << b << endl;
}

//2.地址传递：形参会修饰实参
void mySwap02(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "swap02 a=" << *a << endl;
    cout << "swap02 b=" << *b << endl;
}

//3.引用传递：形参会修饰实参
void mySwap03(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "swap03 a=" << a << endl;
    cout << "swap03 b=" << b << endl;
}
int main() {
    int a = 10;
    int b = 20;
    //mySwap01(a, b);
    //mySwap02(&a, &b);
    mySwap03(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}*/