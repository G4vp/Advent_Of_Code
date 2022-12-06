#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

int problem1(ifstream &file){
    string line;
    int total = 0;
    while(getline(file,line)){
        if(!line.empty()){
            string right, left, intercept;
            right = line.substr(0,line.size()/2);
            left = line.substr(line.size()/2,line.size());

            sort(right.begin(),right.end());
            sort(left.begin(),left.end());
            
            set_intersection(right.begin(),right.end(),left.begin(),left.end(), back_inserter(intercept));

            if(intercept[0] >= 65 && intercept[0] <= 90){
                total += int(intercept[0]) - 38;
            }else{
                total += int(intercept[0]) - 96;
            }
        }
    }
    return total;
}


int problem2(ifstream &file){
    string line;
    int total = 0;
    int count = 1;
    string str1, str2, str3, intercept1,intercept2;

    while(getline(file,line)){
        if(!line.empty()){
            switch(count){
                case 1:
                    str1 = line;
                    break;
                case 2:
                    str2 = line;    
                    break;
                case 3:
                    str3 = line;
                    
                    sort(str1.begin(),str1.end());
                    sort(str2.begin(),str2.end());
                    sort(str3.begin(),str3.end());

                
                    set_intersection(str1.begin(),str1.end(),str2.begin(),str2.end(), back_inserter(intercept1));

                    sort(intercept1.begin(),intercept1.end());

                    set_intersection(intercept1.begin(),intercept1.end(),str3.begin(),str3.end(), back_inserter(intercept2));

                    cout << intercept2 << endl;
                    if(intercept2[0] >= 65 && intercept2[0] <= 90){
                        total += int(intercept2[0]) - 38;
                    }
                    else{
                        total += int(intercept2[0]) - 96;
                    }
                    cout << str1 + " " + str2 + " " + str3 << endl;
                    count = 0;
                    intercept1 = "";
                    intercept2 = "";
                    break;
                }
            count++;
        }
    }
    return total;
}

int main(){
    ifstream file;

    file.open("../input/day3-1.txt",ios::in);
    
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