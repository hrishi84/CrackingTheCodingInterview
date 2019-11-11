#include<bits/stdc++.h>
using namespace std;
bool isPermutation(string s1, string s2){
	if(s1.length()!= s2.length())
		return false;

	unordered_map<char, int> char_map;

	int i=0, n = s1.length();
	for(i=0; i<n; i++){
		if(char_map.find(s1[i]) == char_map.end()){
			char_map[s1[i]] = 1;
		}
		else{
			char_map[s1[i]]++;
		}
	}

	for(i=0; i<n; i++){
            cout << s2[i] << " " << char_map[s2[i]] << endl;
		if(char_map.find(s2[i]) == char_map.end()){
			return false;
		}
		else
             char_map[s2[i]]--;
        if(char_map[s2[i]] <= 0){
				char_map.erase(s2[i]);
			}
	}

	if(char_map.size())
		return 	false;
	return true;
}

string getURLify(string s){
	if(s.length() < 0)
		return "";
	vector<string> words;
	string word = "";
	for(int i=0; i< s.length(); i++){
		if(s[i] != ' ')
			word += s[i];
		else{
			if(word.length())
				words.push_back(word);
			word = "";
		}
	}
	if(word.length())
				words.push_back(word);

	word = "";
	//reverse(words.begin(),words.end());
	for(int i=0; i<words.size(); i++){
		word += words[i];
		if(i != words.size()-1 )
			word += "%20";
	}

	return word;

}

int main(){
    string s1 = "hello world    ";
    string s2 = "ssaavfbc";


   cout << getURLify(s1) << endl;
//	return s1 == s2;
    return 0;

}
