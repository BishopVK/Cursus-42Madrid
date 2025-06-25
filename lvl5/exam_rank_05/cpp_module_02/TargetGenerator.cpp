/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:44:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 17:50:55 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = _target_array.begin();
	std::map<std::string, ATarget *>::iterator it_end = _target_array.begin();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->_target_array.clear();
}

void	TargetGenerator::learnTargetType(ATarget *atarget_ptr)
{
	if (atarget_ptr)
		_target_array.insert(std::pair<const std::string, ATarget *>(atarget_ptr->getType(), atarget_ptr->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &target_name)
{
	std::map<std::string, ATarget *>::iterator it = _target_array.find(target_name);
	if (it != _target_array.end())
		delete it->second;
	_target_array.erase(target_name);
}

ATarget*	TargetGenerator::createTarget(std::string const &target_name)
{
	std::map<std::string, ATarget *>::iterator it = _target_array.find(target_name);
	if (it != _target_array.end())
		return it->second->clone();
	return NULL;
}
