//有三個桶子，它們各能裝 a ， b ， 和 c 公升。（a , b , c 都為正整數而且不超過200。）第一，第二個桶子最剛開始是空的，
//但是第三個桶子卻是裝滿水的。你可以從 X 桶子把水倒入 Y 桶子裡並且把 Y 桶子裝滿，要不然就是把 X 桶子倒乾。倒水的步驟可以執行很多次。
//
//你要寫一個程式去計算整個過程中至少要倒多少水才能達成目標，即這三個桶子中有一個桶子剩 d 公升的水。（d 為正整數而且不超過200。）
//但是如果你沒有辦法達成目標，也就是沒有辦法讓任何一個桶子剩下 d 公升的水，那麼請達成 d’ 公升，d’ 比 d小但是最接近 d。當 d’ 找到了，
//請你輸出整個過程至少要倒多少水才能達成 d’ 公升。
//BFS
#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct state {
	int a[3], cost;
	bool operator < (const state& a) const {
		return this -> cost > a.cost;
	}
};
state temp;
int jugs[3], d, vis[205][205], ans[205], head, tail;
void update(state s) { 
	for (int i = 0; i < 3; i++) {
		int t2 = s.a[i];
		if (ans[t2] < 0 || s.cost < ans[t2]) { //记录到达t2状态(出现装有t2水量的水杯)所需的最小水量
			ans[t2] = s.cost;
		}
	}
}
void BFS() {  
	priority_queue<state> q;
	state start;  
	start.cost = 0;  
	start.a[0] = 0;  
	start.a[1] = 0;  
	start.a[2] = jugs[2];  
	q.push(start);  
	vis[0][0] = 1;   
 
	while(!q.empty()) {  
		temp = q.top();  
		q.pop();  
		update(temp);  //更新记录
		if(ans[d] >= 0)	break;  
 
		for(int i = 0; i < 3; i++) {  
			if (temp.a[i] == 0) continue;
 
			for(int j = 0; j < 3; j++) {  
				if (i == j) continue;
				if (temp.a[j] == jugs[j]) continue;
 
				int m = min(temp.a[i], jugs[j] - temp.a[j]);  
				state temp2 = temp;  
				temp2.cost += m;  
				temp2.a[i] -= m;  
				temp2.a[j] += m;  
 
				if(!vis[temp2.a[0]][temp2.a[1]]) {  
					vis[temp2.a[0]][temp2.a[1]] = 1;  
					q.push(temp2);  
				}  
			}  
		}  
	}  
 
}  
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &jugs[0], &jugs[1], &jugs[2], &d);
		memset(vis, 0, sizeof(vis));
		memset(ans, -1, sizeof(ans));
		BFS();
		while (d >= 0) {
			if (ans[d] >= 0) { //若不能到达目标状态，就寻找最接近并且可达状态
				printf("%d %d\n", ans[d], d);
				break;
			}
			d--;
		}
	}
}