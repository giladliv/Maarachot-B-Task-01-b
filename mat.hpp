#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <vector>

using namespace std;

namespace ariel
{   
    class MessageException : public exception
    {
        public:
            MessageException(string str) : _msg(str) { }
            const char* what() const noexcept {return _msg.c_str();}
        private:
            string _msg;

    };
    
    string mat(int cols, int rows, char a, char b);
    vector<string> makeArrOfStr(int rows, int cols, char initCh = ' ');
    void round_mat(int rows, int cols, string frame_chars, vector<string>& mat);

    void get_intput(int& val, string msg = "");
    void get_intput(char& val, string msg = "");
}




#endif /* MAT_H */