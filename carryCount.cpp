#include <iostream>
using namespace std;

int main()
{
    int cnt = 0;
    int carry = 0;
    
    int a = 165451555;
    int b = 23456705;
    int sum = 0;
    
    while(a > 0 && b > 0){
        int x = a%10;
        int y = b%10;
        if(x+y+carry >= 10){
            carry = 1;
            cnt +=1;
        }
        a = a/10;
        b = b/10;
    }
    cout<<cnt;

    return 0;
}