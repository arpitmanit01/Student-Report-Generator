#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<sstream>

char getgrade(double avg) {
	if (avg <= 100 && avg > 90) { return 'A'; }
	else if (avg <= 90 && avg > 80) { return 'B'; }
	else if (avg <= 80 && avg > 70) { return 'C'; }
	else if (avg <= 70 && avg > 60) { return 'D'; }
	else if (avg <= 60 && avg > 50) { return 'E'; }
	else{ return 'F'; }
}


using namespace std;
int main() {
	ofstream fout;
	fout.open("report.txt");
	

	if (fout.fail()) {
		cout << "Unable to open Destination File";
		exit(1);

	}

	ifstream fin;
	
	fin.open("details.txt");
	if (fin.fail()) {
		cout << "Unable to open Source file";
		exit(1);

	}
	
	fout << setw(20) << left << "Name"
		 << setw(10) << right << "Average"
		 << setw(10) << right << "Grade" << endl;
	string line(40, '-');
	fout << line << endl;
	
	string part;
	while ((getline(fin,part))) {
		
		istringstream iss(part);
		string name;
		string ss1, ss2, ss3;
		getline(iss, name, ':');
		getline(iss, ss1, ',');
		getline(iss, ss2, ',');
		getline(iss, ss3, ',');

		int s1 = atoi(ss1.c_str());
		int s2 = atoi(ss2.c_str());
		int s3 = atoi(ss3.c_str());

		double avg = (s1 + s2 + s3) / (double)3;
		char grade = getgrade(avg);
		//just printing the details
		
		fout << setw(20) << left << name
			 << setw(10) << right <<setprecision(2)<<fixed<< avg
			 << setw(10) << right << setprecision(2) << fixed<< grade << endl;

	}

	cout<<"Successfully parsed detail.txt and created report.txt!!!!!!!";
	getchar();

	return 0;
}