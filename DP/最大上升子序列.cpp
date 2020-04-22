// Strategic Defense Initiative

// 題目：最大上升子序列，輸出一組解。

// 分析：dp，LIS。數據較小O（n^2）算法即可。

//            設以第i個數字作為最大上升子序列中的最後一個數的長度為f（i），則有轉移方程：

//             f（i）= max（f（j）） { 0=< j < i && data[j] < data[i] }；

//            用一個數組記錄前驅，遞歸輸出即可。

// 說明：注意輸出格式有點糾結。
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
char buf[256];
int  data[10000];
int  dp[10000];
int  front[10000];
 
void output( int d, int s )
{
	if ( front[s] >= s )
		printf("Max hits: %d\n",d+1);
	else
		output( d+1, front[s] );
	printf("%d\n",data[s]);
}
 
int main()
{
	int n;
	while (~scanf("%d",&n)) {
		getchar();
		getchar();
		while ( n -- ) {
			char ch;
			int count = 0;
			while (gets(buf) && buf[0])
				data[count ++] = atoi(buf);
			for ( int i = 0 ; i < count ; ++ i ) {
				dp[i] = 1;
				front[i] = i;
				for ( int j = 0 ; j < i ; ++ j )
					if ( data[i] > data[j] && dp[i] < dp[j]+1 ) {
						dp[i] = dp[j]+1;
						front[i] = j;
					}
			}
			
			int max = 0;
			for ( int i = 1 ; i < count ; ++ i )
				if ( dp[i] > dp[max] )
					max = i;
			
			if ( count )
				output( 0, max );
			else printf("Max hits: 0\n");
			if ( n ) printf("\n");
		}
	}
	return 0;
}