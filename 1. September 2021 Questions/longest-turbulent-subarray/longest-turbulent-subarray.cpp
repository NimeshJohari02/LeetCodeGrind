class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int s=1;
        vector<int>countArr;
        int i=0;
        int j=1;
        int count =1;
        while(j<arr.size()){
            if(arr[i] > arr[j] && i%2!=0){
                count++;
                countArr.push_back(count);
            }
            else if(arr[i] < arr[j] && i%2==0){
           count++;
                countArr.push_back(count);     
            }
            else{
                count =1;
            }
            i++;
            j++;
        }
        count =1;
        i=0;
        j=1;
               while(j<arr.size()){
            if(arr[i] > arr[j] && i%2==0){
                count++;
                countArr.push_back(count);
            }
            else if(arr[i] < arr[j] && i%2!=0){
           count++;
                countArr.push_back(count);     
            }
            else{
                count =1;
            }
            i++;
            j++;
        }
        int maximum=1;
        for(auto it : countArr){
            maximum = max(it,maximum);
        }
        return maximum;
    }
};