#include "mat.hpp"

using namespace ariel;

#define CREATE 1
#define HELP 2
#define CLEAR_SCREEN 3
#define QUIT 4 
#define WELCOME_LINE "welcome to our carpet factory - \"Gilad\'s carpets\""

void create_carpet();
void perform_choice(int choice);

/**
 * @brief Create a carpet from the users input
 * 
 */
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

    cout << mat(width, height, a, b) << endl << endl;   // prints the carpet
}

/**
 * @brief by given choice number - make the users selection
 * 
 * @param choice the choice number between 1 to 4
 */
void perform_choice(int choice)
{
    switch (choice)
    {
        case CREATE:
            create_carpet();
            break;

        case HELP:
            // print the helper
            cout << "To make the carpet you need a:" << endl;
            cout << "width(int), height(int), symbol 1 (char), symbol 2 (char)" << endl;
            cout << "the size - width and height must be positive odd numbers" << endl;
            cout << endl;
            break;
        
        case CLEAR_SCREEN:
            system("clear");
            cout << WELCOME_LINE << endl << endl;
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

int main()
{
    int choice = QUIT;
    cout << WELCOME_LINE << endl << endl;
    do
    {
        try
        {
            cout << "What can we offer you?" << endl;
            cout << "1. create a new carpet" << endl;
            cout << "2. help and instructions" << endl;
            cout << "3. clean screen" << endl;
            cout << "4. quit the program" << endl << endl;

            get_int(choice, "Please choose your option (1 - 4): "); // get the users choice

            perform_choice(choice);     // creates the selection
        }
        catch(const std::exception& e)
        {
            std::cerr << "\n" << e.what() << endl << endl;
        }
        
    } while (choice != QUIT);   // continue while user doesnt choose to quit

    return (0);
}