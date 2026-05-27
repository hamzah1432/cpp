#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
    std::srand(time(NULL));

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "[1] Intern creates a RobotomyRequestForm for 'Bender'" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    {
        Intern someRandomIntern;
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            Bureaucrat boss("Boss", 1);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[2] Intern creates a ShrubberyCreationForm for 'Garden'" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    {
        Intern intern;
        AForm *scf = intern.makeForm("shrubbery creation", "Garden");
        if (scf)
        {
            Bureaucrat gardener("Gardener", 100);
            gardener.signForm(*scf);
            gardener.executeForm(*scf);
            delete scf;
        }
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[3] Intern creates a PresidentialPardonForm for 'Arthur Dent'" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    {
        Intern intern;
        AForm *ppf = intern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf)
        {
            Bureaucrat zaphod("Zaphod", 1);
            zaphod.signForm(*ppf);
            zaphod.executeForm(*ppf);
            delete ppf;
        }
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[4] Intern asked for an unknown form" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    {
        Intern intern;
        AForm *unknown = intern.makeForm("coffee request", "Trillian");
        if (unknown == NULL)
            std::cout << "makeForm returned NULL as expected." << std::endl;
        delete unknown;
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[5] Intern form, but bureaucrat grade too low to execute" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    {
        Intern intern;
        AForm *form = intern.makeForm("presidential pardon", "Marvin");
        if (form)
        {
            Bureaucrat weak("Weak", 50);
            weak.signForm(*form);
            weak.executeForm(*form);
            delete form;
        }
    }

    return 0;
}
