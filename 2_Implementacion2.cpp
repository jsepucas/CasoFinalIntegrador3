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
    string script;
    FILE* f = nullptr;
    try {
        f = fopen(filename, "rb");
        if (!f) {
            cerr << "Error en la apertura de " << filename << endl;
            return;
        }
        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = 0;
            script.append(buf);
        }

        if (feof(f) && script.empty()) {
            cerr << "Archivo vacio: " << filename << endl;
            fclose(f);
            return;
        }

        if (ferror(f)) {
            cerr << "Error al leer el archivo: " << filename << endl;
            fclose(f);
            return;
        }

        if (fclose(f) != 0) {
            cerr << "Error al cerrar el archivo: " << filename << endl;
            return;
        }
