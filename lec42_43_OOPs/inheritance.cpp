#include <iostream>
using namespace std;
 
class Human {
public:
    float height; // in cm
    float weight; // in kg
    int age;

    int getAge() {
        return age;
    }

    void setWeight(int w) {
        this->weight = w;
    }

};

class Male: public Human {
public:
    string color;

    void sleep() {
        cout << "Male sleeping" << endl;
    }

};

int main() {
    
    Male ashish;

    // // cout << sizeof(Human) << endl;
    // // cout << sizeof(Male) << endl;
    // // cout << sizeof(Female) << endl;

    ashish.age = 20;
    ashish.weight = 76;
    ashish.height = 168;
    ashish.color = "sand";
    cout << "ashish age: " << ashish.age << endl;
    cout << "ashish weight: " << ashish.weight << endl;
    cout << "ashish height: " << ashish.height << endl;
    cout << "ashish color: " << ashish.color << endl;
    ashish.sleep();

    return 0;
}

/**
 *  +--------------------------+---------------------+------------+
 *  + super-class              + sub-class           + accessible +
 *  + access modifier property + mode of inheritance +            +
 *  + data member              +                     +            +
 *  +--------------------------+---------------------+------------+
 *  + public                   + public              + public     +
 *  + public                   + protected           + protected  +
 *  + public                   + private             + private    +
 *  + protected                + public              + protected  +
 *  + protected                + protected           + protected  +
 *  + protected                + private             + private    +
 *  + private                  + public              + NA         +
 *  + private                  + protected           + NA         +
 *  + private                  + private             + NA         +
 *  +--------------------------+---------------------+------------+
 */