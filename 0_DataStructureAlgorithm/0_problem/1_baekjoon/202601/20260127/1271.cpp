#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string n, m, mCopy;
	cin >> n >> m;

	//int mIdx = 0;
	//for (int nIdx = 0; nIdx < n.length(); nIdx++)
	//{
	//	cout << n[nIdx];
	//}

	mCopy = m;

	while (n.size() != 0)
	{
		if (mCopy.size() == 0)
			mCopy = m;

		cout << "=============" << endl;
		int nNum = n[0] - '0';
		int mNum = mCopy[0] - '0';
		cout << nNum << endl;
		cout << mNum << endl;
		cout << "=============" << endl;

		n.erase(0, 1);
		mCopy.erase(0, 1);
	}




	//string n, m, resultM = "", resultN = "";
	//cin >> n >> m;

	//string temp = "";
	//for (int i = 0; i < m.length(); i++)
	//{
	//	temp += n[i];
	//}

	///////////////////////////////////////////
	//resultM += to_string(stoll(temp) / stoll(m));
	//resultN = to_string(stoll(temp) % stoll(m));
	///////////////////////////////////////////

	//for (int i = m.length(); i < n.length(); i++)
	//{
	//	string temp2 = "";
	//	for (int j = 1; j < temp.length(); j++)
	//	{
	//		temp2 += temp[j];
	//	}

	//	temp2 += n[i];

	//	resultM += to_string(stoll(temp2) / stoll(m));
	//	resultN = to_string(stoll(temp) % stoll(m));

	//	temp = temp2;
	//}

	//cout << stoll(resultM) << '\n' << stoll(resultN);

	return 0;
}