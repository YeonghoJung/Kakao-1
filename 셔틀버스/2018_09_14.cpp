/*
	��Ʋ�� 09:00���� �� nȸ t�� �������� ���� �����ϸ�, �ϳ��� ��Ʋ���� �ִ� m���� �°��� Ż �� �ִ�.
	��Ʋ�� �������� �� ������ ������ ��⿭�� �� ũ����� �����ؼ� ��� ������� �¿�� �ٷ� ����Ѵ�.
		���� ��� 09:00�� ������ ��Ʋ�� �ڸ��� �ִٸ� 09:00�� ���� �� ũ�絵 Ż �� �ִ�.

	*�Է� ����*
	��Ʋ ���� Ƚ�� n, ��Ʋ ���� ���� t, �� ��Ʋ�� Ż �� �ִ� �ִ� ũ�� �� m, 
	ũ�簡 ��⿭�� �����ϴ� �ð��� ���� �迭 timetable�� �Է����� �־�����.
	0 < n <= 10
	0 < t <= 60
	0 < m <= 45
	timetable�� �ּ� ���� 1�̰� �ִ� ���� 2000�� �迭��, �Ϸ� ���� ũ�簡 ��⿭�� �����ϴ� �ð��� HH:MM�������� �̷���� �ִ�.
	ũ���� ���� �ð� HH:MM�� 00:01���� 23:59 �����̴�.

	*��� ����*
	���� ������ ��Ʋ�� Ÿ�� �繫�Ƿ� �� �� �ִ� ���� ���� ���� �ð��� ����Ѵ�.
	���� �ð��� HH:MM �����̸�, 00:00���� 23:59 ������ ���� �� �� �ִ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string solve(int n, int t, int m, vector<string> timetable);
int main()
{
	vector<string> timetable = {"08:00","08:01","08:02","08:03"};
	int n = 1, t = 1, m = 5;
	cout << solve(n, t, m, timetable) << endl;

	system("pause");
	return 0;
}

string solve(int n, int t, int m, vector<string> timetable)
{
	vector<int> mytime;
	for (string time : timetable)
	{
		int hhmm = time[0] - '0' + time[1] - '0' + time[3] - '0' + time[4] - '0';
		mytime.push_back(hhmm);
	}
	sort(mytime.begin(), mytime.end());
	int shuttleTime = 900, result = 0;

	for (int i = 0, j = 0; i < n; i++)
	{
		int cm = 0, cmp = 0;
		map<int, int> timetype;
		while (cm < m && j < timetable.size())
		{
			if (mytime[j] > shuttleTime) break;
			timetype[mytime[j]]++;
			j++;
			cm++;
		}
		if (cm < m)
		{
			result = max(result, shuttleTime);
		}

		else
		{
			int chk = 0;
			for (auto it : timetype)
			{
				if (chk + it.second >= m)
				{
					cmp = it.first - 1;
					if (cmp & 100 > 59)	cmp -= 40;
					if (cmp < 0)cmp += 2400;
					break;
				}
				chk += it.second;
			}
			result = max(result, cmp);
		}
		shuttleTime += t;
		if (shuttleTime % 100 > 59)
		{
			shuttleTime += 100, shuttleTime -= 60;
		}
	}

	string cvtans = "";
	auto hh = to_string(result/ 100), mm = to_string(result % 100);
	if (hh.length() < 2) hh = "0" + hh;
	if (mm.length() < 2) mm = "0" + mm;
	return hh + ":" + mm;
	
}