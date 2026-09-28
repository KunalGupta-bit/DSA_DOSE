#include <iostream>
#include<string>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;

int power(int base, int dig){
    int result = 1;
    for(int i = 0; i < dig; i++){
        result*=base;
    }
    return result;
}

bool isArmstrong(int num){
    int onum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;
    
    while(temp > 0){
        digits++;
        temp/=10;
    }
    
    temp = num;
    while(temp > 0){
        int rem = temp%10;
        sum += power(rem, digits);
        temp /= 10;
    }
    return (sum == onum);
}

int main()
{
    int start, end;

    cout << "Enter the starting number of the range: ";
    cin >> start;
    cout << "Enter the ending number of the range: ";
    cin >> end;

    cout << "Armstrong numbers between " << start << " and " << end << " are:" << endl;
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    
    return 0;
}