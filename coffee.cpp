#include "cofee.h"

Coffee::Coffee(
	float price,
	const std::string& name,
	const MakingType& makingType,
	int grams,
	const MilkType& milkType,
	const MugSize& mugSize
) :
	price{ price },
	name{ name },
	makingType{ makingType },
	grams{ grams },
	milkType{ milkType },
	mugSize{ mugSize }
{}

const Coffee Coffee::Parse(const std::string& s) {

}