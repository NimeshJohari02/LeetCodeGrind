class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
      map<pair<string,string>,int>validEmails;
      for(auto email : emails){
      
        string localName="";
        int i=0;
        while(email[i]!='@'){
          if(email[i]=='.'){
            i++;
           }
           else if(email[i]=='+'){
             while(email[i]!='@'){
               i++;
             }
           }
            else{
             localName+=email[i];
               i++;
            } 
        }
        // i=i+1;
        int remainingLength=email.length();
        cout<<"I = "<<i<<"Remainng Length= "<<remainingLength<<endl;
        string subDomain="";
          while(i<=remainingLength){
          subDomain+=email[i];
            i++;
        }
          cout<<"Name = "<<localName<<"subDomain = "<<subDomain<<endl;
          validEmails[{localName,subDomain}]++;
          localName="";
          subDomain="";
        }
    return validEmails.size();
    } 
};