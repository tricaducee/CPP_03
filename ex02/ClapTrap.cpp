#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Jean-Clap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called with the name : " << name << std::endl;
}

// ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
// {
// 	std::cout << "ClapTrap constructor called with the name : " << name << std::endl;
// }

ClapTrap::ClapTrap(ClapTrap const &trap) : _name(trap.getName()), _hitPoints(trap.getHitPoints()), _energyPoints(trap.getEnergyPoints()), _attackDamage(trap.getAttackDamage())
{
	std::cout << "ClapTrap copy constructor called with the name : " << this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for : " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clap)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &clap)
	{
		this->_name = clap.getName();
		this->_hitPoints = clap.getHitPoints();
		this->_energyPoints = clap.getEnergyPoints();
		this->_attackDamage = clap.getAttackDamage();
	}
	return *this;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " can't attack because he's dead" << std::endl;
		return ;
	} else if (this->_energyPoints == 0) {
		std::cout << this->_name << " can't attack because he has no energy points left" << std::endl;
		return ;
	}
	std::cout << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	--this->_energyPoints;
	std::cout << "He have " << this->_energyPoints << " energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " can't take damage because he's dead" << std::endl;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " points of damage! ";
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
		std::cout << "He's dead" << std::endl;
	} else {
		std::cout << "He have " << this->_hitPoints << " hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " can't be repaired because he's dead" << std::endl;
		return ;
	} else if (this->_energyPoints == 0) {
		std::cout << this->_name << " can't be repaired because he has no energy points left" << std::endl;
		return ;
	}
	std::cout << this->_name << " is repaired for " << amount << " points of damage! ";
	this->_hitPoints += amount;
	std::cout << "He have " << this->_hitPoints << " hit points left!" << std::endl;
	--this->_energyPoints;
	std::cout << "He have " << this->_energyPoints << " energy points left!" << std::endl;
}