class Solution {
public:
    string minWindow(string mainString, string pattern) {
      if(pattern.length()>mainString.length()){
        return "";
    }
    int msl = mainString.length();
    int pl = pattern.length();
    map<char, int> patternMap;
    for(auto it : pattern){
        patternMap[it]++;
    }
    map<char, int> mainStringMap;
    int i = 0;
    int j = 0;
    int minimmumWindowSize = INT_MAX;
    int startIdx = -1;
    int count = 0;
    for (int j = 0; j < msl;j++)
    {
        char curr = mainString[j];
        mainStringMap[curr]++;
        if(patternMap[curr]!=0 and mainStringMap[curr]<=patternMap[curr]){
            count++;
        }
        if(count == pl){
            char toDelete = mainString[i];
            while (mainStringMap[toDelete]==0 or mainStringMap[toDelete]>patternMap[toDelete]){
                mainStringMap[toDelete]--;
                i++;
                toDelete = mainString[i];
            }
            int currentWindowSize = j - i + 1;
            if(currentWindowSize<minimmumWindowSize){
                minimmumWindowSize = currentWindowSize;
                startIdx = i;
            }
        }
    }
    if(startIdx==-1){
        return "";
    }
    return mainString.substr(startIdx, minimmumWindowSize);      
    }
};