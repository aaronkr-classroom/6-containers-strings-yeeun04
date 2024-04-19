#ifndef GUARD_split_h
#define GUARD_split_h

#include <string>
#include <vector>

using namespace std;

string::size_type width(const vector<string>&);
vector<string> frame(const vector<string>& );

// 수직 결합 = vertical concat
vector<string> vcat(const vector<string>& top,
	const vector<string>&);

vector<string> hcat(const vector<string>& left,
	const vector<string>& );

#endif