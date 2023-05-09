#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guardGateMode(false)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGateMode(false)
{
	std::cout << "ScavTrap constructor called with the name : " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &trap) : ClapTrap(trap)
{
	std::cout << "ScavTrap copy constructor called with the name : " << this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for : " << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scav)
{
	std::cout << "ScavTrap assignation operator called from " << scav.getName() << std::endl;
	if (this != &scav)
	{
		this->_name = scav.getName();
		this->_hitPoints = scav.getHitPoints();
		this->_energyPoints = scav.getEnergyPoints();
		this->_attackDamage = scav.getAttackDamage();
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack because he's dead" << std::endl;
		return ;
	} else if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't attack because he has no energy points left" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	--this->_energyPoints;
	std::cout << "He have " << this->_energyPoints << " energy points left!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_guardGateMode)
	{
		this->_guardGateMode = false;
		std::cout << "ScavTrap " << this->_name << " is out of Gate keeper mode" << std::endl;
	} else {
		this->_guardGateMode = true;
		std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
	}
}