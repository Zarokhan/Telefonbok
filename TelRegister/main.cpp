#include <iostream>
#include <algorithm>
#include <string>
#include "register.h"

int main()
{
	std::cout << "command HELP for more commands" << std::endl;

	Register reg;
	reg.Add("Simon", "0720065453");
	reg.Add("Simon", "0720065453");
	reg.Add("Simon", "0720065453");

	std::string input = "";

	while (true)
	{
		input = "";
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input == "printall")
			reg.PrintAll();
		else if (input == "add")
		{
			std::string name = "";
			std::string number = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;
			std::cout << "Number: " << std::endl;
			std::cin >> number;

			reg.Add(name, number);
		}
		else if (input == "remove")
		{
			std::string name = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;

			reg.Remove(name);
		}
		else if (input == "find")
		{
			std::string name = "";
			std::string number = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;
			std::cout << "Number: " << std::endl;
			std::cin >> number;

			if (reg.Find(name, number) == nullptr)
				std::cout << "Could not find person!" << std::endl;
			else
				std::cout << reg.Find(name, number);
		}
		else if (input == "clear")
		{
			system("cls");
		}
		else if (input == "help")
		{
			system("cls");
			std::cout << "Valid commands." << std::endl;
			std::cout << "printall" << std::endl;
			std::cout << "remove" << std::endl;
			std::cout << "find" << std::endl;
			std::cout << "clear" << std::endl;
		}
		else
			std::cout << "Command failed" << std::endl;
	}

	std::cin.get();
	return 0;
}