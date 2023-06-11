#include<iostream>

/*
Tính kế thừa:
    - Nếu class con có dạng kế thừa là public, thì class cha kiểu gì qua class con giữ nguyên 
    - Nếu class con có dạng kế thừa là private, thì nếu:
        + Class cha kiểu plulic -> Class con kiểu private
        + Class cha kiểu private -> Class con kiểu private
        + Class cha kiểu protected - > Class con kiểu private
    - Nếu class con có dạng kế thừa là protected, thì nếu:
        + Class cha kiểu plulic -> Class con kiểu protected
        + Class cha kiểu private -> Class con kiểu private
        + Class cha kiểu protected - > Class con kiểu protected 
*/

using namespace std;

class Person {
private:
	string name;
	string gender;

public:
	Person(string name, string gender) {
		this->name = name;
		this->gender = gender;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getGender() {
		return gender;
	}

	void setGender(string gender) {
		this->gender = gender;
	}

	void display() {
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
	}
};

class Student : Person {
private:
	int salary;

public:
	Student(string name, string gender, int salary) : Person(name, gender) {
		this->salary = salary;
	}

	int getSalary() {
		return salary;
	}

	void setSalary(int salary) {
		this->salary = salary;
	}

	void display() {						//Khai báo 1 phương thước trùng tên với phương thước ở lớp cha 
		Person::display();					//-> khi gọi thì phương thức ở lớp cha bị ghi đè
		cout << "Salary: " << salary << endl;
	}
};

int main() {
	Student s("Trung", "Male", 1700);
	s.display();
	return 0;
}