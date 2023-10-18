#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

void print_menu() //���� ���������
{
	cout << "<1><Register>" << endl;
	cout << "<2><Verification>" << endl;
	cout << "<0><Exit>" << endl;
}
int main()
{
	srand(time(NULL));
	int answer = 0, number = 0;
	int quantity_numbers = 0;
	int small_registr = 0, big_registr = 0;
	string verif_login, verif_password;
	string base_login, base_password;
	string entered_login, entered_password;
	while (true) 
	{
		number = rand() % 1000; //����� ��������������� � ������
		system("pause");
		system("cls"); 
		print_menu(); //����� ����
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			cout << "@Enter login@" << endl; //���� ������
			cin >> entered_login;  //��� ��� getline() �� �������� � fout-�, �� ���������� cin>> 
			while (true) //���� �������� ������
			{
				cout << "@Enter password@" << endl; //���� ������
				cin >> entered_password;
				for (int i = 0; i < entered_password.length(); i++) //������� ����
				{
					if (entered_password[i] == '1' || entered_password[i] == '2' || entered_password[i] == '3')
					{
						quantity_numbers++;
					}
					if (entered_password[i] == '4' || entered_password[i] == '5' || entered_password[i] == '6')
					{
						quantity_numbers++;
					}
					if (entered_password[i] == '7' || entered_password[i] == '8' || entered_password[i] == '9')
					{
						quantity_numbers++;
					}
					if (entered_password[i] == '0')
					{
						quantity_numbers++;
					}
				}
				for (int i = 0; i < entered_password.length(); i++) //������� ���������
				{
					if (entered_password[i] > 64 && entered_password[i] < 91) //������� �������� ��������
					{
						big_registr++;
					}
					if (entered_password[i] > 96 && entered_password[i] < 123) //������� ������ ��������
					{
						small_registr++;
					}
				}
				if (quantity_numbers == 0) //�������� �� ������� ����
				{
					cout << "@There are no numbers in the password@" << endl;
					continue;
				}
				if (small_registr == 0 || big_registr == 0) //�������� �� ������� 2�� ���������
				{
					cout << "@No two registers in the password@" << endl;
					continue;
				}
				if (entered_password.length() < 8) //�������� �� ������� 8�� �������� � ������
				{
					cout << "@The lack of eight characters@" << endl;
					continue;
				}
				break;
			}
			entered_login[0] = toupper(entered_login[0]); //toupper ������� ������� ������
			cout << "____________________" << endl; //�������� ���������� 
			cout << "@Login@: " << "_" << entered_login << number << endl;
			cout << "@Password@: " << entered_password << endl;
			cout << "____________________" << endl;
			ofstream fout; //�����
			fout.open("Database.txt"); //�������� ����� fout
			fout << entered_login << "_" << number << " " << entered_password << endl; //������
			fout.close(); //�������� ����� fout
			cout << "@Account registered@" << endl;
			break;
		}
		case 2:
		{
			cout << "@Enter login@: " << endl;
			cin >> verif_login;
			cout << "@Enter password@: " << endl;
			cin >> verif_password;
			ifstream fin;//�����
			fin.open("Database.txt"); //�������� ����� fin
			fin>> base_login>> base_password;
			fin.close(); //�������� ����� fin
			if (verif_login == base_login && verif_password == base_password) //�������� ����������
			{
				cout << "Successfully@" << endl;
			}
			else
			{
				cout << "@Unsuccessfully@" << endl;
				cout << "@Invalid login or password@" << endl;
			}
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			continue;
		}
		}
	}
	system("pause");
	return 0;
}
