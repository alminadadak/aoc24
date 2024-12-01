#include <iostream>
#include <fstream>    
#include <vector>
#include <sstream>   
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");  
    if (!inputFile.is_open()) {
        cerr << "Error! Couldn't open the file..." << endl;
        return 1;  
    }

    vector<int> list1, list2;  
    string line;
    int totalDistance = 0;
    int similarityScore = 0;


    while (getline(inputFile, line)) {
        istringstream iss(line);  
        int num1, num2;
        if (iss >> num1 >> num2) {  
            list1.push_back(num1);
            list2.push_back(num2);
        } else {
            cout << "Something is wrong with this input! Skipping: " << line << endl;
        }
    }

    inputFile.close();  



    for (auto it = list1.begin(); it != list1.end(); ++it) {
        similarityScore += (count(list2.begin(), list2.end(), *it) * *it);
    }


    sort(list1.begin(), list1.end(), greater<int>());
    sort(list2.begin(), list2.end(), greater<int>());

    while(list1.size() != 0 && list2.size() != 0){
        totalDistance += abs(list1.back() - list2.back());
        list1.pop_back();
        list2.pop_back();
    }

    cout << "the total distance is: " << totalDistance << endl;
    cout << "the similarity score is: " << similarityScore << endl;

    return 0;
}