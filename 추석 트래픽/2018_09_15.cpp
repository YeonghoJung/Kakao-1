/*
	�ʴ� �ִ� ó������ ����Ѵ�.
	�ʴ� �ִ� ó������ ��û�� ���� �Ϸ� ���ο� ������� ���� �ð����� 1��(=1,000�и���)�� ó���ϴ� ��û�� �ִ� ������ �ǹ��Ѵ�.

	*�Է� ����*
	solution �Լ��� ���޵Ǵ� lines �迭�� N(1 <= N <= 2000)���� �α� ���ڿ��� �Ǿ�������,
	 �� �α� ���ڿ����� ��û�� ���� ���� �Ϸ�ð� S�� ó�� �ð� T�� �������� ���еǾ� �ִ�.
	����Ϸ�ð� S�� �۳� �߼��� 2016�� 9�� 15�ϸ� �����Ͽ� ���� ���� 2016-09-15 hh:mm:ss.sss �������� �Ǿ��ִ�.
	ó���ð� T�� 0.1s, 0.312s, 2s �� ���� �ִ� �Ҽ��� ��° �ڸ����� ����ϸ� �ڿ��� �� ������ �ǹ��ϴ� s�� ������.
	���� ���, �α� ���ڿ� 2016-09-15 03:10:33.020 0.011s�� "2016�� 9�� 15�� ���� 3�� 10�� 33.010��" ���� 
	 2016�� 9�� 15�� ���� 3�� 10�� 33.020��"���� "0.011��" ���� ó���� ��û�� �ǹ��Ѵ�.
	�������� Ÿ�Ӿƿ��� 3�ʷ� ����Ǿ� �ֱ� ������ ó���ð��� 0.001 <= T <= 3.000�̴�.
	lines �迭�� ����Ϸ�ð� S�� �������� �������� ���ĵǾ� �ִ�.

	*��� ����*
	solution �Լ������� �α� ������ lines �迭�� ���� �ʴ� �ִ� ó������ �����Ѵ�.
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