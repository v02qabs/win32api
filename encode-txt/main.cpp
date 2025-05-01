#include <iostream>
#include <fstream>
#include <string>

// ASCII 判定
bool is_ascii(const std::string& str) {
    for (unsigned char c : str) {
        if (c > 0x7F) {
            return false;
        }
    }
    return true;
}

// UTF-8 判定
bool is_utf8(const std::string& str) {
    size_t i = 0;
    while (i < str.size()) {
        unsigned char c = str[i];
        if (c <= 0x7F) {
            // 1 バイト文字
            i++;
        } else if ((c & 0xE0) == 0xC0) {
            // 2 バイト文字
            if (i + 1 < str.size() && (str[i + 1] & 0xC0) == 0x80) {
                i += 2;
            } else {
                return false;
            }
        } else if ((c & 0xF0) == 0xE0) {
            // 3 バイト文字
            if (i + 2 < str.size() && (str[i + 1] & 0xC0) == 0x80 && (str[i + 2] & 0xC0) == 0x80) {
                i += 3;
            } else {
                return false;
            }
        } else if ((c & 0xF8) == 0xF0) {
            // 4 バイト文字
            if (i + 3 < str.size() && (str[i + 1] & 0xC0) == 0x80 && (str[i + 2] & 0xC0) == 0x80 && (str[i + 3] & 0xC0) == 0x80) {
                i += 4;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

// SJIS 判定
bool is_sjis(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        unsigned char c = str[i];
        if (c <= 0x7F) {
            // ASCII
            continue;
        }
        if (0x81 <= c && c <= 0x9F || 0xE0 <= c && c <= 0xFC) {
            // SJIS の先頭バイト候補
            if (i + 1 < str.size()) {
                unsigned char next = str[i + 1];
                if (0x40 <= next && next <= 0xFC && next != 0x7F) {
                    i++; // 有効な SJIS のペア
                    continue;
                }
            }
            return false;
        }
        return false;
    }
    return true;
}

// ファイルを読み込んで判定
void check_file_encoding(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "ファイルを開けません: " << filename << std::endl;
        return;
    }

    // ファイル内容を読み込む
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // 判定
    if (is_ascii(content)) {
        std::cout << "ファイルは ASCII エンコーディングです。\n";
    } else if (is_utf8(content)) {
        std::cout << "ファイルは UTF-8 エンコーディングです。\n";
    } else if (is_sjis(content)) {
        std::cout << "ファイルは SJIS エンコーディングです。\n";
    } else {
        std::cout << "ファイルのエンコーディングを判定できませんでした。\n";
    }

    file.close();
}

int main() {
    std::string filename;
    std::cout << "判定したいファイルのパスを入力してください: ";
    std::getline(std::cin, filename);

    check_file_encoding(filename);

    return 0;
}
