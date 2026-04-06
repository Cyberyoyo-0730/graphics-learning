//野指针：指针变量指向非法的内存空间
/*#include<iostream>
using namespace std;
int main() {
	//野指针
	//在程序中，尽量避免出现野指针
	int* p = (int*)0x1100;
	cout << *p << endl;
	return 0;
}*/
//空指针和野指针都不是我们申请的空间，所以尽量不要访问