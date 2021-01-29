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
	else { // 뒤에값을 가져오고 방출.
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

// vector<pair<regex, string>> initReplaceVector(vector<pair<regex, string>> state,vector<string> list) {
// 	if (list.size() == 0)
// 		return state;
// 	else {
// 		state.push_back(pair<regex,string>(regex(list.back()), "0"));
// 		list.pop_back();
// 		initReplaceVector(state, list);
// 	}
// }

int main() {
	int num = 0;
	string in;
	cin >> in;

	//같은 패턴이 반복되면 의심을 하고 코드를 자를 생각을 해야된다.
	//함수 써서 이 문장들을 한줄로 줄여보기.
	//regex가 교체
	vector<pair<regex, string>>replaceSet = vector<pair<regex, string>>();

	replaceSet.push_back(pair<regex, string>(regex("c="), "0"));
	replaceSet.push_back(pair<regex, string>(regex("c-"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("z="), "0"));
	replaceSet.push_back(pair<regex, string>(regex("dz="), "0"));
	replaceSet.push_back(pair<regex, string>(regex("d-"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("lj"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("nj"), "0"));
	replaceSet.push_back(pair<regex, string>(regex("s="), "0"));

	//해야되는일 push_back을 반복하는 함수를만들어라..
	//push_back(replaceSet);
	// string targetlist[] = { "c=","c-","z=","dz=","d-","lj","nj","s=" };
	// vector<string> vec(
	// 	targetlist,
	// 	targetlist + sizeof(targetlist) / sizeof(targetlist[0]));
	// vector<pair<regex, string>> initvec =
	// 	initReplaceVector(
	// 		vector<pair<regex, string>>(),
	// 		vec);

	
	// dz=0 일때 size 2로 인식 'd'+'z='
	cout << recursive_replace(in, replaceSet).length() << endl;
}