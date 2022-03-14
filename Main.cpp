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
    cout << "please enter num of width: ";
    cin >> width;
    cout << "please enter num of height: ";
    cin >> height;
    cout << "choose your first symbol: ";
    
    cin >> a;
    if (a != EOF)
    {
        cout << "choose your second symbol: ";
        cin >> b;
    }
    
    cout << endl;

    if (a != EOF && b != EOF)
    {
        cout << mat(width, height, a, b) << endl << endl;
    }
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
            cout << "\nPlease choose your option (1 - 4): ";
            cin >> choice;
            switch (choice)
            {
                case CREATE:
                    create_carpet();
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
            std::cerr << e.what() << "\n\n";
        }
        
        

    } while (choice != QUIT);

    return (0);
}