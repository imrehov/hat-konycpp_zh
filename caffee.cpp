#include "caffee.h"
#include <algorithm>
#include <numeric>

Caffee::Caffee(const std::string& filename) :
	availableCoffees{ ParseFrom(filename) }
{
}

const Coffee* Caffee::FindCoffee(const std::string& name) const {
	const auto cit = std::find_if(availableCoffees.cbegin(), availableCoffees.cend(), [&](const auto& ac)
		{
			return name == ac.name;
		});

	if (cit != availableCoffees.cend()) {
		return &(*cit);
	}
	return nullptr;
}

bool Caffee::IsValid(const Order& o) const {
	for (const auto& c : o.getCoffeeNames())
	{
		if (!Caffee::FindCoffee(c))
			return false;
	}
	return true;
}

float Caffee::CalculatePrice(const Order& o) const {
	float result{};

	for (const auto& c : o.getCoffeeNames())
	{
		if (const auto cof = FindCoffee(c))
		{
			result += cof->price;
		}

	}
	return result;
}

int Caffee::TotalCoffeeBeans(const Order& o) const {
	int result{};

	for (const auto& c : o.getCoffeeNames())
	{
		if (const auto cof = FindCoffee(c))
		{
			result += cof->grams;
		}
	}
	return result;
}

std::map<MugSize, size_t> Caffee::RequiredMugs(const Order& o) const {
	std::map<MugSize, size_t> result{};

	for (const auto& c : o.getCoffeeNames())
	{
		if (const auto cof = FindCoffee(c))
		{
			++result[cof->mugSize];
		}
	}

	return result;
}

std::vector<MakingType> Caffee::GetMakings(const Order& o) const {
	std::vector<MakingType> result{};

	for (const auto& c : o.getCoffeeNames())
	{
		if (const auto cof = FindCoffee(c))
		{
			if (!std::any_of(result.begin(), result.end(), [&cof](const auto& item)
				{
					return cof->makingType == item;
				}))
				result.push_back(cof->makingType);
		}
	}

	return result;
}

bool Caffee::NeedsWhippedCream(const Order& o) const 
{
	for (const auto& c : o.getCoffeeNames())
	{
		if (const auto& cof = FindCoffee(c)) {
			
			if (cof->milkType == MilkType::WhippedCream)
				return true;
		}
	}

	return false;
}