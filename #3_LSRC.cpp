#include <bits/stdc++.h>
using namespace std;

/*class Solution { bruteforce
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, counter = 0;
        for(int i = 0; i < s.length(); i++) {
            unordered_map<char , int> substr;
            for(int j = i; j < s.length(); j++){
                if(substr.find(s[j]) != substr.end()){
                    break;
                }
                else{
                    substr.insert(make_pair(s[j], j));
                    counter++;
                }
            }
            if(counter > max)
                max = counter;
            counter = 0;
            substr.clear();
        }
        return max;
    }
};*/


class Solution { // optimised
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, len = 0, n = s.length();
        unordered_map<char, int> str;
        for(int i = 0; i < n; i++){
            if(str.find(s[i]) == str.end())
                str.insert(make_pair(s[i], -1));
        }
        
        while(r<n){
            if(str[s[r]] != -1);
                l = max(str[s[r]]+1, l);

            str[s[r]] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};


int main(){
    string s = "abc";
    Solution so;
    cout << so.lengthOfLongestSubstring(s);
    return 0;
}

//Ex: pwwkew