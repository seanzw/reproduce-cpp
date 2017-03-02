#include <iostream>
#include <string>
#include <sstream>

std::string quote(const std::string& s) {
    std::stringstream ss;
    ss << '"';
    for (int i = 0; i < s.length(); ++i) {
        switch (s[i]) {
            case '\\': ss << "\\\\"; break;
            case '\"': ss << "\\\""; break;
            case '\'': ss << "\\\'"; break;
            case '\n': ss << "\\n"; break;
            default: ss << s[i];
        }
    }
    ss << '"';
    return ss.str();
}

int main() {
    std::string source = ";\n\
    source = \"#include <iostream>\\n\\\n\
#include <string>\\n\\\n\
#include <sstream>\\n\\\n\
\\n\\\n\
std::string quote(const std::string& s) {\\n\\\n\
    std::stringstream ss;\\n\\\n\
    ss << \\\'\\\"\\\';\\n\\\n\
    for (int i = 0; i < s.length(); ++i) {\\n\\\n\
        switch (s[i]) {\\n\\\n\
            case \\\'\\\\\\\\\\\': ss << \\\"\\\\\\\\\\\\\\\\\\\"; break;\\n\\\n\
            case \\\'\\\\\\\"\\\': ss << \\\"\\\\\\\\\\\\\\\"\\\"; break;\\n\\\n\
            case \\\'\\\\\\\'\\\': ss << \\\"\\\\\\\\\\\\\\\'\\\"; break;\\n\\\n\
            case \\\'\\\\n\\\': ss << \\\"\\\\\\\\n\\\"; break;\\n\\\n\
            default: ss << s[i];\\n\\\n\
        }\\n\\\n\
    }\\n\\\n\
    ss << \\\'\\\"\\\';\\n\\\n\
    return ss.str();\\n\\\n\
}\\n\\\n\
\\n\\\n\
int main() {\\n\\\n\
    std::string source = \" + quote(source) + source;\n\
    std::cout << source;\n\
    return 0;\n\
}";
    source = "#include <iostream>\n\
#include <string>\n\
#include <sstream>\n\
\n\
std::string quote(const std::string& s) {\n\
    std::stringstream ss;\n\
    ss << \'\"\';\n\
    for (int i = 0; i < s.length(); ++i) {\n\
        switch (s[i]) {\n\
            case \'\\\\\': ss << \"\\\\\\\\\"; break;\n\
            case \'\\\"\': ss << \"\\\\\\\"\"; break;\n\
            case \'\\\'\': ss << \"\\\\\\\'\"; break;\n\
            case \'\\n\': ss << \"\\\\n\"; break;\n\
            default: ss << s[i];\n\
        }\n\
    }\n\
    ss << \'\"\';\n\
    return ss.str();\n\
}\n\
\n\
int main() {\n\
    std::string source = " + quote(source) + source;
    std::cout << source;
    return 0;
}
