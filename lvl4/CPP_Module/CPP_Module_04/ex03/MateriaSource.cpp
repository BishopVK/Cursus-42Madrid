/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:52:04 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 12:38:24 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GREEN << "MateriaSource Empty Constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_materiaLearned[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << GREEN << "MateriaSource Copy Constructor called" << RESET << std::endl;

	for (int i = 0; i < 4; i++) {
		if (other._materiaLearned[i] != NULL) {
			if (other._materiaLearned[i]->getType() == "ice")
				this->_materiaLearned[i] = new Ice();
			else if (other._materiaLearned[i]->getType() == "cure")
				this->_materiaLearned[i] = new Cure();
			else
				this->_materiaLearned[i] = new Ice(other._materiaLearned[i]->getType());
		} else {
			this->_materiaLearned[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << GREEN << "MateriaSource Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other._materiaLearned[i] != NULL)
			{
				if (other._materiaLearned[i]->getType() == "ice")
					this->_materiaLearned[i] = new Ice();
				else if (other._materiaLearned[i]->getType() == "cure")
					this->_materiaLearned[i] = new Cure();
				else
					this->_materiaLearned[i] = new Ice(other._materiaLearned[i]->getType());
			}
			else
				this->_materiaLearned[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource Destructor called" << RESET << std::endl;

	// Delete Materias Learned
	for (int i = 0; i < 4; i++)
	{
		if (_materiaLearned[i] != NULL)
		{
			delete _materiaLearned[i];
			_materiaLearned[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return ;
	int	i;
	for (i = 0; i < 4; i++)
	{
		if (_materiaLearned[i] == NULL)
		{
			_materiaLearned[i] = m->clone();
			std::cout << "Learned " << m->getType() << " materia recipe" << std::endl;
			break;
		}
	}
	if (i == 4)
		std::cout << "Imposible to learn more than 4 materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i;
	for (i = 0; i < 4; i++)
	{
		if (this->_materiaLearned[i] != NULL)
		{
			if (this->_materiaLearned[i]->getType() == type)
			{
				std::cout << "Materia " << _materiaLearned[i]->getType() << " created" << std::endl;
				return (this->_materiaLearned[i]->clone());
			}
		}
	}
	if (i == 4)
		std::cout << "The materia you want to create has not been learned" << std::endl;
	return NULL;
}

void	MateriaSource::printMateriaLearned()
{
	std::cout << YELLOW << std::endl << "-- MATERIAS LEARNED --" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaLearned[i] != NULL)
			std::cout << "Materia " << i << ": " << this->_materiaLearned[i]->getType() << std::endl;
		else
			std::cout << "Materia " << i << ": it's empty" << std::endl;
	}
}