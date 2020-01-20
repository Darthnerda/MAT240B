#include <algorithm>      // sort
#include <iostream>       // cin, cout, printf
#include <unordered_map>  // unordered_map
#include <vector>         // vector
#include <string>         // string
using namespace std;

// comparison function
bool comp(pair<string, unsigned> i, pair<string, unsigned> j) { return (i.second > j.second); }

int main() {
	unordered_map<string, unsigned> dictionary;

	string word;
	while (cin >> word) {
		// only inserts a new pair with initial count 0 if it doesn't find the key already there
		dictionary.insert({ word, 0 });

		// updates the word's count.
		(*dictionary.find(word)).second++;
	}

	vector<pair<string, unsigned>> wordList;
	for (auto& t : dictionary) wordList.push_back(t);

	std::sort(wordList.begin(), wordList.end(), comp);

	for (auto& t : wordList) printf("%u:%s\n", t.second, t.first.c_str());

	return 0;
}