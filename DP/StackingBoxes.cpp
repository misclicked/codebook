//題目
//在數學或電腦科學裡，有些概念在一維或二維時還蠻簡單的，但到 N 維就會顯得非常複雜。試想一個 n 維的「盒子」：在二維空間裡
//，盒子 ( 2 , 3 ) 可代表一個長為 2 個單位，寬為 3 個單位的盒子；在三維空間裡，盒子 ( 4 , 8 , 9 ) 則是一個 4*8*9
//（長、寬、高）的盒子。至於在六維空間裡，也許我們不清楚 ( 4 , 5 , 6 , 7 , 8 , 9 ) 長得怎樣，不過我們還是可以分析這
//些盒子的特性。在此問題裡，我們要算出一組 n 維盒子裡，它們的「最長套入串列」： b1,b2,......,bk，其中每個盒子 bi 都
//可以「放入」盒子 bi+1 中（1≤i<k）考慮兩個盒子 D =（ d1,d2,......,dn ）， E =（ e1,e2,......,en ）。如果盒子 
//D 的 n 個維，能夠存在一種重排，使得重排後， D 每一維的量度都比 E 中相對應的維的量度還要小，則我們說盒子 D 能「放入」
//盒子 E 。（用比較不嚴謹的講法，這就好像我們將盒子 D 翻來翻去，看看能不能擺到 E 裡面去。不過因為我們考慮的是任一重排，
//所以實際上盒子不只可轉來轉去，甚至還可以扭曲。）（還是看看下面的例子說明好了）。譬如說，盒子 D = ( 2 , 6 ) 能夠被放
//入盒子 E = ( 7 , 3 ) 裡，因為 D 可以重排變為 ( 6 , 2 ) ，這樣子 D 的每個維的量度都比 E 裡對應的維還要小。而盒子 
//D = ( 9 , 5 , 7 , 3 ) 就沒辦法放進盒子 E = ( 2 , 10 , 6 , 8 ) ，因為就算再怎摸重排 D 裡的維，還是沒辦法符合
//「放入」的條件。不過 F = ( 9 , 5 , 7 , 1 ) 就可以放入 E 了，因為 F 可以重排成 ( 1 , 9 , 5 , 7 ) ，這樣就符合
//了放入的條件。我們今定義「放入」如下：對於任兩個盒子 D =（ d1,d2,......,dn）和 E =（ e1,e2,......,en ），
//如果存在一種 1..n 的重排π，使得對於任何的 1≤i≤n，皆有 dπ(i)<ei，則我們說盒子 D 能「放入」盒子 E
//
//Input Format
//輸入包含多組測試資料。每組測試資料的第一列有兩個數字：第一個是盒子的數量 k ，然後是盒子的維數 n 。
//接下來有 k 列，每列有n個整數表示一個盒子的 n 個維的量度，量度之間由一個以上的空白做區隔。第一列表示第一個盒子，第二列表示第二個盒子，依此類推。
//此問題裡，盒子的維數最小是 1 ，最大是 10 ， 並且每組測試資料中盒子的個數最多為 30 個。
//
//Output Format
//對於每一組測試資料，你必須輸出兩列數字：第一列是「最長套入串列」的長度，第二列是按照內外順序，印出「最長套入串列」
//裡盒子的編號（其中編號是按照在輸入檔案的每組數列裡所出現的順序，例如第一個盒子就是 1 號 . . . 等等。）最裡面的盒子
//（或是最小的）擺在第一個，再來是次小的，依此類推。
//如果對於每一組的盒子，存在兩個以上的「最長套入串列」，輸出任何一個均可。
//Solution
//這題其實就是經典的LIS變形題目，首先我們要對每一個箱子的維度進行排序，可以用簡單邏輯得知由小到大排是最佳方式。
//接著我們再對各箱子進行排序，排序是利用字典大小的方法排，這樣就解決了！

#include <bits/stdc++.h>
using namespace std;

int k, n;
struct objects {
    int length[12];
    int num;
    bool operator < (objects const &b) const {
        for (int i = 0; i < n; i++)
            if (!(length[i] < b.length[i]))
                return 0;
        return 1;
    }
}input[35];
int dp[35];
int previous[31];
int ans;
void trace(int i) {
    if (previous[i] != -1) trace(previous[i]);
    cout << input[i].num;
    if (--dp[ans])
        cout << ' ';
    else
        cout << '\n';
}
bool cmp(objects a, objects b) {
    for (int i = 0; i < n; i++) {
        if (a.length[i] < b.length[i])
            return 1;
        if (a.length[i] > b.length[i])
            return 0;
    }
    return 0;
}

int main() {
    while (cin >> k >> n) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++)
                cin >> input[i].length[j];
            input[i].num = i + 1;
            sort(input[i].length, input[i].length + n);
        }
        for (int i = 0; i < k; i++) dp[i] = 1;
        sort(input, input + k, cmp);
        for (int i = 0; i < k; i++)
            previous[i] = -1;
        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (input[i] < input[j] && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    previous[j] = i;
                }
        ans = 0;
        for (int i = 1; i < k; i++)
            if (dp[ans] < dp[i])
                ans = i;
        cout << dp[ans] << '\n';
        trace(ans);
    }
    return 0;
}