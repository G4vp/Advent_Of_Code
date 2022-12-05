#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int problem1(ifstream &file){
    string line;
    while(getline(file,line)){

    }
    return 1;
}


int problem2(ifstream &file){
    string line;
    while(getline(file,line)){

    }
    return 1;
}

int main(){
    ifstream file;

    file.open("",ios::in);
    
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