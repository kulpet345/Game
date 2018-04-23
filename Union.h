#include "Army.h"
#include <iostream>
#include <vector>

class My_Squad : public Soldier
{
public:
	std::vector<Soldier*> squad;
public:
	int get_health()
	{
		int total_health = 0;
		for (auto my_soldier : squad)
		{
			total_health += my_soldier->get_health();
		}
		return total_health;
	}
	int get_damage()
	{
		int total_damage = 0;
		for (auto my_soldier : squad)
		{
			if (my_soldier->count_of_alive_soldiers())
			{
				total_damage += my_soldier->get_damage();
			}
		}
		return total_damage;
	}
	int count_of_alive_soldiers()
	{
		int count = 0;
		for (auto my_soldier : squad)
		{
			count += my_soldier->count_of_alive_soldiers();
		}
		return count;
	}
	void add_soldier(Soldier* my_soldier)
	{
		squad.push_back(my_soldier);
	}
	bool health_decrease(int count_of_health)
	{
		for (auto my_soldier : squad)
		{
			my_soldier->health_decrease(count_of_health);
		}
		return true;
	}
	void health_increase(int count_of_health)
	{
		for (auto my_soldier : squad)
		{
			my_soldier->health_increase(count_of_health);
		}
	}
	~My_Squad()
	{
		for (auto my_soldier : squad)
		{
			delete my_soldier;
		}
	}
};

class Enemy_Squad : public Soldier
{
public:
	std::vector<Soldier*> squad;
public:
	int get_health()
	{
		int total_health = 0;
		for (auto enemy_soldier : squad)
		{
			total_health += enemy_soldier->get_health();
		}
		return total_health;
	}
	int get_damage()
	{
		int total_damage = 0;
		for (auto enemy_soldier : squad)
		{
			if (enemy_soldier->count_of_alive_soldiers())
			{
				total_damage += enemy_soldier->get_damage();
			}
		}
		return total_damage;
	}
	int count_of_alive_soldiers()
	{
		int count = 0;
		for (auto enemy_soldier : squad)
		{
			count += enemy_soldier->count_of_alive_soldiers();
		}
		return count;
	}
	void add_soldier(Soldier* enemy_soldier)
	{
		squad.push_back(enemy_soldier);
	}
	bool health_decrease(int count_of_health)
	{
		for (auto enemy_soldier : squad)
		{
			enemy_soldier->health_decrease(count_of_health);
		}
		return true;
	}
	void health_increase(int count_of_health)
	{
		for (auto enemy_soldier : squad)
		{
			enemy_soldier->health_increase(count_of_health);
		}
	}
	~Enemy_Squad()
	{
		for (auto enemy_soldier : squad)
		{
			delete enemy_soldier;
		}
	}
};

My_Squad* create_my_squad(int cnt_warriors, int cnt_archers, int cnt_wizards, My_Warrior* warrior, My_Archer* archer, My_Wizard* wizard)
{
	My_Squad* my_squad = new My_Squad;
	for (int current_warrior = 1; current_warrior <= cnt_warriors; current_warrior++)
	{
		my_squad->add_soldier(new My_Warrior(warrior));
	}
	for (int current_archer = 1; current_archer <= cnt_archers; current_archer++)
	{
		my_squad->add_soldier(new My_Archer(archer));
	}
	for (int current_wizard = 1; current_wizard <= cnt_wizards; current_wizard++)
	{
		my_squad->add_soldier(new My_Wizard(wizard));
	}
	return my_squad;
}

Enemy_Squad* create_enemy_squad(int cnt_warriors, int cnt_archers, int cnt_wizards, Enemy_Warrior* warrior, Enemy_Archer* archer, Enemy_Wizard* wizard)
{
	Enemy_Squad* enemy_squad = new Enemy_Squad;
	for (int current_warrior = 1; current_warrior <= cnt_warriors; current_warrior++)
	{
		enemy_squad->add_soldier(new Enemy_Warrior(warrior));
	}
	for (int current_archer = 1; current_archer <= cnt_archers; current_archer++)
	{
		enemy_squad->add_soldier(new Enemy_Archer(archer));
	}
	for (int current_wizard = 1; current_wizard <= cnt_wizards; current_wizard++)
	{
		enemy_squad->add_soldier(new Enemy_Wizard(wizard));
	}
	return enemy_squad;
}


