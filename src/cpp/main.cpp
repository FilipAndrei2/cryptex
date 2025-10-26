#include <fstream>
#include <iostream>
#include <string_view>
#include <crypto_algo.hpp>
#include <iomanip>

void parseArgs(std::string& content, std::string& key, std::string& outfile, const int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "cryptex [-c/-f] content/file -k key -o outfile" << std::endl;
        exit(EXIT_FAILURE);
    }
    for (size_t i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];

        if (arg == "-c" || arg == "-C") {
            if (i + 1 >= argc) {
                throw std::invalid_argument("Missing content after -c flag. Exiting");
            }
            content = argv[++i];
        } else if (arg == "-f" || arg == "-F") {
            if (i + 1 >= argc) {
                throw std::invalid_argument("Missing content after -f flag. Exiting");
            }
            std::ifstream file(argv[++i], std::ios::binary);
            if (!file) {
                std::cerr << "Failed to open file " << argv[i] << ". Exiting" << std::endl;
                exit(EXIT_FAILURE);
            }

           char c;
           while (file.get(c)) {
                content.push_back(c);
            }
            file.close();
        } else if (arg == "-k" || arg == "-K") {
            if (i + 1 >= argc) {
                throw std::invalid_argument("Missing content after -k flag. Exiting");
            }
            key = argv[++i];
        } else if (arg == "-o" || arg == "-O") {
            if (i + 1 >= argc) {
                throw std::invalid_argument("Missing content after -k flag. Exiting");
            }
            outfile = argv[++i];
        }
    }
    if (content.empty() || key.empty()) {
        throw std::invalid_argument("Please provide the necessary values for key and content!");
    }
}

int main(const int argc, const char** argv) {
    std::string content;
    std::string key;
    std::string outfile;

    try {
        parseArgs(content, key, outfile, argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what();
    }

    std::ostream* out = &std::cout;
    std::ofstream ofs;

    if (!outfile.empty()) {
        ofs.open(outfile);
        if (!ofs) {
            throw std::runtime_error("Failed to open output file");
        }
        out = &ofs;
    }


    auto encrypted = cryptex::xorCrypt(content, key);
    *out  << encrypted;

    return EXIT_SUCCESS;
}