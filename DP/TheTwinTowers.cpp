// input
// 牆磚: 1 ≤ N1, N2 ≤ 100
// N1 個牆磚半徑
// N2 個牆磚半徑

// 題解
// 在一個古帝國, 有兩座形狀不一樣的塔, 它們是由不同半徑的圓形牆磚疊合而成。
// 數千年後, 皇帝要求工匠移除某些牆磚, 使得兩座塔變得一樣, 當然牆磚的順序必須和原本的塔一樣
// 請問若要使塔的高度最高, 它有幾塊牆磚?

// 作法
// 要使塔最高, 就代表相同的牆磚要愈多愈好, 而且順序不能變
// 那就是 LCS 解了！
// 輸出記得空一行


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))

int N1[105],N2[105];
int F[105][105];

int main()
{
	int n1,n2,Case = 1;
	while ( scanf("%d%d",&n1,&n2) && n1+n2 ) {
		for ( int i = 1 ; i <= n1 ; ++ i )
			scanf("%d",&N1[i]);
		for ( int i = 1 ; i <= n2 ; ++ i )
			scanf("%d",&N2[i]);

		memset( F, 0, sizeof(F) );
		for ( int i = 1 ; i <= n1 ; ++ i )
		for ( int j = 1 ; j <= n2 ; ++ j )
			if ( N1[i] == N2[j] )
				F[i][j] = F[i-1][j-1]+1;
			else F[i][j] = max( F[i-1][j], F[i][j-1] );

		printf("Twin Towers #%d\n",Case ++);
		printf("Number of Tiles : %d\n\n",F[n1][n2]);
	}
	return 0;
}