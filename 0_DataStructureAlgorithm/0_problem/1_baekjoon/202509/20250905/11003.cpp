#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

//int main()
//{
//	int n, l, startIdx, endIdx;
//	cin >> n >> l;
//
//	vector<int> arr(n);
//	vector<int> rangeArr;
//
//	//for (int i = 0; i < n; i++)
//	//{
//	//	
//	//}
//
//	
//	int coutIdx = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//
//		int startIdx = i - l + 1;
//		rangeArr.push_back(arr[i]);
//
//		if (coutIdx < startIdx)
//		{
//			rangeArr.erase(rangeArr.begin());
//			//cout << "erase i : " << i << endl;
//			coutIdx++;
//		}
//
//		int min = *min_element(rangeArr.begin(), rangeArr.end());
//		cout << min << ' ';
//		//cout << i - l + 1 << " ~ " << i <<  "   :   ";
//		//cout << "top : " << *rangeArr.begin() << "//" << rangeArr.size() << endl << endl;
//	}
//
//	return 0;
//}

typedef pair<int, int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, l;
	cin >> n >> l;
	deque<Node> myDeque;

	for (int i = 0; i < n; i++)
	{
		int now;
		cin >> now;

		// now 보다 큰 수는 삭제해야함
		while (!myDeque.empty() && myDeque.back().first >= now)
		{
			myDeque.pop_back();
		}

		myDeque.push_back(Node(now, i));

		if (myDeque.front().second <= i - l)
		{
			myDeque.pop_front();
		}
		cout << myDeque.front().first << ' ';
	}


	return 0;
}