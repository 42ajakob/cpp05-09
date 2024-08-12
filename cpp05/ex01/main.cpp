#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
	/* Constructor */
    Bureaucrat Steve("Steve", 1);
	Bureaucrat Alex("Alex", 150);

	Form Form1("Civial Rights", 1, 1);
	Form Form2;

	/* Overload */
    std::cout << Form1;
	std::cout << Form2;

	/* Functions */
	Alex.signForm(Form1);
	Alex.signForm(Form2);

	Steve.signForm(Form1);
	Steve.signForm(Form2);

    return 0;
}