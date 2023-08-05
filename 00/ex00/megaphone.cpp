#include <iostream>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    int i = 1;
    while (i < argc) {
        std::string str = argv[i];
        int j = 0;
        while (j < (int)str.length()) {
            std::cout << (char)std::toupper(str[j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}
