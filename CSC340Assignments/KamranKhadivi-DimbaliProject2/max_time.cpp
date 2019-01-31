//
//  max_time.cpp
//  Assign2CSC340
//  #1
//  Created by Kamran Khadivi-Dimbali July 2017


#include <iostream>
#include <stdio.h>
# include <string>
using namespace std;

string maxTime(int A, int B, int C, int D)
{
    int arr[4];
    bool validNum[4] = { true, true,true,true };
    int hour = 0;
    int mins = 0;
    bool result = false;
    arr[0] = A;
    arr[1] = B;
    arr[2] = C;
    arr[3] = D;
    
    for (int deep = 23; deep > 0; deep--)
    {
        for (int deeper = 0; deeper < 4; deeper++)
        {
            if (deep / 10 == arr[deeper] && validNum[deeper])
            {
                validNum[deeper] = false;
                for (int deepest = 0; deepest < 4; deepest++)
                {
                    if (deep % 10 == arr[deepest] && validNum[deepest])
                    {
                        validNum[deepest] = false;
                        hour = arr[deeper] * 10 + arr[deepest];
                        result = true;
                        break;
                    }
                }
                if (result != true)
                {
                    validNum[deeper] = true;
                }
                else
                {
                    break;
                }
            }
        }
        if (result == true)
        {
            result = false;
            break;
        }
    }
    
    for (int x = 60; x > 0; x--)
    {
        for (int y = 0; y < 4; y++)
        {
            if (x / 10 == arr[y] && validNum[y])
            {
                validNum[y] = false;
                for (int z = 0; z < 4; z++)
                {
                    if (x % 10 == arr[z] && validNum[z])
                    {
                        validNum[z] = false;
                        mins = arr[y] * 10 + arr[z];
                        result = true;
                        break;
                    }
                }
                if (result != true)
                {
                    validNum[y] = true;
                }
                else
                {
                    break;
                }
            }
        }
        if (result == true)
        {
            result = false;
            break;
        }
    }
    
    string c = to_string(hour);
    string d = to_string(mins);
    string possible = c + ":" + d;
    
    if ((validNum[0] || validNum[1] || validNum[2] || validNum[3]) != false)
    {
        return  "NOT POSSIBLE\n";
    }
    else
    {
        return possible;
    }
    
}

int main(){

    int A,B,C,D;
    cout << "Enter 4 numbers like in the following format: # # # # ===> ";
    cin >> A >> B >> C >> D;
    cout << maxTime(A,B,C,D);
    
    
    return 0;

}

