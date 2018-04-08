#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "player.h"

class Basic_My_Warrior_Characteristics
{
protected:
	Basic_My_Warrior_Characteristics* basic_my_warrior_characteristics;
	int basic_my_health_warrior;
	int basic_my_damage_warrior;
	int basic_my_range_of_damage_warrior;
	int basic_my_speed_warrior;
public:
	Basic_My_Warrior_Characteristics()
	{
		basic_my_health_warrior = 20;
		basic_my_damage_warrior = 10;
		basic_my_range_of_damage_warrior = 2;
		basic_my_speed_warrior = 4;
	}
	~Basic_My_Warrior_Characteristics()
	{

	}
};

class Basic_My_Archer_Characteristics
{
protected:
	Basic_My_Archer_Characteristics* basic_my_archer_characteristics;
	int basic_my_health_archer;
	int basic_my_damage_archer;
	int basic_my_range_of_damage_archer;
	int basic_my_speed_archer;
public:
	Basic_My_Archer_Characteristics()
	{
		basic_my_health_archer = 10;
		basic_my_damage_archer = 5;
		basic_my_range_of_damage_archer = 12;
		basic_my_speed_archer = 9;
	}
	~Basic_My_Archer_Characteristics()
	{

	}
};

class Basic_My_Wizard_Characteristics
{
protected:
	Basic_My_Wizard_Characteristics* basic_my_wizard_characteristics;
	int basic_my_health_wizard;
	int basic_my_damage_wizard;
	int basic_my_range_of_damage_wizard;
	int basic_my_speed_wizard;
public:
	Basic_My_Wizard_Characteristics()
	{
		basic_my_health_wizard = 10;
		basic_my_damage_wizard = 8;
		basic_my_range_of_damage_wizard = 9;
		basic_my_speed_wizard = 9;
	}
	~Basic_My_Wizard_Characteristics()
	{

	}
};

class Basic_Enemy_Warrior_Characteristics
{
protected:
	Basic_Enemy_Warrior_Characteristics* basic_my_warrior_characteristics;
	int basic_enemy_health_warrior;
	int basic_enemy_damage_warrior;
	int basic_enemy_range_of_damage_warrior;
	int basic_enemy_speed_warrior;
public:
	Basic_Enemy_Warrior_Characteristics()
	{
		basic_enemy_health_warrior = 22;
		basic_enemy_damage_warrior = 12;
		basic_enemy_range_of_damage_warrior = 4;
		basic_enemy_speed_warrior = 6;
	}
	~Basic_Enemy_Warrior_Characteristics()
	{

	}
};

class Basic_Enemy_Archer_Characteristics
{
protected:
	Basic_Enemy_Archer_Characteristics* basic_enemy_archer_characteristics;
	int basic_enemy_health_archer;
	int basic_enemy_damage_archer;
	int basic_enemy_range_of_damage_archer;
	int basic_enemy_speed_archer;
public:
	Basic_Enemy_Archer_Characteristics()
	{
		basic_enemy_health_archer = 12;
		basic_enemy_damage_archer = 7;
		basic_enemy_range_of_damage_archer = 14;
		basic_enemy_speed_archer = 11;
	}
	~Basic_Enemy_Archer_Characteristics()
	{

	}
};

class Basic_Enemy_Wizard_Characteristics
{
protected:
	Basic_Enemy_Wizard_Characteristics* basic_enemy_wizard_characteristics;
	int basic_enemy_health_wizard;
	int basic_enemy_damage_wizard;
	int basic_enemy_range_of_damage_wizard;
	int basic_enemy_speed_wizard;
public:
	Basic_Enemy_Wizard_Characteristics()
	{
		basic_enemy_health_wizard = 12;
		basic_enemy_damage_wizard = 10;
		basic_enemy_range_of_damage_wizard = 11;
		basic_enemy_speed_wizard = 11;
	}
};

class Warrior
{
protected:
	int health;
	int damage;
	int range_of_damage;
	int speed;
public:
	int get_health()
	{
		return health;
	}
	int get_damage()
	{
		return damage;
	}
	int get_range_of_damage()
	{
		return range_of_damage;
	}
	int get_speed()
	{
		return speed;
	}
	virtual bool health_decrease(int count_health) = 0;
	virtual void health_increase(int count_health) = 0;
	virtual ~Warrior()
	{

	}
};

class Archer
{
protected:
	int health;
	int damage;
	int range_of_damage;
	int speed;
public:
	int get_health()
	{
		return health;
	}
	int get_damage()
	{
		return damage;
	}
	int get_range_of_damage()
	{
		return range_of_damage;
	}
	int get_speed()
	{
		return speed;
	}
	virtual bool health_decrease(int count_health) = 0;
	virtual void health_increase(int count_health) = 0;
	virtual ~Archer()
	{

	}
};

class Wizard
{
protected:
	int health;
	int damage;
	int range_of_damage;
	int speed;
public:
	int get_health()
	{
		return health;
	}
	int get_damage()
	{
		return damage;
	}
	int get_range_of_damage()
	{
		return range_of_damage;
	}
	int get_speed()
	{
		return speed;
	}
	virtual bool health_decrease(int count_health) = 0;
	virtual void health_increase(int count_health) = 0;
	virtual ~Wizard()
	{
	}
};

class Info_About_Soldier
{
	virtual void info_about_health() = 0;
	virtual void info_about_damage() = 0;
	virtual void info_about_range_of_damage() = 0;
	virtual void info_about_speed() = 0;
	virtual void info_about_all() = 0;
};

class My_Warrior : public Warrior, public Basic_My_Warrior_Characteristics
{
public:
	My_Warrior()
	{
		health = basic_my_health_warrior;
		damage = basic_my_damage_warrior;
		range_of_damage = basic_my_range_of_damage_warrior;
		speed = basic_my_speed_warrior;
	}
	My_Warrior(Special_Power_Of_Army* power)
	{
		basic_my_health_warrior += power->get_health();
		basic_my_damage_warrior += power->get_damage();
		basic_my_range_of_damage_warrior += power->get_range_of_damage();
		basic_my_speed_warrior += power->get_speed();
		health = basic_my_health_warrior;
		damage = basic_my_damage_warrior;
		range_of_damage = basic_my_range_of_damage_warrior;
		speed = basic_my_speed_warrior;
	}
	~My_Warrior()
	{
	}
	bool health_decrease(int count_health)
	{
		health -= count_health;
		health = std::max(health, 0);
		return health <= 0;
	}
	void health_increase(int count_health)
	{
		health += count_health;
		health = std::min(health, basic_my_health_warrior);
	}
};

class Info_About_My_Warrior : public Info_About_Soldier, public My_Warrior
{
public:
	void info_about_health()
	{
		std::cout << "My warrior has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "My warrior has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "My warrior has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "My warrior has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_health();
		info_about_damage();
		info_about_range_of_damage();
		info_about_speed();
	}
};

class My_Archer : public Archer, public Basic_My_Archer_Characteristics
{
public:
	My_Archer()
	{
		health = basic_my_health_archer;
		damage = basic_my_damage_archer;
		range_of_damage = basic_my_range_of_damage_archer;
		speed = basic_my_speed_archer;
	}
	My_Archer(Special_Power_Of_Army* power)
	{
		basic_my_health_archer += power->get_health();
		basic_my_damage_archer += power->get_damage();
		basic_my_range_of_damage_archer += power->get_range_of_damage();
		basic_my_speed_archer += power->get_speed();
		health = basic_my_health_archer;
		damage = basic_my_damage_archer;
		range_of_damage = basic_my_range_of_damage_archer;
		speed = basic_my_speed_archer;
	}
	~My_Archer()
	{

	}
	bool health_decrease(int count_health)
	{
		health -= count_health;
		health = std::max(0, health);
		return health <= 0;
	}
	void health_increase(int count_health)
	{
		health += count_health;
		health = std::min(health, basic_my_health_archer);
	}
};

class Info_About_My_Archer : public Info_About_Soldier, public My_Archer
{
public:
	void info_about_health()
	{
		std::cout << "My archer has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "My archer has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "My archer has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "My archer has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_health();
		info_about_damage();
		info_about_range_of_damage();
		info_about_speed();
	}
};

class My_Wizard : public Wizard, public Basic_My_Wizard_Characteristics
{
public:
	My_Wizard()
	{
		health = basic_my_health_wizard;
		damage = basic_my_damage_wizard;
		range_of_damage = basic_my_range_of_damage_wizard;
		speed = basic_my_speed_wizard;
	}
	My_Wizard(Special_Power_Of_Army* power)
	{
		basic_my_health_wizard += power->get_health();
		basic_my_damage_wizard += power->get_damage();
		basic_my_range_of_damage_wizard += power->get_range_of_damage();
		basic_my_speed_wizard += power->get_speed();
		health = basic_my_health_wizard;
		damage = basic_my_damage_wizard;
		range_of_damage = basic_my_range_of_damage_wizard;
		speed = basic_my_speed_wizard;
	}
	~My_Wizard()
	{

	}
	bool health_decrease(int count_health)
	{
		health -= count_health;
		health = std::max(health, 0);
		return health <= 0;
	}
	void health_increase(int count_health)
	{
		health += count_health;
		health = std::min(health, basic_my_health_wizard);
	}
};

class Info_About_My_Wizard : public Info_About_Soldier, public My_Wizard
{
public:
	void info_about_health()
	{
		std::cout << "My wizard has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "My wizard has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "My wizard has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "My wizard has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_health();
		info_about_damage();
		info_about_range_of_damage();
		info_about_speed();
	}
};

class Enemy_Warrior : public Warrior, public Basic_Enemy_Warrior_Characteristics
{
public:
	Enemy_Warrior()
	{
		health = basic_enemy_health_warrior;
		damage = basic_enemy_damage_warrior;
		range_of_damage = basic_enemy_range_of_damage_warrior;
		speed = basic_enemy_speed_warrior;
	}
	~Enemy_Warrior()
	{
	}
	void info_about_health()
	{
		std::cout << "Enemy warrior has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "Enemy warrior has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "Enemy warrior has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "Enemy warrior has " << speed << " speed\n";
	}
	bool health_decrease(int count_health)
	{
		health -= count_health;
		health = std::max(0, health);
		return health <= 0;
	}
	void health_increase(int count_health)
	{
		health += count_health;
		health = std::min(health, basic_enemy_health_warrior);
	}
};

class Info_About_Enemy_Warrior : public Info_About_Soldier, public Enemy_Warrior
{
public:
	void info_about_health()
	{
		std::cout << "Enemy warrior has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "Enemy warrior has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "Enemy warrior has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "Enemy warrior has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_health();
		info_about_damage();
		info_about_range_of_damage();
		info_about_speed();
	}
};

class Enemy_Archer : public Archer, Basic_Enemy_Archer_Characteristics
{
public:
	Enemy_Archer()
	{
		health = basic_enemy_health_archer;
		damage = basic_enemy_damage_archer;
		range_of_damage = basic_enemy_range_of_damage_archer;
		speed = basic_enemy_speed_archer;
	}
	~Enemy_Archer()
	{

	}
	void info_about_health()
	{
		std::cout << "Enemy archer has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "Enemy archer has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "Enemy archer has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "Enemy archer has " << speed << " speed\n";
	}
	bool health_decrease(int count_health)
	{
		health -= count_health;
		health = std::max(0, health);
		return health <= 0;
	}
	void health_increase(int count_health)
	{
		health += count_health;
		health = std::min(health, basic_enemy_health_archer);
	}
};

class Info_About_Enemy_Archer : public Info_About_Soldier, public Enemy_Archer
{
public:
	void info_about_health()
	{
		std::cout << "Enemy archer has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "Enemy archer has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "Enemy archer has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "Enemy archer has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_health();
		info_about_damage();
		info_about_range_of_damage();
		info_about_speed();
	}
};

class Enemy_Wizard : public Wizard, Basic_Enemy_Wizard_Characteristics
{
public:
	Enemy_Wizard()
	{
		health = basic_enemy_health_wizard;
		damage = basic_enemy_damage_wizard;
		range_of_damage = basic_enemy_range_of_damage_wizard;
		speed = basic_enemy_speed_wizard;
	}
	~Enemy_Wizard()
	{

	}
	bool health_decrease(int count_health)
	{
		health -= count_health;
		health = std::max(0, health);
		return health <= 0;
	}
	void health_increase(int count_health)
	{
		health += count_health;
		health = std::min(health, basic_enemy_health_wizard);
	}
};

class Info_About_Enemy_Wizard : public Info_About_Soldier, public Enemy_Wizard
{
public:
	void info_about_health()
	{
		std::cout << "Enemy wizard has " << health << " health\n";
	}
	void info_about_damage()
	{
		std::cout << "Enemy wizard has " << damage << " damage\n";
	}
	void info_about_range_of_damage()
	{
		std::cout << "Enemy wizard has " << range_of_damage << " range of damage\n";
	}
	void info_about_speed()
	{
		std::cout << "Enemy wizard has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_health();
		info_about_damage();
		info_about_range_of_damage();
		info_about_speed();
	}
};

class Army_Factory
{
public:
	virtual Warrior* create_warrior() = 0;
	virtual Archer* create_archer() = 0;
	virtual Wizard* create_wizard() = 0;
	virtual ~Army_Factory()
	{

	}
};

class My_Army_Factory : public Army_Factory
{
public:
	My_Warrior* create_warrior()
	{
		return new My_Warrior;
	}
	My_Warrior* create_warrior_with_power(Special_Power_Of_Army* power)
	{
		return new My_Warrior(power);
	}
	My_Archer* create_archer()
	{
		return new My_Archer;
	}
	My_Archer* create_archer_with_power(Special_Power_Of_Army* power)
	{
		return new My_Archer(power);
	}
	My_Wizard* create_wizard()
	{
		return new My_Wizard;
	}
	My_Wizard* create_wizard_with_power(Special_Power_Of_Army* power)
	{
		return new My_Wizard(power);
	}
};

class Enemy_Army_Factory : public Army_Factory
{
public:
	Enemy_Warrior* create_warrior()
	{
		return new Enemy_Warrior;
	}
	Enemy_Archer* create_archer()
	{
		return new Enemy_Archer;
	}
	Enemy_Wizard* create_wizard()
	{
		return new Enemy_Wizard;
	}
};

class Info_About_Army
{
	virtual void info_about_number_of_warriors() = 0;
	virtual void info_about_number_of_archers() = 0;
	virtual void info_about_number_of_wizards() = 0;
	virtual void info_about_number_of_soldiers() = 0;
};

class My_Army
{
public:
	std::vector < My_Warrior* > army_warrior;
	std::vector < My_Archer* > army_archer;
	std::vector < My_Wizard* > army_wizard;
public:
	~My_Army()
	{
		for (auto warrior : army_warrior)
		{
			delete warrior;
		}
		for (auto archer : army_archer)
		{
			delete archer;
		}
		for (auto wizard : army_wizard)
		{
			delete wizard;
		}
	}
	int count_of_warriors()
	{
		return army_warrior.size();
	}
	int count_of_archers()
	{
		return army_archer.size();
	}
	int count_of_wizards()
	{
		return army_wizard.size();
	}
	int count_of_soldiers()
	{
		return count_of_warriors() + count_of_archers() + count_of_wizards();
	}
};

class Info_About_My_Army: public Info_About_Army, public My_Army
{
public:
	void info_about_number_of_warriors()
	{
		std::cout << "My army has " << army_warrior.size() << " warriors\n";
	}
	void info_about_number_of_archers()
	{
		std::cout << "My army has " << army_archer.size() << " archers\n";
	}
	void info_about_number_of_wizards()
	{
		std::cout << "My army has " << army_wizard.size() << " wizards\n";
	}
	void info_about_number_of_soldiers()
	{
		std::cout << "My army has " << army_warrior.size() + army_archer.size() + army_wizard.size() << " soldiers\n";
	}
};

class Enemy_Army
{
public:
	std::vector < Enemy_Warrior* > army_warrior;
	std::vector < Enemy_Archer* > army_archer;
	std::vector < Enemy_Wizard* > army_wizard;
public:
	~Enemy_Army()
	{
		for (auto warrior : army_warrior)
		{
			delete warrior;
		}
		for (auto archer : army_archer)
		{
			delete archer;
		}
		for (auto wizard : army_wizard)
		{
			delete wizard;
		}
	}
	int count_of_warriors()
	{
		return army_warrior.size();
	}
	int count_of_archers()
	{
		return army_archer.size();
	}
	int count_of_wizards()
	{
		return army_wizard.size();
	}
	int count_of_soldiers()
	{
		return count_of_warriors() + count_of_archers() + count_of_wizards();
	}
};

class Info_About_Enemy_Army : public Info_About_Army, public Enemy_Army
{
public:
	void info_about_number_of_warriors()
	{
		std::cout << "Enemy army has " << army_warrior.size() << " warriors\n";
	}
	void info_about_number_of_archers()
	{
		std::cout << "Enemy army has " << army_archer.size() << " archers\n";
	}
	void info_about_number_of_wizards()
	{
		std::cout << "Enemy army has " << army_wizard.size() << " wizards\n";
	}
	void info_about_number_of_soldiers()
	{
		std::cout << "Enemy army has " << army_warrior.size() + army_archer.size() + army_wizard.size() << " soldiers\n";
	}
};
