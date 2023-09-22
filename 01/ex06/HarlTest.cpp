#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl logger;

    logger.debug();
    logger.info();
    logger.warning();
    logger.error();
    logger.complain("critical");

    return 0;
}