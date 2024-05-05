#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedWord;
        usedWord.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty())
        {
            auto frontVector = q.front();
            q.pop();
            if (frontVector.back() == endWord)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(frontVector);
                }
                else if (ans.back().size() == frontVector.size())
                {
                    ans.push_back(frontVector);
                }
            }
            if (frontVector.size() > level)
            {
                level++;
                d
                    // erase prevLevel;
                    for (auto &it : usedWord) st.erase(it);
                usedWord.clear();
            }
            string currentWord = frontVector.back();
            for (int i = 0; i < currentWord.size(); i++)
            {
                int originalChar = currentWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currentWord[i] = ch;
                    if (st.find(currentWord) != st.end())
                    {
                        frontVector.push_back(currentWord);
                        // add to queue
                        q.push(frontVector);
                        usedWord.push_back(currentWord);
                        // remove last added word
                        frontVector.pop_back();
                    }
                }
                currentWord[i] = originalChar;
            }
        }
        return ans;
    }
};
int main()
{
    string beginWord, endWord;
    int n;
    cin >> beginWord;
    cin >> endWord;
    cin >> n;
    vector<string> dict(n, "");
    for (int i = 0; i < n; i++)
        cin >> dict[i];
    Solution *s1 = new Solution();
    auto ans = s1->findLadders(beginWord, endWord, dict);
    for (auto &vs : ans)
    {
        for (auto &str : vs)
        {
            cout << str << "  ";
        }
        cout << "\n";
    }
    return 0;
}
