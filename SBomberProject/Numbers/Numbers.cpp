// Numbers.cpp : Запрашивает два числа и выводит их в порядке возрастания

#include <iostream>

int main()
{
	std::cout << "Enter two numbers: " << std::endl;
	int a = 0, b = 0;
	std::cin >> a >> b;
	if (a > b) {
		int cnt = 0;
		std::cout << "Here is your range from low to high:" << std::endl << "=> ";
		while (a > b) {			
			std::cout << b << ", ";
			b++;
			cnt++;
			if ((cnt % 10) == 0) std::cout << std::endl;
		}
		std::cout << b << ". <=" << std::endl;
	}
	else if (b > a) {
		int cnt = 0;
		std::cout << "Here is your range from low to high:" << std::endl << "=> ";
		while (b > a) {			
			std::cout << a << ", ";
			a++;
			cnt++;
			if ((cnt % 10) == 0) std::cout << std::endl;
		}
		std::cout << a << ". <=" << std::endl;
	}
	else std::cout << std::endl << " =>Oops! The numbers are equal, there is no range...<=";
	return 0;
}


