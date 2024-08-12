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

int main() {
    
    Dog d;
    d.speak();

    return 0;
}