#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;


vector<vector<string>> readCsvString(string fname) {
    vector<vector<string>> content;
        vector<string> row;
        string line, word;
        
        fstream file (fname, ios::in);
        if (file.is_open()) {
            while(getline(file, line)) {
                row.clear();
            
                stringstream str(line);
                
                while (getline(str, word, ',')) {
                    row.push_back(word);
                }
                content.push_back(row);
            }
        }
        else {
            cout<<"Could not open the file\n";
        }
    return content;
}

vector<vector<double>> readCsvNumeric(string fname) {
    vector<vector<double>> content;
        vector<double> row;
        string line, word;
        
        fstream file (fname, ios::in);
        if (file.is_open()) {
            while(getline(file, line)) {
                row.clear();
            
                stringstream str(line);
                
                while (getline(str, word, ',')) {
                    row.push_back(stoi(word));
                }
                content.push_back(row);
            }
        }
        else {
            cout<<"Could not open the file\n";
        }
    return content;
}

void showMatrix(vector<vector<double>> matrix) {
    for (int i=0; i<matrix.size(); ++i) {
        for (int j=0; j<matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void showMatrix(vector<double> vector) {
    for (int i=0; i<vector.size(); ++i) {
        cout << vector[i] << endl;
    }
}
void showMatrix(vector<int> vector) {
    for (int i=0; i<vector.size(); ++i) {
        cout << vector[i] << endl;
    }
}