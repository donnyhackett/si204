#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string file, temp;
    cin >> file;
    ifstream fin(file);
    int n;
    fin >> temp >> temp >> n;
    double *first = new double[n];
    double *second = new double[n];
    fin >> temp;
    for(int i = 0; i < n; i++){
        fin >> first[i];
    }
    fin >> temp;
    for(int i = 0; i < n; i++){
        fin >> second[i];
    }
    for(int i = 0; i < n; i++){
        cout << "(" << first[i] << "," << second[i] << ") ";
    }
    cout << endl;
    return 0;
}