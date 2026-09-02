#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> nums1 = {42, 7, 89, 14, 56, 3, 91, 28, 65, 33};
    vector<int> nums2 = {12, 84, 5, 49, 73, 22, 60, 98, 17, 39};

    int n = nums1.size();
    int m = nums2.size();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    nums1.resize(n + m);

    int i = n-1;
    int j = m-1;
    int k = m+n-1;

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while(i>=0){
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }

    for (int x : nums1) {
        cout << x << " ";
    }

    return 0;
}