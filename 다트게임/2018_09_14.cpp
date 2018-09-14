/*
 *	1. ��Ʈ������ �� 3���� ��ȸ�� �����ȴ�.
 *	2. �� ��ȸ���� ���� �� �ִ� ������ 0������ 10�������̴�.
 *	3. ������ �Բ� Single(S), Double(D), Triple(T) ������ �����ϰ� 
 *		�� ���� ��÷�� �������� 1����, 2����, 3����(����^1,����^2, ����^3 )���� ���ȴ�.
 *	4. �ɼ����� ��Ÿ��(*), ������(#)�� �����ϸ� ��Ÿ��(*) ��÷ �� �ش� ������ �ٷ� ���� ���� ������ �� 2��� �����. 
 *		������(#) ��÷ �� �ش� ������ ���̳ʽ� �ȴ�.
 */

#include <iostream>	
#include <vector>
#include <string>


using namespace std;

int main()
{
	string dartResult = "";
	bool isFinished = false;
	int score = 0, result = 0,prev=0;

	cin >> dartResult;

	for (char c : dartResult)
	{
		if ('0' <= c && c <= '9')
		{
			if (isFinished)
			{
				result += score;
				prev = score;
				score = 0;
				isFinished = false;
			}
			score = score * 10 + c - '0';
			continue;
		}
		else if ('A' <= c && 'Z' >= c)
		{
			isFinished = true;
			if (c == 'D')
				score = score * score;
			else if (c == 'T')
				score = score * score * score;
		}
		else
		{
			if (c == '*')
			{
				score += prev + score;
			}
			else
				score *= -1;
		}
	}
	result += score;

	cout << result << endl;
	system("pause");
	return 0;
}