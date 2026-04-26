/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:27:21 by marvin            #+#    #+#             */
/*   Updated: 2026/04/08 17:27:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
   Form(const std::string& name, int gradeToSign, int gradeToExecute);
   Form(const Form& other);
   Form& operator=(const Form& other);
   ~Form();

   const std::string& getName(void) const;
   bool getIsSigned(void) const;
   int getGradeToSign(void) const;
   int getGradeToExecute(void) const;

   void beSigned(const Bureaucrat& bureaucrat);

   class GradeTooHighException : public std::exception
   {
   public:
      const char* what() const throw();
   };

   class GradeTooLowException : public std::exception
   {
   public:
      const char* what() const throw();
   };
};
std::ostream& operator<<(std::ostream& out, const Form& form);
#endif