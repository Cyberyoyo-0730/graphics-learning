//使用const来防止误操作
/*#include<iostream>
using namespace std;
#include<string>
//const的使用场景
struct student {
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
};
//将函数中的形参改为指针可以减少内存空间，且不会复制新的副本出来
void printStudent(const student *s) {
    //加入const后一旦有修改的操作就会报错，可以防止误操作
    cout << "姓名：" << s->name << " 年龄：" << s->age << " 得分：" << s->score << endl;
}
int main() {
    //创建结构体变量
    struct student s = { "张三",15,70 };
    //通过函数打印结构体变量信息
    printStudent(&s);
    return 0;

}*/