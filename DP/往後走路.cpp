//給你一個n*m(n<=10,m<=100)的矩陣，
//矩陣每個點上有一個權值ai<=2^30
//你可以選擇一條路徑並選擇這條路徑每個點的的權值，
//使得這條路徑的權值之和最小
//每個點只能走到與它相鄰的右上角右下角和右邊三個點
//特別地，這個矩陣第一行和最後一行是相連的
//相同權值時，要求路徑的字典序最小，
//輸出這條由行的值構成的路徑，並輸出這個權值之和
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m;
ll ans,a[15][105],dp[15][105];
int head,Next[15][105];
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				scanf("%lld",&a[i][j]);
				dp[i][j]=1e18;
			}
		}
		ans=1e18;
		for(int j=m;j>=1;--j)//從右到左枚舉列 
		{
			for(int i=1;i<=n;++i)//增序枚舉行確保head的字典序最小 
			{
				if(j==m)dp[i][j]=a[i][j];
				else
				{
					int row[3]={i,i+1,i-1};
					if(i==n)row[1]=1;//第一行的下一行 
					if(i==1)row[2]=n;//第一行的上一行 
					sort(row,row+3);//滿足行的字典序最小 
					for(int k=0;k<3;++k)
					{
						if(dp[i][j]>dp[row[k]][j+1]+a[i][j])
						{
							dp[i][j]=dp[row[k]][j+1]+a[i][j];
							Next[i][j]=row[k];//(i,j)->(row[k],j+1) 
						}
					}
			    }
				if(j==1)
				{
					if(ans>dp[i][j])
					{
						ans=dp[i][j];
						head=i; 
					}
				} 
			}
		}
		for(int row=head,col=1;col<=m;row=Next[row][col],col++)
		printf("%d%c",row,col==m?'\n':' ');
		printf("%lld\n",ans);
	}
	return 0;
}