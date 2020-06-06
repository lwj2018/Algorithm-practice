#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int> ();
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ret;
        int maxl = (m-1)/2 < (n-1)/2 ? (m-1)/2 : (n-1)/2;
        for (int l = 0; l <= maxl; l++)
        {
            for (int j = l; j < n-l; j++)
            {
                ret.push_back(matrix[l][j]);
            }
            if(l==maxl&&maxl%2!=0) {}
            else {
                for (int j = l+1; j < m-l; j++)
                {
                    ret.push_back(matrix[j][n-l-1]);
                }
                for (int j = n-l-2; j >= l; j--)
                {
                    ret.push_back(matrix[m-l-1][j]);
                }
                if(l==(n-1)/2&&n%2!=0) {}
                else {
                    for (int j = m-l-2; j > l; j--)
                    {
                        ret.push_back(matrix[j][l]);
                    }
                }
            }
        }
        return ret;
    }
};