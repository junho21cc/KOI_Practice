#include <iostream>
#include <stdio.h>

using namespace std;

int position[1000000][2];

int main()
{
    int n;
    int x1, y1, x2, y2 = 0;

    int not_included_by_other_peak = 0;
    int included_other_peak = 0;

    cin >> n;
    
    int peak = 0;
    int start_end = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1;

        if (y1 * y2 < 0)
        {
            if (y1 > 0)
            {
                position[peak][0] = x1;
                start_end++;
            }
            else
            {
                position[peak][1] = x1;
                if (position[peak][0] > position[peak][1])
                {
                    int change = position[peak][0];
                    position[peak][0] = position[peak][1];
                    position[peak][1] = change;
                }
                start_end++;
            }

            if (start_end == 2)
            {
                peak++;
                start_end = 0;
            }
        }
        y2 = y1;

        if (i == n - 1)
        {
            if ((position[peak][0] != 0) && (position[peak][1] == 0))
            {
                position[0][0] = position[peak][1];
            }
        }
    }

    for (int i = 0; i <= peak; i++)
    {
        for (int k = 0; k <= peak; k++)
        {
            if (position[i][0] < position[k][0])
            {
                int change_x1;
                int change_x2;

                change_x1 = position[i][0];
                change_x2 = position[i][1];

                position[i][0] = position[k][0];
                position[i][1] = position[k][1];

                position[k][0] = change_x1;
                position[k][1] = change_x2;
            }
        }
    }

    int check_start_position = position[0][0];
    int check_end_position = position[0][1];

    /*
    봉우리의 개수를 세는 알고리즘

    1. 수직선상의 가장 왼쪽에있는 x 좌표를 기준점으로 잡고, 그 x 좌표를 csp(check_start_position) 이라고 두고
       그 봉우리의 다른 x좌표를 cep(check_end_position) 이라고 한다.

    2. 전제 봉우리의 개수에서 csp와 cep 사이의 봉우리 개수를 뺀 수가 "다른 봉우리에 의해 포함되지 않는 봉우리"의 개수라고 한다.

    3. csp와 cep의 사이에 봉우리의 개수 또한 위와같은 방법으로 센다.

    4. 한 봉우리 안의 다른 봉우리들의 수를 셌으니까 다음 봉우리로 넘어간다.
    */

    for (int k = 1; k < peak; k++)
    {
        if ((check_start_position < position[k][0]) && (check_end_position < position[k][1]))
        {
            included_other_peak++;
       }
    }

    cout << peak - included_other_peak << " " << included_other_peak;

    return 0;
}

/*
다른 봉우리에 의해 포함되지 않는 봉우리 개수와
다른 봉우리를 포함하지 않는 봉우리 개수
*/