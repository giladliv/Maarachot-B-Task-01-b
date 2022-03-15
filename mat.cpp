#include "mat.hpp"

string ariel::mat(int cols, int rows, char a, char b)
{
    if (rows <= 0 || cols <= 0)
    {
        throw MessageException("the rows and columns must be positive");
    }
    if (rows % 2 == 0 || cols % 2 == 0)
    {
        throw MessageException("Mat size is always odd");
    }
    
    vector<string> strVct = makeArrOfStr(rows, cols);
    string charsForMat = string() + a + b;
    
    round_mat(rows, cols, charsForMat, strVct);

    string retStr;
    for (int i = 0; i < strVct.size(); i++)
    {
        retStr += strVct[i];
        retStr += i < rows - 1 ? "\n" : "";
    }

    return retStr;
}

vector<string> ariel::makeArrOfStr(int rows, int cols, char initCh)
{
    vector<string> strVct(rows, string(cols, ' '));
    return strVct;
}

void ariel::round_mat(int rows, int cols, string frame_chars, vector<string>& mat)
{
    int s_ind = 0;
    int e_r = rows - 1;
    int e_c = cols - 1;
    int len = frame_chars.length();
    char ch = 0;
    for ( ; s_ind <= e_r && s_ind <= e_c ; s_ind++, e_r--, e_c--)
    {
        ch = len > 0 ? frame_chars[s_ind % len] : ' ';
        int i = s_ind;
        int j = s_ind;
        while (j <= e_c)
        {
            mat[i][j++] = ch;
        }
        j--;

        while (i <= e_r)
        {
            mat[i++][j] = ch; 
        }
        i--;

        while (s_ind <= j)
        {
            mat[i][j--] = ch; 
        }
        j++;

        while (s_ind <= i)
        {
            mat[i--][j] = ch; 
        }
        i++;
    }
}

void ariel::get_int(int& val, const string& msg)
{
    if (!msg.empty())
    {
        cout << msg;
    }
    if (!(cin >> val))
    {
        cin.clear();
        cin.ignore(BUFFER_LEN, '\n');
        throw MessageException("invalid input - please enter integer");
    } 
}

void ariel::get_char(char& val, const string& msg)
{
    if (!msg.empty())
    {
        cout << msg;
    }
    if (!(cin >> val))
    {
        cin.clear();
        cin.ignore(BUFFER_LEN, '\n');
        throw MessageException("invalid input - please enter char");
    }
}