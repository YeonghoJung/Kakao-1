#include <iostream>
#include <vector>
#include <string>

using namespace std;

void main()
{
	int arr1[5] = { 9, 20, 28, 18, 11 };
	int arr2[5] = { 30, 1, 21, 17, 28 };
	vector<string> res(5);
	for (int i = 0; i < 5; i++)
	{
		arr1[i] = arr1[i] | arr2[i];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			res[i] = (arr1[i] % 2 == 1 ? "#" : " ") + res[i];
			arr1[i] >>= 1;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << res[i] << endl;
	}

	system("pause");
}