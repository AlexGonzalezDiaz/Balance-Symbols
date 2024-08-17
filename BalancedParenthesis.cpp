// BalancedParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct Node
{
    char Symb;
    Node* Next;
};

Node* Head = nullptr;

void Push(char x)
{
    Node* newNode = new Node();
    newNode->Symb = x;
    newNode->Next = nullptr;

    if (Head == nullptr)
    {
        Head = newNode;
    }
    else
    {
        newNode->Next = Head;
        Head = newNode;
    }
    
}

void Pop()
{
    Node* temp = Head;

    Head = temp->Next;
    delete temp;
}

Node* Top()
{
    return Head;
}

bool IsEmpty(Node * h)
{
    if (h == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidPair(Node* l, char r)
{
    if (l->Symb == '(' && r == ')')
    {
        return true;
    }
    else if (l->Symb == '[' && r == ']')
    {
        return true;
    }
    else if (l->Symb == '{' && r == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PrintList(Node* h)
{
    if (h == NULL) return;
    std::cout << h->Symb << " ";
    PrintList(h->Next);

    std::cout << "\n";
}

int main()
{
    std::string userInput = " ";
    
    std::cout << "Enter the symbols to check if they are balanced: \n";
    std::getline(std::cin, userInput);

    bool found = false;

    for (char find : userInput)
    {
        if (find == '(' ||  find =='[' || find == '{' )
        {
            Push(find);
              
        }
        else
        {
            if (IsEmpty(Head) || !(ValidPair(Top(), find)))
            {
                bool test = ValidPair(Top(), find);
                std::cout << test;
                break;
                
            }
            else
            {
                Pop();
            }
        }
    }

    if (IsEmpty(Head))
    {
        std::cout << "Symbols balanced.";
    }
    else
    {
        std::cout << "Symbols unbalanced.";
    }

}

