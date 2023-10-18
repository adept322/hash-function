#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <Windows.h>

using namespace std;

string GetHash(string word)
{
	if (word.length() > 16 || word.length() < 8)
	{
		return "error";
	}
	else
	{
		string Hash;
		string Salt = "safe";
		int Size = 16;
		vector<unsigned long int> arr;
		int num[20] = { 13,23,54,756,2,34,12,87,84,456,34,23,76,89,23,54,23,54,65,32 };
		for (int i = 0; i < Size; i++)
		{
			if (i == word.length())
			{
				Size = Size - i;
				i = 0;
			}
			arr.push_back(abs(static_cast<int>(word[i]) * num[i] * (Size - i) * pow(i, i)));
		}
		for (int i = 0; i < Salt.length(); i++)
			arr.push_back(abs((static_cast<int>(Salt[i]) * num[i] * (Salt.length() - i) * i *pow(i, i)) - pow((i + 7), i)));
		for (int i = 0; i < arr.size(); i++)
		{

			if (arr[i] % 15 == 0)
			{
				Hash.push_back((arr[i]) % 25 + 65);
				continue;
			}
			if (arr[i] % 3 == 0)
			{
				Hash.push_back((arr[i]) % 10 + 47);
				continue;
			}
			Hash.push_back((arr[i]) % 25 + 97);

		}
		return Hash;
	}
}


int main()
{
	vector<string> Hash;
	string BufPass;
	ifstream fin;
	int rev = 0;
	cout << "<Enter revisions(0 - Full test)>" << endl;
	cin >> rev;
	fin.open("rockyou.txt");
	if (fin.is_open())
	{
		if(rev != 0)
		{
			int j = 1;
			while (j != rev)
			{
				system("cls");
				fin >> BufPass;
				cout << "Reading & Modification--> " << j << endl;
				Hash.push_back(GetHash(BufPass));
				j++;
			}
		}
		else
		{
			int j = 1;
			while (!fin.eof())
			{
				system("cls");
				fin >> BufPass;
				cout << "Reading & Modification--> " << j << endl;
				Hash.push_back(GetHash(BufPass));
				j++;
			}
		}
		bool revise = 0;
		for (int i = 0; i < Hash.size(); i++)
		{
			system("cls");
			cout << "Search revisions --> " << i << endl;
			for (int j = i + 1; j < Hash.size(); j++)
			{
				if (Hash[i] == Hash[j])
				{
					revise++;
				}
			}
		}
		system("cls");
		cout << "Revise: " << revise << endl;
		system("pause");
	}
	else
	{
		cout << "<Error code: 1>" << endl;
		system("pause");
		return 1;
	}
	cout << "<Exit>" << endl;
	system("pause");
	return 0;
}



