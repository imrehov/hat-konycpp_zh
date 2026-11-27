#pragma once
#include "coffee.h"
#include "order.h"
#include <map>

class Caffee {
public:

	Caffee(const std::string& filename);

	bool IsValid(const Order& o) const;
	float CalculatePrice(const Order& o) const;
	int TotalCoffeeBeans(const Order& o) const;
	std::map<MugSize, size_t> RequiredMugs(const Order& o) const;
	std::vector<MakingType> GetMakings(const Order& o) const;
	bool NeedsWhippedCream(const Order& o) const;

private:
	std::vector<Coffee> availableCoffees;
	const Coffee* FindCoffee(const std::string& name) const;
};