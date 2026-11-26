#pragma once
#include <string>

enum class MilkType {
	None,
	Milk,
	MilkFoam,
	Cream,
	WhippedCream,
};

MilkType toMilkType(const std::string& s);