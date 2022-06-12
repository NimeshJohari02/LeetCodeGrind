class Solution {
public:
     inline void add(int &a , int &b , int &c , char ch){
        if(ch=='a') a++;
        if(ch=='b') b++;
        if(ch=='c') c++;
        return ;
    }
    
     inline void remove(int &a , int &b , int &c , char ch){
        if(ch=='a') a--;
        if(ch=='b') b--;
        if(ch=='c') c--;
        return ;
    }
    
    int numberOfSubstrings(string s) {
        int i=0 , j =0 , a = 0 , b = 0 , c=0 , res=0;
        for(int j =0 ; j < s.size() ; j++){
            add(a , b , c , s[j] );
            while(a > 0 && b >0 && c >0 ){
                remove(a , b , c , s[i]);
                i++;
            }
            res+=i;
        }
        return res;
    }
};