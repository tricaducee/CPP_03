#include "DiamondTrap.hpp"

/*
Dans l'héritage en diamant les valeurs d'initialisation des attributs sont prise de la classe mere avec les argument donné par l'instance courante.
L'instance courante n'est pas initialisé avec les attribut des classe dérivé dont elle est issue.
Sans initialisation de l'instance courante, les attributs de la classe mere sont initialisé avec les valeurs par defaut et non avec les valeur des dérivé.
Les valeurs d'initialisations de la classe mere par les classe dérivé n'existe pas car il n'y a qu'une seul instance de la classe mere,
toutes les classes dérivé hérite donc des valeurs initialisé par l'instance courante.
Les classes dérivé peuvent avoir leurs propre valeurs d'attribut si ces attribut sont surchargé dans la classe dérivé,
mais l'instance courante hérite des attributs de la classe mere.
Pour acceder aux membres surchargé d'une classe dérivé il faut utiliser la notation :: comme <classe dérivé>::<membre>.
*/
DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(), _name(this->ClapTrap::_name) // l'ordre d'appel des constructeur doit suivre la définition de la classe, on commence par la classe mere puis les classe dérivé dans l'ordre de déclaration.
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->ClapTrap::_name += "_clap_name";
	this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap constructor called with the name : " << name << std::endl;
	this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(DiamondTrap const &trap)
: ClapTrap(trap), ScavTrap(trap), FragTrap(trap), _name(this->ClapTrap::_name)
{
	std::cout << "DiamondTrap copy constructor called with the name : " << this->_name << std::endl;
	this->ClapTrap::_name += "_clap_name";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for : " << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &trap)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &trap)
	{
		this->_name = trap.getName();
		this->ClapTrap::_name = trap.ClapTrap::getName();
		this->_hitPoints = trap.getHitPoints();
		this->_energyPoints = trap.getEnergyPoints();
		this->_attackDamage = trap.getAttackDamage();
	}
	return *this;
}

void DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name : " << this->_name << std::endl;
	std::cout << "ClapTrap name : " << this->ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

// void DiamondTrap::printAllClassValue() const
// {
// 	std::cout << "DiamondTrap name : " << this->_name << std::endl;
// 	std::cout << "ClapTrap name : " << this->ClapTrap::_name << std::endl;
// 	std::cout << "ScavTrap name : " << this->ScavTrap::_name << std::endl;
// 	std::cout << "FragTrap name : " << this->FragTrap::_name << std::endl;
// 	std::cout << "DiamondTrap hit points : " << this->_hitPoints << std::endl;
// 	std::cout << "ClapTrap hit points : " << this->ClapTrap::_hitPoints << std::endl;
// 	std::cout << "ScavTrap hit points : " << this->ScavTrap::_hitPoints << std::endl;
// 	std::cout << "FragTrap hit points : " << this->FragTrap::_hitPoints << std::endl;
// 	std::cout << "DiamondTrap energy points : " << this->_energyPoints << std::endl;
// 	std::cout << "ClapTrap energy points : " << this->ClapTrap::_energyPoints << std::endl;
// 	std::cout << "ScavTrap energy points : " << this->ScavTrap::_energyPoints << std::endl;
// 	std::cout << "FragTrap energy points : " << this->FragTrap::_energyPoints << std::endl;
// 	std::cout << "DiamondTrap attack damage : " << this->_attackDamage << std::endl;
// 	std::cout << "ClapTrap attack damage : " << this->ClapTrap::_attackDamage << std::endl;
// 	std::cout << "ScavTrap attack damage : " << this->ScavTrap::_attackDamage << std::endl;
// 	std::cout << "FragTrap attack damage : " << this->FragTrap::_attackDamage << std::endl;
// }
