#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called with the name : " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &trap) : ClapTrap(trap)
{
	std::cout << "FragTrap copy constructor called with the name : " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for : " << this->_name << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &frag)
{
	std::cout << "FragTrap assignation operator called from " << frag.getName() << std::endl;
	if (this != &frag)
	{
		this->_name = frag.getName();
		this->_hitPoints = frag.getHitPoints();
		this->_energyPoints = frag.getEnergyPoints();
		this->_attackDamage = frag.getAttackDamage();
	}
	return *this;
}

// void FragTrap::attack(std::string const &target)
// {
// 	if (this->_hitPoints == 0)
// 	{
// 		std::cout << "FragTrap " << this->_name << " can't attack because he's dead" << std::endl;
// 		return ;
// 	} else if (this->_energyPoints == 0) {
// 		std::cout << "FragTrap " << this->_name << " can't attack because he has no energy points left" << std::endl;
// 		return ;
// 	}
// 	std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
// 	--this->_energyPoints;
// 	std::cout << "He have " << this->_energyPoints << " energy points left!" << std::endl;
// }

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " is asking for a high five... ... .........." << std::endl;
}
