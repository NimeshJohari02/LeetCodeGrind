[1 , 2 , 3 , 0, 0,  0]
m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
// Sorted in non decreasing thus
max may start from  nums1[m-1] or nums2[n-1]
​
i = k-1
1              2              3              0                 0                      0
k = nums1[m+n-1]
2                    5                              6
j=n-1;
​
WE DONT have clarity on the first element but we can do it from the last .