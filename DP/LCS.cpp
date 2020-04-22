//「最長共同子序列」。出現於每一個序列、而且是最長的子序列。可能有許多個。
//
//s1: 2 5 7 9 3 1 2
//s2: 3 5 3 2 8
//
//LCS(s1, s2) = 5 3 2
//s1: a b c d b c e e a
//s2: c a b d e f g a
//s3: d c e a
//
//LCS(s1, s2, s3) =  {c e a, d e a}
//LCS(s1, s2) =
// { max( LCS(sub1, s2), LCS(s1, sub2) ) , when e1 != e2
// { LCS(sub1, sub2) + e1                , when e1 == e2
const int n1 = 7, n2 = 5;
// 為了實作方便，從陣列的第1格開始存入序列。
int s1[7+1] = {0, 2, 5, 7, 9, 3, 1, 2};
int s2[5+1] = {0, 3, 5, 3, 2, 8};
int length[7+1][5+1];   // DP表格
 
void LCS()
{
    // 初始化：當s1或s2是空集合，則LCS是空集合。
    // length[x][0] = length[0][x] = 0;
    for (int i=0; i<=n1; i++) length[i][0] = 0;
    for (int j=0; j<=n2; j++) length[0][j] = 0;
 
    // 填表格：依照遞迴公式
    for (int i=1; i<=n1; i++)
        for (int j=1; j<=n2; j++)
            if (s1[i] == s2[j])
                // +1是因為e1的長度為1
                length[i][j] = length[i-1][j-1] + 1;
            else
                length[i][j] = max(length[i-1][j],
                                   length[i][j-1]);
 
    cout << "LCS的長度是" << length[n1][n2];
}