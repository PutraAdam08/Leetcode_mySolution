#include <bits/stdc++.h>
using namespace std;

class Solution { // Using Two Pointer
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*if((nums1.size() + nums2.size())%2 != 0){
            if(nums1.size() > nums2.size()) return nums1.back();
            else return nums2.front();
        }*/
        int n = nums2.size() + nums1.size();
        int i = 0, j = 0 , n1 = 0, n2 = 0;

        //vector<int> temp;
        for(int temp = 0; temp <= n/2; temp++){
            n2 = n1;
            if(i != nums1.size() && j != nums2.size()){
                if(nums1[i] < nums2[j]){
                    n1 = nums1[i++];
                }
                else
                    n1 = nums2[j++];
            }
            else if(i < nums1.size())
                n1 = nums1[i++];
            else
                n1 = nums2[j++];
        }

        if(n%2 == 0){
            double ans = (double)(n1+n2);
            return ans / 2.0;
        }
        else
            return n1;/**/

        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2, 3};
    vector<int> nums2 = {1, 4};
    double o = s.findMedianSortedArrays(nums1, nums2);

    cout << o;

    return 0;

}