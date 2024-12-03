#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector> 

using namespace std;

int main(){
    
    //string text = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
    ifstream file("input.txt");
    string line;
    int result = 0;
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))"); //restudy here
    vector<string> matched;
    bool condition = true;

    if (file.is_open()) {
        while (getline(file, line)) {
            for (sregex_iterator rit(line.begin(), line.end(), pattern), end; rit != end; ++rit) {
                matched.push_back(rit->str()); 
                smatch match = *rit;
                string strmatch = match.str(0);
                cout << strmatch << endl;

                if(strmatch == "don't()"){
                    condition = false;
                    continue;
                }
                else if(strmatch == "do()"){
                    condition = true;
                    continue;
                }

                if(condition){
                    int num1 = stoi(match[1]); 
                    int num2 = stoi(match[2]); 
                    result += (num1 * num2); 
                }

            }
        }
        file.close();
    } else {
        cout << "couldn't open the file..." << endl;
        return 1;
    }

    cout << "result: " << result << endl;

    return 0;
}

