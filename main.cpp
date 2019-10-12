#include <iostream>

#include <utility>
#include "Animal.hpp"
#include "Bird.hpp"
#include "Canine.hpp"

int main() {
    //std::cout << "Hello, World!" << std::endl;

    Animal *animal;
    Animal *bird = new Bird(12, 42, 32, 0);
    Animal *canine = new Canine(13, 42, 32);
    cout << "Canine:" <</*canine->location()*/endl;
    cout << "Bird:" << bird->getX() << bird->getY() << bird->getZ() << endl;
    cout << "Canine haunting Bird" << endl;

    cout<<*((Bird*)bird)<<endl;
    ((Canine *) canine)->hunt(bird);

    canine->move(0,0);
    cout<<*((Canine*)canine)<<endl;
    return 0;
}