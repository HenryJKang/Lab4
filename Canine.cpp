//
// Created by danie on 2019-10-11.
//

#include "Canine.hpp"

//Default Constructor
Canine::Canine() {
    age = 0;
    xyzcoordinate = make_tuple(0, 0, 0);

}

Canine::Canine(int age, double x, double y) {
    age = age;
    xyzcoordinate = make_tuple(x, y, 0);
}

void Canine::move(double x, double y) {
    xyzcoordinate = make_tuple(x, y, 0);
}

Canine::Canine(Canine &p2) {
    age = p2.age;
    xyzcoordinate = p2.xyzcoordinate;
}

Canine::~Canine() {
    cout << "Canine" << ID << " Destructor" << endl;
}

void Canine::sleep() {
    cout << "Canine is sleeping" << endl;
}

void Canine::eat() {
    cout << "Canine is eating" << endl;
}

void Canine::hunt(Animal *animal) {
    if (abs(animal->getX() - get<0>(xyzcoordinate) <= 1)) {
        if (abs(animal->getY() - get<1>(xyzcoordinate) <= 1)) {
            if (abs(animal->getZ() - get<2>(xyzcoordinate) <= 1)) {
                animal->setAlive(false);
                cout << "Canine successfully hunted" << endl;
            } else {
                cout << "Hunt failed";
            }
        } else {
            cout << "Hunt failed";
        }
    } else {
        cout << "Hunt failed";
    }
    //animal->setAlive(false);
}
void Canine::location() {
    cout << "Locations X: " << get<0>(xyzcoordinate) << " Y:" << get<1>(xyzcoordinate) << " Z:"
         << get<2>(xyzcoordinate);

}

ostream &operator<<(ostream &out, const Canine &a) {
    out << "Animal Type: Canine" ;
    out << "\nAge:" << a.age;
    out << "\nID: " << a.ID;
    out << "\nAlive: " << (a.life ? "yes" : "no");
    out << "\nThe coordinate x: " << std::get<0>(a.xyzcoordinate);
    out << "\nThe coordinate y: " << std::get<1>(a.xyzcoordinate);
    out << "\nThe coordinate z: " << std::get<2>(a.xyzcoordinate);
    return out;
}

