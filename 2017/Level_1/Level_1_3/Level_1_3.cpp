﻿#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n, k;

	// 걸어서, 자전거
	int time[100][2];	
	
	// 걸어서, 자전거
	int money[100][2];
	   
	for (int i = 0; i < n; i++)
	{
		cin >> time[i][0] >> money[i][0]
			>> time[i][1] >> money[i][1];
	}

	return 0;
}

/*
1. 서울에서 경산까지 거치는 도시의 개수는 n개 이다.
2. 구간 사이에는 도보/자전거 로 이동할수 있는 방법이 2개있다.
3. 구간마다 주어지는 시간과 모금액이 정해져있다.
4. 시간 k가 주어짐!
5. k에 맞춰 가장 효율적인 모금액을 모아야한다.
----------------------------------------
가장 효율적인 방법으로는 무엇이 있을까?
1. 무작정 다 더하고 비교한다
-> 
*/