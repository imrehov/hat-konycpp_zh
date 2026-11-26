#include "milktype.h"
#include <stdexcept>

MilkType toMilkType(const std::string& s) {
	if (s == "None")
		return MilkType::None;
	if (s == "Milk")
		return MilkType::Milk;
	if (s == "MilkFoam")
		return MilkType::MilkFoam;
	if (s == "Cream")
		return MilkType::Cream;
	if (s == "WhippedCream")
		return MilkType::WhippedCream;
	else
		throw std::invalid_argument("Invalid MilkType");
}