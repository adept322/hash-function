#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

char GetSymbol(int symbol)
{
	char csymbol;
	csymbol = symbol % 26 + 65;
	return csymbol;
}

int GetNumber(char symbol)
{
	int number = symbol;
	return number;
}

char GetVar(int symbol)
{
	char csymbol;
	csymbol = symbol % 10 + 48;
	return csymbol;
}

int main()
{
	srand(time(NULL));
	vector<int> arr;
	string word;
	short int size = 0;
	int rand_var = 0;
	int buf = 0;
	char symbol = ' ';
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		rand_var = rand() % 2147483647;
		arr.push_back(rand_var);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % 7 == 0)
		{
			word.push_back(GetVar(arr[i] / 7));
		}
		else
		{
			word.push_back(GetSymbol(arr[i]));
		}

	}
	cout << word << endl;
	system("pause");
	return 0;
}



