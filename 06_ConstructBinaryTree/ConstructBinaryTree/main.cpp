#include <iostream>

using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore
(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
    //ǰ������ĵ�һ���ڵ㼴Ϊ���ĸ��ڵ�
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if(startPreorder == endPreorder)//�ж�����
    {
        if(startInorder == endInorder && *startPreorder == *endPreorder)
            return root;
        else
            throw exception("Invalid input.");
    }

    //
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
            ++rootInorder;
    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw exception("Invalid input");

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength
    //����������
    if(leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,startInorder,rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        //����������
        root->m_pRight = ConstructCore(leftPreorderEnd + 1,endPreorder,rootInorder + 1,endInorder);

    }
    return root;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
