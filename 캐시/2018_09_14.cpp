/*

	*입력 형식*
	캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다.
	cacheSize는 정수이며, 범위는 0 <= cacheSize <= 30 이다.
	cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
	각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다.
		도시 이름은 최대 20자로 이루어져 있다.
	
	*출력 형식*
	입력된 도시 이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

	*조건*
	캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
	cache hit 일 경우 실행시간은 1이다.
	cache miss 일 경우 실행시간은 5이다.
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


	//검색은 string으로, 교체는 int로
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
			//가장 먼저 넣은것을 지운다.
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



