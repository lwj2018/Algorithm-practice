#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
    while(1)
    {
        map<vector<char>,int> dict;
        int count = 0;
        char c = getchar();
        if(c=='#') break;
        vector<char> word;
        if(c!=' '&&c!='\n')
        word.push_back(c);
        // 统计一行中的单词数
        while (1)
        {
            char c = getchar();
            if(c==' '||c=='\n')
            {
                map<vector<char>,int>::iterator itr = dict.find(word);
                if(itr!=dict.end())
                {}
                else
                {
                    dict[word] = 0;
                    if(word.size()>=1)
                    {
                        count += 1;
                    }
                }
                word.clear();
                if(c=='\n')
                {
                    break;
                }
            }
            else
            {
                word.push_back(c);
            }
            
        }
        printf("%d\n",count);
        
    }
}