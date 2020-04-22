//題解：這個題只要知道異或滿足
//
//　　if A ^ B == C then A == B ^ C 這個性質
//
//就會很簡單，首先處理出異或前綴和是很自然的，之后對於滿足條件的pair，必定有f(r) == f(l - 1)，
//f即異或前綴和，這是必要條件，同時也是充分的，充分性同樣利用這個性質
//
//　　若有a[l] ^ a[l+1] ^ ... ^ a[k] = a[k+1] ^ a[k + 2] ^ ... ^ a[r]， 那么就可以利用上述性質使得k == mid，因為
//如果k > mid，那么,等式兩邊同時異或a[k]即可將a[k]從等式左邊變到右邊，繼續進行這種操作知道k == mid，對於k < mid，同理，
//因此現在就是找滿足異或前綴和相等的pair，並且要使得r - l + 1是偶數，也就是r 和 l - 1同奇偶，這個問題很好解決，統計每種異
//或前綴和的個數（對每個值按下標奇偶性分類）即可計算出最終結果，由a數組數據的范圍可知異或前綴和 < 2^21，復雜度是完全可以接受的
//，別忘了開 long long。
#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 1; i <= (n); i++)
#define sqr(x) ((x) * (x))

const int maxn = 2000000 + 100;
const int maxm = 200000 + 100;
const int maxs = 10000 + 10;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const LL unit = 1LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-14;
const double inf = 1e15;
const double pi = acos(-1.0);
const int SIZE = 100 + 5;
const LL MOD = 1000000007;

LL cnt[maxn][2];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int pre = 0, x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        pre ^= x;
        //cout << pre << endl;
        cnt[pre][i % 2]++;
    }
    LL ans = 0;
    cnt[0][0]++;
    for (int i = 0; i < maxn; i++)
    {
        ans += cnt[i][0] * (cnt[i][0] - 1) / 2;
        ans += cnt[i][1] * (cnt[i][1] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
 }