#include <iostream>

// ���������� ����������� ���� ����� ������� ������ ����������� ���������� � ��.
int levelInput()
{
	int level;
	std::cout << "Input tank content level (in mm)" << std::endl << "Level = ";
	std::cin >> level;
	return level;
}

int main()
{
	levelInput();
}