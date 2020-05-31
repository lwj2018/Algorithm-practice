/*
84. 柱状图中最大的矩形

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/
#include <cmath>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int max = 0;
        int top;
        for (int i = 0; i < heights.size(); i++)
        {
            if(s.empty()||heights[i]>=heights[s.top()]) {
                s.push(i);
            }
            else {
                while(heights[i]<heights[s.top()]) {
                    top = s.top();
                    int h = heights[top];
                    if(h*(i-top)>max) max = h*(i-top);
                    s.pop();
                    if(s.empty()) break;
                }
                s.push(i);
                heights[top] = heights[i];
            }
        }
        return max;
    }
};