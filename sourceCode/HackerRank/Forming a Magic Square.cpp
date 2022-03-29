// https://www.hackerrank.com/challenges/magic-square-forming/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */
 
 /* 
        abc     a0 b0 a1
        def     b1 5  b2
        ghi     a2 b3 a3
        
        a, c, g, i -> 2, 4, 6, 8 
        e = 5
        b, d, f, h -> 1, 3, 7, 9
    */
vector<vector<vector<int>>> isAllMagicSquare(vector<vector<int>>&first_v, vector<vector<int>>&second_v){
     vector<vector<vector<int>>>ret_v;
     for(vector<int>first_e : first_v){
         for(vector<int>second_e : second_v){
             if(first_e[0] + second_e[0] + first_e[1] == 15
             && second_e[1] + 5 + second_e[2] == 15
             && first_e[2] + second_e[3] + first_e[3] == 15
             && first_e[0] + second_e[1] + first_e[2] == 15
             && second_e[0] + 5 + second_e[3] == 15
             && first_e[1] + second_e[2] + first_e[3] == 15){
                 vector<vector<int>>temp_v(3, vector<int>(3));
                 temp_v[0][0] = first_e[0]; temp_v[0][1] = second_e[0]; temp_v[0][2] = first_e[1];
                 temp_v[1][0] = second_e[1]; temp_v[1][1] = 5; temp_v[1][2] = second_e[2];
                 temp_v[2][0] = first_e[2]; temp_v[2][1] = second_e[3]; temp_v[2][2] = first_e[3];
                 ret_v.push_back(temp_v);
             }
         }
     }
     return ret_v;
 }

vector<vector<vector<int>>> getAllSquare(){
    
    vector<int>first_cand_v(4);
    first_cand_v[0] = 2; first_cand_v[1] = 4; first_cand_v[2] = 6; first_cand_v[3] = 8;
    vector<vector<int>>first_all_cand_v;
    do{
        vector<int>temp_v;
        for(int i=0; i<4; i++){
            temp_v.push_back(first_cand_v[i]);
        }
        first_all_cand_v.push_back(temp_v);

    }while(next_permutation(first_cand_v.begin(),first_cand_v.end()));
    
    vector<int>second_cand_v(4);
    second_cand_v[0] = 1; second_cand_v[1] = 3; second_cand_v[2] = 7; second_cand_v[3] = 9;
    vector<vector<int>>second_all_cand_v;
    do{
        vector<int>temp_v;
        for(int i=0; i<4; i++){
            temp_v.push_back(second_cand_v[i]);
        }
        second_all_cand_v.push_back(temp_v);

    }while(next_permutation(second_cand_v.begin(),second_cand_v.end()));
    vector<vector<vector<int>>>v = isAllMagicSquare(first_all_cand_v, second_all_cand_v);
    
    return v;
}

int formingMagicSquare(vector<vector<int>> s) {
    /* 
        abc     a0 b0 a1
        def     b1 5  b2
        ghi     a2 b3 a3
        
        a, c, g, i -> 2, 4, 6, 8 
        e = 5
        b, d, f, h -> 1, 3, 7, 9
    */
    vector<vector<vector<int>>>v = getAllSquare();
        // debuging code
    // for(auto e1 : v){
    //     for(auto e2 : e1){
    //         for(auto e3 : e2){
    //             cout << e3 << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl << endl;
    // }
    
    int size = v.size();
    int answer = INT_MAX;
    for(int i=0; i<size; i++){
        vector<vector<int>>cur_v = v[i];
        int candidate_answer = 0;
        for(int row = 0; row<3; row++){
            for(int col=0; col<3; col++){
                candidate_answer += abs(cur_v[row][col] - s[row][col]);
            }
        }
        answer = min(answer, candidate_answer);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

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
