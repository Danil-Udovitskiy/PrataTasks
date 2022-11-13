// Listings 12.1 -12.3 (for task 1).cpp 

#include <iostream>
#include <cstring>



// Листинг 12.1.strngbad.h

class StringBad
{
private:

	char* str; // указатель на строку 
	int len; // длина строки 
	static int num_strings; // количество объектов 

public:
	//static int num_strings; // количество объектов 
	
	StringBad(); // конструктор по умолчанию
	StringBad(const char* s); // конструктор 
	~StringBad(); //деструктор 

	// Дружественная функция 
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);


	StringBad(const StringBad&);        //прототип конструктора копии
	StringBad& operator= (const StringBad&); //прототип перегрузки операции присваивания
	
};



// Листинг 12.2.strngbad.cpp
#include <cstring> // в некоторых случаях — string.h 

using std::cout;
// Инициализация статического члена класса 
int StringBad::num_strings = 0;
// Методы класса 
// Создание StringBad из С-строки 

StringBad::StringBad(const char* s)
{

	len = std::strlen(s);
	str = new char[len + 1];        //+1 нужен  для нуль-символа, признака конца строки
	strcpy_s(str, strlen(s) + 1, s);  //создаём строку на основании значения параметра
	str[len] = '\0';                //на всякий случай, если строка будет слишком большой, насильно перепишем последний символ, если вдруг конца в строке не окажется

	num_strings++;       //наращиваем счётчик объектов

	cout << num_strings << " : " << str << " object created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char [len];

	//char words[10] = "C++";

	strcpy_s(str, strlen("C++") + 1, "C++");

	num_strings++;
	cout << num_strings << " : \"" << str
		<< "\" default object created\n";
}


StringBad:: ~StringBad()
{
	cout << str << " object deleted ";
	--num_strings;
	cout << num_strings << " left\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}


StringBad::StringBad(const StringBad& object) {
	len = object.len;                       //скопировали длину строки из вошедшего в параметр конструктора ззначения
	str = new char[len + 1];                //в каждом конструкторе нужно выделять памяти, чтобы хватило на строку
	strcpy_s(str, strlen(object.str) + 1, object.str);               //копируем в выделенную область памяти значения из другой области памяти
	
	++num_strings;                          //не забываем, что сейчас мы ведём учёт объектов, в кждом конструкторе надо учитывать
}


StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st) // присваивание объекта самому себе 
		return *this; // все готово 
	delete[] str; // освобождение старой строки 
	len = st.len;
	str = new char[len + 1]; // выделение памяти для новой строки 
	strcpy_s(str, strlen(st.str) + 1, st.str); // копирование строки 
	return *this; // возврат ссылки на вызывающий объект 
}


void callme1(StringBad& rsb);
void callme2(StringBad sb);

int main()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		StringBad headlinel( " Celery Stalks at Midnight ");
		StringBad headline2(" Lettuce Prey ");
		StringBad sports(" Spinach Leaves Bowl for Dollars ");
		cout << "headlinel: " << headlinel << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;

		callme1(headlinel);
		cout << "headlinel: " << headlinel << endl;

		callme2(headline2);
		cout << "headline2: " << headline2 << endl;
		
		cout << "\nInitialize one object to another:\n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		
		cout << "\nAssign one object to another:\n";
		StringBad knot;
		knot = headlinel;
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";
	return 0;
}


void callme1(StringBad& rsb)
{
	cout << "\nString passed by reference:\n"; // строка, переданная по ссылке 
	cout << rsb << "\n";
}

void callme2(StringBad sb)
{
	cout << "\nString passed by value:\n"; // строка, переданная по значению 
	cout << sb << "\n";
}



