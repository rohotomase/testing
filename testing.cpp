//
// testing.cpp
//

#include <iostream>
#include <random>
#include <cstdint>

using std::cin;
using std::cout;

class Character {
	std::string _name;
	uint8_t _health;
public: 
	Character(std::string name, uint8_t health) : _name(name), _health(health) {}
	void attack(uint8_t damage) { 
		if (damage > _health)
			_health = 0;
		else
			_health -= damage;
	}
};

class Player : public Character {
public:
	Player() : Character("player", 10) {}
};

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 10);
	int x;
	Player pc;
	while (true)
	{
		auto val = dist(gen);
		pc.attack(val);
		cout << "Press 'x' to exit, or any other key to play again" << std::endl;
		char c;
		cin >> c;
		if (c == 'x')
			break;
	}
    return 0;
}

