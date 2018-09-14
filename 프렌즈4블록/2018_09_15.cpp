/*
	같은 모양의 블록이 2X2 형태로 4개가 붙어있을 경우 사라지면서 점수를 얻는 게임
	같은 블록은 여러 2X2에 포함될 수 있으며, 지워지는 조건에 만족하는 2X2 모양이 여러 개 있다면 한꺼번에 지워진다.
	블록이 지워진 후에 위에 있는 블록이 아래로 떨어져 빈 공간을 채우게 된다.
	만약 빈 공간을 채운 후에 다시 2X2 형태로 같은 모양의 블록이 모이면 다시 지워지고 떨어지고를 반복하게 된다.

	각 문자는 라이언(R), 무지(M), 어피치(A), 프로도(F), 네오(N), 튜브(T), 제이지(J), 콘(C)을 의미한다.

	*입력 형식*
	입력으로 판의 높이 m, 폭 n과 판의 배치 정보 board가 들어온다.
	2 <= n , n <= 30
	board는 길이 n인 문자열 m개의 배열로 주어진다. 블록을 나타내는 문자는 대문자 A에서 Z가 사용된다.

	*출력 형식*
	입력으로 주어진 판 정보를 가지고 몇 개의 블록이 지워질지 출력하라.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int solve(int m, int n, vector<string> board);

int main()
{
	vector<string> board = { "CCBDE","AAADE","AAABF","CCBBF" };
	int m, n;
	cin >> m >> n;
	cout << solve(m, n, board) << endl;
	system("pause");
	return 0;
}

int solve(int m, int n, vector<string> board)
{
	bool isFinished;
	int ans = 0;
	while (1)
	{
		isFinished = true;
		bool f[31][31] = { 0 };

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				char a = board[i - 1][j - 1], b = board[i - 1][j], c = board[i][j - 1], d = board[i][j];
				if (a == b && b == c && c == d)
				{
					if (a == '-') continue;
					isFinished = false;
					f[i - 1][j - 1] = f[i - 1][j] = f[i][j - 1] = f[i][j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (f[i][j])
					board[i][j] = '-';
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				int tj = j;
				while (tj + 1 < m && board[tj + 1][i] == '-')
				{
					swap(board[tj][i], board[tj + 1][i]);
					tj++;
				}
			}
		}
		if (isFinished) break;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '-')ans++;
		}
	}
	return ans;
}