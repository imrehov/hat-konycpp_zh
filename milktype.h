#pragma once
#include <string>
#include <cstdint>

enum class MilkType : uint8_t {
	None,
	Milk,
	MilkFoam,
	Cream,
	WhippedCream,
};

MilkType toMilkType(const std::string& s);