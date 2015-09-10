#pragma once
#include <algorithm>
#include <iostream>
#include "contact.h"

#define DEFAULT_SIZE 2

class Register
{
private:
	Contact** contacts;
	unsigned int size;
	unsigned int count;
public:
	Register();
	~Register();
	void Add(const std::string& name, const std::string& number);
	Contact* Find(const std::string& name, const std::string& number);
	void Remove(Contact* contact);
	void PrintAll() const;
};