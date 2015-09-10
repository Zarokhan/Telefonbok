#include <iostream>
#include <map>
#include "register.h"

int main()
{
	std::cout << "Type 'help' for more commands." << std::endl;

	std::map<std::string, Register*> mapReg;

	mapReg["default"] = new Register();
	mapReg["default"]->Add("Simon", "0720065453");
	mapReg["default"]->Add("Simon", "0720065453");
	mapReg["default"]->Add("Simon", "0720065453");

	std::string input = "";
	std::string reg = "";

	while (true)
	{
		input = "";
		std::cin >> input;
		ToLower(input);

		if (input == "printall")
			mapReg["default"]->PrintAll();
		else if (input == "add")
		{
			std::string name = "";
			std::string number = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;
			std::cout << "Number: " << std::endl;
			std::cin >> number;
			system("cls");
			mapReg["default"]->Add(name, number);
		}
		else if (input == "remove")
		{
			std::string name = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;

			mapReg["default"]->Remove(name);
		}
		else if (input == "find")
		{
			std::string name = "";
			std::string number = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;
			std::cout << "Number: " << std::endl;
			std::cin >> number;
			system("cls");
			if (mapReg["default"]->Find(name, number) == nullptr)
				std::cout << "Could not find person!" << std::endl;
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
		else if (input == "addreg")
		{
			std::cout << "Enter name for new register" << std::endl;
			std::string regname = "";
			std::cin >> regname;
			ToLower(regname);
			std::cout << regname << std::endl;
			if (mapReg[regname])
				std::cout << "It already exists!" << std::endl;
			else
			{
				mapReg[regname] = new Register();
				reg = regname;
			}
		}
		else
			std::cout << "Command failed" << std::endl;
	}

	return 0;
}