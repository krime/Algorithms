#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <numeric>
#include <algorithm>

#include <cstring>

using namespace std;

// N (<=1000) words
// L (<=16) letters in a word
// T (<=80) letters in a sentence

bool word_length[16]; // word length check
char candidates[26];  // Ceaser's Code

bool length_order(string a,string b) {
  return a.size()>b.size();
}

bool pattern_match(string cypher, vector<string> dict, char candidates[]) {
  
}

bool length_match(string cypher) {
  return word_length[cypher.size()-1];
}


void decrypt(string sentence, vector<string> dict) {
  istringstream sio(sentence);
  vector<string> stc;
  string temp;
  bool match=false;
  while (sio>>temp) stc.push_back(temp);
  sort(stc.begin(),stc.end());
  stc.erase(unique(stc.begin(),stc.end()),stc.end());
  stable_sort(stc.begin(),stc.end(),length_order);
  //for (vector<string>::iterator it=stc.begin();it!=stc.end();it++)
  //  cout<<*it<<endl;
  //cout<<stc.size()<<endl;
  for (vector<string>::size_type i=0;i<stc.size();i++) {
    if (!(match=length_match(stc[i]))) break;
    if (!(match=pattern_match(stc[i],dict,candidates))) break;
  }
  if (!match) memset(candidates,'*',sizeof(candidates));
  //return result;
}

int main(void) {
  int n=0;             // N <= 1000 words
  vector<string> dict; // n=dict.size()
  string sentence;     // sentence.size() <= 80
  memset(word_length,0,sizeof(word_length));
  cin>>n;
  for (int i=0;i<n;i++) {
    string word;       // word.size() <= 16
    cin>>word;
    dict.push_back(word);
    !word_length[word.size()-1] && word_length[word.size()-1]++;
  }
  for (int i=0;i<26;i++) cout<<word_length[i]<<' ';
  cout<<endl;

  stable_sort(dict.begin(),dict.end(),length_order);
  for (int i=0;i<n;i++) cout<<dict[i]<<endl;
  while (getline(cin,sentence)) {
    if (sentence.size()==0) continue;
    memset(candidates,0,sizeof(candidates));
    decrypt(sentence,dict);
  }

  return 0;
}
