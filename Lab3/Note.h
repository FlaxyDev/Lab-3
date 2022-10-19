#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Date
{
	int day;
	int month;
	int years;
};

class Note
{
private:
	string firstname;
	string lastname;
	string number;
	Date date;
public:
	Note();
	~Note() {}
	void setFirtstName(string tFN);
	void setLastName(string tLN);
	void setNumber(string tNumber);
	void setDate(int tDay, int tMonth, int tYears);
	string getFirstName();
	string getLastName();
	string getNumder();
	Date getDate();
	friend ostream& operator<<(ostream& os, const Note &temp)
	{
		os << "Ім'я і Прізвище: " << temp.firstname << " " << temp.lastname << endl;
		os << "Тел. номер: " << temp.number << endl;
		os << "Дата народження: " << temp.date.day << "/" << temp.date.month << "/" << temp.date.years << endl;
		return os;
	}
	friend istream& operator >>(istream& is, Note &temp)
	{
		cout << "Введіть ім'я: ";
		is >> temp.firstname;
		cout << "Введіть прізвище: ";
		is >> temp.lastname;
		cout << "Введіть номер телефону: ";
		is >> temp.number;
		cout << "Введіть день народження: ";
		while (!(is >> temp.date.day) || temp.date.day <= 0 || temp.date.day > 31)
		{
			is.clear();
			while (is.get() != '\n');
			cout << "Введіть день народження правильно:: ";
		}
		cout << "Введіть місяць народження: ";
		while (!(is >> temp.date.month) || temp.date.month <= 0 || temp.date.month > 12)
		{
			is.clear();
			while (is.get() != '\n');
			cout << "Введіть місяць народження правильно:: ";
		}
		cout << "Введіть рік народження: ";
		while (!(is >> temp.date.years) || temp.date.years <= 1900 || temp.date.years > 2022)
		{
			is.clear();
			while (is.get() != '\n');
			cout << "Введіть рік народження правильно:: ";
		}
		return is;
	}
	friend bool operator==(const Note& ltemp, const Note& rtemp)
	{
		cout << "LTEMP: " << endl;
		cout << ltemp << endl;
		cout << "RTEMP: " << endl;
		cout << rtemp << endl;
		if (ltemp.firstname == rtemp.firstname && ltemp.lastname == rtemp.lastname && ltemp.number == rtemp.number && ltemp.date.day == rtemp.date.day && ltemp.date.month == rtemp.date.month && ltemp.date.years == rtemp.date.years)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend bool operator<(const Note& ltemp, const Note& rtemp)
	{
		if (rtemp.date.years < ltemp.date.years)
		{
			return false;
		}
		else if (rtemp.date.years == ltemp.date.years && rtemp.date.month < ltemp.date.month)
		{
			return false;
		}
		else if (rtemp.date.years == ltemp.date.years && rtemp.date.month == ltemp.date.month && rtemp.date.day < ltemp.date.day)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
	friend bool operator>(const Note& ltemp, const Note& rtemp)
	{
		if (ltemp.date.years < rtemp.date.years)
		{
			return false;
		}
		else if (ltemp.date.years == rtemp.date.years && ltemp.date.month < rtemp.date.month)
		{
			return false;
		}
		else if (ltemp.date.years == rtemp.date.years && ltemp.date.month == rtemp.date.month && ltemp.date.day < rtemp.date.day)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

