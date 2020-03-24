#include <iostream>
#include <stdio.h>

using namespace std;

int position[1000000][2];

int main()
{
    int n;
    int x1, y1, x2, y2 = 0;

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int start_end = 0;
        cin >> x1 >> y1;

        if (y1 * y2 < 0)
        {
            if (x1 < 0)
            {
                position[start_end][0] = x1;
            }
            else
            {
                position[start_end][1] = x1;
                start_end++;
            }
        }
        y2 = y1;

        if (i == n - 1)
        {
            if (position[start_end][1] == 0)
            {
                position[0][0] = position[start_end][1];
            }
        }
    }


    return 0;
}

/*
다른 봉우리에 의해 포함되지 않는 봉우리 개수와
다른 봉우리를 포함하지 않는 봉우리 개수

*/