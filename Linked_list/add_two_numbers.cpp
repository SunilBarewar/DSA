#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void creatlist(node *&head, int a)
{
    node *newnode, *temp;
    newnode = new node(a);

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printlist(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *add(node *&l1, node *&l2)
{
    node *temp1 = l1;
    node *temp2 = l2;

    node *newList = NULL;
    node *temp3 = NULL;
    int carry = 0;

    while (temp1 != NULL && temp2 != NULL)
    {
        int sum = temp1->data + temp2->data + carry;
        node *newNode = new node(sum % 10);
        carry = sum / 10;
        if (newList == NULL)
        {
            newList = temp3 = newNode;
        }
        else
        {
            temp3->next = newNode;
            temp3 = newNode;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != NULL)
    {
        int sum = temp1->data + carry;
        node *newNode = new node(sum % 10);
        carry = sum / 10;
        temp3->next = newNode;
        temp3 = newNode;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        int sum = temp2->data + carry;
        node *newNode = new node(sum % 10);
        carry = sum / 10;

        temp3->next = newNode;
        temp3 = newNode;
        temp2 = temp2->next;
    }
    if(carry > 0){
         node *newNode = new node(carry);
         temp3->next = newNode;
    }
    return newList;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int n, m;
    cin >> m >> n;
    int arr1[m], arr2[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < m; i++)
    {
        creatlist(head1, arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        creatlist(head2, arr2[i]);
    }

    node *newList = add(head1, head2);
    printlist(newList);
}
