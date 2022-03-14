#include "mat.hpp"

using namespace ariel;

#define CREATE 1
#define HELP 2
#define CLEAR_SCREEN 3
#define QUIT 4 

void create_carpet();


void create_carpet()
{
    char a = 0;
    char b = 0;
    int width = 0;
    int height = 0;
    get_int(width, "please enter num of width: ");
    get_int(height, "please enter num of height: ");

    get_char(a, "choose your first symbol: ");
    get_char(b, "choose your second symbol: ");
    
    cout << endl;

    cout << mat(width, height, a, b) << endl << endl;
}



int main()
{
    int choice = QUIT;
    cout << "welcome to our carpet factory - \"Gilad\'s carpets\"" << endl << endl;
    do
    {
        try
        {
            cout << "What can we offer you?" << endl;
            cout << "1. create a new carpet" << endl;
            cout << "2. help and instructions" << endl;
            cout << "3. clean screen" << endl;
            cout << "4. quit the program" << endl;
            get_int(choice, "\nPlease choose your option (1 - 4): ");
            switch (choice)
            {
                case CREATE:
                    create_carpet();
                    break;

                case HELP:
                    cout << "To make the carpet you need a:" << endl;
                    cout << "width(int), height(int), symbol 1 (char), symbol 2 (char)" << endl;
                    cout << "the size - width and height must be positive odd numbers" << endl;
                    cout << "the symbols must be printable (from ascii 33 to 126)" << endl;
                    break;
                
                case CLEAR_SCREEN:
                    system("clear");
                    break;

                case QUIT:
                    cout << "Goodbye!" << endl;
                    break;

                default:
                    cout << "this is invalid choice" << endl;
                    cout << "please try again" << endl << endl;
                    break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "\n" << e.what() << "\n\n";
        }
        
        

    } while (choice != QUIT);

    return (0);
}