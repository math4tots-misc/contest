#include "expander.hpp"

int main() {
  assert(match_include("#include \"expander.hpp\"") == "expander.hpp");
  {
    ifstream fin("expander_test.cpp");
    assert(find_includes(fin) == vector<string>({"expander.hpp"}));
  }
  {
    map<string,string> file_table({
      {"expander.cpp",
          "#include \"expander.hpp\"\n"
          "int main() {}\n"},
      {"expander.hpp",
          "#include \"expander2.hpp\"\n"
          "int x;\n"},
      {"expander2.hpp",
          "int y;\n"}
    });
    expand("expander.cpp", file_table);
    assert(file_table["expander.cpp"] ==
           "int y;\n"
           "int x;\n"
           "int main() {}\n");
  }
}
