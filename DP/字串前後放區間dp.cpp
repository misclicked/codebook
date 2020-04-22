//題目大意：
//給定一個字符串S和T。有兩種操作：
//1.將S的最前面的字符移到A字符串的最前面，然後將S中的這個最前面的字符刪掉。
//2.將S的最前面的字符移到A字符串的最後面，然後將S中的這個最前面的字符刪掉。
//用不超過n個操作，問有多少個操作序列能夠使得生成的字符串的前綴為T。
//
//解題思路：
//區間dp。首先將T想像成S一樣長的字符，其中長度大於T的部分就是對任何字符都可以匹配。
//dp[i][j]表示T中[i…j]被匹配的方案數。
//然後最外層枚舉區間長度len，內層枚舉i。
//將S的第len個字符插入T的最前面，則將S[len]和T[i]進行比較，如果相同則dp[i][i+len-1]+ = dp[i+1][ i+len-1]。
//將S的第len個字符插入T的最後面，則將S[len]和T[i+len-1]進行比較，如果相同則dp[i][i+len-1]+=dp[i ][i+len-2]。
//因為操作不超過n次，但為了有T的前綴，最少要操作m次，則將dp[1][m…n]的答案都加起來，最後*2就是答案了。
#import<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
string s,t;
ll dp[3002][3002],n,m,ans=0,i,l,r;
int main(){
    cin>>s>>t;
    n=s.size();m=t.size();
    s="*"+s;t="*"+t;
    for(i=1;i<=n+1;++i)dp[i][i-1]=1;
    for(i=1;i<=n;++i)
    for(l=1,r=l+i-1;r<=n;++l,++r){
        if(l>m||s[i]==t[l])dp[l][r]+=dp[l+1][r]%mod;
        if(r>m||s[i]==t[r])dp[l][r]+=dp[l][r-1]%mod;
    }
    for(i=m;i<=n;++i)
    ans=(ans+dp[1][i])%mod;
    cout<<ans;
}