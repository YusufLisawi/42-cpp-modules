#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]\nthink I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

// This function takes a string argument 'level' and prints a message based on the value of 'level'.
// The function first creates an array of strings 'levels' containing the possible values of 'level'.
// It then creates an array of function pointers 'HarlFunc' that point to the member functions of the Harl class.
// Each member function corresponds to a message level in the 'levels' array.
// The function then iterates through the 'levels' array and compares each value to the 'level' argument.
// If a match is found, the corresponding member function is called using the function pointer array 'HarlFunc'.
// This allows the function to call the appropriate message function based on the value of 'level'.
void    Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    void (Harl::*HarlFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*HarlFunc[i])();
    }
}