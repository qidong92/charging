#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char str1[] = "Hello World!";
    char str2[] = "Hello World!";

    char* str3 = "Hello World!";
    char* str4 = "Hello World!";

    if(str1 == str2)
        cout<<"str1 and str2 equals"<<endl;
    else
        cout<<"str1 and str2 not equals"<<endl;

    if(str3 == str4)
        cout<<"str3 and str4 equals"<<endl;
    else
        cout<<"str3 and str4 not equals"<<endl;

    cout<<"The size of str1 and str2 is:"<<sizeof(str1)<<endl;
    cout<<"The size of str3 and str4 is:"<<sizeof(*str3)<<endl;
    cout<<*str3<<endl;

    cout<<"The address of str1 is:"<<&str1<<"The address of str2 is:"<<&str2<<endl;

    cout<<"The address of str3 is:"<<*str3<<"The address of str4 is:"<<*str4<<endl;\
    printf("The value of str1 is: ",str1);


    cout << "Hello world!" << endl;
    return 0;
}
