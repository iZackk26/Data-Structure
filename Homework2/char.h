#include <cstdio>
#include <iostream>
#include <string>

using std::string;

class Array {
    public:
        char name;
        static int count;
        Array() {
            name = ' ';
        }
        static void incrementCount(){
            count++;
        }
        void setchar(char c) {
            name = c;
        }
        friend::std::ostream& operator<<(std::ostream& os, const Array& arr) {
            os << arr.name << " " << arr.count;
            return os;
        }
};
