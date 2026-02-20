#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(time(NULL));

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "[1] Testing ShrubberyCreationForm (Sign: 145, Exec: 137)" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    try {
        Bureaucrat noob("Noob", 150);
        Bureaucrat mid("Mid", 140);
        Bureaucrat pro("Pro", 1);
        ShrubberyCreationForm form("Home");

        std::cout << form << std::endl;
        
        noob.signForm(form);
        
        mid.signForm(form);
        
        mid.executeForm(form);
        
        pro.executeForm(form);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[2] Testing RobotomyRequestForm (Sign: 72, Exec: 45)" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    try {
        Bureaucrat pro("Pro", 1);
        RobotomyRequestForm form("Bender");

        pro.executeForm(form);

        pro.signForm(form);
        pro.executeForm(form);
        
        pro.executeForm(form);
        pro.executeForm(form);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[3] Testing PresidentialPardonForm (Sign: 25, Exec: 5)" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    try {
        Bureaucrat president("Zaphod", 1);
        PresidentialPardonForm form("Criminal_X");

        president.signForm(form);
        president.executeForm(form);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\nDone testing! Check your directory for 'Home_shrubbery' file." << std::endl;
    return 0;
}