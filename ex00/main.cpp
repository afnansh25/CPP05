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
#include <iostream>

static void testValidBureaucrat(void)
{
    Bureaucrat a("Ali", 2);

    std::cout << "valid bureaucrat" << std::endl;
    std::cout << a << std::endl;
    a.incrementGrade();
    std::cout << "after increment: " << a << std::endl;
}

static void testTooHighConstructor(void)
{
    std::cout << "constructor too high" << std::endl;
    Bureaucrat a("Sara", 0);
    std::cout << a << std::endl;
}

static void testTooLowConstructor(void)
{
    std::cout << "constructor too low" << std::endl;
    Bureaucrat a("Omar", 151);
    std::cout << a << std::endl;
}

static void testIncrementException(void)
{
    Bureaucrat a("Mona", 1);

    std::cout << "increment exception" << std::endl;
    std::cout << a << std::endl;
    a.incrementGrade();
}

static void testDecrementException(void)
{
    Bureaucrat a("Lina", 150);

    std::cout << "decrement exception" << std::endl;
    std::cout << a << std::endl;
    a.decrementGrade();
}

int main(void)
{
    try
    {
        testValidBureaucrat();
    }
    catch (std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }

    std::cout << "------------------" << std::endl;

    try
    {
        testTooHighConstructor();
    }
    catch (std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }

    std::cout << "------------------" << std::endl;

    try
    {
        testTooLowConstructor();
    }
    catch (std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }

    std::cout << "------------------" << std::endl;

    try
    {
        testIncrementException();
    }
    catch (std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }

    std::cout << "------------------" << std::endl;

    try
    {
        testDecrementException();
    }
    catch (std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }

    return 0;
}