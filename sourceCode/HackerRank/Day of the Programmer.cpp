// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

bool isLeapYear(int year){
    if(year <= 1917 && year % 4 == 0) return true;
    if(year <= 1917 && year % 4 != 0) return false;
    if(year == 1918) return false;
    if(year % 400 == 0) return true;
    if(year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

void initCalendar(map<int, int> &m, int year){
    m[1] = 31; m[3] = 31; m[4] = 30; m[5] = 31; m[6] = 30; m[7] = 31;
    m[8] = 31; m[9] = 30; m[10] = 31; m[11] = 30; m[12] = 31;
    if(isLeapYear(year)) m[2] = 29;
    else m[2] = 28;
}

string dayOfProgrammer(int year) {
    map<int, int>m;
    cout << isLeapYear(year);
    initCalendar(m, year);
    int num = 256;
    if(year == 1918) num += 13;
    int cur_month = 1;
    while(num > 31){
        num -= m[cur_month];
        cur_month++;
        if(cur_month == 13) {
            year++;
            cur_month = 1;
        }
    }
    if(num > m[cur_month]){
        num -= m[cur_month];
        cur_month++;
        if(cur_month == 13) {
            year++;
            cur_month = 1;
        }
    }
    
    string answer = "";
    if(num <= 9) answer += "0";
    answer += to_string(num);
    answer += ".";
    if(cur_month <= 9) answer += "0";
    answer += to_string(cur_month);
    answer += ".";
    answer += to_string(year);
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
