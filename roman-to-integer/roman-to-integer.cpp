class Solution {
public:
    int romanToInt(string s) {
        map<char, int>mp;
    mp.insert( { 'I',1 } );
    mp.insert( { 'V',5 } );
    mp.insert( { 'X',10 } );
    mp.insert( { 'L',50 } );
    mp.insert( { 'C',100 } );
    mp.insert( { 'D',500 } );
    mp.insert( { 'M',1000 } );
    int sum = 0, i;
    for (i = s.length() - 1; i >= 1; i--) {
        int currentNumber = mp[s[i]];
        int leftNumber = mp[s[i - 1]];
        // cout << "Left Number " << leftNumber << endl;
        // cout << "right Number " << currentNumber << endl;
        if (leftNumber >= currentNumber) {
            sum += currentNumber;
            }
        else {
            sum += (currentNumber - leftNumber);
            i -= 1;
            }
        // cout << "Sum Number " << sum << endl;
        }
    // cout << "I =" << i << endl;
    if (i == -1) {
        return sum;
        }
    sum += mp[s[0]];
    return sum;
    }
};