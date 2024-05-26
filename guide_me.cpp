#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>


int main()
{
    const std::string red = "\033[31m";
    const std::string reset = "\033[0m";

    // we can define a variable here, and use it later
    size_t variable;
    
    
    std::string equation;

    

    std::cout << "Please type in your expression \n\n";

    // This is how we read the entire line

    std::getline(std::cin, equation);


    // AND operator, because if 1 exists we should continue
    if (equation.find("x") == std::string::npos && equation.find("X") == std::string::npos) {
        std::cout << red << "No variable found, DNE \n" << reset;

        return 1;

    } else {

        if (equation.find("x") == std::string::npos){

            // can't define a variable to use here
            variable = equation.find("X");
        } else {
            variable = equation.find("x");
        }

    }
    
    
    if (variable > equation.find("=")) {

        std::cout << "RIGHT SOLVE \n\n";
 

    } else {

        std::cout << "LEFT SOLVE \n\n";

        // calculation
        std::string c_one = equation.substr(0, variable); // denominator

        // +1 because it needs to start after the '='
        std::string c_two = equation.substr(equation.find("=") + 1, equation.length()); // numerator

        float answer = (std::stof(c_two) / std::stof(c_one));

        std::cout << std::fixed << std::setprecision(6);
        std::cout << equation << "\nx = " << answer << "\n";
    }


    return 0;
}