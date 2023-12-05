Here are the 3 solutions for the problem
rotate(k)
1. Brute force --> Create a new array of elements where each element would be at (i+k)%nums.size()
2. Recursive way is to rotate one to the right and call it K times --> not effective
3. push the first n-k elements to the back of the numsArray and then remove/resize the array