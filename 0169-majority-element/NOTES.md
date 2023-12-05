Brute Force -> Sort and return n/2
Optimsed with ExtraSpace-> Hashmap approach
Best Soln ->
keep count and currMajorityElement
if(a[i]==currMajorityElement) count++;
else count--;
// if you have encountered a new majorityElement make the element as the currentMajorityElement and rewrite the count as 1 .
if(count ==0 ) currentMajority = a[i], count = 1 ;
​
​