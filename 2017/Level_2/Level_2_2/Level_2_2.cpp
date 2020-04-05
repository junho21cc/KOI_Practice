#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int position[1000000][2];
int my_compare(const void *a, const void *b)
{
    return *(int*)a < *(int*)b;
}

int main()
{
    int n;
    int x1, y1, x2, y2 = 0;

    int Answer_1 = 0;
    int Answer_2 = 0;

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
                
                sort(position[peak][0], position[peak][1]);
                
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

    qsort(position, peak, sizeof(position[0]), my_compare);


    for (int k = 0; k < peak; k++)
    { 
        int a1 = 0, a2 = 0;

        if (peak == 1)
        {
            Answer_1++;
            Answer_2++;
            break;
        }
        
        for (int j = 0; j < peak; j++)
        {
            if (k == j)
            {
                continue;
            }

            if ((position[k][0] >= position[j][0]) && (position[k][1] <= position[j][1]))
            {
                a1++;
            }
            else if((position[k][0] <= position[j][0]) && (position[k][1] >= position[j][1]))
            {
                a2++;
            }

            if (a2 >= 1)
            {
                Answer_1++;
                break;
            }
            if (a1 >= 1)
            {
                Answer_2++;
                break;
            }
        }
    }

    cout << Answer_1 << " " << Answer_2;
    
    return 0;
}

/*
다른 봉우리에 의해 포함되지 않는 봉우리 개수와
다른 봉우리를 포함하지 않는 봉우리 개수
*/