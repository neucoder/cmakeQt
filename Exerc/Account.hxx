//
// Created by ys on 2019/6/14.
//


//初始化引用成员的唯一机会就是在构造函数的初始化列表中
#ifndef OPONCPP_ACCOUNT_HXX
#define OPONCPP_ACCOUNT_HXX

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::string;

void testBigInt();

void testExer();

void testAcc();



//类的多态性

//多态性的两种形式，编译时多态，运行时多态
//派生类对象转化为基类对象
/*
 * 1. 通过指针和引用调用虚函数，最好使用指针
 *
 * 2. 派生类中的重定义的基类虚函数仍是虚函数可以省略virtual关键字
 * 3. 无虚构造函数，有虚析构函数
 */



/*
 *
 * 纯虚函数
 * virtual 返回类型 函数名(参数表)=0;
 *
 * 至少包含一个纯虚函数的类称为抽象类
 *
 * */
class Shape
{
public:
    virtual float Area() = 0;
    virtual float Circumference() = 0;

    virtual void draw()
    {
        cout << "draw shape" << endl;
    }
};


class Rect : public Shape
{
    float left, top;
    float width, height;
public:
    Rect()
    {
        left = 0;
        top = 0;
        width = 0;
        height = 0;
    }

    Rect(float x, float y, float w, float h)
    {
        left = x;
        top = y;
        width = w;
        height = h;
    }

    virtual float Area()
    {
        return width * height;
    }

    float Circumference() override
    {
        return 2*(width+height);
    }


};


class Line : public Shape
{
public:
    virtual void draw()
    {
        cout << "draw a line" << endl;
    }
};


class Circle : public Shape
{
private:
    float xCenter, yCenter, radius;
public:
    Circle()
    {
        xCenter = 0;
        yCenter = 0;
        radius = 0;
    }

    Circle(float x, float y, float R)
    {
        xCenter = x;
        yCenter = y;
        radius = R;
    }

    virtual float Area()
    {
        return 3.1415 * radius * radius;
    }

    float Circumference() override
    {
        return 3.14159 * 2 * radius;
    }

    void draw()
    {
        cout << "draw a circle" << endl;
    }
};


void testShape();


void testEmp();

//人员类
class Person
{
    string Name;
    int Age;
    int Sex;
protected:
    void Register(string name, int age, char sex)
    {
        Name = name;
        Age = age;
        Sex = (sex == 'm' ? 0 : 1);
    }

public:

    Person(string name, int age, int sex)
    {
        Name = name;
        Age = age;
        Sex = sex;
        cout << "constructtor of person " << Name << endl;
    }

    ~Person()
    {
        cout << "deconstructot of person " << Name << endl;
    }

    const string &getName() const
    {
        return Name;
    }

    int getAge() const
    {
        return Age;
    }

    char getSex() const
    {
        return (Sex == 0) ? 'm' : 'f';
    }

public:
    void Show()
    {
        cout << Name << "\t" << Sex << '\t' << Age << endl;
    }
};

//雇员类
class Employee : public Person
{
    string Dept;
    Person Wang;
    float Salary = 0;

public:
    Employee(string name, int age, string dept, string name1, int age1) :
            Person(name, age, 1), Wang(name1, age1, 1)
    {
        Dept = dept;
        cout << "construntor of Emlpoyee " << endl;

    }

    ~Employee()
    {
        cout << "deconstruntor of employee " << endl;
    }


    void Register(string name, int age, char sex, string dept, float salary);

    const string &getDept() const
    {
        return Dept;
    }

    float getSalary() const
    {
        return Salary;
    }

public:
    void Show();
};


//多继承
//飞机类
//船类

//水上飞机类

class Plane
{
    float propeller;
public:
    void flight();
};

class Boat
{
    float helm;
public:
    void voyage();
};

class SeaPlane : public Plane, public Boat
{

};


class BigInt
{
private:
    int data[200] = {0};
    int n;
public:
    BigInt()
    {};

    int input(char d[], int n);

    void add(BigInt &other);

    void show();
};


class Account
{
public:
    int getID() const;

    void setID(int ID);

    float getBalance() const;

    void setBalance(float balance);

private:
    int ID;
    char Name[20];
    float balance;
public:
    Account()
    {
        ID = -1;
        strcpy(Name, "xxxx");
        balance = 0;
    };

    Account(int ID, char Name[], float balance)
    {
        this->ID = ID;
        strcpy(this->Name, Name);
        this->balance = balance;
    }

    Account(Account &other)
    {
        ID = other.ID;
        strcpy(Name, other.Name);
        balance = other.balance;
    }

    void Initial(int ID, char Name[], float balance);

    //取钱，存钱
    int withdraw(float m);

    void deposits(float m);

    void setName(char *name);

    void getName(char *);

    void showMe()
    {
        cout << Name << ":" << balance << std::endl;
    }
};

#endif //OPONCPP_ACCOUNT_HXX
