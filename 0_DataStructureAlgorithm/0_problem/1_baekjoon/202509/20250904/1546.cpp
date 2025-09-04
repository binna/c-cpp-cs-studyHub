#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int cnt;
	int m = -1;
	double totalScore = 0;

	vector<float> score;

	cin >> cnt;

	//for (int i = 0; i < cnt; i++)
	//{
	//	int temp;
	//	cin >> temp;

	//	score.push_back(temp);

	//	if (temp > m)
	//		m = temp;
	//}

	//for (auto temp : score)
	//{
	//	totalScore += (temp / m * 100.0f);
	//}
	//cout << (totalScore / cnt);

	for (int i = 0; i < cnt; i++)
	{
		int temp;
		cin >> temp;

		if (temp > m)
			m = temp;
		totalScore += temp;
	}

	cout << (totalScore * 100) / m / cnt;
	
	return 0;
}