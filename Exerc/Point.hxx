//
// Created by ys on 19-6-17.
//

#ifndef CMAKEQT_POINT_HXX
#define CMAKEQT_POINT_HXX

#include <string>

using std::string;

class Point
{
    int x, y, z;
public:

    Point(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c)
    {}

    void Show();
};

class ColorPt : public Point
{
    string Color;
public:
    ColorPt(int a = 0, int b = 0, int c = 0, string color = "") : Point(a, b, c), Color(color)
    {}

    void Show();
};

void testPoint();


class Cellphone
{
    string Band;
    string PhoneNumber;
public:
    Cellphone() = default;

    Cellphone(const string &band, const string &phoneNumber);

    void PickUp(string telNum);

    void CallSomebody(string telNum);

    const string &getBand() const;

    void setBand(const string &band);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);
};


class SmartPhone : public Cellphone
{
    int Stroge, Width, Height;
public:
    SmartPhone() = default;

    SmartPhone(const string &band, const string &phoneNumber, int stroge, int width, int height);

    int getStroge() const;

    void setStroge(int stroge);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    void PlayMusic();
};


void testPhone();

//图形类
class Geometry
{
public:
    virtual void Draw() = 0;
};

class RectG : public Geometry
{
    int H, V;
public:
    RectG(int h = 3, int v = 3) : H(h), V(v)
    {}

    void Draw() override;
};


class Cir :public Geometry
{
    int E;
public:
    Cir(int e=3);
    void Draw() override;
};

void testDraw();


class vec3
{
    int x, y, z;
public:
    vec3() = default;

    vec3(int x, int y, int z);

    void show();

    vec3 operator+(vec3& v);
    vec3 operator-(vec3& v);
};

void testVec3();
#endif //CMAKEQT_POINT_HXX
