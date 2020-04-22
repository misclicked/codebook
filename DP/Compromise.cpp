// 题目大意：输入两段文章，每段文章以#字符为终止符，输出最长公共子序列（单词组成）

// 解题策略：DP+LCS输出，算法网上比比皆是。注意输入和单词分离，输出时注意当输出最后一个单词，须输出换行

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1010;
string buf1[3030], buf2[3030];
string s1[3030], s2[3030];
int dp[1010][1010], mark[1010][1010], wordnum_buf1, wordnum_buf2;
int tc = 0;

//定义字符流，分离单词
int input(string s[], string buf[], int ff){
    int i=0, k=0;
    while(ff)
    {
       getline(cin, s[++i]);
       if((s[i])[0] == '#'){
           k=0;
           for(int j=1; j<i; j++){
              stringstream ss(s[j]);
              string temp;
              while(ss >> temp)
              {

                 buf[++k] = temp;
              }
           }
           ff = 0;
       }
    }
    return k;
}

void LCS(){
   memset(dp, 0, sizeof(dp));
   memset(mark, 0, sizeof(mark));
   for(int i=1; i<=wordnum_buf1; i++){
      for(int j=1; j<=wordnum_buf2; j++){
         if(buf1[i] == buf2[j]){
            dp[i][j] = dp[i-1][j-1]+1;
            mark[i][j] = 1;
         }
         else if(dp[i-1][j] >=  dp[i][j-1]){
             dp[i][j] = dp[i-1][j];
             mark[i][j] = 2;
         }
         else{
            dp[i][j] = dp[i][j-1];
            mark[i][j] = 3;
         }
      }
   }
}

void print(int i, int j){
    if(i == 0 || j == 0)   return;
    if(mark[i][j] == 1){
       print(i-1, j-1);
       //定义全局变量，控制输出
       if(tc == 0)  cout << buf1[i];
       else cout << " " << buf1[i];
       tc++;
    }
    else if(mark[i][j] == 2)   print(i-1, j);
    else if(mark[i][j] == 3)   print(i, j-1);
}

bool read(){
    //返回文章单词数量
    wordnum_buf1 = input(s1, buf1, 1);
    wordnum_buf2 = input(s2, buf2, 1);
    return !cin.eof();
}
//////////////////////////////////////////
int main(){
    while(read()){
       LCS();
       tc = 0;
       print(wordnum_buf1, wordnum_buf2);
       cout << endl;
    }
    return 0;
}
