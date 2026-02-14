/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:36 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/14 14:11:46 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("form-124"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form( std::string name,  int gradeToSign,  int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
	}
	return (*this);
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute){}

Form::~Form(){}




std::string Form::getName() const
{
    return (_name);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    
    _isSigned = true;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}


std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form " << f.getName() << " is " << (f.getIsSigned() ? "signed" : "not signed") << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute() << ".";
    return (os);
}
