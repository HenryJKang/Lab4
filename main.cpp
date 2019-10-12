#include <iostream>

#include <utility>
#include "Animal.hpp"
#include "Bird.hpp"
#include "Canine.hpp"

int main() {
    //std::cout << "Hello, World!" << std::endl;



//    cout << "Canine:" <</*canine->location()*/endl;
//    cout << "Bird:" << bird->getX() << bird->getY() << bird->getZ() << endl;
//    cout << "Canine haunting Bird" << endl;
//
//    cout << *((Bird *) bird) << endl;
//    ((Canine *) canine)->hunt(bird);
//
//    canine->move(0, 0);

//----
    Animal *animal = new Animal(30, 40, 50);
    Animal *bird = new Bird(67, 1.5, 8.9, 12);
    Animal *canine = new Canine(23, 15.2, 4.3);
    cout << "\n-----------The animals info section (Before move)" << endl;

    cout << "\n" << *(animal) << endl;
    cout << "\n" << *((Bird *) bird) << endl;
    cout << "\n" << *((Canine *) canine) << endl;


//----------Moved
    cout << "\n-----------The animals info section (After move)" << endl;
    animal->move(5.2, 3.6);
    bird->move(1.2, 4.3, 6.4);
    canine->move(58, 12);


    cout << "\n" << *(animal) << endl;
    cout << "\n" << *((Bird *) bird) << endl;
    cout << "\n" << *((Canine *) canine) << endl;

    //----------Eat / Sleep test ----------//
    animal->sleep();

    bird->sleep();

    canine->sleep();

    animal->eat();

    bird->eat();

    canine->eat();


    //--------Hunting Test ----------//

    cout << "\n--------Hunting Test---------" << endl;
    cout << "\nCanine's current position:" << endl;
    canine->location();
    cout << "\nBird's current position:" << endl;
    bird->location();
    cout << "\nCanine is trying to hunt to the bird where the bird has different location:" << endl;
    ((Canine *) canine)->hunt(bird);

    cout << "\n-----------The animals info section (After Canine hunt bird failed)[Bird didn't die]" << endl;

    cout << "\n" << *(animal) << endl;
    cout << "\n" << *((Bird *) bird) << endl;
    cout << "\n" << *((Canine *) canine) << endl;


    cout << "\n----Move bird to the same position as Canine---" << endl;
    cout << "Bird's current position" << endl;
    bird->move(58, 12);
    bird->location();


    cout << "\nTry hunt again" << endl;
    ((Canine *) canine)->hunt(bird);

    cout << "\n-----------The animals info section (After Canine hunted bird)[Bird died]" << endl;

    cout << "\n" << *(animal) << endl;
    cout << "\n" << *((Bird *) bird) << endl;
    cout << "\n" << *((Canine *) canine) << endl;

    //-------------destruct------------

    cout << "----------Destruct----------" << endl;
    ((Canine*)canine)->~Canine();
    ((Bird*)bird)->~Bird();
    
    animal->~Animal();



    return 0;
}