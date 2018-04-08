#include "pch.h"
#include "../TpGame/Army.h"

TEST(soldier_test, my_warrior) 
{
  My_Warrior* warrior = new My_Warrior();
  EXPECT_EQ(warrior->get_health(), 20);
  EXPECT_EQ(warrior->get_damage(), 10);
  EXPECT_EQ(warrior->get_range_of_damage(), 2);
  EXPECT_EQ(warrior->get_speed(), 4);
  warrior->health_decrease(8);
  EXPECT_EQ(warrior->get_health(), 12);
  warrior->health_increase(5);
  EXPECT_EQ(warrior->get_health(), 17);
  EXPECT_EQ(warrior->health_decrease(18), true);
  delete warrior;
}

TEST(soldier_test, my_archer) 
{
	My_Archer* archer = new My_Archer();
	EXPECT_EQ(archer->get_health(), 10);
	EXPECT_EQ(archer->get_damage(), 5);
	EXPECT_EQ(archer->get_range_of_damage(), 12);
	EXPECT_EQ(archer->get_speed(), 9);
	archer->health_decrease(8);
	EXPECT_EQ(archer->get_health(), 2);
	archer->health_increase(5);
	EXPECT_EQ(archer->get_health(), 7);
	EXPECT_EQ(archer->health_decrease(7), true);
	delete archer;
}

TEST(soldier_test, my_wizard) 
{
	My_Wizard* wizard = new My_Wizard();
	EXPECT_EQ(wizard->get_health(), 10);
	EXPECT_EQ(wizard->get_damage(), 8);
	EXPECT_EQ(wizard->get_range_of_damage(), 9);
	EXPECT_EQ(wizard->get_speed(), 9);
	wizard->health_decrease(8);
	EXPECT_EQ(wizard->get_health(), 2);
	wizard->health_increase(5);
	EXPECT_EQ(wizard->get_health(), 7);
	EXPECT_EQ(wizard->health_decrease(18), true);
	delete wizard;
}

TEST(soldier_test, enemy_warrior) 
{
	Enemy_Warrior* warrior = new Enemy_Warrior();
	EXPECT_EQ(warrior->get_health(), 22);
	EXPECT_EQ(warrior->get_damage(), 12);
	EXPECT_EQ(warrior->get_range_of_damage(), 4);
	EXPECT_EQ(warrior->get_speed(), 6);
	warrior->health_decrease(8);
	EXPECT_EQ(warrior->get_health(), 14);
	warrior->health_increase(5);
	EXPECT_EQ(warrior->get_health(), 19);
	EXPECT_EQ(warrior->health_decrease(18), false);
	delete warrior;
}

TEST(soldier_test, enemy_archer) 
{
	Enemy_Archer* archer = new Enemy_Archer();
	EXPECT_EQ(archer->get_health(), 12);
	EXPECT_EQ(archer->get_damage(), 7);
	EXPECT_EQ(archer->get_range_of_damage(), 14);
	EXPECT_EQ(archer->get_speed(), 11);
	archer->health_decrease(8);
	EXPECT_EQ(archer->get_health(), 4);
	archer->health_increase(7);
	EXPECT_EQ(archer->get_health(), 11);
	EXPECT_EQ(archer->health_decrease(18), true);
	delete archer;
}

TEST(soldier_test, enemy_wizard) 
{
	Enemy_Wizard* wizard = new Enemy_Wizard();
	EXPECT_EQ(wizard->get_health(), 12);
	EXPECT_EQ(wizard->get_damage(), 10);
	EXPECT_EQ(wizard->get_range_of_damage(), 11);
	EXPECT_EQ(wizard->get_speed(), 11);
	wizard->health_decrease(8);
	EXPECT_EQ(wizard->get_health(), 4);
	wizard->health_increase(5);
	EXPECT_EQ(wizard->get_health(), 9);
	EXPECT_EQ(wizard->health_decrease(18), true);
	delete wizard;
}

TEST(player_test, warrior)
{
	Player* player = new Player;
	Builder_Of_Player_Characteristics* builder = new Builder_Of_Player_Characteristics;
	builder->reset(&(player->characteristics));
	builder->set_health(30);
	builder->set_damage(15);
	builder->set_range_of_damage(4);
	builder->set_speed(6);
	builder->set_name();
	EXPECT_EQ((&(player->characteristics))->get_health(), 30);
	EXPECT_EQ((&(player->characteristics))->get_damage(), 15);
	EXPECT_EQ((&(player->characteristics))->get_range_of_damage(), 4);
	EXPECT_EQ((&(player->characteristics))->get_speed(), 6);
	EXPECT_EQ((&(player->characteristics))->get_name_of_class(), "Warrior");
	delete player;
	delete builder;
}

TEST(player_test, archer)
{
	Player* player = new Player;
	Builder_Of_Player_Characteristics* builder = new Builder_Of_Player_Characteristics;
	builder->reset(&(player->characteristics));
	builder->set_health(15);
	builder->set_damage(8);
	builder->set_range_of_damage(10);
	builder->set_speed(9);
	builder->set_name();
	EXPECT_EQ((&(player->characteristics))->get_health(), 15);
	EXPECT_EQ((&(player->characteristics))->get_damage(), 8);
	EXPECT_EQ((&(player->characteristics))->get_range_of_damage(), 10);
	EXPECT_EQ((&(player->characteristics))->get_speed(), 9);
	EXPECT_EQ((&(player->characteristics))->get_name_of_class(), "Archer");
	delete player;
	delete builder;
}

TEST(player_test, wizard)
{
	Player* player = new Player;
	Builder_Of_Player_Characteristics* builder = new Builder_Of_Player_Characteristics;
	builder->reset(&(player->characteristics));
	builder->set_health(30);
	builder->set_damage(12);
	builder->set_range_of_damage(6);
	builder->set_speed(6);
	builder->set_name();
	EXPECT_EQ((&(player->characteristics))->get_health(), 30);
	EXPECT_EQ((&(player->characteristics))->get_damage(), 12);
	EXPECT_EQ((&(player->characteristics))->get_range_of_damage(), 6);
	EXPECT_EQ((&(player->characteristics))->get_speed(), 6);
	EXPECT_EQ((&(player->characteristics))->get_name_of_class(), "Wizard");
	delete player;
	delete builder;
}

TEST(player_test, health)
{
	Player* player = new Player;
	Builder_Of_Special_Power_Of_Army* builder = new Builder_Of_Special_Power_Of_Army;
	builder->reset(&(player->power));
	builder->set_health(18);
	builder->set_damage(10);
	builder->set_range_of_damage(4);
	builder->set_speed(5);
	builder->set_name();
	EXPECT_EQ((&(player->power))->get_health(), 18);
	EXPECT_EQ((&(player->power))->get_damage(), 10);
	EXPECT_EQ((&(player->power))->get_range_of_damage(), 4);
	EXPECT_EQ((&(player->power))->get_speed(), 5);
	EXPECT_EQ((&(player->power))->get_name_of_power(), "A lot of health");
	delete player;
	delete builder;
}

TEST(player_test, damage)
{
	Player* player = new Player;
	Builder_Of_Special_Power_Of_Army* builder = new Builder_Of_Special_Power_Of_Army;
	builder->reset(&(player->power));
	builder->set_health(8);
	builder->set_damage(10);
	builder->set_range_of_damage(4);
	builder->set_speed(5);
	builder->set_name();
	EXPECT_EQ((&(player->power))->get_health(), 8);
	EXPECT_EQ((&(player->power))->get_damage(), 10);
	EXPECT_EQ((&(player->power))->get_range_of_damage(), 4);
	EXPECT_EQ((&(player->power))->get_speed(), 5);
	EXPECT_EQ((&(player->power))->get_name_of_power(), "A lot of damage");
	delete player;
	delete builder;
}

TEST(army_test, my_army)
{
	Player* player = new Player;
	Builder_Of_Special_Power_Of_Army* builder = new Builder_Of_Special_Power_Of_Army;
	builder->reset(&(player->power));
	builder->set_health(5);
	builder->set_damage(3);
	builder->set_range_of_damage(2);
	builder->set_speed(3);
	builder->set_name();
	My_Army* army = new My_Army;
	My_Army_Factory* factory = new My_Army_Factory;
	(army->army_warrior).push_back(factory->create_warrior_with_power(&(player->power)));
	(army->army_warrior).push_back(factory->create_warrior());
	(army->army_warrior).push_back(factory->create_warrior_with_power(&(player->power)));
	(army->army_archer).push_back(factory->create_archer_with_power(&(player->power)));
	(army->army_archer).push_back(factory->create_archer());
	(army->army_wizard).push_back(factory->create_wizard_with_power(&(player->power)));
	EXPECT_EQ(army->army_warrior[1]->get_health(), 20);
	EXPECT_EQ(army->army_warrior[2]->get_health(), 25);
	EXPECT_EQ(army->army_archer[0]->get_damage(), 8);
	EXPECT_EQ(army->army_archer[1]->get_damage(), 5);
	EXPECT_EQ(army->army_wizard[0]->get_speed(), 12);
	EXPECT_EQ(army->count_of_warriors(), 3);
	EXPECT_EQ(army->count_of_archers(), 2);
	EXPECT_EQ(army->count_of_wizards(), 1);
	EXPECT_EQ(army->count_of_soldiers(), 6);
	delete army;
	delete factory;
	delete player;
}

TEST(army_test, enemy_army)
{
	Enemy_Army* army = new Enemy_Army;
	Enemy_Army_Factory* factory = new Enemy_Army_Factory;
	(army->army_warrior).push_back(factory->create_warrior());
	(army->army_warrior).push_back(factory->create_warrior());
	(army->army_warrior).push_back(factory->create_warrior());
	(army->army_archer).push_back(factory->create_archer());
	(army->army_archer).push_back(factory->create_archer());
	(army->army_wizard).push_back(factory->create_wizard());
	EXPECT_EQ(army->army_warrior[0]->get_health(), 22);
	EXPECT_EQ(army->army_warrior[1]->get_health(), 22);
	EXPECT_EQ(army->army_warrior[2]->get_health(), 22);
	EXPECT_EQ(army->army_archer[0]->get_damage(), 7);
	EXPECT_EQ(army->army_archer[1]->get_damage(), 7);
	EXPECT_EQ(army->army_wizard[0]->get_speed(), 11);
	EXPECT_EQ(army->count_of_warriors(), 3);
	EXPECT_EQ(army->count_of_archers(), 2);
	EXPECT_EQ(army->count_of_wizards(), 1);
	EXPECT_EQ(army->count_of_soldiers(), 6);
	delete army;
	delete factory;
}