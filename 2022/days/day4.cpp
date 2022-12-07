#include <iostream>
#include <algorithm>
#include <fstream>

#include <cstring>
#include <sstream>
#include <vector>

using namespace std;


vector<int> split(string s, char del){
    stringstream ss(s);
    string item;
    vector<int> v;
    while (!ss.eof())
    {
        getline(ss,item,del);
        v.push_back(stoi(item));
    }
    return v;
}
int problem1(ifstream &file){
    string line;
    int ans = 0;
    while(getline(file,line)){
        if(!line.empty()){
            size_t ps = line.find(',');
            string str1 = line.substr(0,ps);
            string str2 = line.substr(ps+1,line.size());

            vector<int> a = split(str1,'-');
            vector<int> b = split(str2,'-');

            if((a[0] >= b[0] && a[1] <= b[1]) || (a[0] <= b[0] && a[1] >= b[1])){
                ans++;
            }
        }
    }
    return ans;
}


int problem2(ifstream &file){
    string line;
    while(getline(file,line)){

    }
    return 1;
}

int main(){
    ifstream file;

    file.open("../input/day4-1.txt",ios::in);
    
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