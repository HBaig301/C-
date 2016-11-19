#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;


int main()
{
	system("cls");
	
	int n;
	int rotations;
	int add;
	int y;
	int remain;
	char a[] = {'!','E','C','E','1','5','0','!'};
	
	cout << "Please specify the number of marquee rotations: ";
	cin >> rotations;
	
	if (cin.fail())
	{
		cerr << "ERROR: ";
		return -1;
	}
	
	for (int l=0; l < rotations; l++)
	{
		n=0;
		for (int j = 0; j < 61; j++)
		{
			for (int i = 0; i < 60; i++)
			{
				cout << "=";
			}
			cout << endl;
			
			if (j == 53)
			{
				n--;
			}
			if (j >= 53)
			{
				add = j - 52;
				y=8-add;
				for (int i=0; i<add; i++)
				{
					cout << a[y];
					y++;
				}
				for (int i=0; i < n; i++)
				{
					cout << " ";
				}
				remain = (60 - (n+add));
				for (int i=0; i< remain; i++)
				{
					cout << a[i];
				}
				cout << endl;
				
				for (int i = 0; i < 60; i++)
				{
					cout << "=";
				}
				if (l == (rotations-1) && j==60)
				{
					break;//system("cls");
				}
				else
				{
					system("cls");
				}
			}
			else
			{
				for (int i=0; i < n; i++)
				{
					cout << " ";
				}
				cout << "!ECE150!" << endl;
				for (int i = 0; i < 60; i++)
				{
					cout << "=";
				}
				n++;
				system("cls");
			}
		}
		
		/*if (l == rotations-1)
		{
			for (int i = 0; i < 60; i++)
			{
				cout << "=";
			}
			cout << endl;
			cout << "!ECE150!" << endl;
			for (int i = 0; i < 60; i++)
			{
				cout << "=";
			}
		}*/
		
	}
	
	
	return 0;
}