// https://www.acmicpc.net/problem/14696

using namespace std;

#include <stdio.h>
#include <iostream>

int main()
{
	int match_number;

	int a[1000][100];
	int a_number;

	int a_form_number[5];
	/*
	int a_star = 0;
	int a_circle = 0;
	int a_squar = 0;
	int a_triangle = 0;
	*/

	int b[1000][100];
	int b_number;

	int b_form_number[5];
	/*
	int b_star = 0;
	int b_circle = 0;
	int b_squar = 0;
	int b_triangle = 0;
	*/

	char judge = 'A';

	cin >> match_number;

	// 입력받기

	for (int i = 0; i < match_number; i++)
	{
		cin >> a_number;
		/*
		a_star = 0;
		a_circle = 0;
		a_squar = 0;
		a_triangle = 0;
		b_star = 0;
		b_circle = 0;
		b_squar = 0;
		b_triangle = 0;
		*/

		for (int k = 0; k < 5; k++)
		{
			a_form_number[k] = 0;
			b_form_number[k] = 0;
		}

		for (int k = 0; k < a_number; k++)
		{
			int aa;
			cin >> aa;

			a_form_number[aa - 1]++;

			/*
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
				break;
			case 1:
				a_triangle++;
				break;
				*/
			
		}

		cin >> b_number;
		
		for (int k = 0; k < b_number; k++)
		{
			int bb;
			cin >> bb;

			b_form_number[bb - 1]++;
			/*
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
				break;
			case 1:
				b_triangle++;
				break;
				*/
			
		}

		/*
		
		논리적인 일반화 !!
		a와 b의 모양을 인덱스처럼 만든다 ?
		a[5] = {star, circle, squar, triangle}
		b[5] = {star, circle, squar, triangle}

		*/

		for (int k = 3; k >= 0; k--)
		{
			if (a_form_number[k] < b_form_number[k])
			{
				judge = 'B';
				break;
			}
			else if(a_form_number[k] == b_form_number[k])
			{
				if (k == 0)
				{
					judge = 'D';
				}
			}
			else
			{
				judge = 'A';
				break;
			}
		}
		cout << judge << "\n";

		/*
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
	*/
		}
	return 0;
}
