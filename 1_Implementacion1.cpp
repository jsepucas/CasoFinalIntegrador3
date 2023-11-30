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



