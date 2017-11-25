#ifndef _EMPLOYEE_
#define _EMPLOYEE_

#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//Employee class
class employee {
public: 
	//Default constructor
	employee() {
		id = 0;
		name = "na";
		position = "na";
		seniority = 0;
	}
	
	employee(int ID, string emp_name, string pos, int sen) : id(ID), name(emp_name), position(pos), seniority(sen) {
	}

	employee(const employee &other) {
		id = other.id;
		name = other.name;
		position = other.position;
		seniority = other.seniority;
	}
	virtual ~employee() {};

	//accessing functions sets and gets
	int getID() const {
		return id;
	}
	string getName()const {
		return name;
	}
	string getPosition() const {
		return position;
	}
	int getSeniority() const {
		return seniority;
	}
	void setID(int person_id) {
		id = person_id;
	}
	void setName(string person_name) {
		name = person_name;
	}
	void setPosition(string person_position) {
		position = person_position;
	}
	void setSeniority(int person_seniority) {
		seniority = person_seniority;
	}

protected:

	int id;
	string name;
	string position;
	int seniority;

};

//Researcher class
class researcher : public employee{
public:

researcher() : employee() , title(""), expertise(""){

	}
	
researcher(int ID, string NAME, string POSITION, int SENIORITY, string TITLE, string EXPERTISE) : employee(ID,NAME,POSITION,SENIORITY),  title(TITLE), expertise(EXPERTISE){}
researcher(const researcher &other) {} // copy constructor
virtual ~researcher() {} 

//accessing functions sets and gets
void setTitle(string person_title) {
	title = person_title;
}
void setExpertise(string person_expertise) {
	expertise = person_expertise;
}
string getTitle() {
	return title;
}
string getExpertise() {
	return expertise;
}



private:
	string title;
	string expertise;
};

//Administrator class
class administrator : public employee {

public:

	administrator() : employee(), num_employee(0) {
	}
	
	administrator(int ID, string NAME, string POSITION, int SENIORITY, int NUM_EMPLOYEE) : employee(ID, NAME, POSITION, SENIORITY), num_employee(NUM_EMPLOYEE) {}
	administrator(const administrator &other) {} // copy const
	virtual ~administrator(){}

	//accessing functions sets and gets
	void setNum(int num) {
		num_employee = num;
	}
	int getNum() {
		return num_employee;
	}

private:
	int num_employee;
};

//Company class
class company {
public:
	company() : company_name(""), address(""), list() {
}
	company(string COMPANY_NAME, string ADDRESS, const vector<employee> & LIST) : company_name(COMPANY_NAME), address(ADDRESS), list(LIST) {}

	company(const company &other)  {
		company_name = other.company_name;
		address = other.address;
		list = other.list;
	}

	~company(){}

	//accessing functions
	void setCompanyName(string comp_name) {
		company_name = comp_name;
	}
	void setAddress(string comp_address) {
		address = comp_address;
	}

	//Function that checks if ID exists
	bool checkID(int ID) {
		for (size_t i{ 0 }; i < list.size(); ++i) {
			if (ID == list[i].getID()) {
				return true;
			}
		}
		return false;
	}

	//Function to add employee to list
	void addEmployee(const employee & emp) {
		if (checkID(emp.getID()) == false) {
			list.push_back(emp);
		}
		else
			cout << "The employee " << emp.getID() << " already exists in the list and has not been added. " << endl;
	}
	//Function to remove employee
	void removeEmployee(int ID) {
		int ix = -1;
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i].getID() == ID)
				ix = i;
		}

		if (ix != -1) {
			cout << "The employee " <<list[ix].getID() <<" exists and has been removed." << endl;
			for (size_t i = ix; i < list.size() - 1; ++i) {
				list[i] = list[i + 1];
			}
			list.pop_back();
		}

	}

	//Function to print elements from company
	void print() {
		for (size_t i{ 0 }; i < list.size(); ++i) {
			cout << "Name: " <<list[i].getName() << "	";
			cout << "ID: " << list[i].getID() << "	";
			cout << "Position: " <<list[i].getPosition() << endl;
		}
	}
	//Prints company information
	void printCompany() {
		cout << "Company Name and Address: " << company_name << "; " << address << endl;
	}
	//Returns size of company
	size_t list_size() const { 
		return list.size(); 
	}


private:
	string company_name;
	string address;
	vector<employee> list;
//	size_t list_size() const { return list.size(); };



};

#endif // !_EMPLOYEE_
