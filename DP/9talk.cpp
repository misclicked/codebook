//01
for i=1..N
 for v=V..0
 f[v]=max{f[v],f[v-c[i]]+w[i]}; 
//01優化
 for i=1..n
 bound=max{V-sum{w[i..n]},c[i]}
 for v=V..bound
//完全背包：每種物品有無限件
for i=1..N
 for v=0..V
 f[v]=max{f[v],f[v-cost]+weight} 
//多重背包：每種物品最多n[i]件
const int N = 100, W = 100000;
int cost[N], weight[N], number[N];
int c[W + 1];
 
void knapsack(int n, int w)
{
    for (int i = 0; i < n; ++i)
    {
        int num = min(number[i], w / weight[i]);
        for (int k = 1; num > 0; k *= 2)
        {
            if (k > num) k = num;
            num -= k;
            for (int j = w; j >= weight[i] * k; --j)
                c[j] = max(c[j], c[j - weight[i] * k] + cost[i] * k);
        }
    }
    cout << "最高的價值為" << c[w];
}
//多重背包可行性
F[0, 1 . . . V ] ← −1
F[0, 0] ← 0
for i ← 1 to N
    for j ← 0 to V
        if F[i − 1][j] ≥ 0
            F[i][j] = Mi
        else
            F[i][j] = −1
    for j ← 0 to V − Ci
        if F[i][j] > 0
            F[i][j + Ci] ← max{F[i][j + Ci], F[i][j] − 1}
//湊零錢問題
int price[5] = {5, 2, 6, 11, 17};
int c[1000+1];
 
void change(int m)
{
    memset(c, 0, sizeof(c));
    c[0] = 1;
 
    for (int i = 0; i < 5; ++i)
        for (int j = price[i]; j <= m; ++j)
            c[j] += c[j-price[i]];
 
    cout << "湊得價位" << m;
    cout << "湊法總共" << c[m] << "種";
}
//找零錢問題
int price[5] = {50, 20, 10, 4, 2};
 
void cashier(int n)
{
    int c = 0;
    for (int i=0; i<5; ++i)
    {
        c += n / price[i];
        n %= price[i];
    }
 
    if (n != 0)
        cout << "找不出來";
    else
        cout << "找了" << c << "個錢幣";
}
//混合背包
for i ← 1 to N
    if 第 i 件物品属于 01 背包
        ZeroOnePack(F,Ci,Wi)
    else if 第 i 件物品属于完全背包
        CompletePack(F,Ci,Wi)
    else if 第 i 件物品属于多重背包
        MultiplePack(F,Ci,Wi,Ni)
//二維背包：：对于每件物品，具有两种不同的费用，选择这件物品必
//须同时付出这两种费用。对于每种费用都有一个可付出的最大值（背包容量）。
F[i, v, u] = max{F[i − 1, v, u], F[i − 1, v − Ci, u − Di] + Wi}
//分组的背包问题：划分为 K 组，每组中的物品互相冲突，最多选一件。
for k ← 1 to K
    for v ← V to 0
        for all item i in group k
            F[v] ← max{F[v], F[v − Ci] + Wi}
