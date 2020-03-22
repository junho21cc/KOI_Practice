#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100001];

void dfs(int i, int time_limit, int walk_time, int walk_money, int bike_time, int bike_money)
{
	for (int j = 0; j <= time_limit; j++)
	{
		// 조건문 안으로 들어오는 조건은 무엇일까?
		// >> i -1 번째 지나는 마을에서 j시간이 걸리는데 0원을 벌면 지나간다.
		if (dp[i - 1][j] == 0)
		{
			continue;
		}
		else // j 라는 같은 시간동안에 걸어가거나 자전거를 타고가면서 무엇이 더 많이 버는지를 판단한다.
		{
			if (j + walk_time <= time_limit)
			{
				// 걸어갈때			   dp[i][j + walk_time]은 무슨 뜻이지?
				//					>> i번째 지나는 마을에서 j + walk_time시간 걸리면서 벌리는 돈
				//					   dp[i - 1][j] + walk_money 는 무슨 뜻일까?
				//					>> i - 1번째 지나는 마을에서 j시간 걸리면서 벌리는 돈 + walk_money
				//					>> i 번째 마을에서 j시간 걸리면서 벌리는 돈
				dp[i][j + walk_time] = max(dp[i][j + walk_time], dp[i - 1][j] + walk_money);
			}
			if (j + bike_time <= time_limit)
			{
				dp[i][j + bike_time] = max(dp[i][j + bike_time], dp[i - 1][j] + bike_money);
			}
		}
	}
}

int main()
{
	int n, time_limit;
	int walk_time, walk_money, bike_time, bike_money;

	cin >> n >> time_limit;

	for (int i = 1; i <= n; i++)
	{
		cin >> walk_time >> walk_money >> bike_time >> bike_money;
		if (i == 1)
		{
			// 초기화 값의 의미
			dp[i][walk_time] = walk_money;
			dp[i][bike_time] = max(dp[i][bike_time], bike_money);
		}
		else
		{
			dfs(i, time_limit, walk_time, walk_money, bike_time, bike_money);
		}
	}

	int m = -1;

	for (int i = 1; i <= time_limit; i++)
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
4. 시간 time_limit가 주어짐!
5. time_limit에 맞춰 가장 효율적인 모금액을 모아야한다.
----------------------------------------
가장 효율적인 방법으로는 무엇이 있을까?
1. 무작정 다 더하고 비교한다

모든경우의수를 더하는것? -> 가장 효율적인 방법으로 진행
-> 시간대비 돈을 수로 만들어서?
*/