#include "register.h"
#include <algorithm>
#include <iostream>

Register::Register() : count(0), size(DEFAULT_SIZE)
{
	contacts = new Contact*[size];

	// Assign all to null pointers
	for (unsigned int i = 0; i < size; i++)
		contacts[i] = nullptr;
}

void Register::Add(const std::string& name, const std::string& number)
{
	if (count == size)
	{
		std::cout << "Register full. ALLOCATING NEW MEMORY" << std::endl;

		unsigned int newSize = size * 2;
		Contact** newContacts = new Contact*[newSize];
		for (int i = 0; i < newSize; i++)
		{
			if (i < size)
			{
				newContacts[i] = contacts[i];
				continue;
			}
			newContacts[i] = nullptr;
		}

		size = newSize;
		contacts = newContacts;
	}

	// Find empty slot
	for (int i = 0; i < size; i++)
	{
		if (contacts[i] == nullptr)
		{
			contacts[i] = new Contact(name, number);
			count++;
			return;
		}
	}
}

Contact* Register::Find(const std::string& name, const std::string& number)
{
	std::string temp1 = name;
	std::transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	std::string temp2 = "";

	for (int i = 0; i < size; i++)
	{
		if (contacts[i] == nullptr)
			continue;

		temp2 = contacts[i]->name;
		std::transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);

		if (temp1 == temp2 || contacts[i]->number == number)
		{
			std::cout << "Contact found: " << *contacts[i] << std::endl;
			return contacts[i];

		}
	}
	return nullptr;
}

void Register::Remove(const std::string& name)
{
	if (count == 0)
	{
		std::cout << "Register is empty!" << std::endl;
		return;
	}

	std::string temp1 = name;
	std::transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	std::string temp2 = "";

	for (int i = 0; i < size; i++)
	{
		if (contacts[i] == nullptr)
			continue;

		temp2 = contacts[i]->name;
		std::transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);

		if (temp1 == temp2)
		{
			delete contacts[i];
			contacts[i] = nullptr;
			count--;
			return;
		}
	}
}

void Register::PrintAll() const
{
	for (int i = 0; i < size; i++)
	{
		if (contacts[i] != nullptr)
			std::cout << *contacts[i] << std::endl;
	}
	std::cout << "All contacts printed." << std::endl;
}

Register::~Register()
{
	delete[] contacts;
	for (int i = 0; i < size; i++)
		contacts[i] = nullptr;
}