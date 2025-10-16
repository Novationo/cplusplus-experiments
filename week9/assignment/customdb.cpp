/*
Name: Dylan Smith
Assignment Name: Database Lookup Program
Summary: A program that reads and writes to and from a database/text file of given users/ to add more users to the file.
*/
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    //create ifstream
    std::ifstream dbRead;
    std::ofstream dbWrite;
    int givenID, foundID;
    std::string lastName, firstName, entryFirst, entryLast;


    //open file for reading
    dbRead.open("week9/assignment/CustomerDB.txt");
    if(!dbRead.is_open()){
        std::cout << "File failed to open" << std::endl;
        return 1;
    }

    std::cout << "Enter ID: ";
    std::cin >> givenID;

    // read while not end of file
    bool found = false;
    while (!(dbRead.eof())){
        dbRead >> foundID;
        dbRead >> firstName;
        dbRead >> lastName;

        if (givenID == foundID){
            std::cout << "Found Customer " << foundID << ": " << lastName << ", " << firstName << std::endl;
            found = true;
            break;
        }

        //check if id exists
        // if not break and create new user
        // if found print and break out
    }
    //close file
    dbRead.close();
    if(!found){
        std::cout << "Customer " << givenID << ": Not Found" << std::endl;
        //return 2; // to change later
        std::cout << "Enter First Name: " << std::endl;
        std::cin >> entryFirst;
        std::cout << "Enter Last Name: " << std::endl;
        std::cin >> entryLast;

        dbWrite.open("week9/assignment/CustomerDB.txt", std::ios::app);
        dbWrite << givenID << " " << entryFirst << " " << entryLast << "\n";
        dbWrite.close();

        std::cout << "Added Customer " << givenID << ": " << entryLast << ", " << entryFirst << std::endl;
    }



    // use entryFirst/Last

    // open file to write to
    //create user (id first last)
    // close file
    // exit

    return 0;
}
