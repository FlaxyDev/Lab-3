#include "Notebook.h"
#include "windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Notebook t1;
	cin >> t1;
	cout << t1;
	t1.Sort();
	cout << "ϳ��� ����������: "<< endl;
	cout << t1;
	
	cout << "����� �� ��������: " << endl;
	t1.SearchLN();

	cout << "����� �� �����: " << endl;
	t1.SearchDate();

	system("pause");
	return 0;
}