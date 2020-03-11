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
                if (total_number_of_people == bed_type_A * i + bed_type_B * k + bed_type_C * l)
                {
                    // total_number_of_people = bed_type_A * i + bed_type_B * k + bed_type_C * 정수
                  
                    // (total_number_of_people - (bed_type_A * i + bed_type_B * k)) % bed_type_C == 0

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
    
    return 0;
}