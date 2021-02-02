/*
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 
따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.
크로아티아 알파벳	변경
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 
이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 
이루어져 있는지 출력한다.

dž는 무조건 하나의 알파벳으로 쓰이고, 
d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 
위 목록에 없는 알파벳은 한 글자씩 센다.

입력 
첫째 줄에 최대 100글자의 단어가 주어진다.
알파벳 소문자와 '-', '='로만 이루어져 있다.

단어는 크로아티아 알파벳으로 이루어져 있다. 
문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

출력
입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로
이루어져 있는지 출력한다.

1. 크로아티아 알파벳을 비교할 배열을 만들고 그 안에 해당 알파벳 집어넣기
2. ASCII소문자 코드 배열 만들어 두기.
3. 비교할 단어 입력받기.
4. 먼저 크로아티아 알파벳이 있는지 확인해서 개수를 센다.
5. 그 다음 남아 있는 알파벳 개수 세기.
6. 출력.
*/
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

int main(){
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

    cout << recursive_replace(in, replaceSet).length() << endl;
}