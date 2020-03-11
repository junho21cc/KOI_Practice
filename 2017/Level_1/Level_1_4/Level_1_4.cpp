#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int number_of_student;
	int pair_number;
	int students_card_number[100000];
	int back_up_card_number[100000];

	int X, Y;
	
	int is_truth = 1;
	
	//입력하기
	cin >> number_of_student >> pair_number;

	for (int i = 1; i <= number_of_student; i++)
	{
		students_card_number[i] = i;
	}

	for (int i = 0; i < pair_number; i++)
	{
		cin >> X >> Y;
		// 학생Y가 학생X보다 뒤에있다.
		students_card_number[X]++;
		students_card_number[Y]--;
	}

	for (int i = 1; i <= number_of_student; i++)
	{
		back_up_card_number[i] = students_card_number[i];

		for (int k = 1; k <= number_of_student; k++)
		{			
			if (i == students_card_number[k])
			{
				students_card_number[k] = 0;
				break;
			}
		}
	}

	for (int i = 1; i <= number_of_student; i++)
	{
		if (students_card_number[i] != 0)
		{
			cout << "-1" << "\n";
			is_truth = 0;
			break;
		}
	}
	if (is_truth == 1)
	{
		for (int i = 1; i <= number_of_student; i++)
		{
			cout << back_up_card_number[i] << " ";
		}
	}

	return 0;
}

/*
 방법.NO.1
0	1	2	3	4	5--Y
1	0					 	1;2
2	1	0					2;0
3	3	3	0				3;4
4	4	4	3	0			4;3
5	1	5	3	4	0		5;1
l							3 1 5 4 2

*/