//
// Created by danie on 2019-10-11.
//

#include <array>
#include "Bird.hpp"
#include <iostream>

using namespace std;

Bird::Bird(int age, double x, double y, double z) {
    this->age = age;
    xyzcoordinate = make_tuple(x, y, z);
}

//default constructor
Bird::Bird() {
    age = 0;

    std::get<0>(xyzcoordinate) = 0;
    std::get<1>(xyzcoordinate) = 0;
    std::get<2>(xyzcoordinate) = 0;
}

// Move method for Bird class.
void Bird::move(double x, double y, double z) {
    Animal::move(x,y);
    std::get<2>(xyzcoordinate) = z;
}

//Copy Constructor
Bird::Bird(Bird &p2) {
    age = p2.age;
    xyzcoordinate = p2.xyzcoordinate;

}

//Destructor
Bird::~Bird() {
    cout<<"\nBird Destructor"<<endl;
}

void Bird::eat() { cout << "Bird(s) is(are) eating..." << endl; }

void Bird::sleep() { cout << "Bird(s) is(are) sleeping..." << endl; }

void Bird::location() {
    cout << "Locations X: " << get<0>(xyzcoordinate) << " Y:" << get<1>(xyzcoordinate) << " Z:"
         << get<2>(xyzcoordinate);

}

//overload insertion operator
ostream &operator<<(ostream &out, const Bird &a) {
    out << "Animal Type: Bird";
    out << "\nAge:" << a.age;
    out << "\nID: " << a.ID;
    out << "\nAlive: " << (a.life ? "yes" : "no");
    out << "\nThe coordinate x: " << std::get<0>(a.xyzcoordinate);
    out << "\nThe coordinate y: " << std::get<1>(a.xyzcoordinate);
    out << "\nThe coordinate z: " << std::get<2>(a.xyzcoordinate);
    return out;
}



//istream& operator >> (istream& in, Bird& a){
//    cout <<"Enter the age";
//    in >> a.age;
//    cout <<"Enter if it's alive (true / false)";
//    in >> a.life;
//    cout <<"Enter the coordinate of x: ";
//    in >> std::get<0>(a.xyzcoordinate);
//    cout <<"Enter the coordinate of y: ";
//    in >> std::get<1>(a.xyzcoordinate);
//    cout <<"Enter the coordinate of z: ";
//    in >> std::get<2>(a.xyzcoordinate);
//
//    return in;
//}