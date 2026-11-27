#pragma once
#include <vector>
#include <string>

class Order {
public:

	Order(const std::vector<std::string>& coffeenames);

	const std::vector<std::string>& getCoffeeNames() const;
	
private:
	std::vector<std::string> coffeeNames;
};