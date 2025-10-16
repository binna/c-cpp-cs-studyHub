#include <iostream>
#include <unordered_set>

using namespace std;

// Set 이용하기
int main(void)
{
	int n, m, count = 0;
	cin >> n >> m;

	unordered_set<string> word;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		word.insert(temp);
	}

	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		
		if (word.find(temp) != word.end())
			count++;
	}

	cout << count;

	return 0;
}

// 트라이 자료 구조
//class Node
//{
//public:
//	Node* next[26];
//	bool isEnd;
//
//	Node() : isEnd(false)
//	{
//		fill(next, next + 26, nullptr);
//	}
//
//	~Node()
//	{
//		for (auto& child : next)
//		{
//			delete(child);
//		}
//	}
//
//	void insert(const char* key)
//	{
//		if (*key == 0)
//		{
//			isEnd = true;
//			return;
//		}
//
//		int nextIndex = *key - 'a';
//
//		if (next[nextIndex] == nullptr)
//			next[nextIndex] = new Node();
//
//		next[nextIndex]->insert(key + 1);
//	}
//
//	Node* find(const char* key)
//	{
//		if (*key == 0)
//			return this;
//
//		int nextIndex = *key - 'a';
//
//		if (next[nextIndex] == nullptr)
//			return nullptr;
//
//		return next[nextIndex]->find(key + 1);
//	}
//};
//
//int main()
//{
//	int n, m, count = 0;
//	cin >> n >> m;
//
//	Node* root = new Node();
//
//	for (int i = 0; i < n; i++)
//	{
//		char text[501];
//		cin >> text;
//		root->insert(text);
//	}
//
//	// 트라이 자료구조 검색하기
//	for (int i = 0; i < m; i++)
//	{
//		char text[501];
//		cin >> text;
//
//		Node* result = root->find(text);
//
//		if (result != nullptr && result->isEnd)
//			count++;
//	}
//
//	cout << count;
//
//	return 0;
//}