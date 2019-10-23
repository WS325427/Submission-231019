#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	int iNumberofStudents, iNPassed = 0, iNFailed = 0;
	string sStudent[20], sgrade[20], smeangrade;
	int iMarks[20];
	double dMarkSum = 0, dmean;
	bool bdone = false;
	cout << "Stores up to 20 sets of data\n\n";

	do {
		cout << "Enter Number of Students: ";
		cin >> iNumberofStudents;
		cout << "\n\n";
		if (iNumberofStudents > 0 && iNumberofStudents <= 20)
		{
			bdone = true;
			for (int iCount = 0; iCount < iNumberofStudents; iCount++)
			{
				cout << "\nStudent Name: ";
				cin >> sStudent[iCount];
				cout << "Student Marks out of 100: ";
				cin >> iMarks[iCount];
				dMarkSum = iMarks[iCount] + dMarkSum;

				if (iMarks[iCount] <= 10 && iMarks[iCount] > 0)
				{
					sgrade[iCount] = "F";
				}
				else if (iMarks[iCount] <= 30 && iMarks[iCount] > 10)
				{
					sgrade[iCount] = "E\n";
				}
				else if (iMarks[iCount] <= 50 && iMarks[iCount] > 30)
				{
					sgrade[iCount] = "D\n";
				}
				else if (iMarks[iCount] <= 70 && iMarks[iCount] > 50)
				{
					sgrade[iCount] = "C\n";
				}
				else if (iMarks[iCount] <= 80 && iMarks[iCount] > 70)
				{
					sgrade[iCount] = "B\n";
				}
				else if (iMarks[iCount] <= 90 && iMarks[iCount] > 80)
				{
					sgrade[iCount] = "A\n";
				}
				else if (iMarks[iCount] <= 100 && iMarks[iCount] > 90)
				{
					sgrade[iCount] = "A*\n";
				}
				else
				{
					cout << "Marks out of range, try again\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					iCount--;

				}
			}
			cout << "\nPassed\n";
			for (int iCount = 0; iCount < iNumberofStudents; iCount++)
			{
				if (iMarks[iCount] > 50)
				{

					cout << sStudent[iCount] << ":" << sgrade[iCount] << "\n";
					iNPassed++;
				}
			}
			cout << "\nFailed\n";
			for (int iCount = 0; iCount < iNumberofStudents; iCount++)
			{
				if (iMarks[iCount] <= 50)
				{

					cout << sStudent[iCount] << ":" << sgrade[iCount] << "\n";
					iNFailed++;
				}
			}

			dmean = dMarkSum / iNumberofStudents;
			cout << "\nNumber Passed:" << iNPassed << "\n";
			cout << "Number Failed:" << iNFailed << "\n";
			cout << "Mean Average Marks:" << dmean << "\n";

			if (dmean <= 10 && dmean > 0)
			{
				smeangrade = "F";
			}
			else if (dmean <= 30 && dmean > 10)
			{
				smeangrade = "E\n";
			}
			else if (dmean <= 50 && dmean > 30)
			{
				smeangrade = "D\n";
			}
			else if (dmean <= 70 && dmean > 50)
			{
				smeangrade = "C\n";
			}
			else if (dmean <= 80 && dmean > 70)
			{
				smeangrade = "B\n";
			}
			else if (dmean <= 90 && dmean > 80)
			{
				smeangrade = "A\n";
			}
			else if (dmean <= 100 && dmean > 90)
			{
				smeangrade = "A*\n";
			}
			else
			{
				cout << "Grade out of bounds\n";
			}

			cout << "Mean Grade:" << smeangrade << "\n";
			int iCount = 0, itemp;
			string stemp;
			do
			{
				if (iMarks[0] > iMarks[iCount + 1])
				{
					iCount++;
				}
				else
				{
					itemp = iMarks[0];
					stemp = sStudent[0];
					iMarks[0] = iMarks[iCount + 1];
					sStudent[0] = sStudent[iCount + 1];
					iMarks[iCount + 1] = itemp;
					sStudent[iCount + 1] = stemp;
					iCount == 0;
				}
			} while (iCount < iNumberofStudents);
			cout << "Highest Score is "<< iMarks[0]<< ", achieved by " << sStudent[0];
		}
		else
		{
			cout << "Number too large or not a number\n\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (!bdone);
}

