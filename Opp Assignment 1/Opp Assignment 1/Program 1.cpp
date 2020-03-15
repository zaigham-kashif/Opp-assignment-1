//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//int menu();
//void allocate(int***matrix, int size);
//void deAllocate(int***ptr_matrix, int size);
//void input(int***ptr_matrix, int size);
//void Print(int*** ptr_matrix, int size);
//int*** readFromFile();
//bool multiplication(int** matrix1, int** matrix2, int*** multiplied_matrix, int size1, int size2);
//void deleteRow(int*** Matrix, int& size_of_matrix);
//void swap(int*** Matrix, int size);
//
//int control_flag = 0;
//int file_control_flag = 0;
//
//ifstream fin;
//int matrix_no = 0, sizeof_matrix1_fromFile = 0, sizeof_matrix2_fromFile = 0;
//
//int main()
//{
//	int sizeof_matrix1 = 0, sizeof_matrix2 = 0, sizeof_matrix3 = 0;
//	int*** matrix1 = new int** [1];
//	int*** matrix2 = new int** [1];
//	int*** matrix3 = new int** [1];
//	int*** matrix1_fromFile = new int** [1];
//	int*** matrix2_fromFile = new int** [1];
//	int*** multiplied_matrix = new int** [1];
//
//	int menu_option = 0;
//	int menu_option1 = 0;
//	do
//	{
//		menu_option = menu();
//		if (menu_option == 1 && control_flag == 0)
//		{
//			system("CLS");
//			cout << "	Enter the size of the matrix : ";
//			cin >> sizeof_matrix1;
//			allocate(matrix1, sizeof_matrix1);
//			control_flag = 1;
//			cout << "	Memory Alloacted successfuly for matrix" << endl;
//		}
//		else if (menu_option == 2 && control_flag == 1)
//		{
//			system("CLS");
//			input(matrix1, sizeof_matrix1);
//			control_flag = 2;
//		}
//		else if (menu_option == 3 && control_flag == 2)
//		{
//			system("CLS");
//			Print(matrix1, sizeof_matrix1);
//		}
//		else if (menu_option == 4 && control_flag == 2)
//		{
//			system("CLS");
//			deAllocate(matrix1, sizeof_matrix1);
//			cout << "	Memory Deallocated Successfuly" << endl;
//			control_flag = 0;
//		}
//		else if (menu_option == 5 && file_control_flag == 0)
//		{
//			system("CLS");
//			matrix1_fromFile = readFromFile();
//			if (matrix1_fromFile != nullptr)
//			{
//				Print(matrix1_fromFile, sizeof_matrix1_fromFile);
//			}
//			else
//			{
//				cout << "	Matrix is not an upper triangular matrix " << endl;
//			}
//			matrix2_fromFile = readFromFile();
//			if (matrix2_fromFile != nullptr)
//			{
//				Print(matrix2_fromFile, sizeof_matrix2_fromFile);
//				fin.close();
//			}
//			else
//			{
//				
//				cout << "	Matrix is not an upper triangular matrix " << endl;
//				fin.close();
//			}
//			if (matrix1_fromFile != nullptr && matrix2_fromFile != nullptr)
//			{
//				file_control_flag = 1;
//			}
//		}
//		else if (menu_option == 6 )
//		{
//			do
//			{
//				cout << "	********************************" << endl;
//				cout << "	Select an option from menu below" << endl;
//				cout << "	--------------------------------" << endl;
//				cout << "	1-> Input Matrix to Multiply    " << endl;
//				if (file_control_flag == 1)
//				{
//					cout << "	--------------------------------" << endl;
//					cout << "	2-> Multiply Matrix From file    " << endl;
//				}
//				else if(file_control_flag==0)
//				{
//					cout << "	----------------------------------" << endl;
//					cout << "	First Read Matrix From file to multiply" << endl;
//				}
//				else
//				{
//
//				}
//				cout << "	--------------------------------" << endl;
//				cout << "	0->Back To Main Menu            " << endl;
//				cout << "	--------------------------------" << endl;
//				cout << "	";
//				cin >> menu_option1;
//				if (menu_option1 == 1)
//				{
//					system("CLS");
//					cout << "	Enter the size of Matrix one : ";
//					cin >> sizeof_matrix2;
//					cout << endl;
//					allocate(matrix2, sizeof_matrix2);
//					input(matrix2, sizeof_matrix2);
//					Print(matrix2, sizeof_matrix2);
//					cout << "	Enter the size of Matrix two : ";
//					cin >> sizeof_matrix3;
//					cout << endl;
//					allocate(matrix3, sizeof_matrix3);
//					input(matrix3, sizeof_matrix3);
//					Print(matrix3, sizeof_matrix3);
//					if (multiplication(*matrix2, *matrix3, multiplied_matrix, sizeof_matrix2, sizeof_matrix3) == true)
//					{
//						cout << "	Product of provided matrices is " << endl;
//						Print(multiplied_matrix, sizeof_matrix3);
//						deAllocate(multiplied_matrix, sizeof_matrix3);
//					}
//					else
//					{
//						cout << "	Product of matrices is not possible " << endl;
//					}
//					deAllocate(matrix2, sizeof_matrix2);
//					deAllocate(matrix3, sizeof_matrix3);
//
//				}
//				else if (menu_option1 == 2 && file_control_flag == 1)
//				{
//					system("CLS");
//					if (matrix1_fromFile != nullptr && matrix2_fromFile != nullptr)
//					{
//						if (multiplication(*matrix1_fromFile, *matrix2_fromFile, multiplied_matrix, sizeof_matrix1_fromFile, sizeof_matrix2_fromFile) == true)
//						{
//							//multiplication(*matrix1_fromFile, *matrix2_fromFile, multiplied_matrix, sizeof_matrix1_fromFile, sizeof_matrix2_fromFile);
//							Print(multiplied_matrix, sizeof_matrix1_fromFile);
//							deAllocate(multiplied_matrix, sizeof_matrix1_fromFile);
//							file_control_flag = 3;
//						}
//						else
//						{
//							cout << "	Product of matrices is not possible " << endl;
//						}
//
//					}
//					if (matrix1_fromFile != nullptr)
//					{
//						deAllocate(matrix1_fromFile, sizeof_matrix1_fromFile);
//					}
//					if (matrix2_fromFile != nullptr)
//					{
//						deAllocate(matrix2_fromFile, sizeof_matrix2_fromFile);
//						fin.close();
//					}
//				}
//				else
//				{
//					system("CLS");
//					cout << "	Invalid Option Selected" << endl;
//				}
//
//			} while (menu_option1<0||menu_option1>0);
//
//		}
//		else if (menu_option == 7 && control_flag == 2)
//		{
//			system("CLS");
//			swap(matrix1, sizeof_matrix1);
//		}
//		else if (menu_option == 8 && control_flag == 2)
//		{
//			system("CLS");
//			deleteRow(matrix1, sizeof_matrix1);
//			Print(matrix1, sizeof_matrix1);
//		}
//		else if (menu_option == 0)
//		{
//			system("CLS");
//			cout << "	Exitting Program " << endl;
//		}
//		else
//		{
//			system("CLS");
//			cout << "	Invalid Option Selected " << endl;
//		}
//	} while (menu_option<0||menu_option>0);
//
//}
//int menu()
//{
//	int menu_option = 0;
//	if (control_flag == 0)
//	{
//		cout << "	********************************" << endl;
//		cout << "	Select an option from menu below" << endl;
//		cout << "	-------------------" << endl;
//		cout << "	1->Allocate Memory " << endl;
//		if (file_control_flag == 0)
//		{
//			cout << "	-------------------" << endl;
//			cout << "	5->Read From File  " << endl;
//		}
//		cout << "	-------------------" << endl;
//		cout << "	6->Multiply Matrix " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	0->Exit            " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	";
//		cin >> menu_option;
//		cout << endl;
//		cout << endl;
//		return menu_option;
//	}
//	else if (control_flag == 1)
//	{
//		cout << "	********************************" << endl;
//		cout << "	2->Input Matrix    " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	5->Read From File  " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	6->Multiply Matrix " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	0->Exit            " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	";
//		cin >> menu_option;
//		cout << endl;
//		cout << endl;
//		return menu_option;
//	}
//	else if (control_flag == 2)
//	{
//		cout << "	3->Print Matrix    " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	4->Dealocate Memory" << endl;
//		cout << "	-------------------" << endl;
//		cout << "	5->Read From File  " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	6->Multiply Matrix " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	7->Swap Rows       " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	8->Delete Row      " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	0->Exit            " << endl;
//		cout << "	-------------------" << endl;
//		cout << "	";
//		cin >> menu_option;
//		cout << endl;
//		cout << endl;
//		return menu_option;
//	}
//
//}
//void allocate(int***matrix, int size)
//{
//	int count = size;
//	int** dptr_matrix = new int* [size];
//	for (int j = 0; j < size; j++)
//	{
//			dptr_matrix[j] = new int[count];
//			count--;
//	}
//	*matrix = dptr_matrix;
//}
//
//
//void deAllocate(int*** ptr_matrix, int size)
//{
//	int** dptr_matrix = *ptr_matrix;
//	for (int i = 0; i < size; i++)
//	{
//		delete [] dptr_matrix[i];
//	}
//	delete[]dptr_matrix;
//	dptr_matrix = nullptr;
//}
//
//void input(int*** ptr_matrix, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (i <= j)
//			{
//				cout << "	Enter Value : " << i + 1 << "*" << j + 1 <<"  ";
//				cin >> ptr_matrix[0][i][j - i];
//			}
//		}
//		cout << endl;
//	}
//}
//
//void Print(int***ptr_matrix, int size)
//{
//	cout << "	Row wise view : " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "					";
//		for (int j = 0; j < size; j++)
//		{
//			if (i <= j)
//			{
//				if (ptr_matrix[0][i][j - i] > 9)
//				{
//					cout << "  ";
//				}
//				else if (ptr_matrix[0][i][j - i] > 99)
//				{
//					cout << " ";
//				}
//				else
//				{
//					cout << "   ";
//				}
//				cout<< ptr_matrix[0][i][j - i];
//			}
//			else
//			{
//				cout << "   " << 0;
//			}
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << endl;
//
//	cout << "	Column wise view : " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "					";
//		for (int j = 0; j < size; j++)
//		{
//			if (j <= i)
//			{
//				if (ptr_matrix[0][j][i - j] > 9)
//				{
//					cout << "  ";
//				}
//				else if (ptr_matrix[0][j][i - j] > 99)
//				{
//					cout << " ";
//				}
//				else
//				{
//					cout << "   ";
//				}
//				cout << ptr_matrix[0][j][i - j];
//			}
//			else
//			{
//				cout << "   " << 0;
//			}
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << endl;
//	
//}
//
//int*** readFromFile()
//{ 
//	matrix_no++;
//	int test = 0, data = 0, size = 0, garbage = 0, seak_value = 0;
//	bool flag = true;
//	if (!fin.is_open())
//	{
//		fin.open("sampleMatrices.txt");
//	}
//	if (matrix_no == 1)
//	{
//		fin >> sizeof_matrix1_fromFile;
//		size = sizeof_matrix1_fromFile;
//	}
//	else if (matrix_no == 2)
//	{
//		fin >> sizeof_matrix2_fromFile;
//		size = sizeof_matrix2_fromFile;
//	}
//
//	for (int i = 0;i < size;i++)
//	{
//		for (int j = 0;j < size;j++)
//		{
//			if (i<=j)
//			{
//				fin >> data;
//			}
//			else
//			{
//				fin >> test;
//				if ((test != 0)&&(flag==true))
//				{
//					flag = false;
//				}
//			}
//		}
//		
//	}
//	
//	if (flag == true)
//	{
//		int*** Matrix_fromFile = new int** [1];
//		allocate(Matrix_fromFile, size);
//		if (matrix_no == 1)
//		{
//			fin.seekg(2, ios::beg);
//		}
//		else if (matrix_no == 2)
//		{
//			fin.clear();
//			seak_value = ((((sizeof_matrix1_fromFile * 2) + 1) * (sizeof_matrix1_fromFile)) + 4);
//			fin.seekg(seak_value, ios::beg);
//		}
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (i <= j)
//				{
//					fin >> Matrix_fromFile[0][i][j-i];
//				}
//				else
//				{
//					fin >> garbage;
//				}
//			}
//
//		}
//		return Matrix_fromFile;
//	}
//	else
//	{
//		flag = true;
//		test = 0;
//		return nullptr;
//	}
//	
//}
//
//bool multiplication(int** matrix1, int** matrix2,int ***multiplied_matrix,int size1,int size2)
//{
//	if (size1 == size2)
//	{
//		int size = size1;
//		allocate(multiplied_matrix, size);
//		int x = 0, y = 0;
//		int k = 0;
//		int sum = 0;
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				for (k = 0; k < size; k++)
//				{
//					if ((i <= k) && (k <= j))
//					{
//						x = matrix1[i][k - i];
//						y = matrix2[k][j - k];
//						sum = sum + (x * y);
//					}
//				}
//				if (i <= j)
//				{
//					multiplied_matrix[0][i][j - i] = sum;
//				}
//				sum = 0;
//			}
//		}
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//
//}
//
//void deleteRow(int*** Matrix, int &size_of_matrix)
//{
//	int row_no = 0;
//	int** temp_matrix = new int* [size_of_matrix];
//	for (int x = 0; x < size_of_matrix; x++)
//	{
//		temp_matrix[x] = new int[size_of_matrix];
//	}
//	for (int i = 0; i < size_of_matrix; i++)
//	{
//		for (int j = 0; j < size_of_matrix; j++)
//		{
//			if (i <= j)
//			{
//				temp_matrix[i][j] = Matrix[0][i][j - i];
//			}
//			else
//			{
//				temp_matrix[i][j] = 0;
//			}
//		}
//	}
//	deAllocate(Matrix,size_of_matrix);
//	cout << "	Enter Row Number : ";
//	cin >> row_no;
//	cout << endl;
//	row_no--;
//	delete[]temp_matrix[row_no];
//	for (int i = row_no; i < size_of_matrix-1; i++)
//	{
//		temp_matrix[i] = temp_matrix[i + 1];
//	}
//	for (int i = row_no; i < size_of_matrix - 1; i++)
//	{
//		for (int j = 0; j < size_of_matrix-1; j++)
//		{
//			temp_matrix[j][i] = temp_matrix[j][i + 1];
//		}
//	}
//	size_of_matrix--;
//	allocate(Matrix,size_of_matrix);
//	for (int i = 0; i < size_of_matrix; i++)
//	{
//		for (int j = 0; j < size_of_matrix; j++)
//		{
//			if (i <= j)
//			{
//				Matrix[0][i][j - i] = temp_matrix[i][j];
//			}
//		}
//	}
//	for (int x = 0; x < size_of_matrix; x++)
//	{
//		delete[]temp_matrix[x];
//	}
//	delete[]temp_matrix;
//	temp_matrix = nullptr;
//}
//
//void swap(int*** Matrix,int size)
//{
//	int** temp_matrix = new int* [size];
//	int* Temp_ptr = nullptr;
//	for (int x = 0; x < size; x++)
//	{
//		temp_matrix[x] = new int[size];
//	}
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (i <= j)
//			{
//				temp_matrix[i][j] = Matrix[0][i][j - i];
//			}
//			else
//			{
//				temp_matrix[i][j] = 0;
//			}
//		}
//	}
//	int row1, row2;
//	cout << "	Enter the row you want to swap : ";
//	cin >> row1;
//	cout << "	Enter the row you want to swap with : ";
//	cin >> row2;
//	row1--;
//	row2--;
//	Temp_ptr = temp_matrix[row1];
//	temp_matrix[row1] = temp_matrix[row2];
//	temp_matrix[row2] = Temp_ptr;
//	cout << "	Matrix After Swapping Rows " << endl;
//	cout << endl;
//	cout << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "						  ";
//		for (int j = 0; j < size; j++)
//		{
//			cout << " " << temp_matrix[i][j];
//		}
//		cout << endl;
//	}
//	for (int x = 0; x < size; x++)
//	{
//		delete[]temp_matrix[x];
//	}
//	delete[]temp_matrix;
//	temp_matrix = nullptr;
//}
