// https://www.hackerrank.com/challenges/bigger-is-greater/problem?isFullScreen=true
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    string answer = "";
    string copy_w = w;
    int cnt = 0;
    do{
        string temp_s = "";
        cnt++;
        for(char c : copy_w){
            temp_s += c;
        }
        answer = temp_s;
        if(cnt == 2) break;
    }while(next_permutation(copy_w.begin(), copy_w.end()));
    if(answer == w) answer = "no answer";
    return answer;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

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
