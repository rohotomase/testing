// testing.cpp : Defines the entry point for the console application.
//
#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int x;
	while (true)
	{
		cout << "Pick a number 1 - 10: ";
		cin >> x;
		if (x < 0 || x > 10)
			continue;
		if (x == 3)
			cout << "You got it!!!!" << std::endl;
		else
			cout << "Sorry, better luck next time" << std::endl;
		cout << "Press 'x' to exit, or any other key to play again" << std::endl;
		char c;
		cin >> c;
		if (c == 'x')
			break;
	}
    return 0;
}

