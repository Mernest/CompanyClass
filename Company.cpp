#include "Company.h"

int main() {

	employee additionalEmp(0, "EmployeeName5", "Admin", 38);
	vector<employee> v;
	vector<employee> v1;
	v.push_back(employee(1, "EmployeeName1", "Research", 20));
	v.push_back(employee(2, "EmployeeName2", "Research", 27));
	v.push_back(employee(3, "EmployeeName3", "Research", 26));
	v.push_back(employee(4, "EmployeeName4", "Research", 30));
	v.push_back(researcher(5, "Researcher1", "Head of Research", 43, "Research", "Chemistry"));
	v.push_back(administrator(6, "Admin1", "CEO", 50, 200));

	
	company C1("Company1", "Montreal", v);
	company C2("Company2", "Toronto", v1);

	// Before using add and remove functions
	cout << "Content of Company1: " << endl;
	C1.print();
	cout << endl;
	cout << "Content of Company2: " << endl;
	C2.print();
	cout << endl << "Company1 Information: " << endl;
	C1.printCompany();
	cout << endl;
	cout << "Company2 Information: " << endl;
	C2.printCompany();
	cout << endl;
	cout << "Company1 size: " << C1.list_size() << endl;
	cout << "Company2 size: " << C2.list_size() << endl << endl;

	//After Using add and remove functions
	v1.push_back(additionalEmp);
	cout << "***************************************************************************" << endl;
	cout << "Calling removeEmployee function: ";
	C1.removeEmployee(5);
	cout << "***************************************************************************" << endl;
	C2.addEmployee(additionalEmp);

	cout << "Content of Company1: " << endl;
	C1.print();
	cout << endl;
	cout << "Content of Company2: " << endl;
	C2.print();
	cout << endl << "Company1 Information: " << endl;
	C1.printCompany();
	cout << endl;
	cout << "Company2 Information: " << endl;
	C2.printCompany();
	cout << endl;
	cout << "Company1 size: " << C1.list_size() << endl;
	cout << "Company2 size: " << C2.list_size() << endl << endl;

	cout << "Trying to add employee with ID = 0 another time: " << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "Calling addEmp function: ";
	C2.addEmployee(additionalEmp);
	cout << "**************************************************************************************************" << endl << endl;
	C2.print();
	cout << "Company2 size: " << C2.list_size() << endl << endl;

	//Set and get Testing
	cout << "Set and get Testing: " << endl;
	researcher researcher_test(12, "ResearcherTest", "Researcher", 58, "Assistant Researcher", "Medicine");
	
	cout << "Researcher ID: " << researcher_test.getID() << endl;
	cout << "Researcher Name: " << researcher_test.getName() << endl;
	cout << "Researcher Position: " << researcher_test.getPosition() << endl;
	cout << "Researcher Seniority: " << researcher_test.getSeniority() << endl;
	cout << "Researcher Title: " << researcher_test.getTitle() << endl;
	cout << "Researcher Expertise: " << researcher_test.getExpertise() << endl << endl;
	
	cout << "Changing ID and Expertise: " << endl;
	researcher_test.setID(100);
	researcher_test.setExpertise("Physics");
	cout << "Researcher ID: " << researcher_test.getID() << endl;
	cout << "Researcher Expertise: " << researcher_test.getExpertise() << endl;



}
