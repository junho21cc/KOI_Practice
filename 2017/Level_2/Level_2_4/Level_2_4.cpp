// https://www.acmicpc.net/problem/14866

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int way[300000];

int biggest = 0;
int room_numbering = 0;

vector<int> ways[300000];

void dfs(int x)
{
    if (way[x])
        return;
    way[x] = true;
    cout << x << "\n";
    for (int k = 0; k < ways[x].size(); k++)
    {
        int y = ways[x][k];
        dfs(y);
    }
}

int main()
{
    int room_number;
    int way_number;

    cin >> room_number >> way_number;
    
    /*
    for (int i = 0; i < way_number; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;

        way[a1]++;
        way[a2]++;
    }

    for (int i = 1; i <= room_number; i++)
    {
        if (way[i] > biggest)
        {
            biggest = way[i];
            room_numbering = i;
        }
    }

    for (int i = 1; i <= room_number; i++)
    {
        if (way[i] == biggest)
        {
            biggest = 0;
            break;
        }
    }

    cout << biggest;
    */

    for (int k = 0; k < way_number; k++)
    {
        int a1, a2;
        cin >> a1 >> a2;

        ways[a1].push_back(a2);
        ways[a2].push_back(a1);
    }

    for (int k = 1; k <= room_number; k++)
    {
        dfs(k);
    }

    return 0;
}