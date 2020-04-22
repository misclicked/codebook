/*******************************************************/
/* UVa 481 What Goes Up                                */
/* Author: Maplewing [at] knightzone.studio            */
// 經典的 LIS (Longest Increasing Subsequence) ，印出最後出現的LIS即可得解。
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int getLIS(const vector<int> &sequence, vector<int> &position){
  if(sequence.size() == 0) return 0;

  vector<int> subsequence;
  for(int i = 0 ; i < sequence.size() ; ++i ){
    vector<int>::iterator lowerBound = lower_bound(subsequence.begin(), subsequence.end(), sequence[i]);
    if(lowerBound == subsequence.end()){
      position[i] = subsequence.size();
      subsequence.push_back(sequence[i]);
    }
    else{
      position[i] = lowerBound - subsequence.begin();
      *lowerBound = sequence[i];
    }
  }

  return subsequence.size();
}


int main(){
  vector<int> sequence;
  int n;
  while(scanf("%d", &n) != EOF){
    sequence.push_back(n);
  }

  vector<int> position(sequence.size(), 0);
  int length = getLIS(sequence, position);
  printf("%d\n", length);
  printf("-\n");

  stack<int> increasingSubsequence; 
  int currentPosition = length - 1;
  for(int i = sequence.size() - 1 ; i >= 0 ; --i){
    if(currentPosition == position[i]){
      increasingSubsequence.push(sequence[i]);
      --currentPosition;
    }
  }

  while(!increasingSubsequence.empty()){
    printf("%d\n", increasingSubsequence.top());
    increasingSubsequence.pop();
  }

  return 0;
}