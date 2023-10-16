#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#define ENTER 13

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������
// ��������� ������ � ����� x,y 
void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // �������� ��������� �������
	structCursorInfo.dwSize = size;   // �������� ������ �������
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}


int main() {

	SetConsoleTitle(L"����� ����");
	system("CLS");
	setlocale(0, "rus");
	ConsoleCursorVisible(false, 100);
	string Menu[] = { "�����������", "�������� ����������", "������� ����������", "���������", "�����"};
	int active_menu = 0;

	char ch;
	while (true)
	{
		int x = 52, y = 13;
		
		for (int i = 0; i < size(Menu); i++)
	{
		GoToXY(x, y);
		if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		else 	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
		GoToXY(x, y++);
		cout << Menu[i] << endl;
	}
		

		ch = _getch();
		if (ch == -32) ch = _getch(); // ����������� ���������
		GoToXY(50, 13);
		switch (ch)
		{
		case 27:
			exit(0);
		case 72:
			if (active_menu > 0)
				--active_menu;
			break;
		case 80:
			if (active_menu < size(Menu)-1)
				++active_menu;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				GoToXY(50, 13);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				system("start C:/Windows/System32/calc.exe");
				system("CLS");
				break;
			case 1:
				system("CLS");
				GoToXY(50, 13);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				system("start C:/Windows/System32/osk.exe");
				system("CLS");
				break;
			case 2:
				system("CLS");
				GoToXY(50, 13);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				system("start C:/Windows/System32/WSReset.exe");
				system("CLS");
				break;
			case 3:
				system("CLS");
				GoToXY(47, 14);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_INTENSITY);
				SetConsoleTitle(L"���������");
				cout << "��� ������ �� ����� ��������!";
				_getch();
				SetConsoleTitle(L"����� ����");
				system("CLS");
				break;
			case 4:
				exit(0);
			}
			break;
		}
	}
	return 0;
}