#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree BST;
    
    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        BST.insert(rand() % 100);
    }

    BST.display();

    int choice;
    do{
        cout << "\nWelcome" << endl;
        cout << "\n66066780-Nathakith-baosalee" << endl;
        cout << "******************************" << endl;
        cout << "1. insert(int e)" << endl;
        cout << "2. PRE_ORDER" << endl;
        cout << "3. IN_ORDER" << endl;
        cout << "4. POST_ORDER" << endl;
        cout << "5. findMax()" << endl;
        cout << "6. findMin()" << endl;
        cout << "7. findDepth()" << endl;
            
        cin >> choice;

    switch (choice){
        case 1: int e;
                cout << "Enter e : ";
                cin >> e;
                BST.insert(e);
                BST.display();
            break;
        case 2: BST.display(PRE_ORDER);
            break;
        case 3: BST.display(IN_ORDER);
            break;
        case 4: BST.display(POST_ORDER);
            break;
        case 5: cout << "MAX : " << BST.findMax() << endl;
            break;
        case 6: cout << "MIN : " << BST.findMin() << endl;
            break;
        case 7: cout << "DEPTH : " << BST.findDepth() << endl;
            break;
        }
    } while(choice != 0);

    //cout << "REMOVE : " << BST.remove(20);

    return 0;
}