#include <iostream>
#include <random>
#include <cstdint>
#include <string>

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
	Player(std::string name) : Character(name, 10) {}
};

class Map {
	std::vector<char> _tiles;
	uint16_t _w;
	uint16_t _h;
public:
	Map(uint16_t w, uint16_t h) : _tiles(w*h), _w(w), _h(h) {
		for (auto& tile : _tiles) {
			tile = 'X';
		}
	}
};

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 10);
	int x;
	cout << "What is your name? ";
	std::string pc_name;
	cin >> pc_name;
	Player pc(pc_name);
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

