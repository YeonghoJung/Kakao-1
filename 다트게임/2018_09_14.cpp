/*
 *	1. 다트게임은 총 3번의 기회로 구성된다.
 *	2. 각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.
 *	3. 점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 
 *		각 영역 당첨시 점수에서 1제곱, 2제곱, 3제곱(점수^1,점수^2, 점수^3 )으로 계산된다.
 *	4. 옵션으로 스타상(*), 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 
 *		아차상(#) 당첨 시 해당 점수는 마이너스 된다.
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