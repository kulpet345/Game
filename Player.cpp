#include <iostream>
#include <string>
#include <algorithm>
#pragma once

class Characteristics_Of_Player
{
private:
	static int health;
	static int damage;
	static int range_of_damage;
	static int speed;
	static std::string name_of_class;
public:
	static int& get_health()
	{
		return health;
	}
	static int& get_damage()
	{
		return damage;
	}
	static int& get_range_of_damage()
	{
		return range_of_damage;
	}
	static int& get_speed()
	{
		return speed;
	}
	static std::string& get_name_of_class()
	{
		return name_of_class;
	}
	void info_about_player_health()
	{
		std::cout << "Player has " << health << " health\n";
	}
	void info_about_player_damage()
	{
		std::cout << "Player has " << damage << " damage\n";
	}
	void info_about_player_range_of_damage()
	{
		std::cout << "Player has " << range_of_damage << " range of damage\n";
	}
	void info_about_player_speed()
	{
		std::cout << "Player has " << speed << " speed\n";
	}
	void info_about_all()
	{
		info_about_player_health();
		info_about_player_damage();
		info_about_player_range_of_damage();
		info_about_player_speed();
	}
};

class Special_Power_Of_Army
{
private:
	static int health;
	static int damage;
	static int range_of_damage;
	static int speed;
	static std::string name_of_power;
public:
	static int& get_health()
	{
		return health;
	}
	static int& get_damage()
	{
		return damage;
	}
	static int& get_range_of_damage()
	{
		return range_of_damage;
	}
	static int& get_speed()
	{
		return speed;
	}
	static std::string& get_name_of_power()
	{
		return name_of_power;
	}
	void info_about_health_bonus_of_army()
	{
		std::cout << "Army has " << health << " health bonus\n";
	}
	void info_about_damage_bonus_of_army()
	{
		std::cout << "Army has " << damage << " damage bonus\n";
	}
	void info_about_range_of_damage_bonus_of_army()
	{
		std::cout << "Army has " << range_of_damage << " range_of_damage bonus\n";
	}
	void info_about_speed_bonus_of_army()
	{
		std::cout << "Army has " << speed << " speed bonus\n";
	}
	void info_about_name_of_power()
	{
		std::cout << "Army has " << name_of_power << " special power\n";
	}
	void info_about_all()
	{
		info_about_health_bonus_of_army();
		info_about_damage_bonus_of_army();
		info_about_range_of_damage_bonus_of_army();
		info_about_speed_bonus_of_army();
	}
};

class Player
{
public:
	Player()
	{
	}
	~Player()
	{
	}
	Characteristics_Of_Player characteristics;
	Special_Power_Of_Army power;
};

class Builder_Of_Player
{
protected:
	Player* player;
public:
	virtual void set_health(int count_health)
	{

	}
	virtual void set_damage(int count_damage)
	{

	}
	virtual void set_range(int count_range)
	{

	}
	virtual void set_speed(int count_speed)
	{

	}
	virtual void set_name()
	{

	}
	virtual Player* get_player()
	{
		return player;
	}
};

bool warrior(int health, int damage, int range_of_damage, int speed)
{
	if ((health >= 40 || damage >= 10) && range_of_damage <= 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool archer(int health, int damage, int range_of_damage, int speed)
{
	if (range_of_damage > 5 && damage < 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Builder_Of_Player_Characteristics : public Builder_Of_Player
{
	Characteristics_Of_Player* current_characteristics;
	void reset(Characteristics_Of_Player* characteristics)
	{
		current_characteristics = characteristics;
	}
	void set_health(int count_health)
	{
		(*current_characteristics).get_health() = std::min(count_health, 50);
	}
	void set_damage(int count_damage)
	{
		(*current_characteristics).get_damage() = std::min(count_damage, 20);
	}
	void set_range(int count_range)
	{
		(*current_characteristics).get_range_of_damage() = std::min(count_range, 10);
	}
	void set_speed(int count_speed)
	{
		(*current_characteristics).get_speed() = std::min(count_speed, 10);
	}
	void set_name()
	{
		std::string name = "";
		int health = (*current_characteristics).get_health();
		int damage = (*current_characteristics).get_damage();
		int range_of_damage = (*current_characteristics).get_range_of_damage();
		int speed = (*current_characteristics).get_speed();
		if (warrior(health, damage, range_of_damage, speed))
		{
			name = "Warrior";
		}
		else if (archer(health, damage, range_of_damage, speed))
		{
			name = "Archer";
		}
		else
		{
			name = "Wizard";
		}
		(*current_characteristics).get_name_of_class() = name;
	}
};

bool more_health(int health, int damage, int range_of_damage, int speed)
{
	return (health >= damage) && (health >= range_of_damage) && (health >= speed);
}
bool more_damage(int health, int damage, int range_of_damage, int speed)
{
	return (damage >= health) && (damage >= range_of_damage) && (damage >= speed);
}
bool more_range_of_damage(int health, int damage, int range_of_damage, int speed)
{
	return (range_of_damage >= health) && (range_of_damage >= damage) && (range_of_damage >= speed);
}

class Builder_Of_Special_Power_Of_Army
{
	Special_Power_Of_Army* current_power;
	void reset(Special_Power_Of_Army* characteristics)
	{
		current_power = characteristics;
	}
	void set_health(int count_health)
	{
		(*current_power).get_health() = std::min(count_health, 20);
	}
	void set_damage(int count_damage)
	{
		(*current_power).get_damage() = std::min(count_damage, 10);
	}
	void set_range(int count_range)
	{
		(*current_power).get_range_of_damage() = std::min(count_range, 5);
	}
	void set_speed(int count_speed)
	{
		(*current_power).get_speed() = std::min(count_speed, 5);
	}
	void set_name()
	{
		std::string name = "";
		int health = (*current_power).get_health();
		int damage = (*current_power).get_damage();
		int range_of_damage = (*current_power).get_range_of_damage();
		int speed = (*current_power).get_speed();
		if (more_health(health, damage, range_of_damage, speed))
		{
			name = "A lot of health";
		}
		else if (more_damage(health, damage, range_of_damage, speed))
		{
			name = "A lot of damage";
		}
		else if (more_range_of_damage(health, damage, range_of_damage, speed))
		{
			name = "A lot of range of damage";
		}
		else
		{
			name = "A lot of speed";
		}
		(*current_power).get_name_of_power() = name;
	}
};


// Builder generate a power
