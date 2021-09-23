class Solution {
public:
    int Seive(int n)
    {
        vector<bool>arr(n+1);
        for(int i=0;i<=n;i++){
            arr[i]=true;
        }
     arr[0] = arr[1] = false;
    for (int i = 2; i <= sqrt(n); i++){
        if(arr[i])
        {
            for (int j = i * i; j < n;j=j+i){
                arr[j] = false;
            }
        }
    }
        int count =0;
        for(int i=0;i<n;i++){
            if(arr[i]){
                count++;
            }
        }
        return count;
 }
    int countPrimes(int n) 
    {
        return Seive(n);
    }
};