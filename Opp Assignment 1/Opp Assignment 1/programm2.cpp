#include <iostream>

using namespace std;

char* allocate();
void concatenate(char* str1, char* str2);
void compressString(char* str);
char* ReverseSentence(char* str_tobeReversed);
void Prurels(char** carray);

int words_no = 0;

int main()
{
	int option_menu = 0;
	do
	{
		cout << endl;
		cout << endl;
		cout << "	Select An Option From The Menu Below" << endl;
		cout << "	1-> Concatinate Strings" << endl;
		cout << "	2-> Compress String    " << endl;
		cout << "	3-> Reverse A Sentence " << endl;
		cout << "	4-> Plural of words    " << endl;
		cout << "	0-> Exit Program       " << endl;
		cout << "	";
		cin >> option_menu;
		cin.ignore();
		cout << endl;
		cout << endl;
		system("CLS");
		if (option_menu == 1)
		{
			char* str1_con = allocate();
			char* str2_con = allocate();
			concatenate(str1_con, str2_con);
		}
		else if (option_menu == 2)
		{
			char* str_comp = allocate();
			compressString(str_comp);
			delete[]str_comp;
			str_comp = nullptr;
		}
		else if (option_menu == 3)
		{
			char* str_reverse = allocate();
			cout << "	Reversed sentence is : " << endl;
			cout <<"	" <<ReverseSentence(str_reverse)<<endl;
			delete[]str_reverse;
			str_reverse = nullptr;
		}
		else if (option_menu == 4)
		{
			cout << "	Enter the number of words " << endl;
			cout << "	";
			cin >> words_no;
			cin.ignore();
			char** words_arr = new char* [words_no];
			for (int i = 0; i < words_no; i++)
			{
				words_arr[i] = allocate();
			}
			Prurels(words_arr);
			cout << "	Plural of words are " << endl;
			for (int i = 0; i < words_no; i++)
			{
				cout << "	" << words_arr[i] << endl;
			}
			for (int i = 0; i < words_no; i++)
			{
				delete[]words_arr[i];
			}
			delete[]words_arr;
			words_arr = nullptr;
		}
		else if (option_menu == 0)
		{
			cout << "	Exitting program" << endl;
		}
		else
		{
			cout << "	Invalid Option Selected From Menu" << endl;
		}
	} while (option_menu < 0 || option_menu>0);
	
}
char* allocate( )
{
	char temp_carray_stack[100];
	int temp_array_size = 0;
	cout << "	Enter String" << endl;
	cout << "	";
	cin.getline(temp_carray_stack,100);
	for (int i = 0; temp_carray_stack[i] != '\0'; i++)
	{
		temp_array_size++;
	}
	char* carr_ptr = new char[temp_array_size + 1];
	int j = 0;
	for ( j = 0; temp_carray_stack[j] != '\0'; j++)
	{
		carr_ptr[j] = temp_carray_stack[j];
	}
	carr_ptr[j] = '\0';
	
	return carr_ptr;
}

void concatenate(char* str1,char* str2)
{
	int size1 = 0, size2 = 0;
	char* str;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		size1++;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		size2++;
	}
	str2[size2] = ' ';
	int x = 0;
	int i = 0;
	for (i = size2 + 1; str2[x] != '\0'; i++)
	{
		str2[i] = str1[x];
		x++;
	}
	str2[i-1] = '\0';
	cout << "	String After Concatination : ";
	cout << str2 << endl;
}

void compressString(char* str)
{
	char temp;
	int x = 0;
	for (int i = 0;str[i] != '\0';i++)
	{
		temp = str[i];
		for (int j = i+1 ;str[j] != '\0';j++)
		{
			if (str[j]==temp)
			{
				
				for ( x = j;str[x] != '\0';x++)
				{
					str[x] = str[x+1];
				}
				str[x-1] = '\0';
				j = j - 1;
			}
		}
	}
	cout << "	String after Compression : ";
	cout << str << endl;
}

char* ReverseSentence(char* str_tobeReversed)
{
	int size_of_array = 0, size_of_word = 0;
	int spaces=0;
	for (int i = 0;str_tobeReversed[i] != '\0';i++)
	{
		size_of_array++;
	}
	char* temp_arr_toBeReversed = new char[size_of_array + 2];
	int a;
	for (a = 0; str_tobeReversed[a] != '\0'; a++)
	{
		temp_arr_toBeReversed[a] = str_tobeReversed[a];
	}
	temp_arr_toBeReversed[a] = ' ';
	temp_arr_toBeReversed[a + 1] = '\0';
	char* Reversed_string = new char[size_of_array+2];
	Reversed_string[size_of_array + 1] = '\0';
	int j = size_of_array;
	for (int i = 0;temp_arr_toBeReversed[i] != '\0'; i++)
	{
		size_of_word++;
		if (temp_arr_toBeReversed[i] == ' ')
		{
			size_of_word--;
			for (int x = i; x >= i - size_of_word; x--)
			{
				Reversed_string[j] = temp_arr_toBeReversed[x];
				j--;
			}
			size_of_word = 0;
		}
	}
	delete[]temp_arr_toBeReversed;
	temp_arr_toBeReversed = nullptr;
	return Reversed_string;
}

void Prurels(char** words_arr)
{
	char* temp_ptr = 0;
	int size_of_word = 0, x = 0;
	for (int i = 0; i < words_no; i++)
	{
		for (int j = 0; words_arr[i][j] != '\0'; j++)
		{
			size_of_word++;
		}
		if (words_arr[i][size_of_word-1] == 'h' && words_arr[i][size_of_word - 2] == 'c' || words_arr[i][size_of_word - 2] == 's')
		{
			temp_ptr = new char[size_of_word + 3];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word ] = 'e';
			temp_ptr[size_of_word + 1] = 's';
			temp_ptr[size_of_word + 2] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;
		}
		else if (words_arr[i][size_of_word-1] == 's')
		{
			temp_ptr = new char[size_of_word + 3];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word ] = 'e';
			temp_ptr[size_of_word + 1] = 's';
			temp_ptr[size_of_word + 2] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;
		}
		else if(words_arr[i][size_of_word-1] == 'y'&& (words_arr[i][size_of_word - 2] == 'o'|| words_arr[i][size_of_word - 2] == 'u' || words_arr[i][size_of_word - 2] == 'a' || words_arr[i][size_of_word - 2] == 'e' || words_arr[i][size_of_word - 2] == 'i') )
		{
			temp_ptr = new char[size_of_word + 2];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word ] = 's';
			temp_ptr[size_of_word + 1] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;
		}
		else if (words_arr[i][size_of_word-1] == 'y' &&( words_arr[i][size_of_word - 2] != 'o' || words_arr[i][size_of_word - 2] != 'u' || words_arr[i][size_of_word - 2] != 'a' || words_arr[i][size_of_word - 2] != 'e' || words_arr[i][size_of_word - 2] != 'i'))
		{
			temp_ptr = new char[size_of_word + 4];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word-1] = 'i';
			temp_ptr[size_of_word ] = 'e';
			temp_ptr[size_of_word + 1] = 's';
			temp_ptr[size_of_word + 2] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;

		}
		else  if (words_arr[i][size_of_word-1] == 'z' && (words_arr[i][size_of_word - 2] == 'o' || words_arr[i][size_of_word - 2] == 'u' || words_arr[i][size_of_word - 2] == 'a' || words_arr[i][size_of_word - 2] == 'e' || words_arr[i][size_of_word - 2] == 'i'))
		{
			temp_ptr = new char[size_of_word + 4];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word ] = 'z';
			temp_ptr[size_of_word + 1] = 'e';
			temp_ptr[size_of_word + 2] = 's';
			temp_ptr[size_of_word + 3] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;
		}
		else if (words_arr[i][size_of_word-1] == 'z' && (words_arr[i][size_of_word - 2] != 'o' || words_arr[i][size_of_word - 2] != 'u' || words_arr[i][size_of_word - 2] != 'a' || words_arr[i][size_of_word - 2] != 'e' || words_arr[i][size_of_word - 2] != 'i'))
		{
			temp_ptr = new char[size_of_word + 3];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word ] = 'e';
			temp_ptr[size_of_word + 1] = 's';
			temp_ptr[size_of_word + 2] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;
		}
		else
		{
			temp_ptr = new char[size_of_word + 2];
			for (x = 0; x < size_of_word; x++)
			{
				temp_ptr[x] = words_arr[i][x];
			}
			temp_ptr[size_of_word ] = 's';
			temp_ptr[size_of_word + 1] = '\0';
			delete[]words_arr[i];
			words_arr[i] = temp_ptr;
		}
		size_of_word = 0;
	}

}