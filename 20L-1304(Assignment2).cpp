#include<iostream>
#include<fstream>
using namespace std;
char*** allocating3darray(int  size, int cols)
{
	const int studentslength = 15;
	const int addresslength = 50;
	char*** Dimension = nullptr;
	Dimension = new char** [size];
	for (int i = 0; i < size; i++)
	{
		Dimension[i] = new char* [cols];
		for (int j = 0; j < cols; j++)
		{
			if (j == 1 || j == 2)
				Dimension[i][j] = new char[studentslength];
			else
				Dimension[i][j] = new char[addresslength];
		}



	}
	return Dimension;

}
char* getnameandaddress()
{
	const int maximum = 50;
    char temporary[maximum];
    cin.getline(temporary, maximum);

	int length = 1;
	for (int i = 0; temporary[i] != '\0'; i++)
		length++;
	
	
	char* permenant = new char[length];
	
	for (int i = 0; i < length; i++)
		permenant[i ]= temporary[i];
	return permenant;
		
}

void Print_Array(char***& array3D, int size)
{
	cout << "You have entered the following information: " << endl;
	int count;
	for (int i = 0; i < size; i++)
	{
		count = 0;
		cout << "Data Entered of " << i + 1 << " student " << endl;
		for (int j = 0; j < 3; j++)
		{

			if (count == 0)
				cout << "First Name: " << array3D[i][j] << " " << endl;
			if (count == 1)
				cout << "Second Name: " << array3D[i][j] << " " << endl;
			if (count == 2)
				cout << "Address: " << array3D[i][j] << " " << endl;
			count++;

			cout << endl;
		}
	}
}

void deallocating3darray(char***& arraydimension, int length)
{
	
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 3; j++)
			delete[]arraydimension[i][j];

	}

	for (int i = 0; i < length; i++)

		delete[] arraydimension[i];


	delete[] arraydimension;
	arraydimension = nullptr;
}






int main()
{
	int number;
	
	int count;
	
	
	cout << "Enter the number of students=";
	cin >> number;
	char*** Students= allocating3darray(number,3);
	cin.ignore();
	for (int i = 0; i < number; i++)
	{
		count = 0;
		
		for (int j = 0; j < 3; j++)
			
		{
			cout << "Enter student " << i+1 << " data: " << endl;
			for (int k = 0; k <1 ; k++)

			{
				if(count==0)
				cout << "Enter First name: " << endl;
				if (count == 1)
					cout << "Enter Last name: " << endl;
				if (count == 2)
					cout << "Enter Address: " << endl;
				
			
				Students[i][j] = getnameandaddress();
				
				
			}
			cout << endl;
			count++;

		}
	}
	system("cls");
	Print_Array(Students, number);

	deallocating3darray(Students, number);


	return 0;
}
