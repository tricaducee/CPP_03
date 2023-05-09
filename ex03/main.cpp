#include "DiamondTrap.hpp"

int main()
{
	std::string names[10] = {"Jean-Eude", "Jean-Pierre", "Jean-Claude", "Jean-Paul", "Jean-Jacques", "Titouan", "Jean-Edouard", "Jean-Philippe", "Jean-Marc", "Jean-CroisPasMesYeux"};
	DiamondTrap diamond;
	//diamond.printAllClassValue();
	std::cout << "diamond " << diamond.getName() << " has " << diamond.getHitPoints() << " hit points, " << diamond.getEnergyPoints() << " energy points and " << diamond.getAttackDamage() << " attack damage" << std::endl;
	diamond.guardGate();
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.attack("Jean-Michel");
	diamond.takeDamage(50);
	diamond.beRepaired(50);
	return 0;
}
