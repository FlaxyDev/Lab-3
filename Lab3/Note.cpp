#include "Note.h"

Note::Note()
{
	firstname = "Uknown";
	lastname = "Uknown";
	number = "Uknown";
	date.day = date.month = date.years = 0;
}
void Note::setFirtstName(string tFN)
{
	firstname = tFN;
}
void Note::setLastName(string tLN)
{
	lastname = tLN;
}
void Note::setNumber(string tNumber)
{
	number = tNumber;
}
void Note::setDate(int tDay, int tMonth, int tYears)
{
	if (tDay <= 0 || tDay > 31)
	{
		cout << "¬вед≥ть день народженн€ правильно: ";
		while (!(cin >> date.day) || date.day <= 0 || date.day > 31)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "¬вед≥ть день народженн€ правильно:: ";
		}
	}
	else
	{
		date.day = tDay;
	}
	if (tMonth <= 0 || tMonth > 12)
	{
		cout << "¬вед≥ть м≥с€ць народженн€ правильно: ";
		while (!(cin >> date.month) || date.month <= 0 || date.month > 12)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "¬вед≥ть м≥с€ць народженн€ правильно:: ";
		}
	}
	else
	{
		date.month = tMonth;
	}
	if (tYears <= 1900 || tYears > 2022)
	{
		cout << "¬вед≥ть р≥к народженн€ правильно: ";
		while (!(cin >> date.years) || date.years <= 1900 || date.years > 2022)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "¬вед≥ть р≥к народженн€ правильно:: ";
		}
	}
	else
	{
		date.years = tYears;
	}
}
string Note::getFirstName()
{
	return firstname;
}
string Note::getLastName()
{
	return lastname;
}
string Note::getNumder()
{
	return number;
}
Date Note::getDate()
{
	return date;
}
