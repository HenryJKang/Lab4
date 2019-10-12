//
// Created by danie on 2019-10-11.
//

#ifndef LAB4_CANINE_HPP
#define LAB4_CANINE_HPP

#include <utility>
#include <iostream>
#include "Animal.hpp"

using namespace std;

class Canine : public Animal {

public:
    Canine();

    Canine(int age, double x, double y);

    void move(double x, double y)override;

    Canine(Canine &p2);

    virtual ~Canine();

    void sleep() override;

    void eat() override;

    void hunt(Animal *animal);

    friend ostream &operator<<(ostream &out, const Canine &a);
};


#endif //LAB4_CANINE_HPP
