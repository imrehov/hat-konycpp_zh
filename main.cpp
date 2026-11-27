#include <iostream>
#include <cassert>
#include <stdexcept>
#include "caffee.h"

int main()
{
    // 1. Nem letező fajl tesztelese (ParseFrom dob-e std::invalid_argument-et)
    try {
        Caffee nonExistent("non_existent_file.txt");
        assert(false && "Nem dobott kivetelt nem letezo fajlra!");
    }
    catch (const std::invalid_argument&) {
        std::cout << "[OK] Nem letezo fajlra sikeresen kivetelt dobott.\n";
    }

    // 2. Kavezo betoltese (benne van egy hibas sor is a test.txt-ben, amit at kell ugrania)
    Caffee caffee("test.txt");
    std::cout << "[OK] Kavezo sikeresen betoltve a test.txt-bol.\n";

    // 3. Ervenyes rendeles tesztelese (Espresso, Melange - tejszinhos, Cappuccino)
    Order validOrder({ "Espresso", "Melange", "Cappuccino", "Espresso" });

    // IsValid
    assert(caffee.IsValid(validOrder) == true);
    std::cout << "[OK] IsValid (ervenyes rendeles): true\n";

    // CalculatePrice (1.99 + 4.20 + 3.50 + 1.99 = 11.68)
    float price = caffee.CalculatePrice(validOrder);
    std::cout << "[OK] CalculatePrice: " << price << " (elvart: ~11.68)\n";

    // TotalCoffeeBeans (15 + 20 + 18 + 15 = 68 g)
    int beans = caffee.TotalCoffeeBeans(validOrder);
    assert(beans == 68);
    std::cout << "[OK] TotalCoffeeBeans: " << beans << " g (elvart: 68 g)\n";

    // NeedsWhippedCream (Melange miatt true)
    assert(caffee.NeedsWhippedCream(validOrder) == true);
    std::cout << "[OK] NeedsWhippedCream: true\n";

    // RequiredMugs (Small: 2, Medium: 1, Large: 1)
    auto mugs = caffee.RequiredMugs(validOrder);
    std::cout << "[OK] RequiredMugs:\n";
    std::cout << "     - Small: " << mugs[MugSize::Small] << " (elvart: 2)\n";
    std::cout << "     - Medium: " << mugs[MugSize::Medium] << " (elvart: 1)\n";
    std::cout << "     - Large: " << mugs[MugSize::Large] << " (elvart: 1)\n";
    assert(mugs[MugSize::Small] == 2);
    assert(mugs[MugSize::Medium] == 1);
    assert(mugs[MugSize::Large] == 1);

    // GetMakings (HighPressure, Filter)
    auto makings = caffee.GetMakings(validOrder);
    std::cout << "[OK] GetMakings meret: " << makings.size() << " (elvart: 2 kulonbozo technika)\n";
    assert(makings.size() == 2);

    // 4. Tejszin nelkuli rendeles tesztelese
    Order noCreamOrder({ "Espresso", "TurkishCoffee" });
    assert(caffee.NeedsWhippedCream(noCreamOrder) == false);
    std::cout << "[OK] NeedsWhippedCream tejszin nelkuli rendelesre: false\n";

    // 5. Ervenytelen kavenév tesztelese
    Order invalidOrder({ "Espresso", "NemLetezoKave" });
    assert(caffee.IsValid(invalidOrder) == false);
    std::cout << "[OK] IsValid nem letezo kavere: false\n";

    std::cout << "\n Minden teszt sikeresen lefutott!\n";
    return 0;
}
