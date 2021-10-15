#include "fraction.h"
#include "myArray.h"

void title(string);
void mainMenu();
void inputSelect(int&, int, int);
void fractionMenu();
void arrayMenu();

int main() {
	int choice;

	while (1) {
		system("cls");
		title(" WELCOME TO OUR PROGRAM");
		mainMenu();
		inputSelect(choice, 1, 3);

		if (choice == 1) {
		fractionProgram:
			system("cls");

			title("A PROGRAM PERFORMING FRACTION");
			fractionMenu();
			inputSelect(choice, 1, 7);

			system("cls");

			FRACTION fraction1, fraction2;

			// input fractions
			switch (choice)
			{
			case 1:
			case 2:
				cout << "\nEnter fraction\n";
				cin >> fraction1;
				cout << "\n=> Fraction: ";
				cout << fraction1;
				cout << "\n__________________________________\n";
				break;
			case 3:
			case 4:
			case 5:
			case 6:
				cout << "\nEnter the first fraction\n";
				cin >> fraction1;
				cout << "\n=> Fraction 1: ";
				cout << fraction1;
				cout << "\n__________________________________"
					<< "\nEnter the second fraction\n";
				cin >> fraction2;
				cout << "\n=> Fraction 2: ";
				cout << fraction2;
				cout << "\n__________________________________\n";
				break;
			case 7:
				continue;
			}

			switch (choice) {
			case 1: {
				FRACTION fraction;
				cout << "\n== Reduced fraction: ";
				cout << fraction1.reduction();
				break;
			}

			case 2: {
				cout << "\n== Inversion fraction: ";
				cout << fraction1.inversion();
				break;
			}

			case 3: {
				cout << fraction1;
				cout << " + ";
				cout << fraction2;
				cout << " = ";
				cout << fraction1 + fraction2;
				break;
			}

			case 4: {
				cout << fraction1;
				cout << " - ";
				cout << fraction2;
				cout << " = ";
				cout << fraction1 - fraction2;
				break;
			}

			case 5: {
				cout << fraction1;
				cout << " * ";
				cout << fraction2;
				cout << " = ";
				cout << fraction1 * fraction2;
				break;
			}

			case 6: {
				cout << fraction1;
				cout << " / ";
				cout << fraction2;
				cout << " = ";
				cout << fraction1 / fraction2;
				break;
			}
			}
			cout << endl;
			system("pause");
			goto fractionProgram;
		}
		else if (choice == 2) {
			system("cls");
			MY_ARRAY array;
			int choice;

			cin >> array;

			do {
				system("cls");

				title(" A PROGRAM PERFORMING ARRAY");
				arrayMenu();
				inputSelect(choice, 1, 8);

				system("cls");

				switch (choice) {
				case 1: {
					cin >> array;
					break;
				}

				case 2: {
					if (!array.getSize()) {
						cout << "\nEmpty array\n\n";
						break;
					}
					cout << "Element in array is: ";
					cout << array;
					cout << endl;
					break;
				}

				case 3: {
					cout << "The size of array: " << array.getSize();
					cout << endl;
					break;
				}

				case 4: {
					int pos;
					if (!array.getSize()) {
						cout << "\nEmpty array\n\n";
						break;
					}
					do {
						cout << "Enter the position: ";
						cin >> pos;

						if (pos < 0 || pos >= array.getSize())
							cout << "a[" << pos << "]" << " is unspecified." << endl << endl;
					} while (pos < 0 || pos >= array.getSize());

					cout << "a[" << pos << "] = " << array[pos] << endl;

					break;
				}

				case 5: {
					if (!array.getSize()) {
						cout << "\nEmpty array\n\n";
						break;
					}

					int value;
					cout << "Enter the value you want find: ";
					cin >> value;

					if (array.find(value) == -1)
						cout << "Not found.";
					else
						cout << "a[" << array.find(value) << "] = " << value;

					cout << endl;
					break;
				}

				case 6: {
					if (!array.getSize()) {
						cout << "\nEmpty array\n\n";
						break;
					}
					MY_ARRAY arraySort;

					array.copyArray(arraySort);
					arraySort.sortIncrease();

					cout << "Array after sort increasingly: ";
					cout << arraySort;
					cout << endl;
					
					break;
				}

				case 7: {
					if (!array.getSize()) {
						cout << "\nEmpty array\n\n";
						break;
					}
					MY_ARRAY arraySort;

					array.copyArray(arraySort);
					arraySort.sortDecrease();

					cout << "Array after sort decreasingly: ";
					cout << arraySort;
					cout << endl;

					break;
				}

				case 8:
					continue;

				default:
					cout << "Your choice not available." << endl << endl;
				}

				system("pause");

			} while (choice != 8);
		}
		else {
			cout << "======================================================================"
				<< "\n                 *** THANK YOU! SEE YOU LATER! ***\n";
			return 0;
		}
	}
}

void title(string message) {
	system("cls");
	cout << "*******************************************************\n"
		<< "  *                                                 *\n"
		<< "***";
	for (int i = 0; i < (50 - message.size()) / 2; i++)
		cout << " ";
	cout << message;
	for (int i = 0; i < (50 - message.size()) / 2; i++)
		cout << " ";
	cout << "***\n"
		<< "  *                                                 *\n"
		<< "*******************************************************\n";
}

void inputSelect(int& ans, int beg, int end) {
	cout << "Your choice: ";
	cin >> ans;
	if (ans<beg || ans>end) {
		cout << "Enter error! Please enter again!\n";
		return inputSelect(ans, beg, end);
	}
}

void mainMenu()
{
	cout << "  ***************************************************\n"
		<< "  *                                                 *\n"
		<< "  *   [1] A program performing Fraction             *\n"
		<< "  *                                                 *\n"
		<< "  *   [2] A program performing Array                *\n"
		<< "  *                                                 *\n"
		<< "  *   [3] Exit                                      *\n"
		<< "  *                                                 *\n"
		<< "  ***************************************************\n\n";
}

void fractionMenu()
	{

	cout << "  ***************************************************\n"
		<< "  *                                                 *\n"
		<< "  *   [1] Reduce fraction.                          *\n"
		<< "  *                                                 *\n"
		<< "  *   [2] Inversion fraction.                       *\n"
		<< "  *                                                 *\n"
		<< "  *   [3] Plus 2 fractions.                         *\n"
		<< "  *                                                 *\n"
		<< "  *   [4] Subtract 2 fractions.                     *\n"
		<< "  *                                                 *\n"
		<< "  *   [5] Multiply 2 fractions.                     *\n"
		<< "  *                                                 *\n"
		<< "  *   [6] Divide 2 fractions.                       *\n"
		<< "  *                                                 *\n"
		<< "  *   [7] Back.                                     *\n"
		<< "  *                                                 *\n"
		<< "  ***************************************************\n\n";
	}

void arrayMenu()
{
	cout << "*******************************************************\n"
		<< "*                                                     *\n"
		<< "* [1]. Input array.                                   *\n"
		<< "*                                                     *\n"
		<< "* [2]. Output array.                                  *\n"
		<< "*                                                     *\n"
		<< "* [3]. Get array size.                                *\n"
		<< "*                                                     *\n"
		<< "* [4]. Get an item at another position (index).       *\n"
		<< "*                                                     *\n"
		<< "* [5]. Find an item in array.                         *\n"
		<< "*                                                     *\n"
		<< "* [6]. Sort increasingly.                             *\n"
		<< "*                                                     *\n"
		<< "* [7]. Sort decreasingly.                             *\n"
		<< "*                                                     *\n"
		<< "* [8]. Back.                                          *\n"
		<< "*                                                     *\n"
		<< "*******************************************************\n";
}