class Solution {
public:
    string addBinary(string a, string b) {
      int i=a.length()-1;
      int j=b.length()-1;
      string ans;
      bool carry = false;
      while(i>=0 and j>=0){
        int s1 = a[i]-'0';
        int s2 = b[j]-'0';
        int s3 = s1+s2+(carry?1:0);
        carry=false;
        if(s3>=2){
            s3-=2;
            carry=true;
        }
        ans+=to_string(s3);
        i--;
        j--;
      }
      while(i>=0){
        int s1 = a[i]-'0';
        int s3 = s1+(carry?1:0);
        carry=false;
        if(s3>=2){
            s3-=2;
            carry=true;
        }
        ans+=to_string(s3);
        i--;
      }
      while(j>=0)
      {
        int s2 = b[j]-'0';
        int s3 = s2+(carry?1:0);
        carry=false;
        if(s3>=2){
            s3-=2;
            carry=true;
        }
        ans+=to_string(s3);
        j--;
      }    
      if(carry){
        ans+=to_string(1);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};