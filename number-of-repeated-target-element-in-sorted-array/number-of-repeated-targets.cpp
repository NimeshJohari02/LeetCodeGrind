#include <bits/stdc++.h>
using namespace std;
int lastOcc(vector<int> &arr, int n, int target)
{
    int s = 0, e = n - 1, ans = n;
    while (e >= s)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > target)
            e = mid - 1;
        else
        {
            // if (arr[mid] == target)
            // ans = min(ans, mid);
            s = mid + 1;
        }
    }

    return e;
}
int firstOcc(vector<int> &arr, int n, int target)
{
    int s = 0, e = n - 1, ans = n;
    while (e >= s)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < target)
            s = mid + 1;
        else
        {
            if (arr[mid] == target)
                ans = min(ans, mid);
            e = mid - 1;
        }
    }
    return s;
}
int countRepeatedTarget(vector<int> &arr, int n, int target)
{
    // Ans - lastOccurance - firstOccurance;
    int firstOccurance = firstOcc(arr, n, target);
    int lastOccurance = lastOcc(arr, n, target);
    cout << "FIRST = " << firstOccurance << "LAST ==>" << lastOccurance << endl;
    return lastOccurance - firstOccurance + 1;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> target;
    cout << countRepeatedTarget(arr, n, target);
    return 0;
}

/*
DRY RUN
First Occurance ;
idx = 0 1 2 3 4 5 6 7 8 9
arr = 1 2 3 4 4 4 4 5 6 7


S = 0 , E = 9 , TARGET = 4

IT 1
S = 0 , E = 9 , TARGET = 4, MID  = 4 .
if (arr[mid] < target {S = MID+1}) NO
else E = MID-1 ; YES
IT2
S = 0 , E = 3 , MID = 1
if (arr[mid] < target {S = MID+1}) YES
HENCE
S = 2 , E = 3 , MID = 2
if (arr[mid] < target {S = MID+1}) YES
HENCE
S = 3 E =3 MID =3
if (arr[mid] < target {S = MID+1}) NO
HENCE
S =3 , E = 2

SMALLER EXAMPLE
Target = 2
arr = 1 2 2 2 3
idx = 0 1 2 3 4
S=0 , E = 4 , MID =2
arr[mid]< target s = mid +1 NO
HENCE
S = 0 , E = 1 , MID = 0
1 < 2 (arr[0] < target) YES
S = 1 , E = 1 , MID = 1
arr[mid] < target NO
E = 0 , S = 1
ITERATION END
START HAS THE FIRST OCCURANCE


SIMLIARLY THE END WILL HAVE THE LAST OCCURANCE IN THAT CONDITION
if( arr[mid] > target) e = mid -1 ;
else s =  mid+ 1;

DRY RUN
1 2 2 4
0 1 2 3
TARGET =2 ;
S=0 E = 3 MID = 1
if(arr[mid]>target)e = mid-1 NO
S= 2 , E = 3 , MID = 2 ;
if(arr[mid]>target)e = mid-1 NO
S = 3 , E = 3 , MID = 3
if(arr[mid]>target)e = mid-1 YES
S = 3 , E = 2 ;
HENCE End has the answer

*/