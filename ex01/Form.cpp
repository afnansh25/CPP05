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

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false),
  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned),
  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName(void) const
{
    return _name;
}

bool Form::getIsSigned(void) const
{
    return _isSigned;
}

int Form::getGradeToSign(void) const
{
    return _gradeToSign;
}

int Form::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName()
        << ", signed: " << form.getIsSigned()
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}