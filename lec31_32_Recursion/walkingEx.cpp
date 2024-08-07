#include <iostream>
using namespace std;

void reachHome(int src, int dest) {
    cout << "step-" << src << " distance left: " << dest-src << "/" << dest << endl;
    // base-case
    if (src == dest) {
        cout << "Reached!!" << endl;
        return;
    }

    // processing - steps + 1
    src++;

    // recursive call
    reachHome(src,dest);
}

int main() {
    // code here
    int src = 0;
    int dest = 10;
    cout << "source: " << src << " destination: " << dest << endl;
    reachHome(src, dest);
    return 0;
}