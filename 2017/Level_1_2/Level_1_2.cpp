//https://www.acmicpc.net/problem/14697
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int bed_type_A;
    int bed_type_B;
    int bed_type_C;

    int total_number_of_people;

    int is_break = 0;

    // 입력받기
    cin >> bed_type_A >> bed_type_B >> bed_type_C;
    cin >> total_number_of_people;

    for (int i = 0; i <= total_number_of_people / bed_type_A; i++)
    {
        for (int k = 0; k <= total_number_of_people / bed_type_B; k++)
        {
            for (int l = 0; l <= total_number_of_people / bed_type_C; l++)
            {
                if (bed_type_A * i + bed_type_B * k + bed_type_C * l == total_number_of_people)
                {
                    cout << "1" << "\n";
                    is_break = 1;
                    break;
                }
            }
            if (is_break == 1)
            {
                break;
            }
        }
        if (is_break == 1)
        {
            break;
        }
    }
    if (is_break != 1)
    {
        cout << "0" << "\n";
    }

    /*
    모두가 침대를 사용해야함.
    (가능/불가능)구분을 어떻게 해야 할까?

    ex.1) 5 9 12 113
    1. 큰숫자를 먼저 사용한다.
        12*9 + 9*0 + 5*1 = 113
    ----------------------------
    113 / 12 = 9 > 1
    113 - 12 * 9 = 5
    5 / 9  = 0.5... < 1
      5 / 5 = 1

    ex.2) 3 6 9 112
    112 / 9 = 12
    112 - 12 * 9 = 4
    4 / 6 = 0.6... <1
       4 / 3 = 1.3... > 1

    ex.3) 2 7 9 217
    217 / 9 = 24
    217 - 9 * 24 = 1
    217 - 9 * 23 = 10
    10 - 2*5 = 0

    */

    return 0;
}

/*
1. 방안에는 침대수를 기준으로 3가지 종류의 방이 있다.
2. 방안의 침대를 모두 사용해 배정해야한다.

    3가지 종류의 방을 입력받음
    총인원수 입력받음
    가능/불가능 표시
*/