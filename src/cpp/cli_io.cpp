//
// Created by filan on 27.10.2025.
//
#include "cli_io.hpp"

#include <fstream>
#include <iostream>
#include <memory>

namespace cryptex {
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

    std::shared_ptr<std::ostream> setOutStream(std::string_view outfile) {
        if (outfile.empty()) {
            return nullptr;
        }
        auto ofs = std::make_shared<std::ofstream>(outfile.data(), std::ios::binary);
        if (!ofs->is_open()) {
            throw std::runtime_error("Failed to open output file");
        }
        return ofs;
    }

    void writeToOutStream(const std::shared_ptr<std::ostream>& out, std::string_view content) {
        if (!out) {
            std::cout << content;
        } else {
            *out << content;
        }
    }
}
