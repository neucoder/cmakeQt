//
// Created by ys on 2019/6/14.
//

#include "Account.hxx"
#include <iostream>
#include <cstring>

using namespace std;


//雇员类的实现

void Employee::Register(string name, int age, char sex, string dept, float salary)
{
    Person::Register(name, age, sex);
    Dept = dept;
    Salary = salary;
}

void Employee::Show()
{
    cout << getName() << "\t" << getSex() << "\t" << getAge() << "\t" << getDept() << "\t"
         << getSalary() << endl;
}

//雇员类的测试函数

void testEmp()
{
    Employee emp;
    emp.Show();
    emp.Register("joe", 30, 'f', "library", 2000);
    emp.Show();
    cout << "base class getAge() return " << emp.getAge() << endl;
}




//大整数类

int BigInt::input(char *d, int n)
{
    this->n = n;
    for (int i = 0; i < n; ++i)
    {
        data[n - 1 - i] = d[i] - '0';
    }

    return 0;
}

void BigInt::add(BigInt &other)
{
    //处理进位
    int nn = n < other.n ? n : other.n;

    for (int i = 0; i < nn; ++i)
    {

        data[i] = data[i] + other.data[i];
        if (n == other.n && (data[n - 1] > 9))
        {
            n += 1;
        }
        if (data[i] > 9)
        {
            data[i + 1] += 1;
            data[i] -= 10;
        }
    }


    if (n < other.n)
    {
        n = other.n;
        for (int i = nn; i < other.n; ++i)
        {
            data[i] = data[i] + other.data[i];
            if ((i == other.n - 1) && data[i] > 9)
            {
                n += 1;
            }
            if (data[i] > 9)
            {
                data[i + 1] += 1;
                data[i] -= 10;
            }

        }
    }

    if (n > other.n)
    {

        for (int i = nn; i < n; ++i)
        {
            if ((i == n - 1) && data[i] > 9)
            {
                n += 1;
            }
            if (data[i] > 9)
            {
                data[i + 1] += 1;
                data[i] -= 10;
            }

        }
    }
}


void BigInt::show()
{
    for (int i = n - 1; i >= 0; --i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void testBigInt()
{
    char d1[] = "11";
    char d2[] = "999";
    BigInt a, b;
    a.input(d1, 2);
    b.input(d2, 3);
    a.show();
    b.show();
    a.add(b);
    a.show();
}


void Account::Initial(int ID, char *Name, float balance)
{
    this->ID = ID;
    strcpy(this->Name, Name);
    this->balance = balance;
}


int Account::withdraw(float m)
{
    if (balance > m)
    {
        balance = balance - m;
        return 1;
    }
    else
    {
        return -1;
    }
}


void Account::deposits(float m)
{
    balance += m;
}

void Account::setName(char *name)
{
    strcpy(Name, name);
}

void Account::getName(char *res)
{
    strcpy(res, Name);
}

int Account::getID() const
{
    return ID;
}

void Account::setID(int ID)
{
    Account::ID = ID;
}

float Account::getBalance() const
{
    return balance;
}

void Account::setBalance(float balance)
{
    Account::balance = balance;
}

void testAcc()
{
    Account my;
    char name[] = "Jack";
    my.Initial(10112, name, 600.0);
    my.withdraw(500);
    my.showMe();
    Account other(my);
    other.deposits(200);
    other.showMe();
    Account d;
    d.showMe();
    char dname[] = "abc";
    Account dd(110, dname, 900);
    dd.showMe();
    Account C[3];
    Account *pa = new Account();
    Account *pb = new Account(111, dname, 1000);
    cout << pb->getID() << " " << pb->getBalance() << endl;
    pb->setID(122);
    pb->setBalance(12222);
    cout << pb->getID() << " " << pb->getBalance() << endl;

    pb->setName(dname);
    pb->showMe();

}

void testQt()
{
    cout << "test QT_Acc lib" << endl;
}
