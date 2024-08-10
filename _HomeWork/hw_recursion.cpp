#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * - TODO: practice all the binary search problems using recursion
 * - [x]first position last position
 * - [x]Peak Index in a Mountain Array
 * - [x]Find Pivot Index (sum)
 * - [x]sqrt
 * - [x]aggressive cows
 * - [ ]book allocation
 * - [ ]search in rotated array
 * - [ ]selection sort
 * - [ ]insertion sort
 * - [ ]subset/subsequence (using bits manipulation)
 */
int firstOcc(int arr[], int start, int end, int key) {
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        // Check if it's the first occurrence
        if (mid == 0 || arr[mid - 1] != key) {
            return mid;
        }
        // Search in the left half
        return firstOcc(arr, start, mid - 1, key);
    } else if (key < arr[mid]) {
        return firstOcc(arr, start, mid - 1, key);
    } else {
        return firstOcc(arr, mid + 1, end, key);
    }
}
int lastOcc(int arr[], int start, int end, int key) {
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        // Check if it's the last occurrence
        if (mid == end || arr[mid + 1] != key) {
            return mid;
        }
        // Search in the right half
        return lastOcc(arr, mid + 1, end, key);
    } else if (key < arr[mid]) {
        return lastOcc(arr, start, mid - 1, key);
    } else {
        return lastOcc(arr, mid + 1, end, key);
    }
}
int peakIndexInMountainArray(vector<int>& arr, int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] < arr[mid + 1]) {
        return peakIndexInMountainArray(arr, mid + 1, end);
    } else {
        return peakIndexInMountainArray(arr, start, mid);
    }
}
class Pivot 
{
private:
    int leftSum(const std::vector<int>& nums, int index) {
        if (index < 0) {
            return 0;
        }
        return nums[index] + leftSum(nums, index - 1);
    }
    int rightSum(const std::vector<int>& nums, int index, int n) {
        if (index >= n) {
            return 0;
        }
        return nums[index] + rightSum(nums, index + 1, n);
    }
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int lhs = leftSum(nums, i - 1);
            int rhs = rightSum(nums, i + 1, n);
            if (lhs == rhs) {
                return i;
            }
        }
        return -1;
    }
};
class root {
public:
    int floorSqrt(int n, int start, int end, int ans=-1) {
        if (start > end) {return ans;}
        long long int mid = start + (end - start) / 2;
        long long int sq = mid * mid;
        if (sq == n) {
            return mid;
        } else if (sq < n) {
            return floorSqrt(n, mid + 1, end, mid);
        } else {
            return floorSqrt(n, start, mid - 1, ans);
        }
    }
    double morePrecision(int n, double tempsol, int precision, double fact=0.1, int currentLevel=0) {
        if (currentLevel == precision) {return tempsol;}
        // Increment tempsol with precision factor to improve accuracy
        for (double j = tempsol; 1LL*j * j < n; j += fact) {
            tempsol = j;
        }
        // Move to the next level of precision
        return morePrecision(n, tempsol, precision, fact / 10, currentLevel + 1);
    }
};
class aggrcows
{
private:
    bool isPossible(vector<int> &stalls, int k, int mid) {
        int countCows = 1;
        int lastPos = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= mid) {
                countCows++;
                if (countCows == k) {
                    return true;
                }
                lastPos = stalls[i];
            }
        }
        return countCows >= k;
    }
public:
    int aggressiveCows(vector<int> &stalls, int k, int s, int e) {
        if (s > e) {
            return -1;
        }
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, k, mid)) {
            // Try to find a better solution with a larger minimum distance
            int result = aggressiveCows(stalls, k, mid + 1, e);
            return result == -1 ? mid : result;
        } else {
            // Otherwise, try a smaller minimum distance
            return aggressiveCows(stalls, k, s, mid - 1);
        }
    }
};
int main() {
    // // first position last position
    // int arr[9] = {1,3,3,3,4,4,5,5,6};
    // cout << firstOcc(arr,0,8,1) << endl; // 0
    // cout << firstOcc(arr,0,8,3) << endl; // 1
    // cout << firstOcc(arr,0,8,4) << endl; // 4
    // cout << firstOcc(arr,0,8,5) << endl; // 6
    // cout << firstOcc(arr,0,8,6) << endl; // 8
    // cout << firstOcc(arr,0,8,0) << endl; // -1
    // cout <<endl;
    // cout << lastOcc(arr,0,8,1) << endl; // 0
    // cout << lastOcc(arr,0,8,3) << endl; // 3
    // cout << lastOcc(arr,0,8,4) << endl; // 5
    // cout << lastOcc(arr,0,8,5) << endl; // 7
    // cout << lastOcc(arr,0,8,6) << endl; // 8
    // cout << lastOcc(arr,0,8,0) << endl; // -1

    // // Peak Index in a Mountain Array
    // // Test case 1: Mountain with peak in the middle
    // vector<int> mountain1 = {1, 3, 5, 7, 6, 4, 2};
    // cout << "Peak index: " << peakIndexInMountainArray(mountain1, 0, mountain1.size() - 1) << endl; // Expected output: 3
    // // Test case 2: Mountain with peak at the beginning
    // vector<int> mountain2 = {10, 8, 6, 4, 2, 1};
    // cout << "Peak index: " << peakIndexInMountainArray(mountain2, 0, mountain2.size() - 1) << endl; // Expected output: 0
    // // Test case 3: Mountain with peak at the end
    // vector<int> mountain3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << "Peak index: " << peakIndexInMountainArray(mountain3, 0, mountain3.size() - 1) << endl; // Expected output: 9

    // // Test case 1: Pivot exists  
    // Pivot obj;
    // vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    // cout << "Pivot index: " << obj.pivotIndex(nums1) << endl; // Expected output: 3
    // // Test case 2: Pivot does not exist
    // vector<int> nums2 = {1, 2, 3};
    // cout << "Pivot index: " << obj.pivotIndex(nums2) << endl; // Expected output: -1
    // // Test case 3: Empty vector
    // vector<int> nums3;
    // cout << "Pivot index: " << obj.pivotIndex(nums3) << endl; // Expected output: -1

    // // root N
    // // Test case 1: Perfect square
    // root obj;
    // int n1 = 15;
    // int tempsol1 = obj.floorSqrt(n1, 0, n1);
    // cout << "floor square root: " << tempsol1 << endl; // Expected output: 3
    // cout << "2 precision square root: " << obj.morePrecision(n1, tempsol1, 2) << endl;
    // // Test case 2: Non-perfect square
    // int n2 = 27;
    // int tempsol2 = obj.floorSqrt(n2, 0, n2);
    // cout << "floor square root: " << tempsol2 << endl; // Expected output: 5
    // cout << "3 precision square root: " << obj.morePrecision(n2, tempsol2, 3) << endl;
    // // Test case 3: Large number
    // int n3 = 100099;
    // int tempsol3 = obj.floorSqrt(n3, 0, n3);
    // cout << "floor square root: " << tempsol3 << endl; // Expected output: 316
    // cout << "1 precision square root: " << obj.morePrecision(n3, tempsol3, 1) << endl;

    // aggresive cows
    aggrcows obj;
    // Test case 1: Minimum number of stalls with 1 cow
    vector<int> test1 = {1};
    cout << obj.aggressiveCows(test1, 1, test1[0], (test1[test1.size()-1])) << endl; // Expected output: 1
    // Test case 2: Minimum number of stalls with 2 cows
    vector<int> test2 = {1};
    cout << obj.aggressiveCows(test2, 2, test2[0], (test2[test2.size()-1])) << endl; // Expected output: -1
    // Test case 3: Equal number of stalls and cows
    vector<int> test3 = {1, 2, 3, 4, 5};
    cout << obj.aggressiveCows(test3, 3, test3[0], (test3[test3.size()-1])) << endl; // Expected output: 2
    // Test case 4: More stalls than cows
    vector<int> test4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << obj.aggressiveCows(test4, 5, test4[0], (test4[test4.size()-1])) << endl; // Expected output: 2
    // Test case 5: More cows than stalls
    vector<int> test5 = {1, 2, 3, 4, 5};
    cout << obj.aggressiveCows(test5, 6, test5[0], (test5[test5.size()-1])) << endl; // Expected output: -1
    // Test case 6: More cows than stalls
    vector<int> test6 = {4,2,1,3,6};
    sort(test6.begin(),test6.end());
    cout << obj.aggressiveCows(test6, 2, test6[0], (test6[test6.size()-1])) << endl; // Expected output: 5
    
    return 0;
}