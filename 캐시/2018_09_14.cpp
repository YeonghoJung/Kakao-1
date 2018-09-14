/*

	*�Է� ����*
	ĳ�� ũ��(cacheSize)�� �����̸� �迭(cities)�� �Է¹޴´�.
	cacheSize�� �����̸�, ������ 0 <= cacheSize <= 30 �̴�.
	cities�� ���� �̸����� �̷��� ���ڿ� �迭��, �ִ� ���� ���� 100,000���̴�.
	�� ���� �̸��� ����, ����, Ư������ ���� ���� �����ڷ� �����Ǹ�, ��ҹ��� ������ ���� �ʴ´�.
		���� �̸��� �ִ� 20�ڷ� �̷���� �ִ�.
	
	*��� ����*
	�Էµ� ���� �̸� �迭�� ������� ó���� ��, "�� ����ð�"�� ����Ѵ�.

	*����*
	ĳ�� ��ü �˰����� LRU(Least Recently Used)�� ����Ѵ�.
	cache hit �� ��� ����ð��� 1�̴�.
	cache miss �� ��� ����ð��� 5�̴�.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> cities = { "Jeju", "Pangyo","Seoul", "NewYork","LA","Sanfrancisco","Seoul","Rome","Paris","Jeju","NewYork","Rome" };

int solve(int cacheSize, vector<string> cities)
{
	const int CACHE_HIT = 1, CACHE_MISS = 5;

	if (!cacheSize)
	{
		return cities.size() * CACHE_MISS;
	}

	int time = 0, result = 0;


	//�˻��� string����, ��ü�� int��
	map<int, string> cache1;	
	map<string, int> cache2;
	
	for (string city : cities)
	{
		time++;
		if (!cache2[city])
		{
			result += CACHE_MISS;
		}
		else
		{
			result += CACHE_HIT;
		}

		if (cache1.size() == cacheSize)
		{
			//���� ���� �������� �����.
			auto elem = *cache1.begin();
			cache2.erase(elem.second);
			cache1.erase(elem.first);
		}
		cache1[time] = city;
		cache2[city] = time;
	}

	return result;

}

int main()
{
	cout << solve(2, cities) << endl;
	system("pause");

	return 0;
}



