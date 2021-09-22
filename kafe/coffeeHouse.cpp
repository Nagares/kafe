#include "coffeeHouse.h"
coffeeHouse::coffeeHouse(string name, string adminPass) :nameCafe_(name), adminPass_(adminPass) {}
void coffeeHouse:: readBases() {
	this->readCoffeBase();
	this->readClientBase();
	this->readAdditiveBase();
}
void coffeeHouse:: saveBase() {
	this->saveCoffeBase();
	this->saveAdditiveBase();
	this->saveClientBase();
}
bool coffeeHouse:: getDiscount(string number) {
	for (auto i = 0; i < this->clientBase_.size(); i++) {
		if (this->clientBase_[i].phoneNumber == number) {
			cout << "Hi " << this->clientBase_[i].name <<
				" " << this->clientBase_[i].lastName << " your discount 10%\n";
			return true;
		}
	}
	return false;
}
bool coffeeHouse:: reconcilePass(string pass) {
	return pass == adminPass_;
}
void coffeeHouse:: menu() {
	int key = 0;
	string buf;
	do {
		cout << "~Welcome to " << nameCafe_ << "~\n" <<
			"Pleace enter:\n1 - to order coffee\n2 - to login as administrator\n0 - to exit\n";
		cin >> key;
		cin.ignore();
		switch (key)
		{
		case 1:toOrder();
			break;
		case 2:
			cout << "Enter password ";
			getline(cin, buf);
			if (reconcilePass(buf)) {
				this->adminMenu();
			}
			break;
		default:
			break;
		}


	} while (key != 0);

}
void coffeeHouse:: toOrder() {
	int key = 0;
	string buf;

	do {
		cout << "~Coffee Menu~\n" <<
			"Pleace enter:\n1 - to order coffee\n2 - to show chek\n3 - to enter the phone number of a regular customer \n4 - to cancel the order\n0 - back to main menu\n";
		cin >> key;
		cin.ignore();
		switch (key)
		{
		case 1:{
			if (this->orderCoffe()) {
				cout << "Would you like to add something to this coffee? (1 - yes / 0 - no)\n";
				cin >> key;
				cin.ignore();
				if (key) {
					this->orderAdditive();
				}
				key = 1;
			}
			break;
		}
		case 2: {
			showOrder(this->order_, this->discount_);
			cout << "Print chek ?(1 - yes / 0 - no)\n";
			cin >> key;
			cin.ignore();
			if (key) {
				saveOrder(this->order_, this->discount_);
				break;;
			}
			key = 1;
			break;
		}
		case 3: {
			cout << "Enter the phone number\n";
			getline(cin, buf);
			discount_ = this->getDiscount(buf);
			break;
		};
		case 4: {
			this->order_.clear();
			cout << "clearing - done\n";
			break;
		}
		default:
			break;
		}

	} while (key != 0);
	this->order_.clear();
	this->discount_ = false;

}
bool coffeeHouse:: orderCoffe() {
	int n = 0;
	cout << "Pleace enter:\n";
	for (auto i = 0; i < this->coffeBase_.size(); i++) {
		cout << i + 1 << " - to order " << this->coffeBase_[i].name << " (" << this->coffeBase_[i].volume << " ml) - " << this->coffeBase_[i].price << " grn\n";
	}
	cout << "0 - back to the menu\n";
	cin >> n;
	cin.ignore();
	if (n <= 0 && n - 1 > this->coffeBase_.size())
		return false;
	this->order_.push_back(&this->coffeBase_[n - 1]);
	return true;
}
void coffeeHouse:: orderAdditive() {
	int n = 0;
	cout << "Pleace enter:\n";
	for (auto i = 0; i < this->additiveBase_.size(); i++) {
		cout << i + 1 << " - to order " << this->additiveBase_[i].name << " - " << this->additiveBase_[i].price << " grn\n";
	}
	cout << "0 - back to the menu\n";
	cin >> n;
	cin.ignore();
	if (n <= 0 || n - 1 > this->additiveBase_.size())
		return;
	this->order_.push_back(&this->additiveBase_[n - 1]);
	do {
		cout << "Add more to the order (entep above key) \n0 - back to the menu\n";
		cin >> n;
		cin.ignore();
		if (n != 0 && n - 1 < this->additiveBase_.size())
			this->order_.push_back(&this->additiveBase_[n - 1]);
	} while (n != 0);
}
void coffeeHouse:: adminMenu() {
	int key = 0;
	string buf, buf1, buf2;
	do {
		cout << "~Welcome to admin menu~\n" <<
			"Pleace enter:\n1 - to add new coffee\n2 - to add new additive\n3 - to add new client\n0 - to exit admin menu\n";
		cin >> key;
		cin.ignore();
		switch (key)
		{
		case 1: {
			cout << "Enter name coffe \n";
			getline(cin, buf);
			cout << "Enter volume coffe \n";
			getline(cin, buf1);
			cout << "Enter price coffe \n";
			getline(cin, buf2);
			this->coffeBase_.push_back(coffee(buf, buf1, buf2, vector<additive>()));
			int n = 0, k = 0;
			do {
				cout << "Add to coffee ingredients?(yes - 1/ no - 0) ";
				cin >> n;
				cin.ignore();
				if (n) {
					cout << "Enter name ingredients\n";
					getline(cin, buf);
					for (auto i = 0; i < this->additiveBase_.size(); i++) {

						if (this->additiveBase_[i].name == buf) {
							this->coffeBase_[(this->coffeBase_.size()) - 1].supplements_.push_back(this->additiveBase_[i]);
							k++;
							break;
						};
					}
					k ? cout << "add ingredients is ready\n" : cout << "ingredients not find\n";
					k = 0;
				}

			} while (n);
			this->saveCoffeBase();
			break;
		}
		case 2:
			cout << "Enter name additive \n";
			getline(cin, buf);
			cout << "Enter price additive \n";
			getline(cin, buf1);
			this->additiveBase_.push_back(additive(buf, buf1));
			this->saveAdditiveBase();
			break;
		case 3:
			cout << "Enter name client \n";
			getline(cin, buf);
			cout << "Enter last name client \n";
			getline(cin, buf1);
			cout << "Enter phone number client \n";
			getline(cin, buf2);
			this->clientBase_.push_back(client(buf, buf1, buf2));
			this->saveClientBase();
			break;
		default:
			break;
		}


	} while (key != 0);
}

void showOrder(vector<order*>& order, bool discount) {
	cout << "~~~~~~~~~~Order~~~~~~~~~~" << "\n";
	int sum = 0;

	for (auto i = 0; i < order.size(); i++) {

		if (order[i]->isCoffe()) {

			cout << dynamic_cast <coffee*>(order[i])->name << " " <<
				dynamic_cast <coffee*>(order[i])->volume << " ml\t\t\t" <<
				dynamic_cast <coffee*>(order[i])->price << " grn\n";
			sum = sum + stoi(dynamic_cast <coffee*>(order[i])->price);
		}
		else {
			cout << dynamic_cast <additive*>(order[i])->name << "\t\t\t\t" <<
				dynamic_cast <additive*>(order[i])->price << " grn\n";
			sum = sum + stoi(dynamic_cast <additive*>(order[i])->price);
		}
	};
	discount ? cout << "~~~~~~~~~~\nYour discount\t\t\t" << sum * 0.10 << "\nSum\t\t" << sum << " - " << sum * 0.10 << " = " << sum - sum * 0.10 << "\n~~~~~~~~~~\n" :
		cout << "~~~~~~~~~~\nSum\t\t\t\t" << sum << "\n~~~~~~~~~~\n";

}
void saveOrder(vector<order*>& order, bool discount) {
	string file = "baseOrder.txt";
	ofstream fout;
	int sum = 0;
	fout.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		fout.open(file, ios_base::app);
		if (fout.is_open()) {
			for (auto i = 0; i < order.size(); i++) {

				if (order[i]->isCoffe()) {
					fout << dynamic_cast <coffee*>(order[i])->name << "\n";
					fout << dynamic_cast <coffee*>(order[i])->volume << "\n";
					fout << dynamic_cast <coffee*>(order[i])->price << "\n";
					sum = sum + stoi(dynamic_cast <coffee*>(order[i])->price);
				}
				else {
					fout << "~\n";
					fout << dynamic_cast <additive*>(order[i])->name << "\n";
					fout << dynamic_cast <additive*>(order[i])->price << "\n";
					sum = sum + stoi(dynamic_cast <additive*>(order[i])->price);
				}
				if (i != order.size() - 1) {
					fout << "#" << '\n';
				}
				else {
					discount ? fout << "$+\n" << sum - sum * 0.10 << '\n#' : fout << "$\n" << sum << '\n#';
				}
			}
			fout.close();
		}
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}

};