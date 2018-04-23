#include <iostream>
#include "Union.h"

class Bonus_For_My_Squad
{
public:
	virtual void use_bonus(My_Squad* my_squad, Enemy_Squad* enemy_squad, int level_bonus) = 0;
};

class Bonus: public Bonus_For_My_Squad
{
private:
	My_Squad* my_squad;
	Enemy_Squad* enemy_squad;
	int level_bonus;
public:
	Bonus(My_Squad* my_squad_, Enemy_Squad* enemy_squad_, int level_bonus_)
	{
		my_squad = my_squad_;
		enemy_squad = enemy_squad_;
		level_bonus = level_bonus_;
	}
	void use_bonus(My_Squad* my_squad, Enemy_Squad* enemy_squad, int level_bonus)
	{
	}
};

class Decorator: public Bonus_For_My_Squad
{
public:
	Bonus_For_My_Squad* bonus;
	Decorator(Bonus_For_My_Squad* bonus_)
	{
		bonus = bonus_;
	}
	void use_bonus(My_Squad* my_squad, Enemy_Squad* enemy_squad, int level_bonus)
	{
		bonus->use_bonus(my_squad, enemy_squad, level_bonus);
	}
};

class Heal_Decorator: public Decorator
{
public:
	Heal_Decorator(Bonus_For_My_Squad* bonus_) : Decorator(bonus_){}
	void use_bonus(My_Squad* my_squad, Enemy_Squad* enemy_squad, int level_bonus)
	{
		Decorator::use_bonus(my_squad, enemy_squad, level_bonus);
		my_squad->health_increase(level_bonus);
	}
};

class Bomb_Decorator: public Decorator
{
public:
	Bomb_Decorator(Bonus_For_My_Squad* bonus_) : Decorator(bonus_){}
	void use_bonus(My_Squad* my_squad, Enemy_Squad* enemy_squad, int level_bonus)
	{
		Decorator::use_bonus(my_squad, enemy_squad, level_bonus);
		enemy_squad->health_decrease(level_bonus);
	}
};

