#include "scan.hpp"
#include <fstream>

int main(int argc, const char *argv[]) {
    if (argc < 1) {
        std::cout << "No arguments\n";
        return 1;
    }
    // get filename
    std::string fn = argv[0];
    // open file
    std::ifstream in;
    std::string input((std::istreambuf_iterator<char>(in)),
                    (std::istreambuf_iterator<char>()));
    std::ofstream out(fn + ".out");
    out << input;
    out.close();
    return 0;
}