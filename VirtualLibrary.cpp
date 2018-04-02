//===========================================================
// File Name: VirtualLibrary.cpp
// Author: Alex Groenewold
// Date: 11/24/16
// Description: A database that provides info for books
// Collaborators: None
//===========================================================
#include <iostream>
#include <fstream>
using namespace std;

// Database: My database will store information about books including the title,
// author, year of publication, and the type of book
// The user will be able to add a book to the library.
// They will also be able to remove a book, update a books information,
// search for a book, and calculate a total for each type of book they have

class BookInfo
{
public:
  string title;
  string author;
  string year;
  string type;

  /**
    *Default Constructor
    *Sets all data members to a default value
    */
  BookInfo()
          // Set parameters to default values
          :title(""), author(""), year(""), type("")
           {

           }

  /**
    *Constructor
    *
    *@Param string title A holder for book titles
    *@Param string author A holder for book authors
    *@Param int year A holder for book years of publications
    *@Param string type A holder for book types
    */
  BookInfo(string title, string author, string year, string type)

           // Set parameters to the classes data members
           :title(title), author(author), year(year), type(type)
           {

           }

  /**
    *A method that lets user add a book
    *
    *@Param string title A holder for book titles
    *@Param string author A holder for book authors
    *@Param int year A holder for book years of publications
    *@Param string type A holder for book types
    *@Param int numOfBooks A holder for the total number of books in the database
    *@Param int index A holder for the book index
    *@Param BookInfo books A holder for each book and it's data
    */
  void addBook(string &title, string &author, string &year, string &type, int &numOfBooks, int index, BookInfo *books){
   const int STOP = 1;
   for(int j = 0; j < STOP; j++){

    // Prompt user to enter new books data
    cin.ignore();
    cout << "Please enter a title" << endl;
    getline(cin, books[index].title);
    cout << "The authors last name" << endl;
    getline(cin, books[index].author);
    cout << "The year it was published" << endl;
    getline(cin, books[index].year);
    cout << "The type of book it is" << endl;
    getline(cin, books[index].type);
    }
  }

  /**
    *A method that lets user remove a book
    *
    *@Param string title A holder for book titles
    *@Param string author A holder for book authors
    *@Param int year A holder for book years of publications
    *@Param string type A holder for book types
    *@Param int numOfBooks A holder for the total number of books in the database
    *@Param BookInfo books A holder for each book and it's data
    *@Param char erase A variable used to either remove or keep a book
    */
  void removeBook(string &title, string &author, string &year, string &type, int numOfBooks, BookInfo *books, char &erase){
    long maxNum = 1000;
    string removeABook;

    // Prompt user to enter title of book to remove
    cout << "Enter the title of the book you would like to remove" << endl;
    cin >> removeABook;
    for(int j = 0; j < numOfBooks; j++){
      if(removeABook == books[j].title){
        // Print chosen books data
        cout << books[j].title << endl;
        cout << books[j].author << endl;
        cout << books[j].year << endl;
        cout << books[j].type << endl;

        // Confirm that user would like to remove book
        cout << "Are you sure you would like to delete this book? [Y]es or [N]o?" << endl;
        cin >> erase;
      }
    }
  }
  /**
    *A method that lets user update book
    *
    *@Param string title A holder for book titles
    *@Param string author A holder for book authors
    *@Param int year A holder for book years of publications
    *@Param string type A holder for book types
    *@Param int numOfBooks A holder for the total number of books in the database
    *@Param BookInfo books A holder for each book and it's data
    */
  void updateBook(string &title, string &author, string &year, string &type, int numOfBooks, BookInfo *books){
    string updateABook;

    // Prompt user to enter title of book to update
    cout << "Please enter the title of the book you would like to update" << endl;
    cin >> updateABook;
    for(int j = 0; j < numOfBooks; j++){
      if(updateABook == books[j].title){
        // Prompt user to update books data
        cin.ignore();
        cout << "Enter a new title" << endl;
        getline(cin, books[j].title);
        cout << "Enter a new author" << endl;
        getline(cin, books[j].author);
        cout << "Enter a new publication year" << endl;
        getline(cin, books[j].year);
        cout << "Enter a new type" << endl;
        getline(cin, books[j].type);
      }
    }
  }

  /**
    *A method that lets user find book
    *
    *@Param string title A holder for book titles
    *@Param string author A holder for book authors
    *@Param int year A holder for book years of publications
    *@Param string type A holder for book types
    *@Param int numOfBooks A holder for the total number of books in the database
    *@Param BookInfo books A holder for each book and it's data
    */
  void findBook(string &title, string &author, string &year, string &type, int numOfBooks, BookInfo *books){
    string searchForBook;

    // Prompt user to enter title of book to find
    cout << "Please enter the title of the book you would like to find" << endl;
    cin >> searchForBook;
    for(int j = 0; j < numOfBooks; j++){
      if(searchForBook == books[j].title){

        // Print chosen books data
        cout << books[j].title << endl;
        cout << books[j].author << endl;
        cout << books[j].year << endl;
        cout << books[j].type << endl;
      }
    }
  }

  /**
    *A method that lets user calculate total of books
    *
    *@Param string title A holder for book titles
    *@Param string author A holder for book authors
    *@Param int year A holder for book years of publications
    *@Param string type A holder for book types
    *@Param int numOfBooks A holder for the total number of books in the database
    *@Param BookInfo books A holder for each book and it's data
    */
  void calculateTotal(string &title, string &author, string &year, string &type, int numOfBooks, BookInfo *books){
    int total = 0;
    string bookType;

    // Prompt user to enter the type of books they want the total for
    cout << "Please enter the book type you want to search for" << endl;
    cin >> bookType;

    // Calculate the total
    for(int j = 0; j < numOfBooks; j++){
      if(bookType == books[j].type){
        total++;
      }
    }
    cout << "The total number of books with this type is " << total << " books" << endl;
  }
};

void welcomeMessage(string message);
void promptUser(char &userChoice);
void printToFile(int numOfBooks, BookInfo *books, string space);
void readFromFile(int numOfBooks, BookInfo *books, string space);
void erase1(int &index, BookInfo *books, long maxNum);

/**
  *Determines user path and invokes class methods
  *
  *@Param int argc A holeder for the number of command line arguements
  *@Param char argv A holder for all the command line arguements in a list
  *@return The value of all the books in the database
  */
int main(int argc, char **argv){

  // Declare or Initialize variables and instances
  const long MAX_VALUE = 10000;
  long max = 10000;
  BookInfo books[MAX_VALUE], bookInfo;
  string message = "Welcome to the Library Database!";
  string title, author, year, type;
  int numOfBooks = 0;
  int i = 0;
  int j = 0;
  char choice, erase, cont;

  // Say hello to the first command line argument (after the program name).
  cout << "Hello " << argv[1] << endl;

  // Invoke welcomeMessage function
  welcomeMessage(message);

  // Create while loop so the program will
  // continue until the user wants to quit.
 do{

  // Invoke promptUser function
  promptUser(choice);

    // If user chooses to add a book
    if(choice == 'a' || choice == 'A'){

      // Invoke addBook method
      books[i].addBook(title, author, year, type, numOfBooks, i, books);
      i++;
      numOfBooks++;

      // 'z' is default value for choice variable
      choice = 'z';
    }

    // If user chooses to remove book
    else if(choice == 'r' || choice == 'R'){

      // Invoke removeBook method
      books[i].removeBook(title, author, year, type, numOfBooks, books, erase);
      numOfBooks--;
      if(erase == 'y' || erase == 'Y'){

        // Erase book and data
        erase1(i, books, max);
        cout << "Okay, the book was removed" << endl;
        max--;
        i--;
      }
      else if(erase == 'n' || erase == 'N'){
        cout << "Okay, the book was not removed" << endl;
      }
      else{
        cout << "Not a valid option, please press any character to return to the home screen" << endl;
        cin >> cont;
      }
      choice = 'z';
      }

    // If user chooses to update book
    else if(choice == 'u' || choice == 'U'){

      // Invoke updateBook method
      books[i].updateBook(title, author, year, type, numOfBooks, books);
      choice = 'z';
      }

    // If user chooses to find a book
    else if(choice == 's' || choice == 'S'){

      // Invoke findBook method
      books[i].findBook(title, author, year, type, numOfBooks, books);
      choice = 'z';
      }

    // If user chooses to calculate total for each type
    else if(choice == 'c' || choice == 'C'){

      // Invoke calculateTotal method
      books[i].calculateTotal(title, author, year, type, numOfBooks, books);
      choice = 'z';
      cout << "Press any character key to continue" << endl;
      cin >> cont;
      }

    // If user chooses to print to a file
    else if(choice == 'p' || choice == 'P'){

      // Invoke printToFile function
      printToFile(numOfBooks, books, "");
      choice = 'z';
    }
    else if(choice == 't' || choice == 'T'){

      // Invoke readFromFile function
      readFromFile(numOfBooks, books, "");
      choice = 'z';
    }
    else if(choice == 'w' || choice == 'W'){
      for(j; j <= numOfBooks; j++){
        cout << books[j].title << endl;
        cout << "\n" << endl;
      }
    }
    else if(choice == 'q' || choice == 'Q'){

      // End the program
      return 0;
    }

    // If user choice is invalid
    else{
      cerr << "Not a valid choice, please try again" << endl;
      cin >> choice;
    }
  }while(choice != 'q' || choice != 'Q');
}

/**
  *Prints out welcome message and banner
  *
  *@Param string message A holder for welcome message
  */
void welcomeMessage(string message){

  // Print welcome message and welcome banner
  cout << "************************************" << endl;
  cout << " " << message << endl;
  cout << "************************************" << endl;
}

/**
  *Prompts user to select and execute an option
  *
  *@Param char userChoice A holder for users selection
  */
void promptUser(char &userChoice){

  // Prompt usere to select an option
  cout << "Would you like to: " << endl;
  cout << "[A]dd a book" << endl;
  cout << "[R]emove a book" << endl;
  cout << "[U]pdate a book" << endl;
  cout << "[S]earch for a book" << endl;
  cout << "[W]rite all the books to the terminal" << endl;
  cout << "[C]alculate a total for a certain type of book" << endl;
  cout << "[P]rint the books and their info to a file" << endl;
  cout << "[T]ake books and their info in from a file" << endl;
  cout << "[Q]uit" << endl;
  cin >> userChoice;
}

/**
  *Prints books and data to chosen file
  *
  *@Param int numOfBooks A holder for the number of books in the database
  *@Param BookInfo books A holder for the books and their data
  *@Param string space A holder for separation between books data
  */
void printToFile(int numOfBooks, BookInfo *books, string space){
  string fileName;
  ofstream fileOut;

  // Prompt user to enter file name to print to
  cout << "Please enter a file you would like to print to" << endl;
  cin >> fileName;

  // Open chosen file
  fileOut.open(fileName.c_str());

  // If file does not exist
  while(fileOut.good() == false){
    cout << "The file yoe chose does not exist, try again" << endl;
    cin >> fileName;
  }

  // Print books and data to chosen file
  while(fileOut.good()){
   for(int i = 0; i <= numOfBooks; i++){
    fileOut << books[i].title << endl;
    fileOut << books[i].author << endl;
    fileOut << books[i].year << endl;
    fileOut << books[i].type << endl;
  }
  return;
 }
}

/**
  *Reads info out of a chosen file
  *
  *@Param int numOfBooks A holder for the number of books in the database
  *@Param BookInfo books A holder for the books and their data
  *@Param string space A holder for separation between books data
  */
void readFromFile(int numOfBooks, BookInfo *books, string space){
  string fileName;
  ifstream fileIn;

  // Prompt user to choose a file to read out from
  cout << "Please enter a file to read from" << endl;
  cin >> fileName;

  // Open chosen file
  fileIn.open(fileName.c_str());

  // If file does not exist
  while(fileIn.good() == false){
    cout << "The file you chose does not exist, please try again" << endl;
    cin >> fileName;
  }

  // Read info in from file
  while(fileIn.good()){
   for(int i = 0; i < numOfBooks; i++){
    fileIn >> books[i].title;
    fileIn >> books[i].author;
    fileIn >> books[i].year;
    fileIn >> books[i].type;
  }
  return;
 }
}

/**
  *Erases book the user wants to remove
  *
  *@Param int index A holder for the array index of the books instance
  *@Param BookInfo books A holder for books and their info
  *@Param long maxNum A holder for the maximum number the erased value can be stored in
  */
void erase1(int &index, BookInfo *books, long maxNum){

  // Use negative numbers to delete books
  index = index - maxNum;
  books[index];
}