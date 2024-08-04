#include <iostream>
using namespace std;

void update1(int j) {
    j = j + 2;
}

void update2(int& j) {
    j = j + 2;
}

/* bad pracices
int& func1(int n) { // returning a dangling reference
    int& ans = n;
    return ans;
}
int* func2(int n) { // returning a dangling pointer
    int* ptr = &n;
    return ptr;
}
*/

int getSum(int* arr, int n) {
    int sum=0;
    for (int i=0; i<n; i++) {
        sum+=arr[i];
    }
    return sum;
}

/**
 * @brief Creates a dynamically allocated character array and populates it with alphabets.
 * 
 * @param n The size of the character array.
 * @return char* A pointer to the dynamically allocated character array.
 */
char* usingDynamicI(int n) {
    char* arr = new char[n+1];
    for (int i=0; i<n; i++) {
        *(arr+i) = i+'a';
    }
    arr[n] = '\0';
    return arr;
}
/**
 * Returns a reference to a character in a dynamically allocated array.
 *
 * This function takes a pointer to a character array and an integer index as parameters.
 * It calculates the memory address of the character at the given index and assigns it to a reference variable.
 * The reference variable is then returned.
 *
 * @param p Pointer to a character array.
 * @param m Index of the character to be accessed.
 * @return Reference to the character at the given index.
 */
char& usingDynamicII(char* p, int m) {

    char &q = *(p + m);
    return q;
}

int main() {
    // // # creating a reference variable
    // int i = 5;
    // int& j = i;
    // cout << i << endl;
    // i++;
    // cout << i << endl;
    // j++;
    // cout << i << endl;

    // int i = 5;
    // //
    // cout << "before - " << i << endl;
    // update1(i);
    // cout << "after - " << i << endl;
    // //
    // cout << "before - " << i << endl;
    // update2(i);
    // cout << "after - " << i << endl;

    // // # static and dynamic allocation of memory {stack memory | heap memory}
    // int *p = new int; 
    /* `new` returns the address of 4 byte memory created for int inside heap memory. 
        pointer size = 4 (in case of 32 bit system. {general case} 8 in case of 64 bit system ) 
            +
        size of int = 4
        ------------------
        total 8 bytes of memory allocated for the program
    */
    // //
    // int* arr = new int[5]; // 4 {static} + 5*4 {dynamic} = 24bytes 

    // int n;
    // cin >> n;
    // // variable size array
    // int* arr = new int[n];
    // for (int i=0; i<n; i++) {
    //     cin >>arr[i];
    // }
    // cout << "sum of all numbers is : " << getSum(arr,n) << endl;

    /*
    -> in static memory allocation, the memory clears the local variables automatically. 
    while (<condition>) {
        int i = 5; // static
    }
    -> incase of dynamic allocation, we have to do it manually.
    while (<condition>) {
        int* i = new int; // dynamic
        delete i; // deletes from heap
    }
    while (<condition>) {
        int* arr = new int[5]; // dynamic
        delete []arr; // deletes from heap
    }
    */

    int n,m;
    cout << "enter n,m: ";
    cin >> n >> m;

    char* p1 = usingDynamicI(n);
    cout << "generated array: " << p1 << endl;
    
    char& p2 = usingDynamicII(p1,m);
    cout << "Character at index " << m << ": " << p2 << endl;
    return 0;
}