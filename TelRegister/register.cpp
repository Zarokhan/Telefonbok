#include <algorithm>
#include <iostream>
#include "register.h"

Register::Register() : count(0), size(DEFAULT_SIZE)
{
	contacts = new Contact*[size];

	// Assign all contacts to null pointers
	for (unsigned int i = 0; i < size; i++)
		contacts[i] = nullptr;
}

// Adds a contact to the register
void Register::Add(const std::string& name, const std::string& number)
{
	// Making array 
	if (count == size)
	{
		std::cout << "Register is full, ALLOCATING NEW MEMORY!" << std::endl;

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

// Finds a contact by name or number
Contact* Register::Find(const std::string& name, const std::string& number)
{
	std::string temp1 = name;
	ToLower(temp1);
	std::string temp2 = "";

	for (int i = 0; i < size; i++)
	{
		if (contacts[i] == nullptr)
			continue;

		temp2 = contacts[i]->name;
		ToLower(temp2);

		if (temp1 == temp2 || contacts[i]->number == number)
		{
			std::cout << "Contact found: " << *contacts[i] << std::endl;
			return contacts[i];
		}
	}
	return nullptr;
}

// Removes contact by name
void Register::Remove(const std::string& name)
{
	if (count == 0)
	{
		std::cout << "Register is empty!" << std::endl;
		return;
	}

	std::string temp1 = name;
	ToLower(temp1);
	std::string temp2 = "";

	for (int i = 0; i < size; i++)
	{
		if (contacts[i] == nullptr)
			continue;

		temp2 = contacts[i]->name;
		ToLower(temp2);

		if (temp1 == temp2)
		{
			delete contacts[i];
			contacts[i] = nullptr;
			count--;
			return;
		}
	}
}

// Prints all contacts in register
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
}