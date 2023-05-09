#include "ClapTrap.hpp"

int main()
{
	std::string names[10] = {"Jean-Eude", "Jean-Pierre", "Jean-Claude", "Jean-Paul", "Jean-Jacques", "Titouan", "Jean-Edouard", "Jean-Philippe", "Jean-Marc", "Jean-CroisPasMesYeux"};
	ClapTrap clap;
	ClapTrap clap2("Paul");
	ClapTrap clap3;
	ClapTrap clap4(clap);
	clap3 = clap2;
	clap.attack("Jean-Michel");
	clap.takeDamage(5);
	clap.beRepaired(5);
	for (int i = 0; i < 10; i++)
		clap.attack(names[i]);
	clap.beRepaired(5);
	clap3.takeDamage(15);
	clap3.attack("Titouan");
	clap3.beRepaired(5);
	clap3.takeDamage(1);
	return 0;
}
