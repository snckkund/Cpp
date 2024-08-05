#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

void printVectorvector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void swapArray(int arr[], int size) {
    for (int i=0; i<size; i+=2) {
        if (i+1<=6) {
            swap(arr[i],arr[i+1]);
        }
    }
    printArray(arr,size);

}

// Find Unique {codestudio ques}
int findUnique(int *arr, int size)
{
    //Write your code here
    int ans=0;
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Intersection Of Two Sorted Arrays {codestudio ques}
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	int i=0,j=0;
	vector<int> ans;
	while (i<n && j<m) {
		if (arr1[i]==arr2[j]) {
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else if (arr1[i]<arr2[j]) {
			i++;
		}
		else {
			j++;
		}
	}

	return ans;
}

// pair sum {codestudio ques}
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector< vector <int> > ans;
   for (int i=0; i<arr.size(); i++) {
      for (int j=i+1; j<arr.size(); j++) {
         if (arr[i]+arr[j]==s) {
            vector <int> temp;
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i],arr[j]));
            ans.push_back(temp);
         }
      }
   }
   sort(ans.begin(),ans.end());
   return ans;
}

// 3sum {codestudio}
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	set<vector<int>> st;

	for ( int i = 0 ; i < arr.size() ; i++)
	{
		for ( int  j = i+1 ; j < arr.size() ; j++)
		{
			for (int k = j+1 ; k < arr.size() ; k++)
			{
				if ((arr[i]+arr[j]+arr[k]) == K )
				{	
					vector<int> temp = { arr[i] , arr[j] , arr[k]};
					sort(temp.begin() , temp.end());
					st.insert(temp);
					
				}
			}
		}
	}
	vector<vector<int>> result(st.begin() , st.end());
	return result;
}

// sort 0,1,2 {codestudio}

// // unique number of occurrences {leetcode ques #1207}
// class Solution {
// public:
//    bool uniqueOccurrences(std::vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         vector<int> occurrences;
//         int count = 1;
//         for (int i = 1; i < arr.size(); ++i) {
//             if (arr[i] == arr[i - 1]) {
//                 count++;
//             } else {
//                 occurrences.push_back(count);
//                 count = 1;
//             }
//         }
//         occurrences.push_back(count);
//         sort(occurrences.begin(), occurrences.end());
//         for (int i = 1; i < occurrences.size(); ++i) {
//             if (occurrences[i] == occurrences[i - 1]) {
//                 return false;
//             }
//         }
//         return true;
//     } 
// };

// // Find All Duplicates in an Array {leetcode ques #442}
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> duplicates;
//         for (int i = 0; i < nums.size(); i++) {
//             int index = abs(nums[i]) - 1;
//             if (nums[index] < 0) {
//                 duplicates.push_back(abs(nums[i]));
//             } else {
//                 nums[index] = -nums[index];
//             }
//         }
//         return duplicates;
//     }
// };

int main() {
    // // swapping with next element
    // int even[6]={3,1,2,7,11,8};
    // int odd[7]={5,2,7,19,0,54,10};
    // swapArray(even,6);
    // swapArray(odd,7);

    // // find unique
    // int unique[7]={1,8,8,9,1,4,9};
    // cout << findUnique(unique,7);

    // // Intersection Of Two Sorted Arrays
    // vector<int> arr1= {1,2,3,4,5};
    // vector<int> arr2= {2,3,4,6,7};
    // vector<int> op = findArrayIntersection(arr1,5,arr2,5);
    // printVector(op);

    // // pair sum
    // vector<int> vec = {-1,9,1,-2,3,4,-5,2};
    // vector< vector<int> > out = pairSum(vec,0);
    // printVectorvector(out);


    // leetcode
    // vector<int> u = {7,4,7,4,2,7,2,2,7,3};
    // vector<int> nu = {2,2,1,1,5};
    // Solution obj;

    // cout << obj.uniqueOccurrences(u) << endl;  //  - 1
    // cout << obj.uniqueOccurrences(nu) << endl;  //  - 1

    // vector<int> vec = {2,2,1,5,4};
    // vector<int> vec_print = obj.findDuplicates(vec);  //  - 2
    // printVector(vec_print);   //  - 2

    return 0;
}