/*
155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MinStack {
public:
    int s[20000];
    int mTop;
    int min;
    /** initialize your data structure here. */
    MinStack() {
        mTop = 0;
    }
    bool empty(){
        return (mTop==0);
    }
    
    void push(int x) {
        if (empty())
        {
            min = x;
        }
        if(x<min) min = x;
        s[mTop] = x;
        s[mTop+1] = min;
        mTop++;
        mTop++;
    }
    
    void pop() {
        if (!empty())
        {
            mTop--;
            mTop--;
        }
        if (!empty())
        {
            min = s[mTop-1];
        }
    }
    
    int top() {
        return s[mTop-2];
    }
    
    int getMin() {
        return s[mTop-1];
    }
};

int main()
{
    MinStack m;
    m.push(2);
    m.push(0);
    m.push(3);
    m.push(0);
    cout<<m.getMin()<<endl;
    m.pop();
    cout<<m.getMin()<<endl;
    m.pop();
    cout<<m.getMin()<<endl;
    m.pop();
    cout<<m.getMin()<<endl;
}