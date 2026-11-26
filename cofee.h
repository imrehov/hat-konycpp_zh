#pragma once
#include "mugsize.h"
#include "makingtype.h"
#include "milktype.h"


struct Coffee {
	const float price;
	const std::string name;
	const MakingType makingType;
	const int grams;
	const MilkType milkType;
	const MugSize mugSize;

	explicit Coffee(
		float price,
		const std::string& name="Espresso",
		const MakingType& makingType=MakingType::HighPressure,
		int grams=15,
		const MilkType& milkType=MilkType::None,
		const MugSize& mugSize=MugSize::Small
	);

	const Coffee Parse(const std::string& s);
};