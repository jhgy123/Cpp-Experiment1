// Experiment1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Student {
private:
	static int totalNumbers;//static 成员变量，创建的Student对象的总共数量
	const int id;//const 成员变量，学生学号
	string name;//学生姓名
	int age;//学生年龄
	string hometown;//学生家乡

public:
	//不带参数的构造函数
	//使用const说明的数据成员，常数据成员必须通过构造函数的初始化列表进行初始化，并且不能被更新
	Student() :id(totalNumbers + 1) {
		name = "未知姓名";
		age = 18;
		hometown = "云南";
		totalNumbers++;//创建的Sudent对象数加1
		cout << "调用不带参数的构造函数" << endl;
	}
	//带有默认值的构造函数
	//使用const说明的数据成员，常数据成员必须通过构造函数的初始化列表进行初始化，并且不能被更新
	Student(int stuid, string name = "未知姓名", int age = 18, string hometown = "云南") :id(stuid) {
		this->name = name;
		this->age = age;
		this->hometown = hometown;
		totalNumbers++;//创建的Sudent对象数加1
		cout << "调用带有默认值的构造函数" << endl;
	}
	//拷贝构造函数
	//使用const说明的数据成员，常数据成员必须通过构造函数的初始化列表进行初始化，并且不能被更新
	Student(const Student& stu) :id(stu.id) {
		name = stu.name;
		age = stu.age;
		hometown = stu.hometown;
		totalNumbers++;//创建的Sudent对象数加1
		cout << "调用拷贝构造函数" << endl;
	}
	//析构函数
	~Student() {
		totalNumbers--;//创建的Sudent对象数减1
		cout << "学生"<<id<<"调用析构函数" << endl;
	}
	//声明友元函数
	friend void getStudentInf(Student stu);

	void setName(string name) {
		this->name = name;
	}
	void getName() {
		cout << this->name << endl;
	}
	//静态成员函数
	static void displayNumbers() {
		cout << "目前创建了" << totalNumbers << "个对象" << endl;
	}
};

//友元函数定义
void getStudentInf(Student stu) {
	cout << "使用友元函数" << endl;
	cout << "学生学号:" << stu.id << " 学生姓名:" << stu.name << " 学生年龄:" << stu.age << " 学生家乡:" << stu.hometown << endl;
}


//测试函数
int Student::totalNumbers = 0;//静态成员变量初始化
int main()
{
	Student stu1;//使用无参数构造函数创建对象
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
	Student stu2(20, "李华", 19);//使用带有默认值的构造函数创建对象
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
	Student stu3(21, "李华",17,"山东");//使用带有默认值的构造函数创建对象
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
	Student stu4(22, "小明", 20, "湖南");//使用带有默认值的构造函数创建对象
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
	Student stu5(stu4);//使用拷贝构造函数创建对象
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
	Student* s = new Student(24, "小红", 21, "山西");//new 动态创建Student对象
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
	getStudentInf(stu3);//使用友元函数获取stu3的信息
	delete s;//销毁动态创建的对象s
	Student::displayNumbers();//调用静态成员函数，显示当前创建的Student对象的数量
    std::cout << "finish!\n";
}

