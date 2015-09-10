#include <iostream>
#include <map>
#include "register.h"

int main()
{
	std::cout << "Type 'help' for more commands." << std::endl;

	std::map<std::string, Register*> mapReg;

	std::string input = "";
	std::string currentReg = "default";

	mapReg[currentReg] = new Register();

	while (true)
	{
		input = "";
		std::cin >> input;
		ToLower(input);

		if (input == "testcase")
		{
			for (unsigned int i = 0;i < 1000; i++)
			{
				mapReg[currentReg]->Add("Sven Svensson", "07222000324234");
			}
			continue;
		}

		if (input == "help")
		{
			system("cls");
			std::cout << "-Contact commands-" << std::endl;
			std::cout << "printall" << std::endl;
			std::cout << "find" << std::endl;
			std::cout << "add" << std::endl;
			std::cout << "delete\n\n-Register commands-" << std::endl;
			std::cout << "setreg" << std::endl;
			std::cout << "addreg" << std::endl;
			std::cout << "deletereg\n\n-General commands-" << std::endl;
			std::cout << "clear" << std::endl;
			std::cout << "exit" << std::endl;
		}
		else if (input == "exit")
			return 0;
		else if (input == "clear")
		{
			system("cls");
		}
		else if (input == "addreg")
		{
			std::cout << "Enter name for new register" << std::endl;
			std::string regname = "";
			std::cin >> regname;
			ToLower(regname);
			if (mapReg[regname])
			{
				std::cout << "Register: " << regname << " already exist. Setting current register to: " << regname << std::endl;
				currentReg = regname;
			}
			else
			{
				std::cout << "Register: " << regname << " added." << std::endl;
				mapReg[regname] = new Register();
				currentReg = regname;
			}
		}
		else if (input == "deletereg")
		{
			std::cout << "Enter name of register" << std::endl;
			std::string regname = "";
			std::cin >> regname;
			ToLower(regname);
			if (mapReg[regname])
			{
				//std::cout << "Deleting: " << regname << std::endl;
				delete mapReg[regname];
				mapReg[regname] = nullptr;
				mapReg.erase(regname);
				currentReg = "";
			}
			else
				std::cout << "Register: " << regname << " not found." << std::endl;
		}
		else if (input == "setreg")
		{
			std::cout << "Enter name of register" << std::endl;
			std::string regname = "";
			std::cin >> regname;
			ToLower(regname);
			if (mapReg[regname])
			{
				std::cout << "Register set to: " << regname << std::endl;
				currentReg = regname;
			}
			else
				std::cout << "Could not find register: " << regname << std::endl;
		}
		else if (currentReg == "")
		{
			std::cout << "No current register. Please use command 'setreg'." << std::endl;
		}
		else if (input == "printall")
		{
			mapReg[currentReg]->PrintAll();
		}
		else if (input == "add")
		{
			std::string name = "";
			std::string number = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;
			std::cout << "Number: " << std::endl;
			std::cin >> number;
			system("cls");
			mapReg[currentReg]->Add(name, number);
		}
		else if (input == "remove" || input == "delete")
		{
			std::string name = "";
			std::cout << "Name: " << std::endl;
			std::cin >> name;

			mapReg[currentReg]->Remove(mapReg[currentReg]->Find(name, ""));
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
			if (mapReg[currentReg]->Find(name, number) == nullptr)
				std::cout << "Could not find person!" << std::endl;
		}
		else
			std::cout << "Command failed" << std::endl;
	}

	return 0;
}