/*
210. 课程表 II
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    const int MAX_COURSE = 10000;
    bool dfs(vector<int>& res,unordered_map<int,vector<int>>& graph,int course,unordered_map<int,int>& color)
    {
        if(color[course]==2) return false;
        if(color[course]==1) return true;
        color[course] = 1;
        for(int & n : graph[course])
        {
            if(dfs(res,graph,n,color)) return true;
        }
        color[course] = 2;
        res.push_back(course);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> graph;
        vector<int> indegrees(numCourses,0);
        for(auto &p : prerequisites)
        {
            graph[p[0]].push_back(p[1]);
            indegrees[p[1]]++;
        }
        unordered_map<int,int> color;
        vector<int> res;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i]==0)
            {
                if (dfs(res,graph,i,color))
                {
                    return vector<int>();
                }
            }
        }
        if(res.size()<numCourses) return vector<int>();
        return res;
    }
};