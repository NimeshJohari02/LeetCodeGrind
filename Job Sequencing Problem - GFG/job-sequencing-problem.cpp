// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

// class Solution 
// {
//     public:
//     static bool cmp(Job &j1 , Job &j2){
//         return j1.profit >= j2.profit;
//     }
//     //Function to find the maximum profit and the number of jobs done.
//     vector<int> JobScheduling(Job arr[], int n) 
//     { 
//         // your code here
//         sort(arr , arr+ n , cmp);
//         int maxi = INT_MIN;
//         for(int i=0 ; i < n ; i++)
//         maxi = max(maxi , arr[i].dead);
//         int seq[maxi+1];
//         memset(seq , -1 , sizeof seq);
//         int numJobs =0 , maxProfit = 0;
//         for(int i=0 ; i < n; i++){
//               Job currJob = arr[i];
//                 int idxToPlace = currJob.id;
//                 int dead = currJob.dead;
//                 int pro = currJob.profit ;
//             for(int j=dead ; j>0 ; j--){
              
//                 if(seq[j] == -1){
//                     seq[j] = i ;
//                     numJobs++ ;
//                     maxProfit+= pro;
//                     break;
//                 }
//             }
//         }
//         return {numJobs , maxProfit};
//     } 
// };


class Solution 
{
   public:
   //Function to find the maximum profit and the number of jobs done.
   static bool comparator(Job a, Job b){
       return a.dead<b.dead;
   }
   vector<int> JobScheduling(Job arr[], int n) 
   { 
       
       priority_queue<int,vector<int>,greater<int>> pq;
       sort(arr,arr+n,comparator);
       int day=1,pro=arr[0].profit,si=1;
       pq.push(arr[0].profit);
       for(int i=1;i<n;i++){
           if(day<arr[i].dead){
               while(day<arr[i].dead){
                   pq.push(-1);
                   day++;
               }
           }
           if(day==arr[i].dead){
               pro+=(arr[i].profit);
               pq.push(arr[i].profit);
               si++;
               if(pq.top()!=-1){
                   pro-=(pq.top());
                   si--;
               }
               pq.pop();
           }
       }
       vector<int> ans;
       ans.push_back(si);
       ans.push_back(pro);
       return ans;
   } 
};


// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends