#include "coffeBase.h"
coffeBase::coffeBase() :coffeBase_(vector<coffee>()) {};
void coffeBase:: saveCoffeBase() {
	string file = "baseCoffee.txt";
	ofstream fout;
	fout.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fout.open(file);

		if (fout.is_open()) {
			for (auto i = 0; i < coffeBase_.size(); i++) {
				fout << coffeBase_[i].name << '\n';
				fout << coffeBase_[i].volume << '\n';
				fout << coffeBase_[i].price << '\n';

				for (auto element : coffeBase_[i].supplements_) {
					fout << "~\n";
					fout << element.name << '\n';
					fout << element.price << '\n';
				}
				i != coffeBase_.size() - 1 ? fout << '#' << '\n' : fout << '#';
			}
		}
		fout.close();
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}
void coffeBase::readCoffeBase() {
	string path = "baseCoffee.txt";
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fin.open(path);
		if (fin.is_open()) {
			int i = 0;
			string name, volume, price, buf;
			while (!fin.eof())
			{
				getline(fin, name);
				getline(fin, volume);
				getline(fin, price);
				coffeBase_.push_back(coffee(name, volume, price, vector<additive>()));
				getline(fin, buf);
				while (buf != "#") {
					getline(fin, name);
					getline(fin, price);
					coffeBase_[i].supplements_.push_back(additive(name, price));
					getline(fin, buf);
				}

				i++;
			}
			fin.close();
		}
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}