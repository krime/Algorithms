#include <iostream>
#include <vector>
#include <string>

using namespace std;

// N (<=1000) words
// L (<=16) letters in a word
// T (<=80) letters in a sentence

void pattern_match(string cypher, vector<string> dict, char candidates[]) {
  
}

void length_match(string cypher, vector<string> dict, char candidates[]) {
  
}

void decrypt(string sentence, vector<string> dict) {
  char candidates[26];
}

int main(void) {
  int n=0; // N <=1000 words
  vector<string> dict; // n=dict.size()
  string sentence;     // sentence.size() <= 80
  for (int i=0;i<n;i++) {
    string word;       // word.size() <= 16
    cin>>word;
    dict.push_back(word);
  }
  while (cin>>sentence)
    decrypt(sentence,dict);
  
  return 0;
}
