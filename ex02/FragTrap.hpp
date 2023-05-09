#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &trap);
		~FragTrap();
		FragTrap &operator=(FragTrap const &frag);
		//void attack(std::string const &target);
		void highFivesGuys();
};

#endif