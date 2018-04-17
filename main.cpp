#include "tree.h"

int main()
{
        short initial = 0;
        short inp = 0;
        short mid = 50;
        bool sto = false;
        char inst;

        cout << "Welcome to the B+ Tree Creator" << endl << endl;
        cout << "How many values are in the initial sequence?" << endl;
        cin  >> initial;

        for(short i = 0; i < initial; i++)
        {
                cout << "Input value you wish to insert into the tree: ";
                cin  >> inp;
                insert(inp);
        }

        cout << endl << endl << setw(mid) << "Initial B+ Tree" << endl;
        cout << setw(mid) << "-------------------------------------------------------------------------------------" << endl;

        output(root);

        cout << endl;

        do
        {
                cout << "What instruction would you like to do? (Insert = i, delete = d, stop = s): ";
                cin  >> inst;

                switch (inst)
                {
                        case 'i':
                                cout << "Input value you wish to insert into the tree: ";
                                cin  >> inp;

                                insert(inp);

                                cout << setw(mid) << "New B+ Tree" << endl;
                                output(root);
                                cout << endl;
                                break;
                        case 'd':
                                cout << "Input value you wish to remove from the tree: ";
                                cin  >> inp;

                                remove(inp);

                                cout << setw(mid) << "New B+ Tree" << endl;
                                output(root);
                                cout << endl;
                                break;
                        case 's':
                                cout << setw(mid) << "Final B+ Tree" << endl;

                                output(root);
                                cout << endl;
                                sto = true;

                                break;
                        default:
                                cout << "Please enter a valid command" << endl << endl;
                                break;

                }
        }while(sto == false);

        return 0;
}
