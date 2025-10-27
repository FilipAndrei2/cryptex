#include <fstream>
#include <iostream>
#include <iomanip>

#include "cli_io.hpp"
#include "crypto_algo.hpp"

int main(const int argc, const char** argv) {
    std::string content;
    std::string key;
    std::string outfile;

    try {
        cryptex::parseArgs(content, key, outfile, argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }

    std::shared_ptr<std::ostream> out = nullptr;
    try {
        out = cryptex::setOutStream(outfile);
    } catch (std::exception& e) {
        std::cerr << "Failed to open file. Output is redirected to stdout.";
    }

    auto encrypted = cryptex::xorCrypt(content, key);

    cryptex::writeToOutStream(out, encrypted);

    return EXIT_SUCCESS;
}