#include <string>
#include <map>

using namespace std;
class HappyLetterDiv2 {
public:
	char getHappyLetter(string letters) {
		map<char,int> counter;
		for (string::iterator it = letters.begin(); it != letters.end(); ++it) {
			if (counter.find(*it) == counter.end())
				counter[*it] = 1;
			else
				counter[*it]++;
		}
		char best = '.';
		int best_size = letters.size() / 2;
		for (map<char,int>::iterator i = counter.begin(); i != counter.end(); ++i) {
			if (best_size < i->second) {
				best = i->first;
				best_size = i->second;
			}
		}
		return best;
	}
};