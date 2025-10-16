#include <iostream>

using namespace std;

static int binaryTree[26][2];

void preOrder(int node)
{
	if (node == -1)
		return;

	cout << (char)(node + 'A');			// 루트
	preOrder(binaryTree[node][0]);		// 왼쪽
	preOrder(binaryTree[node][1]);		// 오른쪽
}

void inOrder(int node)
{
	if (node == -1)
		return;

	inOrder(binaryTree[node][0]);	// 왼쪽
	cout << (char)(node + 'A');		// 루트
	inOrder(binaryTree[node][1]);	// 오른쪽
}

void postOrder(int node)
{
	if (node == -1)
		return;

	postOrder(binaryTree[node][0]);	// 왼쪽
	postOrder(binaryTree[node][1]);	// 오른쪽
	cout << (char)(node + 'A');		// 루트
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char node_char, left, right;
		cin >> node_char >> left >> right;

		int charIdx = node_char - 'A';

		if (left == '.')
			binaryTree[charIdx][0] = -1;
		else
			binaryTree[charIdx][0] = left - 'A';

		if (right == '.')
			binaryTree[charIdx][1] = -1;
		else
			binaryTree[charIdx][1] = right - 'A';
	}
	
	// 출력
	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);

	return 0;
}