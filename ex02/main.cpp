#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::string names[10] = {"Jean-Eude", "Jean-Pierre", "Jean-Claude", "Jean-Paul", "Jean-Jacques", "Titouan", "Jean-Edouard", "Jean-Philippe", "Jean-Marc", "Jean-CroisPasMesYeux"};
	FragTrap frag;
	FragTrap frag2("Paul");
	FragTrap frag3;
	FragTrap frag4(frag);
	ScavTrap scav("Jean-Eude");
	frag3 = frag2;
	frag.attack("Jean-Michel");
	frag.takeDamage(50);
	frag.beRepaired(50);
	for (int i = 0; i < 10; i++)
		frag.attack(names[i]);
	frag.beRepaired(5);
	frag3.takeDamage(110);
	frag3.attack("Titouan");
	frag3.beRepaired(5);
	frag3.takeDamage(1);
	frag2.highFivesGuys();
	scav.guardGate();
	scav.guardGate();
	std::cout << "scav" << scav.getName() << " has " << scav.getHitPoints() << " hit points, " << scav.getEnergyPoints() << " energy points and " << scav.getAttackDamage() << " attack damage" << std::endl;
	std::cout << "frag4 " << frag4.getName() << " has " << frag4.getHitPoints() << " hit points, " << frag4.getEnergyPoints() << " energy points and " << frag4.getAttackDamage() << " attack damage" << std::endl;
	return 0;
}
