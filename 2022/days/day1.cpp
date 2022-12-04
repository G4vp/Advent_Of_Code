#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int problem1(ifstream &file){
    string line;

    int max = 0;
    int local = 0;
    while(getline(file,line)){
        if(line.empty()){
            if(local >= max) max = local;
            local = 0;
        }else{
            local += stoi(line);
        }
    }
    return max;
}


int problem2(ifstream &file){
    string line;

    int local = 0;
    int top[3] = {0,0,0};
    while(getline(file,line)){
        if(line.empty()){
            sort(begin(top),end(top));
            if(top[0] < local)top[0] = local;
            local = 0;
        }else{
            local += stoi(line);
        }
    }
    return top[0]+top[1]+top[2];
}

int main(){
    ifstream file;

    file.open("../input/day1-1.txt",ios::in);
    
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