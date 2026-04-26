/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:50:53 by marvin            #+#    #+#             */
/*   Updated: 2026/04/13 19:50:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery", 145, 137), _target(target)
{
}

void ShrubberyCreationForm::executeAction(void) const
{
    std::ofstream file((_target + "_shrubbery").c_str());

    file << "  🌳🌳🌳\n";
    file << " 🌳🌳🌳🌳\n";
    file << "  🌳🌳🌳\n";
}