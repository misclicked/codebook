//11100111 
//11100111
//11100111
//00000000
//00000000
//11100111
//11100111
//11100111
//可不可以壓縮
//x-壓縮 => A[i][j]=B[⌈i/x⌉][⌈j/x⌉]
//題解 行列連續1 or 0的gcd = ans
#include <bits/stdc++.h>
using namespace std;
const int N = 5200;
int n;
bool a[N][N];
void parse_char(int x, int y, char c) {
	int num = -1;
	if (isdigit(c)) {
		num = c - '0';
	} else {
		num = c - 'A' + 10;
	}
	for (int i = 0; i < 4; ++i) {
		a[x][y + 3 - i] = num & 1;
		num >>= 1;
	}
}
int main() {
	scanf("%d", &n);
	char buf[N];
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < n / 4; ++j) {
			parse_char(i, j * 4, buf[j]);
		}
	}
	int g = n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int k = j;
			while (k < n && a[i][k] == a[i][j]) ++k;
			g = __gcd(g, k - j);
			j = k - 1;
		}
	}
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			int k = i;
			while (k < n && a[k][j] == a[i][j]) ++k;
			g = __gcd(g, k - i);
			i = k - 1;
		}
	}
	cout << g << endl;
}