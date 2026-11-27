#pragma once
#include "mugsize.h"
#include "makingtype.h"
#include "milktype.h"

#include <vector>


struct Coffee {
	 float price;
	 std::string name;
	 MakingType makingType;
	 int grams;
	 MilkType milkType;
	 MugSize mugSize;

	Coffee(
		float price,
		const std::string& name="Espresso",
		const MakingType makingType=MakingType::HighPressure,
		int grams=15,
		const MilkType milkType=MilkType::None,
		const MugSize mugSize=MugSize::Small
	);

	static Coffee Parse(const std::string& s);

	Coffee() = default;

};

std::vector<Coffee> ParseFrom(const std::string& filename);