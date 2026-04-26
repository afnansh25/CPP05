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

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Ali");
    AForm* f4 = someRandomIntern.makeForm("unknown form", "???");

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    if (f4)
        delete f4;

    return 0;
}
