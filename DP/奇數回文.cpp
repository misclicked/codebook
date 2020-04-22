//大致題意：給你一個序列，數字有-1或者1到k構成。其中的-1需要用1到k中任意一個數字替代，現在定義一個壞序列的標準是把-1替代完畢後，
//沒有長度大於1的奇回文串。問你在所有的替代方案中，最後能得到不是壞序列的方案數是多少。
//
//這裡的一個奇回文串，看似很複雜不知道應該怎麼做，但是其實很容易發現，所有的奇回文串必定包含一個長度為3的回文串。換句話說，
//含有長度為3的回文串的就是壞序列。再進一步，發現長度為3的回文串，第一個字符和第三個字符是一樣的。也就意味著，如果我們把原串
//按照奇偶取拆成兩個串的話，只要其中有一個串有連續兩個相同的字符，那麼這個串就是一個壞序列，反之就是好序列。
//
//繼續分析，最後的答案就是奇數串好序列個數*偶數串好序列個數。那麼，現在問題的關鍵就是怎麼求這個好序列個數。我們考慮dp[i][0]表示
//長度為i的一串-1且兩端夾著兩個不相等的數字的好序列方案數。同理，dp[i][1]表示長度為i的一串-1且兩端夾著兩個相等的數字的好序列的
//方案數。那麼，我們可以很簡單的得到轉移方程：
//
//
//dp[i][0] = dp[i-1][0] + (k-2)*d[i-1][1]
//dp[i][1] = (k-1)*d[i-1][0]
//dp[0][0] = 0, dp[1][0] = 1
//
//根據這個轉移方程，我們就可以把序列按照已知的數字進行分段，把每一段的方案數乘起來就是我們最後的答案。最後要特殊處理
//一下兩端為-1的情況。具體見代碼：
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define file(x) freopen(#x".in","r",stdin);
 
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
 
int a[N],b[N];
int n,k,l1,l2;
 
LL solve(int *a,int len)
{
    if (len==1)
        if (a[1]==-1) return k;
                else return 1;
    LL sam=1,dif=0,res=1;
    int ls=a[1];
    for(int i=2;i<=len;i++)
    {
        LL nxt_sam=dif*(k-1)%mod;
        LL nxt_dif=(sam+(k-2)*dif%mod)%mod;
        if (a[i]==-1) sam=nxt_sam,dif=nxt_dif;
        else
        {
            if (ls==-1) res=res*(nxt_sam+nxt_dif*(k-1)%mod)%mod;
            else res=res*(a[i]==ls?nxt_sam:nxt_dif)%mod;
            ls=a[i]; sam=1; dif=0;
        }
    }
    res=res*(sam+dif*(k-1)%mod)%mod;
    if (ls==-1) return res*k%mod;
    return res;
}
 
int main()
{
    scc(n,k);
    for(int i=1;i<=n;i++)
    {
        int x; sc(x);
        if (i&1) a[++l1]=x;
            else b[++l2]=x;
    }
    printf("%lld\n",solve(a,l1)*solve(b,l2)%mod);
}