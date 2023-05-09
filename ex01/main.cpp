#include "ScavTrap.hpp"

int main()
{
	std::string names[10] = {"Jean-Eude", "Jean-Pierre", "Jean-Claude", "Jean-Paul", "Jean-Jacques", "Titouan", "Jean-Edouard", "Jean-Philippe", "Jean-Marc", "Jean-CroisPasMesYeux"};
	ScavTrap scav;
	ScavTrap scav2("Paul");
	ScavTrap scav3;
	ScavTrap scav4(scav);
	scav3 = scav2;
	scav.attack("Jean-Michel");
	scav.takeDamage(50);
	scav.beRepaired(50);
	for (int i = 0; i < 10; i++)
		scav.attack(names[i]);
	scav.beRepaired(5);
	scav3.takeDamage(110);
	scav3.attack("Titouan");
	scav3.beRepaired(5);
	scav3.takeDamage(1);
	scav2.guardGate();
	scav2.guardGate();
	std::cout << "scav4 " << scav4.getName() << " has " << scav4.getHitPoints() << " hit points, " << scav4.getEnergyPoints() << " energy points and " << scav4.getAttackDamage() << " attack damage" << std::endl;
	return 0;
}
