//
// Created by filan on 27.10.2025.
//

#pragma once
#include <string_view>

namespace cryptex {


    /**
     * @brief Encrypts or decrypts a string using a repeating-key XOR cipher.
     *
     * This function applies a simple XOR operation between each byte of the
     * input content and the corresponding byte of the key. If the key is
     * shorter than the content, it wraps around using modulo.
     *
     * XOR encryption is symmetric: applying the same key again decrypts the data.
     *
     * @param content The string content to encrypt or decrypt.
     * @param key The key used for XOR. Must not be empty.
     * @return A new std::string containing the encrypted or decrypted data.
     *
     * @throws std::invalid_argument if the key is empty.
     */
    std::string xorCrypt(std::string_view content, std::string_view key);
}
