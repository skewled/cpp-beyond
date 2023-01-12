#include <iostream>
using namespace std;


class Light {
    public:
        Light() {}
        Light (const Light& other) 
        {}
        Light (Light&& other) 
        {}
        Light& operator = (const Light& other) 
        {return *this;}
        Light& operator = (Light&& other) 
        {return *this;}

    private:
    char* data;
};

Light GetLight() {return Light();}


void foo (const int& data)
{
Light a;
Light b = a;
Light c (a);
Light d = GetLight();
a = d;
b = GetLight();

    // data = 10;
}

void bar (const int* data)
{
    //*data = 10;
}
void foobar(int* const data)
{
    *data = 10;
  //  data = nullptr;
}

int mainx()
{
int myval = 5;
foo(myval);
cout << myval << endl;

char* ptrToData = new char[80];
// use memory buffer
delete[] ptrToData;
return 0;

}