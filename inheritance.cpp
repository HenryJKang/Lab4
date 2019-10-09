//
// Created by Henry on 2019-10-08.
//
#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

//class Animal
/*---------------------------------------------------*/
class Animal
{
private:
    int age;
    static long ID;
    bool life;
    std::pair<double,double> coordinate;
public:

    //Testing for the age
    int get(){return age;}

    //Testing for pair of coordinates
    pair<double,double> get1(){return coordinate;}

    // Constructor1
    Animal(int age, double x, double y):
    age(age), coordinate(std::make_pair(x,y)),life(true)
    {ID= ID++;};
    // Constructor2
    Animal():
    life(true),age(0),coordinate(std::make_pair(0,0)){ID =ID++;}

    //Virtual move method
    virtual void move(double x, double y){
        coordinate.first = x;
        coordinate.second = y;
    }

    //Destructor
    virtual ~Animal(){}

    virtual void sleep(){cout<<"Animal Sleeping..."<<endl;}
    virtual void eat(){cout<<"Animal Eating..."<<endl;}

    //Copy Constructor made
    Animal(const Animal &p2){
        age = p2.age;
        ID = p2.ID;
        life = p2.life;
        coordinate = p2.coordinate;
    }

    void setAlive(bool yn){
        life = yn;
    }
    //overload insertion operator
    friend ostream & operator <<(ostream& out, const Animal& a);
    friend istream & operator >>(istream& in, Animal& a);


};
//overload insertion operator
ostream& operator << (ostream& out, const Animal& a){
    out <<"Age:" << a.age;
    out <<"ID: "<< a.ID;
    out <<"life: "<<a.life;
    out <<"The coordinate x: "<<a.coordinate.first;
    out <<"The coordinate y: "<< a.coordinate.second;

    return out;
}
istream& operator >> (istream& in, Animal& a){
    cout <<"Enter the age";
    in >> a.age;
    cout <<"Enter if it's alive (true / false)";
    in >> a.life;
    cout <<"Enter the coordinate of x: ";
    in >> a.coordinate.first;
    cout <<"Enter the coordinate of y: ";
    in >> a. coordinate.second;
    return in;

}
//set the beginning of the Unique ID
long Animal::ID = 'A';

/*---------------------------------------------------*/

//Bird Class

class Bird : public Animal{

private:
    int age;

    //
    //double height;

    //Land-Lubbers
    pair<double,double>xycoordinate;

    //Something that flies
    //To assign value into tuple
    //get<i>(tuple variable name) where i is index of tuple.
    tuple<double,double,double>xyzcoordinate;

    //4 params Bird constructor.
    Bird(int age, int x, int y, int z){
        age = age;
        xyzcoordinate = make_tuple(x,y,z);
    }

    //default constructor
    Bird(){
        age =0;

        std::get<0>(xyzcoordinate) = 0;
        std::get<1>(xyzcoordinate) = 0;
        std::get<2>(xyzcoordinate) = 0;
    }
    // Move method for Bird class.
    void move(double x, double y, double z){
        std::get<0>(xyzcoordinate) = x;
        std::get<1>(xyzcoordinate) = y;
        std::get<2>(xyzcoordinate) = z;
    }
    //Copy Constructor
    Bird(Bird& p2){
        age = p2.age;
        xycoordinate = p2.xycoordinate;
        xyzcoordinate = p2.xyzcoordinate;

    }
    //Destructor
    ~Bird(){}

    void eat(){cout<<"Bird(s) is(are) eating..."<<endl;}

    void sleep(){cout<<"Bird(s) is(are) sleeping..."<<endl;}


    //overload insertion operator
    friend ostream & operator <<(ostream& out, const Bird& a);
    friend istream & operator >>(istream& in, Bird& a);
};

//overload insertion operator
ostream& operator << (ostream& out, const Bird& a){
    out <<"Age:" << a.age;
    //out <<"ID: "<< a.ID;
    //out <<"life: "<<a.life;
    out <<"The coordinate x: "<<std::get<0>(a.xyzcoordinate);
    out <<"The coordinate y: "<<std::get<1>(a.xyzcoordinate);
    out <<"The coordinate z: "<<std::get<2>(a.xyzcoordinate);
    return out;
}
istream& operator >> (istream& in, Bird& a){
    cout <<"Enter the age";
    in >> a.age;
//    cout <<"Enter if it's alive (true / false)";
//    in >> a.life;
    cout <<"Enter the coordinate of x: ";
    in >> std::get<0>(a.xyzcoordinate);
    cout <<"Enter the coordinate of y: ";
    in >> std::get<1>(a.xyzcoordinate);
    cout <<"Enter the coordinate of z: ";
    in >> std::get<2>(a.xyzcoordinate);

    return in;
}


/*---------------------------------------------------*/

int main() {
    std::cout << "Hello, World!" << std::endl;
    Animal a(4,32,12);
    Animal b;

    cout<<a.get1().first<<endl;
    cout<<b.get1().first<<endl;
    return 0;
}