#include "utils.hpp"

regex include_re("#include \"(.*?)\"");

string match_include(const string& line) {
	smatch sm;
	return regex_match(line, sm, include_re) ? sm[1].str() : "";
}

vector<string> find_includes(istream& fin) {
	vector<string> includes;
	string line;
	while (getline(fin, line)) {
		string include(match_include(move(line)));
		if (include.size() > 0)
			includes.push_back(move(include));
	}
	return includes;
}

vector<string> find_includes(const string& text) {
	istringstream iss(text);
	return find_includes(iss);
}

void expand(const string& file_name, map<string,string>& file_table) {
	istringstream iss(file_table[file_name]);
	ostringstream oss;
	string line;

	while (getline(iss, line)) {
		if (match_include(line).size()) {
			expand(match_include(line), file_table);
			oss << file_table[match_include(line)];
		} else {
			oss << line;
		}
	}
	oss << endl;

	file_table[file_name] = oss.str();
}
