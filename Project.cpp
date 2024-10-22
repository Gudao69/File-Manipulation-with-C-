// Assignment Project
#include <sstream>  // for Insertion and Extraction of Data to and from the string Objects.
#include <fstream>  // for Using ofstream and ifstream to Write and Read Information to/from files
#include <iostream> // for Input and Output
#include <string>   // for Using the string Class
#include <iomanip>  // for Manipulating Output such as Filling Characters and Precision
using namespace std;

class member
{
private:
    string mname, mid;
protected:
    string mtype;
    int credit;
    double price, discount; // Base Class Members
public:
    void input_member();
    void display_member();
    void write_Record();
    void display()          // Base Class Functions
    {
        cout << endl << "Welcome to the Members' Club. " ;
    }

    member(double a = 0, double b = 0)
    {
        price = a;
        discount = b;
    }

    virtual double final_price()    // Virtual Function to Achieve Polymorphism
    {
        cout << "Member's Final Price : " << endl;
        return 0;
    }
};

class Ordinary : public member  // Child Class or Derived Class 1
{

public:
    void display1() // Derived Class 1 Functions
    {
        cout << endl << "We are SORRY that" 
            << "there is no Currently Available Discount for Ordinary Members!!!" << endl;
    }

    Ordinary(double a = 0, double b = 0) :member(a, b) {}
    double final_price()    // Same Function Name with Virtual Function
    {
        cout << "Ordinary Member's Final Price : " << endl;
        return price - (price * discount / 100);
    }

}ord;

class Silver : public member  // Child Class or Derived Class 2
{

public:
    void display2() // Derived Class 2 Functions
    {
        cout << endl << "Congratulations!!! There is a 10% discount for Silver Members. " << endl;
    }

    Silver(double a = 0, double b = 0) :member(a, b) {}
    double final_price()    // Same Function Name with Virtual Function
    {
        cout << "Silver Member's Final Price : " << endl;
        return price - (price * discount / 100);
    }

}sil;

class Gold : public member  // Child Class or Derived Class 3
{

public:
    void display3() // Derived Class 3 Functions
    {
        cout << endl << "Congratulations!!! There is a 20% discount for Gold Members. " << endl;
    }

    Gold(double a = 0, double b = 0) :member(a, b) {}
    double final_price()    // Same Function Name with Virtual Function
    {
        cout << "Gold Member's Final Price : " << endl;
        return price - (price * discount / 100);
    }
} gold;


void member::input_member()     // Defining Function " input_member() " outside Class
{
    cout << "Member's Name : ";
    cin >> mname;
    cout << "Member ID : ";
    cin >> mid;
    cout << "Member Type : ";
    cin >> mtype;
    cout << "Credit Points : ";
    cin >> credit;              // Inputs for Receiving New Member Details from User
}

void member::display_member()   // Defining Function " display_member() " outside Class to Display Member Details
{
    cout << "Member's name : " << mname << endl;
    cout << "Member ID : " << mid << endl;
    cout << "Member Type : " << mtype << endl;
    cout << "Credit Points : " << credit << endl;   // Outputs for Displaying Member Details
}

void member::write_Record()     // Defining Function " write_Record() " outside Class to Add New Member Details
{
    cout << endl << "Writing to member.txt file ..... " << endl;
    ofstream myfile("member.txt", ios::app);    // ofstream for Creating and Writing to files
    // ios::app for Appending Data to the End of the Files

    if (myfile.is_open())
    {
        myfile << endl << mname << " "
            << mid << " " << mtype << " " << credit;    // Write User Inputs into " member.txt "
        myfile.close();
    }
    else
        cout << "Unable to open file!!! ";
    system("pause");
}

int main()
{
    void addMember();
    void display_Member();
    void modify_Member();       // Function Calls
    void discount();
    char choice;           // Variable for Switch Statememt ( Main Menu )
    do                // For the Loop to be Executed at least Once
    {
        system("cls");
        cout << endl
            << "Choose 1 to Add a New Member to the File. " << endl
            << "Choose 2 to Modify the Details of an Existing Member. " << endl
            << "Choose 3 to Display the Member details from the File. " << endl
            << "Choose 4 to See Price and Discounts. " << endl
            << "Choose 5 to Exit this Program. " << endl
            << "Enter Your Choice and Press Return: " << endl;      // Outputs for Main Menu
        cin >> choice;       // User Input for Main Menu

        switch (choice)     // Use Switch Statement for Selecting One of Many Code Blocks to be Executed
        {
        case '1':
            cout << endl << "Option 1 is selected. \n" << endl;
            addMember();
            break;
        case '2':
            cout << endl << "Option 2 is selected. \n" << endl;
            modify_Member();
            system("PAUSE");
            break;
        case'3':
            cout << endl << "Option 3 is selected. \n" << endl;
            display_Member();
            system("PAUSE");
            break;
        case '4':
            discount();
            system("PAUSE");
            break;
        case'5':
            cout << " End of Program. " << endl;
            cout << "........x........" << endl;
            break;
        default:
            cout << "Not a valid choice. \n" << "Choose again. \n" << endl;
            system("PAUSE");
            break;

        }
    } while (choice != '5');
    system("Pause");
    return 0;
}

void addMember()        // Defining Function to Add a New Member to the File
{
    member m;
    cout << endl << "Input Data..... \n" << endl;
    m.input_member();
    cout << endl << "Confirming the Input Data..... \n " << endl;
    m.display_member();
    m.write_Record();
}

void display_Member()   // Defining Function to Display the Member Details from the File
{
    string data;
    ifstream myfile;
    string table[4];    // Array for Displaying Member Details with Table
    myfile.open("member.txt");

    cout << "                 Displaying All Members' Data : \n" << endl;
    cout << "*---------------*---------------*---------------*---------------*" << endl;
    cout << "|  Member Name  |   Member ID   |  Member Type  | Credit Points |" << endl;
    while (!myfile.eof())       // Loop Till the End of File
    {

        for (int i = 0; i < 4; i++)
        {
            myfile >> table[i];
        }

        cout << "*---------------*---------------*---------------*---------------*" << endl;
        cout << "|" << left << setw(15) << table[0];   
        cout << "|" << left << setw(15) << table[1];
        cout << "|" << left << setw(15) << table[2];
        cout << "|" << left << setw(15) << table[3] << "|" << endl;
        // Use setw for Setting the Field Width and left for Starting from Left

    }
    cout << "*---------------*---------------*---------------*---------------*" << endl;
    myfile.close();
}

void modify_Member()        // Function Defining for Modifying the Details of an Existing Member
{
    string search;
    fstream myfile("member.txt", ios::in | ios::out);
    string line;
    string myArray[4];      // Array for Displaying Member Details
    char confirmation;      // Variable fot Switch Statement ( Modify Menu )

    myfile.is_open();

    if (!myfile)
    {
        cout << "Unable to open file!!!" << endl;
        exit(1);
    }

    else
    {
        cout << "Enter Member's Name or ID to search for : " << endl;
        cin >> search;
    }

    size_t pos;     // size_t for loop counters and array indexing
    while (myfile.good())
    {
        getline(myfile, line);
        pos = line.find(search);    // Put the Line that Involves the Searched Word into pos
        if (pos != string::npos)
        {
            cout << endl << "Found ! " << endl;

            ofstream tempfile("file.txt");  // For Creating and Writing to the Files 
            tempfile << line; // Put the Line that Involves the Searched Word into the New File named "file.txt"
            tempfile.close();

            fstream newfile("file.txt", ios::in | ios::out);
            // For Performing both writing and reading from "file.txt"

            if (newfile.is_open())
            {
                for (int i = 0; i < 4; ++i)
                {
                    newfile >> myArray[i];  // Put the Datas from " file.txt " into myArray through looping
                }
            }

            cout << endl << "Name : " << myArray[0] << endl;
            cout << "ID : " << myArray[1] << endl;
            cout << "Type : " << myArray[2] << endl;
            cout << "Credit Points : " << myArray[3] << endl;   // Show Datas through Respective Arrays

            newfile.close();

            fstream newfile2("file.txt", ios::in | ios::out);

            do {        // For the Loop to be Executed at least Once
                cout << endl << "Which One Do You Want To Modify? " << endl
                    << "Press 1 to Modify Member Name. " << endl
                    << "Press 2 to Modify Member ID. " << endl
                    << "Press 3 to Modify Member Type. " << endl
                    << "Press 4 to Modify Credit Points. " << endl
                    << "Press 5 to Return to Main Menu. " << endl
                    << "Enter Your Choice and Press Return: ";
                cin >> confirmation;

                switch (confirmation)   // Switch Statement for Modify Menu
                {
                case '1':
                    cout << endl << "Enter New Name : ";
                    cin >> myArray[0];
                    break;
                case '2':
                    cout << endl << "Enter New ID : ";
                    cin >> myArray[1];
                    break;
                case '3':
                    cout << endl << "Enter New Type : ";
                    cin >> myArray[2];
                    break;
                case '4':
                    cout << endl << "Enter New Credit Points : ";
                    cin >> myArray[3];
                    break;
                case '5':
                    cout << endl << "Returning to Main Menu ..... " << endl;
                    break;
                default:
                    cout << "Not a Valid Choice !! " << endl << "Please Choose Again. " << endl;
                    break;
                }
            }

            while (confirmation != '5');
            system("PAUSE");
            newfile2 << myArray[0] << " " << myArray[1] << " " << myArray[2] << " " << myArray[3];

            newfile2.close();
            myfile.close();
            break;
        }
    }

    if (pos == string::npos)
    {
        cout << endl << "Not Found !!! " << "Please Check Your Input and Try Again. " << endl;
    }

    ifstream file;
    ofstream outfile;
    ofstream newfile;
    string lineN;

    file.open("member.txt");
    outfile.open("newS.txt", ios::app);

    while (getline(file, lineN))
    {
        if ((lineN.find(search, 0)) == string::npos)    // Put the Line with the Searched Word into " newS.txt "
            outfile << endl << lineN;

        else                       // Put All the Lines except the Line with the Searched Word into " newS.txt "
        {
            outfile << endl << myArray[0] << " " << myArray[1] << " " << myArray[2] << " " << myArray[3];
        }
    }

    outfile.close();
    file.close();
    remove("member.txt");       // Remove the Original " member.txt " and
    rename("newS.txt", "member.txt");   // Rename the " newS.txt " into " member.txt "

}

void discount()
{
    member* price;
    Ordinary ord(1000, 0);
    Silver sil(1000, 10);
    Gold gold(1000, 20);

    ord.display();  // Inherited Function from Base Class
    ord.display1();
    price = &ord; // Store the Address of Ordinary Member
    price->final_price();
    sil.display();  // Inherited Function from Base Class
    sil.display2();
    price = &sil;   // Store the Address of Silver Member
    price->final_price();
    gold.display(); // Inherited Function from Base Class
    gold.display3();
    price = &gold;  // Store the Address of Gold Member
    price->final_price();
    
    
}
