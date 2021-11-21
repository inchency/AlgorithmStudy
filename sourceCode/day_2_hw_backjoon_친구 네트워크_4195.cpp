#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string>parent_m;
unordered_map<string, int>rank_m;
unordered_map<string, int>friends_cnt_m;

void solve(string a, string b);
string find_root(string& node);
void do_union(string& a, string& b);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int F;
		cin >> F;
		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			solve(a, b);
		}
		parent_m.clear(); rank_m.clear(); friends_cnt_m.clear();
	}
	return 0;
}

void solve(string a, string b) {
	if (parent_m.find(a) == parent_m.end()) {
		parent_m[a] = a;
		rank_m[a] = 0;
		friends_cnt_m[a] = 1;
	}
	if (parent_m.find(b) == parent_m.end()) {
		parent_m[b] = b;
		rank_m[b] = 0;
		friends_cnt_m[b] = 1;
	}
	if (find_root(a) != find_root(b)) {
		do_union(a, b);
	}
	cout << friends_cnt_m[find_root(a)] << "\n";
}

string find_root(string& node) {
	if (parent_m[node] == node)
		return node;
	else
		return find_root(parent_m[node]);
}

void do_union(string& a, string& b) {
	string a_root = find_root(a), b_root = find_root(b);
	if (rank_m[a_root] > rank_m[b_root]) {
		parent_m[b_root] = a_root;
		friends_cnt_m[a_root] += friends_cnt_m[b_root];
	}
	else if (rank_m[a_root] < rank_m[b_root]) {
		parent_m[a_root] = b_root;
		friends_cnt_m[b_root] += friends_cnt_m[a_root];
	}
	else {
		rank_m[a_root] += 1;
		parent_m[b_root] = a_root;
		friends_cnt_m[a_root] += friends_cnt_m[b_root];
	}
}

// 아래는 일반적으로 사용하는 map이 아닌 int형 vector을 이용해 union find 를 사용한 방법 (메모리, 시간 절반으로 단축 가능) 단점은 풀이 지저분
//#include <vector>
//#include <map>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//map<string, int>m;
//
//int find_root(vector<int>& parent_v, int node);
//void union_f(vector<int>& parent_v, vector<int>& rank_v, vector<int>& friends_cnt_v, int start_node, int dest_node);
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		int F;
//		cin >> F;
//		int name_ind = 0;
//		vector<pair<string, string>>v(F);
//		for (int i = 0; i < F; i++) {
//			string a, b;
//			cin >> a >> b;
//			if (m.find(a) == m.end())
//				m[a] = name_ind++;
//			if (m.find(b) == m.end())
//				m[b] = name_ind++;
//			v[i].first = a; v[i].second = b;
//		}
//		int v_size = m.size();
//		// 초기화
//		vector<int>parent_v(v_size);
//		for (int i = 0; i < v_size; i++) parent_v[i] = i;
//		vector<int>rank_v(v_size, 0);
//		vector<int>friends_cnt_v(v_size, 1);
//		// 찾기
//		for (int i = 0; i < F; i++) {
//			string a = v[i].first; string b = v[i].second;
//			int a_ind = m[a]; int b_ind = m[b];
//			if (find_root(parent_v, a_ind) != find_root(parent_v, b_ind)) {
//				union_f(parent_v, rank_v, friends_cnt_v, a_ind, b_ind);
//			}
//			cout << friends_cnt_v[find_root(parent_v, a_ind)] << "\n";
//		}
//	}
//	return 0;
//}
//
//int find_root(vector<int>& parent_v, int node) {
//	if (parent_v[node] == node) return node;
//	else {
//		//return find_root(parent_v, parent_v[node]);
//		parent_v[node] = find_root(parent_v, parent_v[node]);
//		return parent_v[node];
//	}
//}
//
//void union_f(vector<int>& parent_v, vector<int>& rank_v, vector<int>& friends_cnt_v, int start_node, int dest_node) {
//	int start_root = find_root(parent_v, start_node);
//	int dest_root = find_root(parent_v, dest_node);
//	// root의 rank가 높은거에 붙여준다.
//	if (rank_v[start_root] > rank_v[dest_root]) {
//		parent_v[dest_root] = start_root;
//		friends_cnt_v[start_root] += friends_cnt_v[dest_root];
//	}
//	else if (rank_v[start_root] < rank_v[dest_root]) {
//		parent_v[start_root] = dest_root;
//		friends_cnt_v[dest_root] += friends_cnt_v[start_root];
//	}
//	else {
//		rank_v[start_root] += 1;
//		parent_v[dest_root] = start_root;
//		friends_cnt_v[start_root] += friends_cnt_v[dest_root];
//	}
//}
