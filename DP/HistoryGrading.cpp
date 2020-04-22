// 题目：历史上有一些事件发生的先后顺序，现在有很多学生写了不同的顺序表，

//            判断每个学生的最大的前后顺序正确的序列。

// 分析：dp，LIS，最大上升子序列。

//            注意本题的数据格式，串里的每个元素对应于：对应下标编号的事件在表中的位置；

//            状态：F（n）记录以第n个元素为结束元素的序列的最长上升子序列，有转移方程：

//             F（n）= max（F（i）+1）  { 其中 0 < i < n 且 data[i] < data[n] }
#include <iostream>
#include <cstdlib>

using namespace std;

int A[22],B[22],L[22];

int main()
{
	int n,t;
	cin >> n;
	for (int i = 1 ; i <= n ; ++ i)
		cin >> A[i];
	while (cin >>t) {
		B[t] = 1;
		for (int i = 2 ; i <= n ; ++ i) {
			cin >> t;
			B[t] = i;
		}

		for (int i = 1 ; i <= n ; ++ i) {
			L[i] = 1;
			for (int j = 1 ; j < i ; ++ j)
				if (A[B[j]] < A[B[i]] && L[j] >= L[i])
					L[i] = L[j]+1;
		}

		int max = 0;
		for (int i = 1 ; i <= n ; ++ i)
			if (max < L[i])
				max = L[i];

		cout << max << endl;
	}
	return 0;
}
