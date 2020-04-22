// UVA 231: Testing the CATCHER
// 题目：有一个导弹拦截系统，当它拦截一个导弹后，下次拦截就不能超过这个高度，问拦截的最多导弹数。
// 大意: 题目大意：输出最长递减子序列长度，LIS简单变形。


//  【解題想法】DP: Longest Non-Increasing Subsequence (LDS) 非嚴格遞減
#include <bits/stdc++.h>
using namespace std;
 
vector <int> v;
int Case, n;
 
int main(){
    while (1){
        cin >> n;
        if (n == -1) break;
        v.clear();
        v.push_back(n);
        while (1){
            cin >> n;
            if (n == -1) break;
            if (n <= v[v.size()-1]) v.push_back(n);
            else {
                for (int i = 0; i < v.size(); i++){
                    if (n > v[i]){
                        v[i] = n;
                        break;
                    }
                }
            }
        }
        if (Case) cout << "\n";
        Case++;
        cout << "Test #" << Case << ":\n";
        cout << "  maximum possible interceptions: " << v.size() << "\n";
    }
}