/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:36:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 17:48:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		TargetGenerator(const TargetGenerator &oteher);
		TargetGenerator &operator=(const TargetGenerator &other);

		std::map<std::string, ATarget *> _target_array;

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *atarget_ptr);
		void forgetTargetType(std::string const &target_name);
		ATarget* createTarget(std::string const &target_name);
};

#endif