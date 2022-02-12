class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ss;
        bool isPresent = false;
        
        for(auto &word : wordList){
            if(endWord.compare(word) == 0)
                isPresent = true;
            ss.insert(word);
        }
        
        if(!isPresent)return 0;
        
        
        queue<string>q;
        
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            depth++;
            int lsize = q.size();
            while(lsize--){
                 string curr = q.front();
                q.pop();
                // check for all possible 1 depth words 
                for(int i = 0;  i < curr.length();++i){
                    string temp = curr;
                    
                    for(char c = 'a'; c <= 'z';++c){
                        temp[i] = c;
                        if(curr.compare(temp) == 0)continue;//skip the same word
                        if(temp.compare(endWord) == 0)
                            return depth+1;// endword found
                        
                        auto it = ss.find(temp);
                        if(it != ss.end()){
                            q.push(temp);
                            ss.erase(it);
                        }
                    }
                }
            }
        }
        return 0;
    }
};