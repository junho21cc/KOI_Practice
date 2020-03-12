#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int number_of_student;
	int pair_number;
	int students_card_number[100000];

	int X, Y;
	
	int is_truth[100000];
	int is_break = 0;
	
	//입력하기
	cin >> number_of_student >> pair_number;

	for (int i = 1; i <= number_of_student; i++)
	{
		students_card_number[i] = i;
		is_truth[i] = 0;
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
		is_truth[students_card_number[i]]++;
	}

	for (int i = 1; i <= number_of_student; i++)
	{
		if (is_truth[i] == 2)
		{
			cout << "-1";
			is_break = 1;
			break;
		}
	}

	if (is_break == 0)
	{
		for (int i = 1; i <= number_of_student; i++)
		{
			cout << students_card_number[i] << " ";
		}
	}
	
	return 0;
}