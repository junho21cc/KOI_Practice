// https://www.acmicpc.net/problem/14866

#include <iostream>
#include <stdio.h>

using namespace std;


int room[300000];
int way[300000];

int sum = 0;

int main()
{
    int room_number;
    int way_number;

    cin >> room_number >> way_number;
  
    for (int i = 0; i < way_number; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;

        way[a1]++;
        way[a2]++;


    return 0;
}