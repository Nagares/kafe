#include "clientBase.h"
clientBase::clientBase() :clientBase_(vector<client>()) {};
void clientBase:: saveClientBase() {
	string file = "baseClient.txt";
	ofstream fout;
	fout.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fout.open(file);

		if (fout.is_open()) {
			for (auto i = 0; i < clientBase_.size(); i++) {
				fout << clientBase_[i].name << '\n';
				fout << clientBase_[i].lastName << '\n';
				fout << clientBase_[i].phoneNumber << '\n';
				i != clientBase_.size() - 1 ? fout << '#' << '\n' : fout << '#';
			}
		}
		fout.close();
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}
void clientBase::readClientBase() {
	string path = "baseClient.txt";
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fin.open(path);
		if (fin.is_open()) {
			string name, lastName, number, buf;
			while (!fin.eof())
			{
				getline(fin, name);
				getline(fin, lastName);
				getline(fin, number);
				clientBase_.push_back(client(name, lastName, number));
				getline(fin, buf);
			}
			fin.close();
		}
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}
client clientBase::findByNumber(string number) {
	for (auto i = 0; i < clientBase_.size(); i++) {
		if (clientBase_[i].phoneNumber == number)
			return clientBase_[i];
	}
}