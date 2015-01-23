inline string read_all(istream& t) {
	return string((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
}
