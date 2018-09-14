/*
	���� ����� ����� 2X2 ���·� 4���� �پ����� ��� ������鼭 ������ ��� ����
	���� ����� ���� 2X2�� ���Ե� �� ������, �������� ���ǿ� �����ϴ� 2X2 ����� ���� �� �ִٸ� �Ѳ����� ��������.
	����� ������ �Ŀ� ���� �ִ� ����� �Ʒ��� ������ �� ������ ä��� �ȴ�.
	���� �� ������ ä�� �Ŀ� �ٽ� 2X2 ���·� ���� ����� ����� ���̸� �ٽ� �������� �������� �ݺ��ϰ� �ȴ�.

	�� ���ڴ� ���̾�(R), ����(M), ����ġ(A), ���ε�(F), �׿�(N), Ʃ��(T), ������(J), ��(C)�� �ǹ��Ѵ�.

	*�Է� ����*
	�Է����� ���� ���� m, �� n�� ���� ��ġ ���� board�� ���´�.
	2 <= n , n <= 30
	board�� ���� n�� ���ڿ� m���� �迭�� �־�����. ����� ��Ÿ���� ���ڴ� �빮�� A���� Z�� ���ȴ�.

	*��� ����*
	�Է����� �־��� �� ������ ������ �� ���� ����� �������� ����϶�.
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