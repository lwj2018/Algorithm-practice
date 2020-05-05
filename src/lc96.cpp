/*
96. 不同的二叉搜索树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
*/
class Solution {
public:
    int numTrees(int n) {
        int a[1000] = {0};
        a[0] = 1;
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                a[i] = a[i] + a[j-1]*a[i-j];
            }
            
        }
        
        return a[n];
    }
};

int main()
{
    Solution sol = Solution();
    sol.numTrees(4);
}