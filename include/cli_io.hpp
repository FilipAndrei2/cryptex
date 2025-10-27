//
// Created by filan on 27.10.2025.
//

#pragma once
#include <memory>
#include <string>

namespace cryptex {
    void parseArgs(std::string& content, std::string& key, std::string& outfile, const int argc, const char** argv);
    std::shared_ptr<std::ostream> setOutStream(std::string_view outfile);
    void writeToOutStream(const std::shared_ptr<std::ostream>& out, std::string_view content);
}
