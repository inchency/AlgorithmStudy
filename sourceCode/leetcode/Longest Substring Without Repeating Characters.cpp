class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int answer = 0;
        for(int i=0; i<len; i++){
            set<char>char_set;
            char_set.insert(s[i]);
            int temp_answer = 1;
            for(int j=i+1; j<len; j++){
                if(char_set.find(s[j]) == char_set.end()){
                    char_set.insert(s[j]);
                    temp_answer++;
                }
                else break;
            }
            answer = max(answer, temp_answer);
        }
        return answer;
    }
};
