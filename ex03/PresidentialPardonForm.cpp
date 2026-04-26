/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:01:30 by marvin            #+#    #+#             */
/*   Updated: 2026/04/13 20:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential", 25, 5), _target(target)
{
}

void PresidentialPardonForm::executeAction(void) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}