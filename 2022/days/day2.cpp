#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

int problem1(ifstream &file){
    string line;
    int total = 0;
    unordered_map<char,int> umap = 
    {   {'X',1},{'Y',2},{'Z',3},
        {'A',1},{'B',2},{'C',3},
    };
    while(getline(file,line)){
        char enemy = line[0];
        char player = line[2];
        if(umap[player] == umap[enemy]) total += 3;
        else{
            switch (player)
            {
            case 'X':
                if(enemy == 'C') total += 6;
                break;
            case 'Y':
                if(enemy == 'A') total += 6;
                break;
            case 'Z':
                if(enemy == 'B') total += 6;
                break;
            }
        }
        total += umap[player];
    }
    return total;
}   


int problem2(ifstream &file){
    string line;
    int total = 0;
    unordered_map<char,int> umap = 
    {   
        {'A',0},{'B',1},{'C',2},
    };
    while(getline(file,line)){
        char enemy = line[0];
        char player = line[2];

        switch(player)
        {
        case 'X':
            total += ((umap[enemy]-1+3)%3)+1;
            break;
        case 'Y':
            total += 3; 
            total += umap[enemy]+1;
            break;
        case 'Z':
            total += 6;
            total += ((umap[enemy]+1)%3) + 1;
            break;
        }
    }
    return total;
}

int main(){
    ifstream file;

    file.open("../input/day2-1.txt",ios::in);
    
    if(!file.is_open()){
        cout << "Error Opening File" << endl;
        return -1;
    }

    cout << problem1(file) << endl;;

    file.clear();
    file.seekg(0, ios::beg);

    cout << problem2(file) << endl;

    file.close();
    return 0;
}