#include "Notebook.h"
#include <algorithm>

Notebook Notebook::operator+(Notebook& rtemp)
{
	Notebook temp;
	temp.Notes = this->Notes;
	for (int i = 0; i < rtemp.Notes.size(); i++)
	{
		temp.Notes.push_back(rtemp.Notes[i]);
	}
	return temp;
}
Notebook Notebook::operator+(const Note& rtemp)
{
	Notebook temp;
	temp.Notes = this->Notes;
	temp.Notes.push_back(rtemp);
	return temp;
}
Notebook Notebook::operator-(const Notebook& rtemp)
{
	Notebook temp;
	temp.Notes = this->Notes;
	for (int i = 0; i < temp.Notes.size(); i++)
	{
		for (int j = 0; j < rtemp.Notes.size(); j++)
		{
			if (temp.Notes[i] == rtemp.Notes[j])
			{
				temp.Notes.erase(temp.Notes.begin() + i);
				if (i != 0)
				{
					i--;
					break;
				}
				else 
				{
					i = 0;
				}
			}
		}
	}
	return temp;
}
Notebook Notebook::operator-(const Note& rtemp)
{
	Notebook temp;
	temp.Notes = this->Notes;
	for (int i = 0; i < Notes.size(); i++)
	{
		if (temp.Notes[i] == rtemp)
		{
			temp.Notes.erase(temp.Notes.begin() + i);
			break;
		}
	}
	return temp;
}
Notebook Notebook::operator=(const Notebook& temp)
{
	Notes.clear();
	for (int i = 0; i < temp.Notes.size(); i++)
	{
		Notes.push_back(temp.Notes[i]);
	}
	return *this;
}

void Notebook::Sort()
{
	sort(Notes.begin(), Notes.end());
}
void Notebook::SearchLN()
{
	string temp;
	cout << "¬вед≥ть пр≥звище: ";
	cin >> temp;
	for (int i = 0; i < Notes.size(); i++)
	{
		if (temp == Notes[i].getLastName())
		{
			cout << Notes[i] << endl;
		}
	}
}
void Notebook::SearchDate()
{
	Date temp;
	cout << "¬вед≥ть день народженн€: ";
	while (!(cin >> temp.day) || temp.day <= 0 || temp.day > 31)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬вед≥ть день народженн€ правильно:: ";
	}
	cout << "¬вед≥ть м≥с€ць народженн€: ";
	while (!(cin >> temp.month) || temp.month <= 0 || temp.month > 12)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬вед≥ть м≥с€ць народженн€ правильно:: ";
	}
	cout << "¬вед≥ть р≥к народженн€: ";
	while (!(cin >> temp.years) || temp.years <= 1900 || temp.years > 2022)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬вед≥ть р≥к народженн€ правильно:: ";
	}

	for (int i = 0; i < Notes.size(); i++)
	{
		Date temp1 = Notes[i].getDate();
		if (temp.day == temp1.day && temp.month == temp1.month && temp.years == temp1.years)
		{
			cout << Notes[i] << endl;
		}
	}
}