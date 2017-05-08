#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> PAIR;
struct CmpByValue{
	bool operator()(const PAIR& left, const PAIR& right){
		return (left.second > right.second);
	}
};

map<string, int> suffix;
vector<string> suffix_list;

vector<string> suffix_search;

bool isfront(string s1, string s2){ //如果s1比s2小，返回真
	int len = s1.length();
	for (int i = 0; i < len; ++i){
		if (s1[i] == s2[i]) continue;
		if (s1[i] < s2[i]) return true;
		if (s1[i] > s2[i]) return false;
	}
	return false;
}

void merge(vector<string> &v1, vector<string> &v2, vector<string> &mergelist){
	int i = 0, j = 0, k = 0;
	int len_v1 = v1.size(), len_v2 = v2.size();
	while (i < len_v1 && j < len_v2){
		if (isfront(v1[i],v2[i])){
			mergelist[k] = v1[i];
			++i; ++k;
		}
		else{
			mergelist[k] = v2[j];
			++j; ++k;
		}
	}
	while (i < len_v1){
		mergelist[k] = v1[i];
		++i; ++k;
	}
	while (j < len_v2){
		mergelist[k] = v2[j];
		++j; ++k;
	}
}

void mergeSort(vector<string> &data){
	int len = data.size();
	if (len>1){
		int m = len / 2;
		//切分.....
	}
}

int main(){
	string name_in = "dictionary.txt";
	ifstream ist(name_in.c_str());
	if (!ist) cout << "error" << endl;
	
	int suf_len;
	cout << "The number of letters of suffix: ";
	cin >> suf_len;
	cout << endl;

	string word;
	while (getline(ist, word, '\n')){
		if (word.length() < suf_len) continue;
		else{
			string tmp = word.substr(word.length() - 3, 3); //suf_len位后缀
			if (suffix.find(tmp) == suffix.end()){
				suffix[tmp] = 1;
				suffix_list.push_back(tmp);
			}
			else{
				++suffix[tmp];
			}
		}
	}

	vector<PAIR> pair_vec;
	map<string, int>::iterator iter;
	for (iter = suffix.begin(); iter != suffix.end(); ++iter){
		pair_vec.push_back(make_pair(iter->first, iter->second));
	}
	sort(pair_vec.begin(), pair_vec.end(),CmpByValue());
	for (int i = 0; i < 10; ++i){
		cout << pair_vec[i].first << " : " << pair_vec[i].second << endl;
	}

	cout << endl;

	cout << "The suffix you want to search: ";
	string suffix_name;
	cin >> suffix_name;
	cout << "Number of the word having this suffix: "<<suffix[suffix_name] << endl;

	ifstream jst(name_in.c_str());
	if (!jst) cout << "error" << endl;

	string other_word;
	while (getline(jst, other_word, '\n')){
		if (other_word.length() < suf_len) continue;
		if (other_word.substr(other_word.length() - 3, 3) == suffix_name){
			suffix_search.push_back(other_word);
		}
	}

	sort(suffix_search.begin(), suffix_search.end());

	for (int i = suffix_search.size()-1; i >= 0; --i){
		cout << suffix_search[i] << endl;
	}

	system("pause");
	return 0;

}