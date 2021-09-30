/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#define ll long long int
class Solution {
public:
    ll guessNumber(ll n) {
      ll left =1;
      ll right = n ;   
      while(right>=left){
        ll mid = (left + right )/2;
      ll returnedChoice = guess(mid);       
        if(returnedChoice ==0){
          return mid;
        }
        else if(returnedChoice == 1){
          left = mid+1;
          returnedChoice=guess(mid);
        }
        else{
          right = mid-1;
          returnedChoice = guess(mid);
        }
      }
      return 0;
    }
};