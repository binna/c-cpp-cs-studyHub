#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//push X : 정수 X를 스택에 넣는 연산이다.
//pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//size : 스택에 들어있는 정수의 개수를 출력한다.
//empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
//top : 스택의 가장 위에 있는 정수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.

enum Command
{
	push,
	pop,
	size,
	empty,
	top
};

unordered_map<string, Command> mappingTable = {
	{ "push",Command::push },
	{ "pop",Command::pop },
	{ "size",Command::size },
	{ "empty",Command::empty },
	{ "top",Command::top }
};

stack<int> stackData;

int main(void)
{
	int repeatNum, command2;
	string command1;

	cin >> repeatNum;

	for (int i = 0; i < repeatNum; i++)
	{
		cin >> command1;

		switch (mappingTable[command1])
		{
		case Command::push:
			cin >> command2;
			stackData.push(command2);
			continue;
		case Command::pop:
			if (stackData.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << stackData.top() << '\n';
			stackData.pop();
			continue;
		case Command::size:
			cout << stackData.size() << '\n';
			break;
		case Command::empty:
			cout << stackData.empty() << '\n';
			break;
		case Command::top:
			if (stackData.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << stackData.top() << '\n';
			break;
		}
	}

	return 0;
}