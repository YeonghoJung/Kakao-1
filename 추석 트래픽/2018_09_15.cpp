/*
	초당 최대 처리량을 계산한다.
	초당 최대 처리량은 ㅇ청의 응답 완료 여부에 관계없이 임의 시간부터 1초(=1,000밀리초)간 처리하는 요청의 최대 개수를 의미한다.

	*입력 형식*
	solution 함수에 전달되는 lines 배열은 N(1 <= N <= 2000)개의 로그 문자열로 되어있으며,
	 각 로그 문자열마다 요청에 대한 응답 완료시간 S와 처리 시간 T가 공백으로 구분되어 있다.
	응답완료시간 S는 작년 추석인 2016년 9월 15일만 포함하여 고정 길이 2016-09-15 hh:mm:ss.sss 형식으로 되어있다.
	처리시간 T는 0.1s, 0.312s, 2s 와 같이 최대 소수점 셋째 자리까지 기록하며 뒤에는 초 단위를 의미하는 s로 끝난다.
	예를 들어, 로그 문자열 2016-09-15 03:10:33.020 0.011s은 "2016년 9월 15일 오전 3시 10분 33.010초" 부터 
	 2016년 9월 15일 오전 3시 10분 33.020초"까지 "0.011초" 동안 처리된 요청을 의미한다.
	서버에는 타임아웃이 3초로 적용되어 있기 떄문에 처리시간은 0.001 <= T <= 3.000이다.
	lines 배열은 응답완료시간 S를 기준으로 오름차순 정렬되어 있다.

	*출력 형식*
	solution 함수에서는 로그 데이터 lines 배열에 대해 초당 최대 처리량을 리턴한다.
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int solve(vector<string> lines);
class Node
{
public:
	long long begin, end;

	bool operator <(const Node &n) const
	{
		return begin < n.begin;
	}
};
int main()
{
	vector<string> lines = { "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"};
	cout << solve(lines) << endl;
	system("pause");
	return 0;
}
int solve(vector<string> lines)
{
	vector<Node> v;
	for (string s : lines)
	{
		int hh, mm;
		double ss, ts;
		sscanf_s(s.c_str(), "2016-09-15 %d:%d:%lf %lfs", &hh, &mm, &ss, &ts);


		long long day = 20160915, endtime = hh * 10000000 + mm * 100000 + ss * 1000;
		endtime = stoll(to_string(day) + to_string(endtime));
		ss -= ts;

		if (ss < 0)
			mm--, ss += 60;
		if (mm < 0)
			hh--, mm += 60;
		if (hh < 0)
			day--, hh += 24;

		long long starttime = hh * 10000000 + mm * 100000 + ss * 1000;
		starttime = stoll(to_string(day) + to_string(starttime));
		v.push_back({ starttime, endtime });
	}
	sort(v.begin(), v.end());


	int ans = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		int cmp = 1;
		for (int j = 0; j < (int)v.size(); j++)
		{
			if (i == j) continue;
			if (!(v[j].end < v[i].begin || v[i].begin + 1000 < v[j].begin)) cmp++;
		}
		ans = max(ans, cmp);
		cmp = 1;
		for (int j = 0; j < (int)v.size(); j++)
		{
			if (i == j) continue;
			if (!(v[j].end < v[i].end || v[i].end + 1000 < v[j].begin)) cmp++;
		}
		ans = max(ans, cmp);
	}
	return ans;
}