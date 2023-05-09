#ifndef DIMONDTRAP_HPP
# define DIMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &trap);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &trap);
		void attack(std::string const &target);
		void whoAmI() const;
		std::string getName() const;
		//void printAllClassValue() const;
	private:
		std::string _name;
};

#endif