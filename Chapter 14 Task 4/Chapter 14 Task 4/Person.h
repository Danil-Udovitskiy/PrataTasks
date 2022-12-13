#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	std::string second_name;


public:
	Person();
	Person(const std::string n, const std::string s_n);
	virtual ~Person();
	virtual void Show();

};




class Gunslinger : virtual public Person
{
private:
	int number_of_notches_on_rifle; // количество насечек на винтовке
	double combat_readiness_time; // время боевой готовности снайпера

public:
	Gunslinger();
	Gunslinger(const std::string n, const std::string s_n, int notches_on_rifle, double readiness_time);
	~Gunslinger();
	double Draw();
	virtual void Show();

};




class PokerPlayer : virtual public Person
{
public:
	PokerPlayer();
	PokerPlayer(const std::string n, const std::string s_n) : Person(n, s_n) {};
	
	~PokerPlayer();
	unsigned int Draw();  // возвращает случайное число 1-52 (значение карты)
	void Show();

};





