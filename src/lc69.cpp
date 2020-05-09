/*
69. x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
        {
            return 0;
        }
        if (x==1)
        {
            return 1;
        }
        if (x==2)
        {
            return 1;
        }
        if (x==3)
        {
            return 1;
        }
        int min = 0;
        int max = x;
        while (max-min>1)
        {
            int i = (max+min)/2;
            if (x/i==i)
            {
                return i;
            }
            else if (x/i>i)
            {
                min = i;
            }
            else
            {
                max = i;
            }
            
        }
        return min;
    }
};