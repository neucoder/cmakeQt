//
// Created by ys on 19-6-17.
//

#include "Point.hxx"

#include <iostream>

using namespace std;

void Point::Show()
{
    cout << "x:" << x << " y:" << y << " z:" << z << endl;
}

void ColorPt::Show()
{
    Point::Show();
    cout << " color:" << Color << endl;
}


void testPoint()
{
    Point a, b(2, 3, 5);
    a.Show();
    b.Show();
    ColorPt c, d(10, 20, 30, "red");
    c.Show();
    d.Show();
}

const string &Cellphone::getBand() const
{
    return Band;
}

void Cellphone::setBand(const string &band)
{
    Band = band;
}

const string &Cellphone::getPhoneNumber() const
{
    return PhoneNumber;
}

void Cellphone::setPhoneNumber(const string &phoneNumber)
{
    PhoneNumber = phoneNumber;
}

void Cellphone::PickUp(string telNum)
{
    cout << "接听来自" << telNum << "的电话" << endl;
}

void Cellphone::CallSomebody(string telNum)
{
    cout << "呼叫来自" << telNum << "的电话" << endl;
}

Cellphone::Cellphone(const string &band, const string &phoneNumber) : Band(band), PhoneNumber(phoneNumber)
{}

int SmartPhone::getStroge() const
{
    return Stroge;
}

void SmartPhone::setStroge(int stroge)
{
    Stroge = stroge;
}

int SmartPhone::getWidth() const
{
    return Width;
}

void SmartPhone::setWidth(int width)
{
    Width = width;
}

int SmartPhone::getHeight() const
{
    return Height;
}

void SmartPhone::setHeight(int height)
{
    Height = height;
}

SmartPhone::SmartPhone(const string &band, const string &phoneNumber, int stroge, int width, int height) : Cellphone(
        band, phoneNumber), Stroge(stroge), Width(width), Height(height)
{}

void SmartPhone::PlayMusic()
{
    cout << "播放音乐" << getBand() << endl;
}
void testPhone()
{
    Cellphone a, b("XiaoMi", "1551294874");
    cout << "a" << a.getBand() << " " << a.getPhoneNumber() << endl;
    a.setBand("Huawei");
    a.setPhoneNumber("1729455789");
    cout << a.getBand() << " " << a.getPhoneNumber() << endl;
    cout << b.getBand() << " " << b.getPhoneNumber() << endl;
    SmartPhone c, d("apple","1242347964", 128, 400, 600);
    cout << c.getBand() << " " << c.getPhoneNumber() << " "
         << c.getWidth() << " " << c.getHeight() << " 手机存储"
         << c.getStroge() << "G"<< endl;
    c.setBand("vivo ");
    c.setPhoneNumber("2817899765");
    c.setStroge(64);
    c.setWidth(400);
    c.setHeight(900);
    cout << c.getBand() << " " << c.getPhoneNumber() << " "
         << c.getWidth() << " " << c.getHeight() << " 手机存储"
         << c.getStroge() << "G"<< endl;

    cout << d.getBand() << " " << d.getPhoneNumber() << " "
         << d.getWidth() << " " << d.getHeight() << " 手机存储"
         << d.getStroge() << "G"<< endl;
    c.PlayMusic();
    d.PlayMusic();


}

void RectG::Draw()
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            if (i==0 || i == V-1)
            {
                cout << "*";
            } else if(j==0 || j==H-1)
            {
                cout << "*";
            } else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

class Cir;
void testDraw()
{
    RectG R(20, 10);
    R.Draw();
    Cir c;
    c.Draw();
    Cir d(10);
    d.Draw();

}

void testVec3()
{
    vec3 a, b(10,20,30), c(9,8,7);
    a.show();
    a = b + c;
    a.show();
    a = b-c;
    a.show();
}

void Cir::Draw()
{
    for (int i = 0; i < E; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            if(i==E-1)
            {
                cout << "*";
            } else if(j==0 || j==i)
            {
                cout << "*";
            } else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

Cir::Cir(int e) : E(e)
{}


void vec3::show()
{
    cout << "x:" << x << " y:" << y << " z:" << z << endl;
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

vec3 vec3::operator+(vec3 &v)
{
    vec3 tmp;
    tmp.x = x + v.x;
    tmp.y = y + v.y;
    tmp.z = z + v.z;


    return tmp;
}

vec3 vec3::operator-(vec3 &v)
{
    vec3 tmp;
    tmp.y = y - v.y;
    tmp.z = z - v.z;
    tmp.x = x - v.x;


    return tmp;
}

vec3::vec3(int x, int y, int z) : x(x), y(y), z(z)
{}
