/*#include<iostream>
using namespace std;
//1.构造函数的分类及调用
//分类
//按照参数分类：无参构造（默认构造）和有参构造
//按照类型分类：普通构造和拷贝构造
class Person{
    int age;
public:   //构造函数
    Person() {
        cout << "Person的无参构造函数调用" << endl;
    }
    Person(int a) {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }
    //拷贝构造函数

    Person(const Person &p) {
        //将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
    }
    ~Person() {
        cout << "Person的析构函数调用" << endl;
        cout << "Person的拷贝构造函数调用" << endl;
    }
};
//调用
void test01() {
    //1.括号法
    //Person p1;//默认函数调用
    //Person p2(10);//有参构造函数
    //Person p3(p2); //拷贝构造函数
    //注意事项：调用默认构造函数时，不要加()
    //因为编译器会以为这行代码是一个函数的声明，不会认为在创建对象

    //2.显示法
    Person p1;
    Person p2 = Person(10);//有参构造
    Person p3 = Person(p2);//拷贝构造
    //Person(10)//匿名对象：当前行执行结束后，系统会立即回收掉匿名对象
    //注意事项2：不要利用拷贝构造函数初始化匿名对象

    //3.隐式转换法
    Person p4 = 10;//相当于写了 Person p4=Person(10); 有参构造
    Person p5 = p4;//拷贝构造
}
int main() {
    test01();
    return 0;
}*/