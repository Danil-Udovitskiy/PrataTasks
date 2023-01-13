#pragma once

//header file for abstr_emp class and its child classes
#include <iostream> 
#include <string> 
#include <fstream>

class Abstr_emp
{
private:
	std::string fname; // name abstr_emp 
	std::string lname; // last name abstr_emp 
	std::string job;

public:
	Abstr_emp();
	Abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const;	// outputs all data with names
	virtual void SetAll();			// requests values from the user

	friend std::ostream& operator<<(std::ostream& os, const Abstr_emp& e);  // Displays only first and last name

	virtual ~Abstr_emp() = 0; // virtual base class

	//++
	virtual void WriteAll(std::ofstream& fout);
	virtual void ReadAll(std::ifstream& fin);
};


class employee : public Abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();

	//++
	virtual void WriteAll(std::ofstream& fout);
	virtual void ReadAll(std::ifstream& fin);
};



class manager : virtual public Abstr_emp
{
private:
	int inchargeof; // number of managed abstr_emp

protected:
	int InChargeOf() const { return inchargeof; } // cout
	int& InChargeOf() { return inchargeof; } // cin

public:
	manager();
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const Abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();

	//++
	virtual void WriteAll(std::ofstream& fout);
	virtual void ReadAll(std::ifstream& fin);
};



class fink : virtual public Abstr_emp
{
private:
	std::string reportsto; // report to

protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const Abstr_emp& e, const std::string& rpo);
	fink(const fink& e);

	virtual void ShowAll() const;
	virtual void SetAll();

	//++
	virtual void WriteAll(std::ofstream& fout);
	virtual void ReadAll(std::ifstream& fin);
};



class highfink : public manager, public fink // supervision of managers
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const Abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);

	virtual void ShowAll() const;
	virtual void SetAll();

	//++
	virtual void WriteAll(std::ofstream& fout);
	virtual void ReadAll(std::ifstream& fin);
};
