// 给定两行字符串序列，输出它们之间最大公共子单词的个数

// 对于给的两个序列X 和 Y，用i 和 j分别作为它们的前缀指针，f[i][j]表示序列X的前缀Xi 和 序列Y的前缀Yi 的最长公共子序列的长度，在这道题中，可把每一个单词当作一个字符来进行比较。

// 当 i || j 为0时 ，此 f[i][j] = 0;

// 当 i!=0 && j!=0 && Xi==Yi 时 f[i][j] = f[i-1][j-1] + 1;

// 当 i!=0 && j!=0 && Xi!=Yi 时 f[i][j] = max ( f[i-1][j] + f[i][j-1] );

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct node
{
    int num;          //记录单词的个数
    string w[1010];   //单词序列
};
int f[1010][1010];    //Xi 中前i个单词 与 Yj 中前j个单词 最大公共子序列个数为f[i][j]
void devide(string s,node &t)
{
    int len=s.size();
    t.num=1;
    for(int i=0; i<len; i++)
    {
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9') )
        {
            t.w[t.num]+=s[i];
        }
        else t.num++;
    }
    int n=0;
    for(int i=1; i<=t.num ; i++)
    {
        if(!t.w[i].empty())
            t.w[++n]=t.w[i];
    }
    t.num=n;
}
int main()
{
    int ca=1;
    while(!cin.eof())
    {
        string X,Y;
        node t1,t2;
        getline(cin,X);
        devide(X,t1);      //把x中的单词取出来
        getline(cin,Y);
        devide(Y,t2);       //同上
        printf("%2d. ",ca++);
        if(X.empty() || Y.empty())
        {
            printf("Blank!\n");
            continue;
        }
        memset(f,0,sizeof(f));
        for(int i=1; i<=t1.num; i++)
            for(int j=1; j<=t2.num; j++)
            {                                        //计算前i个单词 和 前j个单词最大匹配数
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(t1.w[i] == t2.w[j])
                    f[i][j]=max(f[i][j] , f[i-1][j-1]+1);
            }
        printf("Length of longest match: %d\n",f[t1.num][t2.num]);
    }
    return 0;
}
