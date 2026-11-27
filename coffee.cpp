#include "coffee.h"
#include <sstream>
#include <limits>
#include <fstream>

Coffee::Coffee(
	float price,
	const std::string& name,
	const MakingType makingType,
	int grams,
	const MilkType milkType,
	const MugSize mugSize
) :
	price{ price },
	name{ name },
	makingType{ makingType },
	grams{ grams },
	milkType{ milkType },
	mugSize{ mugSize }
{}

Coffee Coffee::Parse(const std::string& s) {
	std::stringstream ss(s);
	std::string nameToken, priceToken, makingTypeToken, gramsToken, milkTypeToken, mugSizeToken;

	if (!std::getline(ss, nameToken, ',') ||
		!std::getline(ss, priceToken, ',') ||
		!std::getline(ss, makingTypeToken, ',') ||
		!std::getline(ss, gramsToken, ',') ||
		!std::getline(ss, milkTypeToken, ',') ||
		!std::getline(ss, mugSizeToken, ','))
		throw std::invalid_argument("Invalid input data");

	ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	float price = std::stof(priceToken);
	int grams = std::stoi(gramsToken);
	MakingType makingType = toMakingType(makingTypeToken);
	MilkType milkType = toMilkType(milkTypeToken);
	MugSize mugSize = toMugSize(mugSizeToken);

	return Coffee(price, nameToken, makingType, grams, milkType, mugSize);
}

std::vector<Coffee> ParseFrom(const std::string& filename) {

	std::ifstream fs(filename, std::ios::in);
	if (!fs.is_open())
		throw std::invalid_argument("File does not exist");
	std::vector<Coffee> result{};
	
	std::string line;
	while (std::getline(fs, line)) {
		try 
		{
			result.push_back(Coffee::Parse(line));
		}
		catch (...)
		{

		}
	}
	
	return result;
	
}