#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
#define min(a,b) ((a)<(b))?(a):(b)
class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int l1, int l2, int K) {
        int x1;
        int x2;
        if(K==1){
            if(l1>=nums1.size()) return nums2[l2];
            if(l2>=nums2.size()) return nums1[l1];
            return min(nums1[l1],nums2[l2]);
        }
        if(l1+K/2-1<nums1.size()) x1 = nums1[l1+K/2-1];
        else x1 = INT_MAX;
        if(l2+K/2-1<nums2.size()) x2 = nums2[l2+K/2-1];
        else x2 = INT_MAX;
        cout<<x1<<' '<<x2<<endl;
        if(x1<x2) return findKth(nums1,nums2,l1+K/2,l2,K-K/2);
        else return findKth(nums1,nums2,l1,l2+K/2,K-K/2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int k1 = (len+1)/2;
        int k2 = (len+2)/2;
        int x1 = findKth(nums1,nums2,0,0,k1);
        int x2 = findKth(nums1,nums2,0,0,k2);
        return (x1+x2)/2.0;
    }
};

int main()
{
    auto sol = Solution();
    int a1[2] = {1,2};
    int a2[2] = {3,4};
    vector<int> v1(a1,a1+2);
    vector<int> v2(a2,a2+2);
    sol.findMedianSortedArrays(v1,v2);
}