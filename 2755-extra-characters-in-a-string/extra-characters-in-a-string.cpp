class Solution {
public:
	int minExtraChar(string s, vector<string>& dictionary) {
		map<int, int> memo;
		return recurse(0, s, dictionary, memo);
	}

	int recurse(int start, string& s, vector<string>& dictionary,
		map<int, int>& memo) {
		// base case, string searched
		if (start >= s.size()) {
			return 0;
		}
		// if memoised, return
		else if (memo.find(start) != memo.end()) {
			return memo[start];
		}
		// else recurse
		else {
			int out = s.size() - start;
			int idx; // output of string::find
			for (string substr : dictionary) {
				idx = s.find(substr, start);
				if (idx >= 0) {
					cout << start << substr << idx << endl;
					out = min(out, idx - start +
						recurse(idx + substr.size(), s, dictionary, memo));
				}
			}
			memo[start] = out;
			return memo[start];
		}
	}
};