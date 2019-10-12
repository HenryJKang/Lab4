//
// Created by danie on 2019-10-11.
//

#include <iosfwd>
#include <iostream>
#include "Animal.hpp"

using namespace std;

long Animal::counter = 1;

//Testing for the age
int Animal::get1() { return age; }

//Testing for pair of coordinates
//pair<double,double> get1(){return coordinate;}

// Constructor1
Animal::Animal(int age, double x, double y) :
        age(age), xyzcoordinate(std::make_tuple(x, y, 0)), life(true) { ID = counter++; };

// Constructor2
Animal::Animal() :
        life(true), age(0), xyzcoordinate(std::make_tuple(0, 0, 0)) { ID = counter++; }

//Virtual move method
void Animal::move(double x, double y) {
    get<0>(xyzcoordinate) = x;
    get<1>(xyzcoordinate) = y;
    get<2>(xyzcoordinate) = 0;
}
void Animal::move(double x, double y, double z){
    get<0>(xyzcoordinate) = x;
    get<1>(xyzcoordinate) = y;
    get<2>(xyzcoordinate) = z;
}

void Animal::location() {
    cout << "Locations X: " << get<0>(xyzcoordinate) << " Y:" << get<1>(xyzcoordinate) << " Z:"
         << get<2>(xyzcoordinate);
}

//Destructor
Animal::~Animal() {
    cout << "Animal Destructor\n";
}

void Animal::sleep() { cout << "Animal Sleeping..." << endl; }

void Animal::eat() { cout << "Animal Eating..." << endl; }

//Copy Constructor made
Animal::Animal(const Animal &p2) {
    age = p2.age;
    ID = p2.ID;
    life = p2.life;
    xyzcoordinate = p2.xyzcoordinate;
}

void Animal::setAge(int x) {
    age = x;
}

void Animal::setAlive(bool yn) {
    life = yn;
}

//overload insertion operator
int Animal::getX() {
    return std::get<0>(xyzcoordinate);
}

int Animal::getY() {
    return std::get<1>(xyzcoordinate);
}

int Animal::getZ() {
    return std::get<2>(xyzcoordinate);
}

int Animal::getAge() {
    return age;
}


ostream &operator<<(ostream &out, const Animal &a) {
    out << "Animal type: Animal";
    out << "\nAge:" << a.age;
    out << "\nID: " << a.ID;
    out << "\nAlive: " << (a.life ? "yes" : "no");
    out << "\nThe coordinate x: " << std::get<0>(a.xyzcoordinate);
    out << "\nThe coordinate y: " << std::get<1>(a.xyzcoordinate);
    out << "\nThe coordinate z: " << std::get<2>(a.xyzcoordinate);

    return out;
}
