#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void load_script(const char* filename, bool show_script = false) {
    ifstream file(filename);

    if(!file.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string line;
    while(getline(file, line)) {
        if(show_script) {
            cout << line << endl;
        }
    }

    if (!file.eof()) {
        cout << "Ha ocurrido un error al leer el archivo." << endl;
    }
    file.close();
}

