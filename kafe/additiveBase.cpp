#include "additiveBase.h"

additiveBase::additiveBase():additiveBase_(vector<additive>()) {};
void additiveBase::saveAdditiveBase() {
	string file = "baseAdditive.txt";
	ofstream fout;
	fout.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fout.open(file);

		if (fout.is_open()) {
			for (auto i = 0; i < additiveBase_.size(); i++) {
				fout << additiveBase_[i].name << '\n';
				fout << additiveBase_[i].price << '\n';
				i != additiveBase_.size() - 1 ? fout << '#' << '\n' : fout << '#';
			}
		}
		fout.close();
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}
void additiveBase::readAdditiveBase() {
	string path = "baseAdditive.txt";
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fin.open(path);
		if (fin.is_open()) {
			string name, price, buf;
			while (!fin.eof())
			{
				getline(fin, name);
				getline(fin, price);
				additiveBase_.push_back(additive(name, price));
				getline(fin, buf);
			}
			fin.close();
		}
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}