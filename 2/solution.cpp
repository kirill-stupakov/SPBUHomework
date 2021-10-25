#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int *patternPreprocess(string pattern) {
	int size = pattern.size();
	int *pie = new int[size];
  
	pie[0] = 0;

	int k = 0;
	for (int i = 1; i < size; i++) {
		while (k > 0 && pattern[k] != pattern[i]) {
			k = pie[k - 1];
		}

		if (pattern[k] == pattern[i]) {
			k = k + 1;
		}

		pie[i] = k;
	}
	
	return pie;
}

int findKMP(string text, string pattern, int startIndex, int endIndex) {
	int* pie = patternPreprocess(pattern);

	int matchedPos = 0;
	for (int current = startIndex; current < endIndex; current++) {
		while (matchedPos > 0 && pattern[matchedPos] != text[current])
			matchedPos = pie[matchedPos - 1];
			
		if (pattern[matchedPos] == text[current]) {
			matchedPos = matchedPos + 1;
    }
			
		if (matchedPos == pattern.length()) {
      return current - pattern.length() + 1;
			matchedPos = pie[matchedPos - 1];
		}
	}

  return -1;
}

int numberOfOccurences(string text, string pattern) {
  int ans = 0;
  int startIndex = findKMP(text, pattern, 0, text.size());

  while (startIndex != -1) {
      ans++;
      startIndex = findKMP(text, pattern, startIndex + 1, text.size());
  }

  return ans;
}

int main() {
  ifstream input("sample.txt");
  stringstream buffer;
  buffer << input.rdbuf();
  string text = buffer.str();

  for (char &c: text) {
    c = tolower(c);
  }

	vector<string> words = {"never", "love", "you"};

  for (string pattern: words) {
    cout << "\"" << pattern << "\": " << numberOfOccurences(text, pattern) << "\n";
  }
	
	return 0;
}