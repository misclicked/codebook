//找subsequence a中間有b 幾種找法
//abbaa -> 5
//[1], [4], [5], [1,4], [1,5].
//Firstly, let's erase all symbols different from 'a' and 'b'. Then let's split string on blocks of consecutive symbols 'a'. 
//Now we need to multiply all sizes of blocks increased by 1. 
//It is an answer which also includes one empty subsequence, so we should just decrease it by one.
#include <bits/stdc++.h>
using namespace std;
int64_t i,k,r,z=1e9+7;
string s;
int main(){
	for(cin>>s,s+='b';i<s.size();i++){
		if(s[i]=='a')k++;
		if(s[i]=='b')r=(r*k+r+k)%z,k=0;
	}
	cout<<r;
}