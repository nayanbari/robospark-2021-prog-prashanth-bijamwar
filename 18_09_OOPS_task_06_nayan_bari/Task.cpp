#include <iostream>
using namespace std;

class Personal
{
protected:
    string name, surname, address, dob;
    double mobile_no;
    Personal()
    {
        name, surname, address, dob = "";
        mobile_no = 0;
    }
    Personal(string name, string surname, string address, string dob, double mobile_no)
    {
        cout << "Constructor callled 1";
        this->name = name;
        this->surname = surname;
        this->address = address;
        this->dob = dob;
        this->mobile_no = mobile_no;
    }
};

class Professional
{
protected:
    string name_of_organization, job_profile, project;
    Professional()
    {
        name_of_organization, job_profile, project = "";
    }
    Professional(string name_of_organization, string job_profile, string project)
    {
        cout << "Constructor callled 2";
        this->name_of_organization = name_of_organization;
        this->job_profile = job_profile;
        this->project = project;
    }
};
class Academics
{
protected:
    int year_of_passing;
    float cgpa;
    string college_name, branch;
    Academics()
    {
        college_name, branch = "";
        year_of_passing = 0;
        cgpa = 0;
    }
    Academics(int year_of_passing, float cgpa, string college_name, string branch)
    {
        cout << "Constructor callled 3";
        this->year_of_passing = year_of_passing;
        this->cgpa = cgpa;
        this->college_name = college_name;
        this->branch = branch;
    }
};

class Biodata : public Personal, public Professional, public Academics
{
public:
    void set_data()
    {
        cout << "Personal Data" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Address: ";
        cin >> address;
        cout << "Date of Birth: ";
        cin >> dob;
        cout << "Mobile Number: ";
        cin >> mobile_no;
        cout << "Professional Data" << endl;
        cout << "Name of Organization: ";
        cin >> name_of_organization;
        cout << "Job Profile: ";
        cin >> job_profile;
        cout << "Project: ";
        cin >> project;
        cout << "Academic Data" << endl;
        cout << "Year of Passing: ";
        cin >> year_of_passing;
        cout << "CGPA: ";
        cin >> cgpa;
        cout << "College Name: ";
        cin >> college_name;
        cout << "Branch: ";
        cin >> branch;
    }
    void get_data()
    {
        cout << "----------Your Biodata---------" << name << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Address: " << address << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Mobile Number: " << mobile_no << endl;
        cout << "Name of Organization: " << name_of_organization << endl;
        cout << "Job Profile: " << job_profile << endl;
        cout << "Project: " << project << endl;
        cout << "Year of Passing: " << year_of_passing << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "College Name: " << college_name << endl;
        cout << "Branch: " << branch << endl;
    }
};

main()
{
    Biodata obj;
    obj.set_data();
    obj.get_data();
}