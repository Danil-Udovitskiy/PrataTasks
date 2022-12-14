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
	virtual void Show()const;

	//+++
	virtual void Get();
	void Set();

};




class Gunslinger : virtual public Person
{
private:
	int number_of_notches_on_rifle; // ���������� ������� �� ��������
	double combat_readiness_time; // ����� ������ ���������� ��������

public:
	Gunslinger();
	Gunslinger(const std::string n, const std::string s_n, int notches_on_rifle, double readiness_time);
	~Gunslinger();
	double Draw()const;
	virtual void Show()const;

	//+++
	virtual void Get();
	void Set();
};




class PokerPlayer : virtual public Person
{
public:
	PokerPlayer();
	PokerPlayer(const std::string n, const std::string s_n) : Person(n, s_n) {};
	
	~PokerPlayer();
	unsigned int Draw()const;  // ���������� ��������� ����� 1-52 (�������� �����)
	void Show()const;

	//+++
	void Set();

};




class BadDude : virtual public Person, virtual public Gunslinger , virtual public PokerPlayer
{
private:

	double weapon_draw_time;

public:
	BadDude();
	BadDude(const std::string n, const std::string s_n, int notches_on_rifle, double readiness_time, double weapon_draw) : Person(n, s_n), Gunslinger(n, s_n, notches_on_rifle, readiness_time), PokerPlayer(n, s_n) { weapon_draw_time = readiness_time; };


	~BadDude();

	double Gdraw()const; // ���������� ����� ��������� ������
	unsigned int Cdraw()const; // ������������ ��������� ��������� �����.

	void Show()const;

	//+++
	void Get();
	void Set();
};










