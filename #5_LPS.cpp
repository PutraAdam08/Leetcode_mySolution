#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        string res;
        int max = 0;

        for(int i = s.length()-1; i >= 0; i--){
            int temp = 0;
            int a = 0;
            int b = i;
            while(s[a] != s[b] && a < s.length()) a++;
            if(a == s.length()-1 || a == 0) continue;
            cout << a << endl;
            while(temp <= b-a){
                res.push_back(s[temp+a]); temp++;
            }
            return res;
            
        }
        return "";
    }
};

int main (){
    solution ss;
    string s = "aacabdkacaa";

    string res = ss.longestPalindrome(s);
    cout << res;

    return 0;
}