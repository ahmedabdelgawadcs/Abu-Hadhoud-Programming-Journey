#include <iostream>
using namespace std;


enum enColor { Red = 1, Green = 6, Yellow = 7, Blue };
enum enGender { Male = 1, Female = 0 };
enum enMaritalStatus { Single, Married };




struct stAddress
{
    string StreetName;
    string BuildingNo;
    string POBox;
    string ZipCode;
};




struct stContactInfo
{
    string Phone;
    string Email;
    stAddress Address;
};




struct stPerson
{


    string FirstName;
    string LastName;
	unsigned short Age;

    stContactInfo ContactInfo;


    enMaritalStatus MaritalStatues;
    enGender Gender;
    enColor FavourateColor;
};




int main()
{

    stPerson Person1;


    Person1.FirstName = "Ahmed";
    Person1.LastName = "Ali";
	Person1.Age = 30;

    Person1.ContactInfo.Email = "ahmedalkoly185@gmail.com";
    Person1.ContactInfo.Phone = "+201500223299";
    Person1.ContactInfo.Address.POBox = "7777";
    Person1.ContactInfo.Address.ZipCode = "11194";
    Person1.ContactInfo.Address.StreetName = "Nour Al-Islam Street";
    Person1.ContactInfo.Address.BuildingNo = "13";

    Person1.Gender = enGender::Male;
    Person1.MaritalStatues = enMaritalStatus::Married;
    Person1.FavourateColor = enColor::Green;


	cout << "\t\tPerson Information\n";
    cout << "*************************************************************" << endl;
    cout << "Name: " << Person1.FirstName << " " << Person1.LastName << endl;
    cout << "Gender: " << Person1.Gender << endl;
    cout << "Age: " << Person1.Age << endl;
    cout << "Marital Status: " << Person1.MaritalStatues << endl;
    cout << "*************************************************************" << endl;

	cout << "\n\t\tContact Information" << endl;
    cout << "*************************************************************" << endl;
    cout << "Email: " << Person1.ContactInfo.Email << endl;
	cout << "Phone: " << Person1.ContactInfo.Phone << endl;
    cout << "Address: " << Person1.ContactInfo.Address.BuildingNo << " " << Person1.ContactInfo.Address.StreetName
         << ", POBox: " << Person1.ContactInfo.Address.POBox
		<< ", ZipCode: " << Person1.ContactInfo.Address.ZipCode << endl;
    cout << "*************************************************************" << endl;
	




    return 0;
}
