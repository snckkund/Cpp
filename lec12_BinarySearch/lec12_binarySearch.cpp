#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    
    int mid = (start + end) / 2;
    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int main() {
    // code here
    int even[6] = {2,3,5,7,9,11};
    int odd[7] = {0,6,12,14,18,22,23};

    cout << "Index of 3 is: " << binarySearch(even,6,3) << endl;
    cout << "Index of 22 is: " << binarySearch(odd,7,22) << endl;
    cout << "search for 25: " << binarySearch(odd,7,25) << endl;

    return 0;
}