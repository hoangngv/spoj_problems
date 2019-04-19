#include <bits/stdc++.h>

using namespace std;

void longest_road (int *road, int road_length, int budget)
{

    int temp[road_length] ;
    int sInd=0 , eInd=-1, used_budget=0, max=INT_MIN;
    if(budget == 0)
    {
        int count = 0;
        for(int i=0 ; i < road_length ; i++)
        {
            if(road[i] == 1)
                count++;
            else
            {
                if(count > max)
                    max = count;
                count = 0;
            }
        }
        if(count > max)
            max = count;
        cout << max << endl;
        return;
    }

    for(int i=0 ; i < road_length ; i++)
    {
        if(road[i] == 1)
            eInd++;
        else if(road[i] == 0 )
        {
            used_budget++;
            if(used_budget > budget)
            {
                eInd++;
                if(eInd - sInd > max)
                    max = eInd-sInd;
                while(road[sInd] != 0 )
                {
                    sInd++;
                }
                if(eInd - sInd > max)
                    max = eInd-sInd;
                sInd++;
                j–;
            }
            else{
                eInd++;
                if(used_budget == budget)
                {
                    if((eInd – sInd +1) > max)
                    max= eInd-sInd+1;
                }
            }
        }
    }
    if((eInd–sInd+1) > max)
    max = eInd-sInd+1;
    cout << max << endl;
}

int main()
{
    int road_length, budget;
    cin >> road_length >> budget;
    int road[road_length];
    for(int i =0 ; i <road_length ; i++)
        cin >> road[i];
    longest_road (road, road_length, budget);

    return 0;
}