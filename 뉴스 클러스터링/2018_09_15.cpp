/*
	*�Է� ����*
	�Է����δ� str1�� str2�� �� ���ڿ��� ���´�. �� ���ڿ��� ���̴� 2 �̻�, 1,000 �����̴�.
	�Է����� ���� ���ڿ��� �� ���ھ� ��� ���������� ���ҷ� �����.
	�̶� �����ڷ� �� ���� �ָ� ��ȿ�ϰ�, ��Ÿ �����̳� ����, Ư�� ���ڰ� ����ִ� ���� �� ���� ���� ������.
	���� ��� "ab+"�� �Է����� ������, "ab"�� ���������� ���ҷ� ���, "b+"�� ������.
	�������� ���� ���̸� ���� ��, �빮�ڿ� �ҹ����� ���̴� �����Ѵ�.
	"AB"�� "Ab","ab"�� ���� ���ҷ� ����Ѵ�.

	*��� ����*
	�Է����� ���� �� ���ڿ��� ��ī�� ���絵�� ����Ѵ�. ���絵 ���� 0���� 1������ �Ǽ��̹Ƿ�, 
	 �̸� �ٷ�� ������ 65536�� ���� �Ŀ� �Ҽ��� �Ʒ��� ������ �����θ� ����Ѵ�.

	 ��ī�� ���絵 ������ũ��/������ũ��, �������� ��� 1�� ����
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