#include <iostream>
#include <string>
#include <sstream>

using std::string;

struct movie{
    string title;
    int year;
};

struct friends{
    string name;
    string email;
    movie fav_movie;
} maria, john;

int main() {
    friends *ptr_friend = &maria;
    ptr_friend->name = "Maria";
    ptr_friend->email = "a@google.com";
    ptr_friend->fav_movie.title = "The Matrix";
    ptr_friend->fav_movie.year = 1999;

    return 0;
}
