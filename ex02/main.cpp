/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:29:50 by marvin            #+#    #+#             */
/*   Updated: 2026/04/05 20:29:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(time(0));

    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    ShrubberyCreationForm s("home");
    RobotomyRequestForm r("robot");
    PresidentialPardonForm p("Ali");

    boss.signForm(s);
    boss.executeForm(s);

    boss.signForm(r);
    boss.executeForm(r);

    boss.signForm(p);
    boss.executeForm(p);

    return 0;
}