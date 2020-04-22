// 題意:
// 此題輸出入都是小寫字母

// 每兩行為一組測資，分別代表兩序列 (A 和 B)
// 輸出共同存在 A 和 B的字母
// 如果某字母出現不只一次，就要印出 A 和 B 之間較少的次數

// 如: A = abccc , B = accd，則輸出 acc

// 以字母 a ~ z 的順序印出

// 解法:
// 以兩陣列分別統計兩序列所有元素出現次數
// 輸出時，從 a 開始，依序印出兩陣列次數大於0且較小次數的字母

// 其中，小寫 a~z 的 ASCII 為從 97~122

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a,b;//輸入用字串
    int i,t;//方便用

    while(getline(cin, a))//輸入資料
    {
        getline(cin, b);//輸入資料

        string re[1000]={""};//記錄用陣列

        for(i=0;i<a.length();i++)//使用雙重迴圈比對
        {
            for(t=0;t<b.length();t++)
            {
                if(a[i]==b[t])//找到重複的字
                {
                    re[i]=a[i];//紀錄
                    b.erase(t,1);//擦掉該字避免重複找查
                    break;//直接結束第二個迴圈， 理由同上
                }
            }
        }

        sort(re,re+1000);//排序

        for(i=0;i<1000;i++)//輸出
        {
            cout<<re[i];
        }

        cout<<endl;//記得換行
    }
    return 0;

}