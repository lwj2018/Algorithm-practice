#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        int right = 1;
        vector<int> out(nums.size(),0);
        for (int i = 0; i < nums.size(); i++)
        {
            out[i] = left;
            left *= nums[i];
        }
        for (int i = nums.size()-1; i >= 0; i--)
        {
            out[i] = out[i] * right;
            right *= nums[i];
        }
        return out;
    }
};