// 題目: 找最大子段和，如果有多个答案，那就找加一起的数最多的和起点最小的

#include <bits/stdc++.h>
using namespace std;
int a[20005];
fstream in,out;
int main()
{
    ios::sync_with_stdio(false);
    int n,c,s;
    in.open("data.txt");
    out.open("answer.txt");
    cin>>c;
    for(int t=1;t<=c;t++)
    {
        int st=1,en=-1,stm=1;
        cin>>s;
        memset(a,0,sizeof(a));
        for(int i=1;i<s;i++)
            cin>>a[i];
        int Max=-1,tmp=0;
        for(int i=1;i<s;i++)
        {
            if(tmp>=0)
                tmp+=a[i];
            else
            {
                tmp=a[i];
                stm=i;
            }
            if(tmp>Max||tmp==Max&&i-stm>en-st)
            {
                Max=tmp;
                st=stm;
                en=i;
            }
        }
        if(Max<=0)
            cout<<"Route "<<t<<" has no nice parts"<<endl;
        else
            cout<<"The nicest part of route "<<t<<" is between stops "<<st<<" and "<<en+1<<endl;
    //  if(t!=c)

    }
    in.close();
    out.close();
    return 0;
}