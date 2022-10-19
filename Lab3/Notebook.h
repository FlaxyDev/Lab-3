#pragma once
#include "Note.h"
#include <vector>
class Notebook
{
private:
	vector<Note> Notes;
public:
	Notebook() {}
	~Notebook() { Notes.clear(); }
	Notebook operator+(Notebook& temp);
	Notebook operator+(const Note& temp);
	Notebook operator-(const Notebook& temp);
	Notebook operator-(const Note& temp);
	Notebook operator=(const Notebook& temp);
	void Sort();
	void SearchLN();
	void SearchDate();
	friend ostream& operator<<(ostream& os, const Notebook& temp)
	{
		if (temp.Notes.size() == 0)
		{
			os << "Записник пустий!" << endl;
		}
		else
		{
			for (int i = 0; i < temp.Notes.size(); i++)
			{
				os << temp.Notes[i] << endl;
			}
		}	
		return os;
	}
	friend istream& operator >>(istream& is, Notebook& temp)
	{
		int tempCount;
		cout << "Введіть кількість записів: ";
		is >> tempCount;
		Note temp1;
		for (int i = 0; i < tempCount; i++)
		{
			is >> temp1;
			temp.Notes.push_back(temp1);
		}
		return is;
	}
};

