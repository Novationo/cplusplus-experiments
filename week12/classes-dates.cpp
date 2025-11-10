
#include <iostream>
// #include <ctime>
class Date {
    public:
    // prototypes/declarations of functions
    Date(int,int,int);
    void print();
    
    private:
    //create a int/ normal variable, do not need to redeclare public things in here either
    
};

int main()
{
    Date today(3,11,2025);
    std::cout<< "This program was written on ";
    today.print()
    
    return 0;
}

void Date::print(){
    std::cout << 

}