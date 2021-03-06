#include "contact.h"

Contact::Contact() { }

Contact::Contact(const std::string& name, const std::string& number) : name(name), number(number)
{
	std::cout << *this << " added" << std::endl;
}

Contact::~Contact()
{
	std::cout << *this << " deleted" << std::endl;
}

// << operator assignment
std::ostream& operator << (std::ostream& os, const Contact& contact)
{
	return os << contact.name << " - " << contact.number;
}