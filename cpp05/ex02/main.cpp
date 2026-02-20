#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    // تشغيل العشوائية عشان الروبوت
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
        
        // Noob يحاول يوقع (رح يفشل)
        noob.signForm(form);
        
        // Mid يحاول يوقع (رح ينجح)
        mid.signForm(form);
        
        // Mid يحاول ينفذ (رح يفشل لأن درجته 140 والمطلوب 137)
        mid.executeForm(form);
        
        // Pro يحاول ينفذ (رح ينجح ويطبع الشجرة في الملف)
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

        // محاولة تنفيذ قبل التوقيع (رح يفشل ويرمي FormNotSignedException)
        pro.executeForm(form);

        // التوقيع ثم التنفيذ
        pro.signForm(form);
        pro.executeForm(form);
        
        // بننفذ كمان مرة عشان نشوف الـ 50% حظ بتعطي نتائج مختلفة
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