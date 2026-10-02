#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{   
    string str = "Hello world!! 123";
    
    int cnt[4] = {0};
    
    for(char c: str){
        if(isdigit(c)){
            cnt[0]++;
        }
        else if (c == ' ') {
            cnt[1]++;
        }
        else if(isalpha(c)){
            char lower_c = tolower(c);
            
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                cnt[2]++;
            } else {
                cnt[3]++;
            }
        }
    }
    
    cout<<"Vowels: "<<cnt[2]<<endl;
    cout<<"consonants: "<<cnt[3]<<endl;
    cout<<"digits: "<<cnt[0]<<endl;
    cout<<"spaces: "<<cnt[1]<<endl;

    return 0;
}