#include <iostream>

using namespace std;

struct ListNode{
    int m_nValue;
    ListNode *m_pNext;
};
void AddToTail(ListNode** pHead,int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_value = value;
    p_New->m_pNext = NULL;

    if(*pHead == NULL){
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead,int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;
    ListNode* pToBeDeleted = NULL;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->pNext->m_nValue != value)
            pNode = pNode->m_nValue;

        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if(pToBeDeleted != NULL)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }

}
//从尾到头输出链表--使用栈结构来实现，将链表中的结点依次压入到栈中，弹栈，即为从尾到头输出
void PrintListReversingly_Interatively(ListNode* pHead)//
{
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != NULL){
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout<<pNode->m_nValue<<'\t';
        nodes.pop();
    }

}

void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        cout<<pHead->m_nValue<<'\t';
    }

}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
