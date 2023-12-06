Recursion and DP is not needed. Why ?
​
See
​
at everyStep you can reach a max of i + nums[i];
We have ki humesha we will reach n-1  .
​
intially say you start at 0 and end at 0 .
now everytime start == end ==> that we need to take another jump to reach the target .
and everytime the end would move to the maxReach calculated so far signaling
"KI ek jump mai max tumhara end yaha aa sakta hai ."