#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100001];

void dfs(int i, int k, int a, int b, int c, int d)
{
	for (int j = 0; j <= k; j++)
	{
		if (dp[i - 1][j] == 0)
		{
			continue;
		}
		else
		{
			if (j + a <= k)
			{
				dp[i][j + a] = max(dp[i][j + a], dp[i - 1][j] + b);
			}
			if (j + c <= k)
			{
				dp[i][j + c] = max(dp[i][j + c], dp[i - 1][j] + d);
			}
		}
	}
}

int main()
{
	int n, k;
	int a, b, c, d;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c >> d;
		if (i == 1)
		{
			dp[i][a] = b;
			dp[i][c] = max(dp[i][c], d);
		}
		else
		{
			dfs(i, k, a, b, c, d);
		}
	}

	int m = -1;

	for (int i = 1; i <= k; i++)
	{
		m = max(m, dp[n][i]);
	}

	cout << m;

	return 0;
}


// 모든 경우의수 : 2^n개

/*
1. 서울에서 경산까지 거치는 도시의 개수는 n개 이다.
2. 구간 사이에는 도보/자전거 로 이동할수 있는 방법이 2개있다.
3. 구간마다 주어지는 시간과 모금액이 정해져있다.
4. 시간 k가 주어짐!
5. k에 맞춰 가장 효율적인 모금액을 모아야한다.
----------------------------------------
가장 효율적인 방법으로는 무엇이 있을까?
1. 무작정 다 더하고 비교한다

모든경우의수를 더하는것? -> 가장 효율적인 방법으로 진행
-> 시간대비 돈을 수로 만들어서?
*/