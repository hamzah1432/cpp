/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:36 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/14 14:11:46 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    this->executeAction();
}

AForm::AForm() : _name("AForm-124"), _target("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm( std::string name, std::string target, int gradeToSign,  int gradeToExecute) : _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
	}
	return (*this);
}

AForm::AForm(const AForm &src) : _name(src._name), _target(src._target), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute){}

AForm::~AForm(){}




std::string AForm::getName() const
{
    return (_name);
}

std::string AForm::getTarget() const
{
    return (_target);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    
    _isSigned = true;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "AForm " << f.getName() << " is " << (f.getIsSigned() ? "signed" : "not signed") << ", target: " << f.getTarget() << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute() << ".";
    return (os);
}
