#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &trap);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &scav);
		void attack(std::string const &target);
		void guardGate();
	private:
		bool _guardGateMode;
};

#endif