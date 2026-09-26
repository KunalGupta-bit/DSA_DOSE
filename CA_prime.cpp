#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int k = 5;
    int cnt = 0;
    int num = 2;
    vector<int> arr;

    while(cnt < k){
        if(isPrime(num)){
            arr.push_back(num);
            cnt++;
        }
        num++;
    }
    for(int x:arr){
        cout<<x<<" ";
    }


    return 0;
}