#include <iostream>
#include <direct.h>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
    string name;
    cout << "Folder name: ";
    cin >> name;

    filesystem::create_directories(name);
    filesystem::create_directories(name + "/css");
    filesystem::create_directories(name + "/img");
    filesystem::create_directories(name + "/js");

    ofstream writeCSS(name + "/css/style.css");
    writeCSS << "";
    writeCSS.close();

    ofstream writeJS(name + "/js/main.js");
    writeJS << "";
    writeJS.close();

    ofstream writeFile(name + "/index.html");
    writeFile << "<!DOCTYPE html>\n";
    writeFile << "<html lang=\"lt\">\n\n";
    writeFile << "<head>\n";
    writeFile << "    <meta charset=\"UTF-8\">\n";
    writeFile << "    <title>" + name + "</title>\n";
    writeFile << "<link rel=\"stylesheet\" href=\"css/style.css\">\n";
    writeFile << "</head>\n\n";
    writeFile << "<body>\n";
    writeFile << "<script src=\"js/main.js\"></script>\n";
    writeFile << "</body>\n\n";
    writeFile << "</html>";
    writeFile.close();

    cout << "Done.";

    return 0;
}
