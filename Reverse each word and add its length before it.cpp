#include <iostream>
#include<string>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;

int main()
{   
    string a = "Hello world from mars";
    istringstream ss(a);
    string word;
    vector<string>words;
    while(ss >> word){
        reverse(word.begin(), word.end());
        words.push_back(word);
    }
    for(int i = 0; i < words.size(); i++){
        cout<<words[i].length()<<words[i]<<" ";
    }
    
    
    return 0;
}