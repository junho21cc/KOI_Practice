// https://www.acmicpc.net/problem/14866

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int biggest = 0;

int room_number;
int way_number;

int ways[300000];

vector<int> way[300000];

void backtracking(int x)
{

}

int main()
{
    cin >> room_number >> way_number;
   
    for (int k = 0; k < way_number; k++)
    {
        int a1, a2;
        cin >> a1 >> a2;

        way[a1].push_back(a2);
        way[a2].push_back (a1);
    }
    return 0;
}