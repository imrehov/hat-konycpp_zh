#include "order.h"

Order::Order(const std::vector<std::string> &coffeenames)
	: coffeeNames{ coffeenames }
{
}

const std::vector<std::string>& Order::getCoffeeNames() const {
	return coffeeNames;
}