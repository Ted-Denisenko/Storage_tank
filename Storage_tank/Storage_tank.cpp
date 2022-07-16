#include <iostream>

// Необходимо реализовать ввод через консоль уровня содержимого резервуара в мм.
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