#include <bits/stdc++.h>
using namespace std;

//Failed bruteforce
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 1;
        while(nums[i]+nums[j] != target){
            while(j < nums.size()){
                j++;
            }
            i++;
            j = i+1;
        }
        vector<int> arr;
        arr.push_back(i);
        arr.push_back(j);
        return arr;
    }
};*/

//Bruteforce with 57ms
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m = 0, n = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    m = i;
                    n = j;
                    break;
                }
            }
        }
        vector<int> arr;
        arr.push_back(m);
        arr.push_back(n);
        return arr;
    }
};*/

//Using memoization with hash table
//courtesy: rahulvarma5297
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m = 0, n = 0;
        unordered_map<int, int> tables;
        for(int i = 0; i < nums.size(); i++){
            //if(nums[i] < target)
                tables.insert({nums[i] ,i});
        }

        for(int i = 0; i < nums.size(); i++){
            int b = target - nums[i];

            if(tables.count(b) && tables[b] != i)
                return {i, tables[b]};

        }
        return {};

    }
};

int main (){
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int tg = 9;
    vector<int> rs = s.twoSum(nums, tg);
    
    for(int i : rs)
        cout << i << ", ";

    return 0;
}