#include "mat.hpp"

/**
 * @brief the function creates and returns the string of the carpet of matrix with size of n*m with 2 symbols.
 * complexity - O(n*m)
 * 
 * @param cols the width of the carpet, num cols of the matrix
 * @param rows the height of the carpet, num rows of the matrix
 * @param sym1 first symbol
 * @param sym2 second symbol
 * @return string 
 */
string ariel::mat(int cols, int rows, char sym1, char sym2)
{
    if (rows <= 0 || cols <= 0)             // the rows and cols must be positive
    {
        throw MessageException("the rows and columns must be positive");
    }
    if (rows % 2 == 0 || cols % 2 == 0)     // the size of the matrix must be odd
    {
        throw MessageException("Mat size is always odd");
    }

    // create a vector with size of rows num of the strings
    // each string has the size of the width - the string inits  as spaces
    vector<string> strVct(rows, string(cols, ' '));

    string charsForMat = string() + sym1 + sym2;    // the string that samples the symbols
    
    round_mat(rows, cols, charsForMat, strVct);     // create the carpet design

    string retStr;
    for (int i = 0; i < strVct.size(); i++)         // assemble the vector to one string
    {
        retStr += strVct[i];
        retStr += i < rows - 1 ? "\n" : "";
    }

    return retStr;
}

/**
 * @brief by a given matrix its assigns the symbols to the proper location
 * 
 * @param rows the width of the carpet, num cols of the matrix
 * @param cols the height of the carpet, num rows of the matrix
 * @param frame_chars the symbols as a string one after another
 * @param mat the matrix to design
 */
void ariel::round_mat(int rows, int cols, string frame_chars, vector<string>& mat)
{
    int s_ind = 0;
    int e_r = rows - 1;     // end row index
    int e_c = cols - 1;     // end col index
    int len = frame_chars.length();
    char ch = 0;
    int k = 0;

    //run of every frame - a box from the outer to inner
    for ( ; s_ind <= e_r && s_ind <= e_c ; s_ind++, e_r--, e_c--)
    {
        //the start point dictates the symbol of the frame
        ch = len > 0 ? frame_chars[s_ind % len] : ' ';

        for(k = s_ind; k <= e_c; k++)       // fill the first box row
        {
            mat[s_ind][k] = ch;
        }

        for(k = s_ind; k <= e_c; k++)       // fill the last box row
        {
            mat[e_r][k] = ch;
        }

        for(k = s_ind; k <= e_r; k++)       // fill the first box column
        {
            mat[k][s_ind] = ch;
        }

        for(k = s_ind; k <= e_r; k++)       // fill the last box column
        {
            mat[k][e_c] = ch;
        }
    }
}

/**
 * @brief get integer input in a secure way, get only input
 * 
 * @param val the integer that wanted from input
 * @param msg the line before the input
 */
void ariel::get_int(int& val, const string& msg)
{
    if (!msg.empty())   // if the message is not empty then print it
    {
        cout << msg;
    }
    if (!(cin >> val))  // if failed input - clear the cin and throw exception
    {
        cin.clear();
        cin.ignore(BUFFER_LEN, '\n');
        throw MessageException("invalid input - please enter integer");
    } 
}

/**
 * @brief get integer input in a secure way, get only input
 * 
 * @param val the integer that wanted from input
 * @param msg the line before the input
 */
void ariel::get_char(char& val, const string& msg)
{
    if (!msg.empty())   // if the message is not empty then print it
    {
        cout << msg;
    }
    if (!(cin >> val))  // if failed input - clear the cin and throw exception
    {
        cin.clear();
        cin.ignore(BUFFER_LEN, '\n');
        throw MessageException("invalid input - please enter character");
    }
}