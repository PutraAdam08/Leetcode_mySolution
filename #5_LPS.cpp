#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void longestPalindrome(string s) {
        string res;
        vector<int> str(256, -1);
        int max = 0;

        for(int i = s.length()-1; i >= 0; i--){
            int temp = 0;
            int a = 0;
            int b = i;
            while(s[a] != s[b]) a++;
            while(a != b && a<b && b>a){
                if(a != b) {temp++; a++;}
                if(b != a) {temp++; b--;}
            }
            cout <<temp<< endl;
            

        }
        
    }
};

int main (){
    solution ss;
    string s = "cbbd";

    ss.longestPalindrome(s);

    return 0;
}