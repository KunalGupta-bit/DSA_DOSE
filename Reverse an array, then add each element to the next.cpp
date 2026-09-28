#include <iostream>
#include<string>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;

int main()
{   
    vector<int> arr = {1,9,4, 3, 8};
    reverse(arr.begin(), arr.end());
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        arr[i] = arr[i] + arr[i+1];
    }
    for(int num: arr){
        cout<<num<<" ";
    }
    
    return 0;
}