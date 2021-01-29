#include <iostream>
#include <string>
#include <regex>
#include <utility>
#include <vector>
using namespace std;

string recursive_replace(string in, vector<pair<regex, string>> replaceset) {
	if (replaceset.size() == 0) { 
		return in;
	}
	else {
		pair<regex, string> replacePair = replaceset.back();
		replaceset.pop_back();
		
		return recursive_replace(
			regex_replace(
				in,
				replacePair.first,
				replacePair.second),
			replaceset);
	}
}

int main(){
	string in;
	cin >> in;
	vector<pair<regex, string>>replaceSet = vector<pair<regex, string>>();

	replaceSet.push_back(pair<regex, string>(regex("c="), "0"));
	replaceSet.push_back(pair<regex, string>(regex("c-"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("z="), "0"));
	replaceSet.push_back(pair<regex, string>(regex("dz="), "0"));
	replaceSet.push_back(pair<regex, string>(regex("d-"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("lj"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("nj"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("s="), "0"));

    cout << recursive_replace(in, replaceSet).length() << endl;
}