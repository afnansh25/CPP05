/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:47:24 by marvin            #+#    #+#             */
/*   Updated: 2026/04/08 17:47:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false),
  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other)
: _name(other._name), _isSigned(other._isSigned),
  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName(void) const
{
    return _name;
}

bool AForm::getIsSigned(void) const
{
    return _isSigned;
}

int AForm::getGradeToSign(void) const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform)
{
    out << Aform.getName()
        << ", signed: " << Aform.getIsSigned()
        << ", grade to sign: " << Aform.getGradeToSign()
        << ", grade to execute: " << Aform.getGradeToExecute();
    return out;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}