//
// Created by filan on 27.10.2025.
//

#include "crypto_algo.hpp"

#include <stdexcept>
#include <string_view>

namespace cryptex {

    std::string xorCrypt(std::string_view content, std::string_view key) {
        if (key.empty()) {
            throw std::invalid_argument("Key cannot be empty");
        }
        std::string encripted;
        encripted.reserve(content.size());
        for (size_t i = 0; i < content.size(); ++i) {
            encripted.push_back(content.at(i) ^ key[i % key.size()]);
        }
        return encripted;
    }

}
