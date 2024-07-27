#include <string>

std::string	truncate_field(std::string field)
{
	return (field.size() > 10 ? field.substr(0, 9) + '.' : field + std::string(10 - field.size(), ' '));
}


