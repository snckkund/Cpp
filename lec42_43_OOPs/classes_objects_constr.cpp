#include <iostream>
#include <string.h>
using namespace std;
// [ ]padding
// [ ]greedy alignment
// [ ]const keyword
// [ ] initialisation list
// [ ]data member 
class Hero {
    // properties

    // by default private
    int health;
private:
    
public:
    char* name;
    char level;
    static int timeToComplete;

    // constructor
    Hero() {
        // cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    // parameterised constructor
    Hero(int health) {
        // cout << "this->" << this << endl;
        this->health = health;
    }

    Hero(int health, char level) {
        // cout << "this->" << this << endl;
        this->level = level;
        this->health = health;
    }

    // copy constructor (deep copy)
    Hero(Hero &temp) {
        // cout << "copy constructor called" << endl;
        char* ch = new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;

    }

    void print() {
        cout << endl << "[ name: " << this->name << ", ";
        
        cout << "health: " << this->health << ", ";
        cout << "level: " << this->level << " ]" << endl << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    // static function (can access static members only)
    static int random() {
        // cout << this->health << endl; // error
        // cout << health << endl; // error
        // cout << "time to complete: " << timeToComplete << endl; // can access static member
        return timeToComplete;

    }

    // destructor
    ~Hero() {
        // cout << "destructor called" << endl;
    }

};

int Hero::timeToComplete = 5; // initialise // :: scope resolution operator

int main() {
    // // creating object
    // Hero ramesh;
    // ramesh.health = 70;
    // ramesh.level = 'A';
    // cout << "hero ramesh health: " << ramesh.health << endl;
    // cout << "hero ramesh level: " << ramesh.level << endl;
    // cout << "size of ramesh is: " << sizeof(ramesh) << endl;
    // ramesh.setHealth(70); // setter
    // cout << "ramesh health is: " << ramesh.getHealth() << endl; // getter

    // // static allocation
    // Hero a;
    // a.setLevel('A');
    // a.setHealth(70);
    // cout << "level is: " << a.level << endl;
    // cout << "health is: " << a.getHealth() << endl;
    // // dynamic allocation
    // Hero* b = new Hero;
    // (*b).setLevel('B');
    // (*b).setHealth(85);
    // cout << "level is: " << (*b).level << endl;
    // cout << "health is: " << (*b).getHealth() << endl;
    // // OR
    // // b->setLevel('B');
    // // b->setHealth(85);
    // // cout << "level is: " << b->level << endl;
    // // cout << "health is: " << b->getHealth() << endl;

    // // this -> points to the current object
    // // object created statically
    // Hero ramesh(10);
    // ramesh.print();
    // // cout << "address of ramesh: " << &ramesh << endl;
    // // dynamically
    // Hero *h = new Hero(11);
    // h->print();
    // Hero temp(22,'B');
    // temp.print();

    // // copy constructor
    // Hero S(70, 'C');
    // S.print();
    // Hero R(S); /* R.health = S.health; R.level = S.level; */
    // R.print();

    // //
    // Hero S(70, 'C');
    // S.print();
    // Hero R(S);
    // R.print();

    // // in case of default copy constructor (uses shallow copy)
    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "chandu";
    // hero1.setName(name);
    // // hero1.print();
    // //
    // Hero hero2(hero1); // default copy constr
    // // Hero hero2 = hero1;
    // // hero2.print();
    // //
    // hero1.name[0] = 'S'; // changed name for hero1
    // hero1.print();
    // //
    // hero2.print(); // hero2 name also changes
    // //
    // hero1 = hero2;
    // hero1.print();
    // hero2.print();

    // // destructor (memory de-allocate)
    // // for static,  destructor is called automatically
    // Hero a;
    // // for dynamic, we have to call it manually
    // Hero* b = new Hero;
    // delete b;

    // // static data member
    // cout << "time to complete: " << Hero::timeToComplete << endl; // static member belong to the class, not he object
    // Hero a;
    // cout << a.timeToComplete << endl; // dont access like this
    // Hero b;
    // b.timeToComplete = 10;
    // cout << a.timeToComplete << endl;
    // cout << a.timeToComplete << endl; // not recommended

    // static function
    cout << Hero::random() << endl;


    return 0;
}