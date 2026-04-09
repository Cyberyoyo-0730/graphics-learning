/*#include<iostream>
using namespace std;
#include<string>
struct student {
    string name;
    int age;
    int score;
};
//打印学生信息函数
//1.值传递
void printStudent01(struct student s) {
  
    cout << "main函数中打印 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
}
//2.地址传递
void printStudent02(struct student *p){
    p->age = 100;
    cout << "main函数中打印 姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
}
int main() {
    //结构体做函数参数
    //将学生传入到一个参数中，打印学生身上的所有信息
    //创建结构体变量
    struct student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;
    printStudent01(s); 
    printStudent02(&s);
    cout << "main函数中打印 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
    return 0;

}*/