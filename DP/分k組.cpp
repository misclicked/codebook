//題意
//
//給你n個數，分成k組，要求每組內最大值與最小值的差值不超過5。求k組最多可以放多少個數。
//
//1 ≤ n , k ≤ 50001 \leq n,k \leq 50001≤n ,k≤5 0 0 0
//做法
//
//首先對數組排序，我們可以預處理每個數最多可以向左擴展的長度。
//之後我們用dp [ i ] [ j ]dp[i][j]d p [ i ] [ j ]表示前i個數分為j組最多可以放多少個數。
//對於每個i，一定是從之前預處理的位置轉移過來，因為一段應該放盡量多的值。
//我們設位置iii能夠擴展的最左位置為l[i]l[i]l [ i ]。那麼轉移方程為:d
//p [ i ] [ j ] = m a x ( dp [ i − 1 ] [ j ] , dp [ i ] [ j − 1 ] , dp [ l [ i ] − 1 ] [ j − 1 ] + i − l [ i ] + 1 )dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[l[i]-1][j-1]+il[i]+ 1)d p [ i ] [ j ]=m a x ( d p [ i−1 ] [ j ] ,d p [ i ] [ j−1 ] ,d p [ l [ i ]−1 ] [ j−1 ]+i−l [ i ]+1 )
//最後dp [ n ] [ k ]dp[n][k]d p [ n ] [ k ]便是答案。
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5005;
int a[maxn],l[maxn];
int dp[maxn][maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    dp[0][0]=0;
    for(int i=1;i<=n;i++) l[i]=lower_bound(a+1,a+1+n,a[i]-5)-a;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[l[i]-1][j-1]+i-l[i]+1);
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}