#include<iostream>
using namespace std;
//访问权限有三种
//公共权限 public       成员 类内可以访问 类外可以访问   
//保护权限 protected    成员 类内可以访问 类外不可以访问 儿子可以1访问父亲的私有内容
//私有权限 private      成员 类内可以访问 类外不可以访问 儿子不可以1访问父亲的私有内容
/*class Person {
public:
    //公共权限
    string m_Name;//姓名
protected:
    //保护权限
    string m_Car;//汽车
private:
    //私有权限
    int m_Password;//银行卡密码
private://写成public类型main函数内可以访问
    void func() {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};
int main() {
    //实例化具体形象
    Person p1;
    p1.m_Name = "李四";
    //p1.m_Car = "奔驰";保护权限内容，在类外访问不到
    //p1.m_Password=123456;私有权限内容，在类外访问不到
}*/