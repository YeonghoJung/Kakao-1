/*
	셔틀은 09:00부터 총 n회 t분 간격으로 역에 도착하며, 하나의 셔틀에는 최대 m명의 승객이 탈 수 있다.
	셔틀은 도착했을 때 도착한 순간에 대기열에 선 크루까지 포함해서 대기 순서대로 태우고 바로 출발한다.
		예를 들어 09:00에 도착한 셔틀은 자리가 있다면 09:00에 줄을 선 크루도 탈 수 있다.

	*입력 형식*
	셔틀 운행 횟수 n, 셔틀 운행 간격 t, 한 셔틀에 탈 수 있는 최대 크루 수 m, 
	크루가 대기열에 도착하는 시각을 모은 배열 timetable이 입력으로 주어진다.
	0 < n <= 10
	0 < t <= 60
	0 < m <= 45
	timetable은 최소 길이 1이고 최대 길이 2000인 배열로, 하루 동안 크루가 대기열에 도착하는 시각이 HH:MM형식으로 이루어져 있다.
	크루의 도착 시각 HH:MM은 00:01에서 23:59 사이이다.

	*출력 형식*
	콘이 무사히 셔틀을 타고 사무실로 갈 수 있는 제일 늦은 도착 시각을 출력한다.
	도착 시각은 HH:MM 형식이며, 00:00에서 23:59 사이의 값이 될 수 있다.
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