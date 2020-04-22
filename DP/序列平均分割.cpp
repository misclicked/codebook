//题目大意：将一个个数为n的序列分割成m份，要求这m份中的每份中值（该份中的元素和）最大值最小， 输出切割方式，
//有多种情况输出使得越前面越小的情况。
//
//解题思路：二分法求解f(x), f(x) < 0 说明不能满足， f(x) >= 0说明可以满足，f(x) 就是当前最大值为x的情况最少需要
//划分多少份-要求份数（如果f(x ) >= 0 说明符合要求而且还过于满足，即x还可以更小）。
//
//注意用long long .
#include <stdio.h>
#include <string.h>
int max(const int &a, const int &b) { return a > b ? a : b;}
 
const int N = 1005;
int n, T;
long long num[N], sum[N], rec[N];
 
bool judge(int Max) {
    int cnt = 0, first = 0, end = 1;
    while (end <= n) {
	if (sum[end] - sum[first] > Max) {
	    cnt++;
	    first = end - 1;
	}
	end++;
    }
    return cnt <= T - 1;
}
 
int main () {
    long long  cas, lift, right, cur;
    scanf("%lld", &cas);
    while (cas--) {
	// Init;
	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));
	memset(rec, 0, sizeof(rec));
	lift = right = 0;
 
	// Read.
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++) {
	    scanf("%lld", &num[i]);
	    sum[i] = sum[i - 1] + num[i];
	    lift = max(lift, num[i]);
	}
	right = sum[n];
 
	// Count;
	while (lift != right) {
	    cur = (right + lift) / 2;
	    if (judge(cur)) {
		right = cur;
	    }
	    else
		lift = cur + 1;
	}
 
	// Draw;
	long long now = 0, cnt = 0;
	for (int i = n; i > 0; i--) {
	    if (now + num[i] > lift || i < T - cnt) {
		rec[i] = 1;
		cnt++;
		now = num[i];
	    }
	    else
		now += num[i];
	}
 
	// Printf;
	for (int i = 1; i < n; i++) {
	    printf("%lld ", num[i]);
	    if (rec[i])	    printf("/ ");
	}
	printf("%lld\n", num[n]);
    }
    return 0;
}
题意：有n本书，m个人，每本书有相应的时间花费。每个人只能抄序列中连续的书，并且每人至少抄一本书。求使得最大花费时间最小的分配方式。如果有多解尽量使前面的人的工作量小。

思路：dp[i][j]表示i个人抄前j本书的最大花费时间的最小值。dp[i][j]=min(dp[i][j],max(dp[i-1][k],sum[j]-sum[k]));然后求得这个值之后，从后往前贪心地尽量让后面的人多做。
for(i=2;i<=m;i++)
           for(j=i;j<=n;j++)
           {
               dp[i][j]=INF;
               for(k=i-1;k<j;k++)
                  dp[i][j]=min(dp[i][j],max(dp[i-1][k],sum[j]-sum[k]));