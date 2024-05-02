#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool canEat(vector<int> &piles, int givenSpeed, long long int hours)
    {
        // bananas eat per hour is givenSpeed .
        int hrs = 0;
        for (int it : piles)
        {
            // IF YOU HAVE 7 banana in one pile and you can eat at speed of 2
            // THEN YOU WILL TAKE 3 + 1 = 4 hours as the one banana can not be clubbed into the next one .
            hrs += it / givenSpeed + (it % givenSpeed != 0);
        }
        // GIVEN HOURS IS GREATER OR EQUAL RETURNS TRUE THIS MEANS IF KOKO CAN FINISH BANANAS at a "givenSpeed" this function would return true if it can finish before or less than given time limit . if not then we have the increase the speed of banana eating
        return hrs <= hours;
    }

public:
    //  SO BASICALLY THE QUESTION IS THE KOKO CAN EAT at MAX SPEED OF INF ONLY BUT THAT WILL make it finish early
    // Hence we have to find the minimum Eating Speed which is needed to finish all the piles of banana in h hrs .

    int minEatingSpeed(vector<int> &piles, int h)
    {
        // eat all bananas in h hours
        int n = piles.size();
        int minSpeed = 1;
        int maxSpeed = INT_MAX;
        // AGAIN IN THIS EXAMPLE OBSERVE THAT WE WILL BE SHIFTING TOWARDS THE LEFT
        // Like if they can finish in mid time they can definitely finish in mid+1 time at a given speed .
        while (maxSpeed >= minSpeed)
        {
            int givenSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            if (canEat(piles, givenSpeed, h))
            {
                // IF CAN EAT  AT GIVEN SPEED WE TRY THE LESSER SPEED to minimize the speed .
                maxSpeed = givenSpeed - 1;
            }
            else
            {
                // IF NOT ABLE TO EAT WE INCREASE THE MINSPEED TO RIGHT TO FIND MINIMUM SPEED.
                minSpeed = givenSpeed + 1;
            }
        }

        return maxSpeed;
    }
};

int main()
{
    int n, h;
    // h is the number of hours that the monkey has before the guard is back on the shift .
    cin >> n;
    vector<int> piles(n, 0);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    cin >> h;
    Solution *s1 = new Solution();
    cout << "MIN SPEED ==>" << s1->minEatingSpeed(piles, h);
    return 0;
}

/*
DRY RUN
piles : [3 , 6 , 7 ,11] h = 8
minSpeed = 1 , maxSpeed= 100 , midSpeed = 50 .
if(PROCESSFUNC== true) maxSpeed = min -1  YES
minSpeed = 1 , maxSpeed = 49 , midSpeed = 25 ;
if(PROCESSFUNC== true) maxSpeed = min -1  YES
minSpeed = 1 , maxSpeed = 24 , midSpeed = 12
if(PROCESSFUNC== true) maxSpeed = min -1  YES
minSpeed =1 , maxSpeed = 11 , midSpeed = 6 . YES HERE hrs = 6 ;
if(PROCESSFUNC== true) maxSpeed = min -1  YES
minSpeed = 1 , maxSpeed = 5 , midSpeed = 3
FALSE. CANT MANAGE
minSpeed = 4 , maxSpeed = 5 , midSpeed = 4
if(PROCESSFUNC== true) maxSpeed = min -1  YES
YES
minSpeed = 4, maxSpeed = 3
STOP HERER .
minSpeed has the ans .
*/
