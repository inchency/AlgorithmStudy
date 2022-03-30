// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void combination(vector<vector<int>>&ret_v, vector<int>temp_v, int n, int pick_n, int cur_cnt, int cur_num){
       if(cur_cnt == pick_n){
           ret_v.push_back(temp_v);
           return;
       }
       if(cur_num > n) return;
       // select
       temp_v.push_back(cur_num);
       combination(ret_v, temp_v, n, pick_n, cur_cnt+1, cur_num+1);
       // don't select
       temp_v.pop_back();
       combination(ret_v, temp_v, n, pick_n, cur_cnt, cur_num+1);
}

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(vector<string> topic) {
    int n = topic.size();
    int m = topic[0].size();
    vector<int>answer;
    vector<vector<int>>comb_v;
    vector<int>temp_v;
    combination(comb_v, temp_v, n, 2, 0, 1);
    map<int, int>map_m; // known topics cnt, cnt
    for(vector<int>v : comb_v){
        int first_ind = v[0];
        int second_ind = v[1];
        string s1 = topic[first_ind-1];
        string s2 = topic[second_ind-1];
        int cnt = 0;
        for(int i=0; i<m; i++){
            if(s1[i] == '1' || s2[i] == '1') cnt++;
        }
        if(map_m.find(cnt) == map_m.end()) map_m[cnt] = 1;
        else map_m[cnt] += 1;
    }
    int maximum_num = 0;
    for(pair<int, int>p : map_m){
        maximum_num = max(maximum_num, p.first);
    }
    answer.push_back(maximum_num);
    answer.push_back(map_m[maximum_num]);
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
