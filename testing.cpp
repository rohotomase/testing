// testing.cpp

#include <iostream>
#include <random>

using std::cin;
using std::cout;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 10);
	auto val = dist(gen);
	int x;
	while (true)
	{
		cout << "Pick a number 1 - 10: ";
		cin >> x;
		if (x < 0 || x > 10)
			continue;
		if (x == val)
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

