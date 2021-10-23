#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void description(){
    cout << "Welcome to the arknights random operator and stage selector version 1.0\n";
    cout << "Made by Hyngwarus#0780\n";
    cout << "There are currently only all CN main story stages starting from 2-1 and EN permanent side events + the current event (Under tides)\n";
    cout << "The operators are from CN so I apologize if you have to reroll them a lot of time\n";
    cout << "If you want to try stages from chapter 0 and 1 just copy them from the easy.txt  fileinto the stages.txt file\n";
    cout << "I'll try to maintain and update the code as much as possible, but you can add the current operators and stages if they are not in the files\n";
    cout << "Anyway good luck and have fun!\n\n";
    
}

void menu(){
    cout << "Pick your option:\n";
    cout << "1 - Get 12 random operators and a random stage\n";
    cout << "2 - Change one operator (if you don't have the operator, if it repeated, if the stage requires an operator from a class or an archetype you don't have)\n";
    cout << "3 - Change the stage (if it is too hard or isn't unlocked)\n";
    cout << "0 - Exit\n\n";
    
}

int main(){
    srand((unsigned)time(NULL));
    string stage, operators[12];
    fstream stages_list, operators_list;
    bool exit=1;
    int choice, rng, i, j, change;
    description();
    while(exit)
    {
        menu();
        cin >> choice;
        cout << "\n";
        switch(choice)
        {
            case 1:
                for( i=0; i<12; i++)
                {
                    rng=rand()%208;
                    operators_list.open("operators.txt", ios::in);
                    if(operators_list.is_open())
                    {
                        for( j=0; j<rng; j++)
                        {
                            getline(operators_list, operators[i]);
                        }
                        operators_list.close();
                    }
                }
                rng=rand()%298;
                stages_list.open("stages.txt", ios::in);
                if(stages_list.is_open())
                {
                    for( i=0; i<rng; i++)
                    {
                        getline(stages_list, stage);
                    }
                    stages_list.close();
                }
                cout << "The operators are:\n";
                for( i=0; i<12; i++)
                {
                    cout << "Operator " << i+1 <<" : " << operators[i] << "\n";
                }
                cout << "The stage is: " << stage <<"\n";
                break;
            case 2:
                cout << "Pick the operator you'd like to change, by number: \n";
                cin >> change;
                cout << "\n";
                if((change < 1) || (change > 12))
                {
                    cout << "Number not in range\n";
                    break;
                }
                operators_list.open("operators.txt", ios::in);
                if(operators_list.is_open())
                {
                    rng=rand()%208;
                    for( j=0; j<rng; j++)
                    {
                        getline(operators_list, operators[change-1]);
                    }
                    operators_list.close();
                }
                cout << "The operators are:\n";
                for( i=0; i<12; i++)
                {
                    cout << "Operator " << i+1 <<" : " << operators[i] << "\n";
                }
                cout << "The stage is: " << stage <<"\n";
                break;
            case 3:
                rng=rand()%298;
                stages_list.open("stages.txt", ios::in);
                if(stages_list.is_open())
                {
                    for( i=0; i<rng; i++)
                    {
                        getline(stages_list, stage);
                    }
                    stages_list.close();
                }
                cout << "The operators are:\n";
                for( i=0; i<12; i++)
                {
                    cout << "Operator " << i+1 <<" : " << operators[i] << "\n";
                }
                cout << "The stage is: " << stage <<"\n";
                break;
            case 0:
                exit=0;
                break;
            default:
                break;
        }
    }
    return 0;
}
