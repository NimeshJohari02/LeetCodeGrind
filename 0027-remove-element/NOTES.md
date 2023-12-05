[3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
​
​
​
3                   2                               2                        3
i=0                                                                           k=n-1
​
Intution : Keep one pointer at the start and the other at the end .
Corner case -> Move the end pointer to k-- until the last places have the value you have to remove
​
Once done --> Start moving i  . Swap nums[i++] and nums[k--]
and by the end you'll be left with the needed elements in the first i positions
Any other edge cases
​
​
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
​
nums.size()==0
handled
​
​
Failing Cases
​
[0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
​
replace number
​
​
​
​
​