#include <iostream>
#include <random>
#include <cstdint>
#include <string>

using std::cin;
using std::cout;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, 10);

class enemy
{
private:
    uint32_t hp_;
public:
    enemy(std::string name, uint8_t health) : hp_(health) {}
    void get_hit(uint8_t damage)
    {
        hp_ -= damage;
    }
};

class player
{
	std::string _name;
	uint8_t _health;
public: 
	player(std::string name, uint8_t health) : _name(name), _health(health) {}
	void attack(uint8_t damage) 
    { 
		if (damage > _health)
			_health = 0;
		else
			_health -= damage;
	}
};

class new_class
{
public:
    new_class()
    {
        cout << "new_class\n";
    }
};

int main()
{

	int x;
	cout << "What is your name? ";
	std::string pc_name;
	cin >> pc_name;
    player pc("scott", 100);
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

