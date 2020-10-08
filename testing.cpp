//
// testing.cpp
//

#include <iostream>
#include <random>
#include <cstdint>

using std::cin;
using std::cout;

class Character {
	uint8_t _health;
public: 
	Character(uint8_t health) : _health(health) {}
	void Attack(uint8_t damage) { 
		if (damage > _health)
			_health = 0;
		else
			_health -= damage;
	}
};

class Player : public Character {
public:
	Player() : Character(10) {}
};

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 10);
	int arr[] = { 0, 1, 2 };
	cout << arr[3] << std::endl;
	int x;
	Player player;
	while (true)
	{
		auto val = dist(gen);
		player.Attack(val);
		cout << "Press 'x' to exit, or any other key to play again" << std::endl;
		char c;
		cin >> c;
		if (c == 'x')
			break;
	}
    return 0;
}

