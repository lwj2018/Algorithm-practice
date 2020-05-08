/*
221. 最大正方形
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
*/
#include<iostream>
#include<vector>
using namespace std;


#define min(a,b) ((a)<(b)?(a):(b))
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int dp[1000][1000] = {0};
        int maxLength = 0;
        int l1 = matrix.size();
        int l2 = matrix[0].size();
        
        if (l1==0) return 0;
        else if(l2==0) return 0;
        
        dp[0][0] = matrix[0][0]-'0';
        for (int i = 1; i < l1; i++)
        {
            dp[i][0] = matrix[i][0]-'0';
        }
        for (int j = 1; j < l2; j++)
        {
            dp[0][j] = matrix[0][j]-'0';
        }
        
        for (int i = 1; i < l1; i++)
        {
            for (int j = 1; j < l2; j++)
            {
                if (matrix[i][j]=='1')
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1],dp[i][j-1]);
                    dp[i][j] = min(dp[i][j],1 + dp[i-1][j]);
                }
            }
            
        }
        for (int i = 0; i < l1; i++)
            for (int j = 0; j < l2; j++)
                if(dp[i][j]>maxLength)
                    maxLength = dp[i][j];
        return maxLength*maxLength;
    }
};

void readMatrix(int&l1,int&l2,vector<vector<char>>& matrix)
{
    cin>>l1>>l2;
    for (int i = 0; i < l1; i++)
    {
        vector<char> row;
        for (int j = 0; j < l2; j++)
        {
            char x;
            cin>>x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    
}

void printMatrix(vector<vector<char>> matrix)
{
    int l1 = matrix.size();
    int l2 = matrix[0].size();
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void print2dArray(int l1,int l2)
{
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    // char x;
    // cin>>x;
    // cout<<x-'0'<<endl;
    int l1,l2;
    vector<vector<char>> matrix;
    readMatrix(l1,l2,matrix);
    Solution sol = Solution();
    sol.maximalSquare(matrix);
    print2dArray(l1,l2);
}