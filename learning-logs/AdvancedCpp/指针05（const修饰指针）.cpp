/*
#include<iostream>
using namespace std;
int main() {
	//1.const修饰指针 常量指针
	int a = 10;
	int b = 10;
	const int* p = &a;
	//常量指针的指向可以改，但指针指向的值不可以改
	//*p = 20;
	p = &b;//正确

	//2.const修饰常量 指针常量
	int* const p2 = &a;
	//指针常量的值可以改，但指针的指向不可以改
	*p2 = 100;//正确
	//p2 = &b;

	//3.const修饰指针和常量
	const int* const p3 = &a;
	//指针指向的值和指针的指向都不可以改
	//*p3 = 100;
	//p3 = &b;
}*/