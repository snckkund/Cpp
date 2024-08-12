#include <iostream>
using namespace std;

class Animal {
public:
    int age;
    int weight;

    void speak() {
        cout << "speaking" << endl;
    }

};

class Dog: public Animal{
public:
    void bark() {
        cout << "bark!!" << endl;
    }
};

class GermanSephard: public Dog {
    
};

int main() {
    
    GermanSephard g;
    g.speak();
    g.bark();

    return 0;
}