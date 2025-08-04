#include "Intern.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &i)
{
	// o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static AForm *createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidentPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	typedef AForm *(*FormSelector)(std::string);
	AForm *form;
	const std::string formNames[3] = {"shrubbery creation", "robotomy request",
									  "presidential pardon"};
	FormSelector formPointer[] = {&createShrubbery, &createRobotomy, &createPresidentPardon};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			form = formPointer[i](target);
			break ;
		}
	}
	// replace this with an exception
	if (!form)
		std::cout << "Intern failed to create the form!" << std::endl;
	return (form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */