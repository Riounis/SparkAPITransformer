#include "scan.hpp"
#include "replace.hpp"
#include <fstream>
#include <sstream>

int main(int argc, const char *argv[]) {
    if (argc < 1) {
        std::cout << "No arguments\n";
        return 1;
    }
    // get filename
    std::string fn = argv[1];
    std::cout << fn << std::endl;
    // open file
    std::ifstream in(fn);
    std::string input;
    std::stringstream buf;
    buf << in.rdbuf();
    input = buf.str();
    //std::cout << input << std::endl;
    std::vector<Pair> tokens = scan(input);
    //std::ofstream out(fn + ".out");
    //std::vector<Pair>::iterator it = tokens.begin();
    //for (it; it != tokens.end(); ++it) {
    //    out << it->to_string() << std::endl;
    //}
    //out.close();
    
    replace_sc(tokens);
    
    replace_textfile(tokens);

    replace_reduce(tokens);

    replace_reducebykey(tokens);

    replace_sortby(tokens);
    
    std::ofstream out(fn + ".out");
    std::vector<Pair>::iterator it = tokens.begin();
    for (it; it != tokens.end(); ++it) {
        out << it->token;
    }
    out.close();
    
    return 0;
}