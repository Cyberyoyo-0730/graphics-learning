//在C++中struct和class唯一的区别就在于默认的访问权限不同
//struct的默认权限为公共
//class的默认权限为私有
/*#include<iostream>
using namespace std;
class C1 {
    int m_A;//默认权限是私有
};
struct C2 {
    int m_B;//默认权限是公共
};
int main() {
    C1 c1;
    //c1.m_A = 100;在class里默认权限为私有，因此类外不可以访问
    C2 c2;
    c2.m_B = 100;//在struct默认的权限为公共，因此可以访问
}*/