#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*if((nums1.size() + nums2.size())%2 != 0){
            if(nums1.size() > nums2.size()) return nums1.back();
            else return nums2.front();
        }*/
        int n = nums2.size() + nums1.size();
        int i = 0, j = 0 ,temp = -1;

        if(n/2 == 0) temp == 0;
        //vector<int> temp;
        while(i + j < nums2.size() + nums1.size()){
            if(temp == n/2){
                break;
            }
            if(nums1[i] <= nums2[j] && i < nums1.size()){
                //temp.push_back(nums1[i]);
                i++;
                temp++;
            }
            else{
                //temp.push_back(nums2[j]);
                if(j < nums2.size()-1)
                    j++;
                temp++;
            }
            temp = i+j;
        }

        if(n%2 == 0)
            return (double)(nums1[i-1]+nums2[j])/2;
        else
            return nums2[j];

        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    double o = s.findMedianSortedArrays(nums1, nums2);

    cout << o;

    return 0;

}