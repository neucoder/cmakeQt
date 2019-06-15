//
// Created by ys on 2019/6/14.
//


//初始化引用成员的唯一机会就是在构造函数的初始化列表中
#ifndef OPONCPP_ACCOUNT_HXX
#define OPONCPP_ACCOUNT_HXX

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void testBigInt();

void testQt();

void testAcc();


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
        return (Sex==0) ? 'm' : 'f';
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
    float Salary;

public:
    Employee()
    {
        Register("XXX", 0, 'm', "XXX", 0);
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
