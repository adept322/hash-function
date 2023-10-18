#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <conio.h>
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
			arr.push_back(abs((static_cast<int>(Salt[i]) * num[i] * (Salt.length() - i) * i *pow(i, i)) - pow(19, i)));
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
	string word;
	while (true)
	{
		system("cls");
		cin >> word;
		cout << GetHash(word) << endl;
		system("pause");
	}
	return 0;
}



