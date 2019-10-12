//
// Created by danie on 2019-10-11.
//

#ifndef LAB4_ANIMAL_HPP
#define LAB4_ANIMAL_HPP

#include <tuple>

using namespace std;

class Animal {
protected:
    long ID;
    static long counter;
    bool life;
    ///std::pair<double,double> coordinate;
    tuple<double, double, double> xyzcoordinate;

    //friend istream & operator >>(istream& in, Animal& a);

    int age;
public:
    Animal();

    Animal(int age, double x, double y);

    virtual void move(double x, double y);
    virtual void move(double x, double y, double z);

    void setAlive(bool yn);

    void location();

    Animal(const Animal &p2);

    friend ostream &operator<<(ostream &out, const Animal &a);


    virtual ~Animal();

    virtual void sleep();

    virtual void eat();

    int get1();

    int getX();

    int getY();

    int getZ();

    int getAge();

    int getLive();


    void setAge(int x);
};


#endif //LAB4_ANIMAL_HPP
