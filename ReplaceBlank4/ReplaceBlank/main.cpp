#include <iostream>

using namespace std;
/*
length is the length of string */

void ReplaceBlank(char string[],int length)
{
    if(string == NULL || length == 0)
    {
        cout<<"The given string is empty or the place is null"<<endl;
        return;

    }

    int originalLength = 0;//�ַ�����ʵ�ʳ���
    int numberofBlank = 0;//�ո�ĸ���
    int i = 0;

    while('\0' != string[i])
    {
        ++originalLength;
        if(' ' == string[i])
            ++numberofBlank;

        ++i;
    }

    int newLength = originalLength + 2 * numberofBlank;//���ո��滻����ַ���

    if(newLength > length)
    {
        cout<<"The is no enough place to repacle the string"<<endl;
        return;//�����ַ������������ܷ����滻����ַ���

    }

    char* p1 = &string[originalLength - 1];
    char* p2 = &string[newLength - 1];

    //while(){}

    //��������ȷʹ��

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal )
    {
        if(' ' == string[indexOfOriginal])
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }

        --indexOfOriginal;

    }

}
int main()
{
    const int length = 30;
    char string[length] = "          ";
    cout<<"Size of string is:"<<sizeof(string)<<endl;
    cout<<string<<endl;
    ReplaceBlank(string,length);
    cout<<string<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
