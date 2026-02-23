/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:54:57 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/14 14:11:41 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const std::string _target;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

protected:
	virtual void executeAction() const = 0;

public:
	AForm();
	AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute);
	AForm &operator=(const AForm &src);
	AForm(const AForm &src);
	virtual ~AForm();

	std::string getTarget() const;
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);

	void execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif