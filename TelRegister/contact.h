#pragma once
#include <iostream>
#include <string>

// struct defualt public
struct Contact
{
	std::string name;
	std::string number;

	Contact();
	Contact(const std::string& name, const std::string& number);
	Contact(Contact& contact);
	~Contact();

	friend std::ostream& operator << (std::ostream&, const Contact& contact);
};