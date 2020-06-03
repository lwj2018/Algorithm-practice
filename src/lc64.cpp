class Solution {
public:
    int sumNums(int n) {
        int sum = n;
        bool flag = n && (sum+=sumNums(n-1));
        return sum;
    }
};