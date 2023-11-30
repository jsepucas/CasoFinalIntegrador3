#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};
struct ConsoleBox {
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};
ConsoleBox *consoleBox = new ConsoleBox;

bool is_filename_valid(const char* filename) {
    if (!filename || std::strlen(filename) == 0 || std::strlen(filename) >= 500) {
        return false;
    }

    return true;
}
void load_script(const char* filename, bool show_script = false) {
    if (!is_filename_valid(filename)) {
        cerr << "El nombre no es valido u ocupa demasiados caracteres: " << filename << endl;
        return;
    }

