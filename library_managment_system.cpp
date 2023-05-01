/*this code contains books data stored in file name book.data which is already uploaded on git.
it also has student data stored in file name student.data which is also uploaded on git
for running this program it is pre-requisite
here by default the password is admin*/
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <iostream>

using namespace std;

class book
{
    char book_number[30];
    char book_name[50];
    char author_name[20];

public:
    void create_book()
/*this code contains books data stored in file name book.data which is already uploaded on git.
it also has student data stored in file name student.data which is also uploaded on git
for running this program it is pre-requisite
here by default the password is admin*/
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <iostream>

using namespace std;

class book
{
    char book_number[30];
    char book_name[50];
    char author_name[20];

public:
    void create_book()
    {
        cout << "\nEnter The Book Number: ";
        cin >> book_number;
        cout << "\nEnter The Name of The Book: ";
        cin.ignore();
        cin.getline(book_name, 50);
        cout << "\nEnter The Author's Name: ";
        cin.ignore();
        cin.getline(author_name, 50);
        cout << "\t\t\n\nBook Created Successfully...";
    }

    void show_book()
    {
        cout << "\nBook Number: " << book_number;
        cout << "\nBook Name: " << book_name;
        cout << "\nAuthor's Name: " << author_name;
    }
    void modify_book()
    {
        cout << "\nBook number : " << book_number;
        cout << "\nModify Book Name : ";
        cin.ignore();
        cin.getline(book_name, 50);
        cout << "\nModify Author's Name: ";
        cin.ignore();
        cin.getline(author_name, 50);
    }
    char *getbooknumber()
    {
        return book_number;
    }
    void report()
    {
        cout << book_number << setw(30) << book_name << setw(30) << author_name << endl;
    }
};

class student
{
    char ID_number[20];
    char Student_name[20];
    char stbno[6];
    int token;

public:
    void create_student()
    {
        cout << "\nEnter The ID Number ";
        cin >> ID_number;
        cout << "\n\nEnter The Name of The Student: ";
        cin >> Student_name;
        token = 0;
        stbno[0] = '/0';
        cout << "\t\t\n\nStudent Record Created Successfully...";
    }
    void show_student()
    {
        cout << "\nID Number: " << ID_number;
        cout << "\nStudent Name: ";
        puts(Student_name);
        cout << "\nNo of Book issued: " << token;
        if (token == 1)
            cout << "\nBook No " << stbno;
    }
    void modify_student()
    {
        cout << "\nID Number: " << ID_number;
        cout << "\nModify Student Name: ";
        cin.ignore();
        cin.getline(Student_name, 50);
    }
    char *get_ID_number()
    {
        return ID_number;
    }
    char *retstbno()
    {
        return stbno;
    }
    int rettoken()
    {
        return token;
    }
    void addtoken()
    {
        token = 1;
    }
    void resettoken()
    {
        token = 0;
    }
    void getstbno(char t[])
    {
        strcpy(stbno, t);
    }
    void report()
    {
        cout << "\t" << ID_number << setw(20) << Student_name << setw(10) << token << endl;
    }
};

fstream fp, fp1;
book bk;
student st;
void write_book()
{
    system("cls");
    int more_or_main;
    fp.open("book.dat", ios::out | ios::app);
    do
    {
        bk.create_book();
        fp.write((char *)&bk, sizeof(book));
        cout << "\nPress 1 to add more books.";
        cout << "\nPress 2 to return to main menu.\n";
        cout << "Enter: ";
        cin >> more_or_main;
    } while (more_or_main == 1);
    fp.close();
}
void write_student()
{
    system("cls");
    int more_or_main;
    fp.open("student.dat", ios::out | ios::app);
    do
    {
        st.create_student();
        fp.write((char *)&st, sizeof(student));
        cout << "\nPress 1 to add more students.";
        cout << "\nPress 2 to return to main menu.\n";
        cout << "Enter: ";
        cin >> more_or_main;
    } while (more_or_main == 1);
    fp.close();
}
void display_a_book(char n[])
{
    system("cls");
    cout << "\nBOOK DETAILS\n";
    int check = 0;
    fp.open("book.dat", ios::in);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (strcmpi(bk.getbooknumber(), n) == 0)
        {
            bk.show_book();
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
        cout << "\n\nBook does not exist";
    getch();
}
void display_a_student(char n[])
{
    system("cls");
    cout << "\nSTUDENT DETAILS\n";
    int check = 0;
    fp.open("student.dat", ios::in);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if ((strcmpi(st.get_ID_number(), n) == 0))
        {
            st.show_student();
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
        cout << "\n\nStudent does not exist";
    getch();
}
void modify_book()
{
    system("cls");
    char n[20];
    int found = 0;
    cout << "\n\n\tMODIFY BOOK";
    cout << "\n\n\tEnter The book number: ";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    while (fp.read((char *)&bk, sizeof(book)) && found == 0)
    {
        if (strcmpi(bk.getbooknumber(), n) == 0)
        {
            bk.show_book();
            cout << "\nEnter The New Details of book" << endl;
            bk.modify_book();
            int pos = -1 * sizeof(bk);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&bk, sizeof(book));
            cout << "\n\n\t Record Updated Successfully...";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}