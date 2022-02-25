class Solution {
public:
    vector<long long int>tokeinizingFunction(string line){
         // Vector of string to save tokens
    vector <long long int> tokens;
     
    // stringstream class check1
    stringstream check1(line);
     
    string intermediate;
     
    // Tokenizing w.r.t. space '.'
    while(getline(check1, intermediate, '.'))
    {
        tokens.push_back(stoi(intermediate));
    }
     return tokens;
    }
    // int compareVersion(string s1, string s2) {
    //      vector<long long int>v1 = tokeinizingFunction(s1);
    //      vector<long long int>v2 = tokeinizingFunction(s2);
    //     int i=0;
    //     int j=0;
    //     for(auto &it : v1){
    //         cout<<it<<"   ";
    //     }
    //     for(int i=0 ; i < max(v1.size() , v2.size()) ; i++){
    //         if(((i>=v1.size()) ? 0 : v1[i])>(i>=v2.size() ? 0 :v2[i]))return 1;
    //         else if(((i>=v1.size()) ? 0 : v1[i])<(i>=v2.size() ? 0 :v2[i]))return -1;
    //     }
    // return 0;
    // }
int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();
    
    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }
        
        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }
        
        if(num1>num2) return 1;
        else if(num1 < num2) return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}
};