/*
	*입력 형식*
	입력으로는 str1과 str2의 두 문자열이 들어온다. 각 문자열의 길이는 2 이상, 1,000 이하이다.
	입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다.
	이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
	예를 들어 "ab+"가 입력으로 들어오면, "ab"만 다중집합의 원소로 삼고, "b+"는 버린다.
	다중집합 원소 사이를 비교할 떄, 대문자와 소문자의 차이는 무시한다.
	"AB"와 "Ab","ab"는 같은 원소로 취급한다.

	*출력 형식*
	입력으로 들어온 두 문자열의 자카드 유사도를 출력한다. 유사도 값은 0에서 1사이의 실수이므로, 
	 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.

	 자카드 유사도 교집합크기/합집합크기, 공집합인 경우 1로 간주
 */

#include <iostream>
#include <string>
#include <map>	
#include <algorithm>

using namespace std;

int solve(string str1, string str2);
int main()
{
	string str1, str2;
	cin >> str1 >>str2;
	cout << solve(str1, str2) << endl;
	system("pause");
	return 0;
}


int solve(string str1, string str2)
{
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

	map<string, int> mp1, mp2;
	int cup = 0; 
	int hat = 0;

	for (int i = 0; i < (int)str1.length() - 1; i++)
	{
		string substr1 = str1.substr(i, 2);
		if ('A' <= substr1[0] && substr1[0] <= 'Z' && 'A' <= substr1[1] && substr1[1] <= 'Z')
		{
			mp1[substr1]++;
		}
	}

	for (int i = 0; i < (int)str2.length() - 1; i++)
	{
		string substr2 = str2.substr(i, 2);
		if ('A' <= substr2[0] && substr2[0] <= 'Z' && 'A' <= substr2[1] && substr2[1] <= 'Z')
		{
			mp2[substr2]++;
		}
	}


	for (auto it : mp1)
	{
		if (mp2.count(it.first) > 0)
		{
			hat += min(it.second, mp2[it.first]);
			cup += max(it.second, mp2[it.first]);
		}
		else
		{
			cup += it.second;
		}
	}

	for (auto it : mp2)
	{
		if (mp1.count(it.first) == 0)
		{
			cup += it.second;
		}
	}

	if (!hat) hat = 1;
	hat *= 65536;
	if (!cup) cup = 1;
	return hat/cup;
}