#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);		// �޴� ���
void MakeAccout(void);		// ���°����� ���� �Լ�
void DepositMoney(void);	// �Ա�
void WithdrowMoney(void);	// ���
void ShowAllAccInfo(void);	// �ܾ���ȸ

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
}Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccout();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrowMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection..." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccout(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, NAME_LEN, name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void WithdrowMoney(void)
{
	int money;
	int id;
	cout << "[���]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "���� ID: " << accArr[i].accID << endl;
		cout << "�̸�: " << accArr[i].cusName << endl;
		cout << "�ܾ�: " << accArr[i].balance << endl << endl;
	}
}
