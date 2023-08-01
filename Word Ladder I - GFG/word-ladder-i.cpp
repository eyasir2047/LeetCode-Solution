//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& list) {
        // Code here
        //bfs
        //startWord=s, endWord=t
        
        queue<pair<string,int>>q;
        //string-> word and steps/result->int
        q.push({s,1});
        
        unordered_set<string>st(list.begin(),list.end());
        st.erase(s);
        
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(word==t){
                return steps;
            }
            
            for(int i=0;i<word.size();i++){
                char c=word[i];
                
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    
                    if(st.find(word)!=st.end()){//find the word into the st
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=c;
            }
        }
        
        return 0;//not possible
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends