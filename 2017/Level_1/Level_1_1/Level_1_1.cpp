// https://www.acmicpc.net/problem/14696

using namespace std;

#include <stdio.h>
#include <iostream>

int main()
{
	int match_number;

	int a[1000][100];
	int a_number;
	int a_star = 0;
	int a_circle = 0;
	int a_squar = 0;
	int a_triangle = 0;

	int b[1000][100];
	int b_number;
	int b_star = 0;
	int b_circle = 0;
	int b_squar = 0;
	int b_triangle = 0;
	
	cin >> match_number;

	// 입력받기

	for (int i = 0; i < match_number; i++)
	{
		cin >> a_number;

		a_star = 0;
		a_circle = 0;
		a_squar = 0;
		a_triangle = 0;
		b_star = 0;
		b_circle = 0;
		b_squar = 0;
		b_triangle = 0;

		for (int k = 0; k < a_number; k++)
		{
			int aa;
			cin >> aa;
			a[k][i] = aa;

			switch (aa) 
			{
			case 4:
				a_star++;
				break;
			case 3:
				a_circle++;
				break;
			case 2:
				a_squar++;
			case 1:
				a_triangle++;
			}
		}

		cin >> b_number;
		
		for (int k = 0; k < b_number; k++)
		{
			int bb;
			cin >> bb;
			b[k][i] = bb;

			switch (bb)
			{
			case 4:
				b_star++;
				break;
			case 3:
				b_circle++;
				break;
			case 2:
				b_squar++;
			case 1:
				b_triangle++;
			}
		}

		if (a_star == b_star)
		{
			if (a_circle == b_circle)
			{
				if (a_squar == b_squar)
				{
					if (a_triangle == b_triangle)
					{
						cout << "D" << "\n";
					}
					else if (a_triangle > b_triangle)
					{
						cout << "A" << "\n";
					}
					else
					{
						cout << "B" << "\n";
					}
				}
				else if (a_squar > b_squar)
				{
					cout << "A" << "\n";
				}
				else
				{
					cout << "B" << "\n";
				}
			}
			else if (a_circle > b_circle)
			{
				cout << "A" << "\n";
			}
			else
			{
				cout << "B" << "\n";
			}
		}
		else if (a_star > b_star)
		{
			cout << "A" << "\n";
		}
		else
		{
			cout << "B" << "\n";
		}
	}
	return 0;
}

/* 
1. 우선순위 : 별, 동그라미, 네모, 세모
2. 모양별 숫자 : 4, 3, 2, 1

1. 경기하는 수 "N" 이 입력받는다.
2. 경기마다 A와 B는 한번씩 딱지를 낸다.
3. 2N 번의 줄이 입력받는다.
4. 각각의 경기마다 A와 B중 누가 이겼는지 출력한다.
*/
/*
표준 입력으로 다음 정보가 주어진다. 
첫 번째 줄에는 딱지놀이의 총 라운드 수를 나타내는 자연수 N이 주어진다. N 은 1 이상 1,000 이하이다. 
다음 줄에는 라운드 1에서 어린이 A가 내는 딱지에 나온 그림의 총 개수 a가 주어진다. a는 1 이상 100 이하이다. 뒤따라 나오는 a개의 정수는 어린이 A가 낸 딱지의 그림을 나타내는데, 각각 4, 3, 2, 1 중 하나의 값이다. 4, 3, 2, 1의 순서대로 주어지지 않을 수 있음에 주의하라. 
다음 줄에는 라운드 1에서 어린이 B가 내는 딱지에 나온 그림의 총 개수 b가 주어진다. b도 1 이상 100 이하이다. 뒤따라 나오는 b개의 정수는 어린이 B가 낸 딱지의 그림을 나타내는데, 역시 4, 3, 2, 1 중 하나의 값이다. 역시 4, 3, 2, 1의 순서대로 주어지지 않을 수 있음에 주의하라. 
다음 두 줄에는 라운드 2에서 어린이 A, B가 낸 딱지의 그림들을 같은 식으로 표현한다. 위와 같은 식으로 매 라운드마다 두 어린이가 낸 딱지의 정보는 두 줄에 표현되며, N 라운드의 딱지 정보는 차례대로 총 2N 개의 줄에 주어진다.
*/