#include "HashTable.h"

Entry::Entry() {}

Entry::Entry(string date, string open, string high, string low, string close, string volume, string adjClose){
    this->date = date;
    // std::stof -> converts string to float
    this->open = stof(open);
    this->high = stof(high);
    this->low = stof(low);
    this->close = stof(close);
    this->volume = stof(volume);
    this->adjClose = stof(adjClose);
}

Aktie::Aktie() {}

int HashTable::hash_function(const std::string& s) {
    int hash_val = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        // static_cast<int> to get the ASCII number of the char s[i]
        hash_val += static_cast<int>(s[i]) * pow(31, n-1-i);
        }
    // Take the modulus to restrict the values from 0 to 1092
    return hash_val%1093;
}

int HashTable::getInsertionIndex(string s) {
    // TODO
    return 0;
}

void insertData(vector<vector<string>> data, int insertionIndex){
    // TODO
}

HashTable::HashTable() {}

//get data from csv and copy it into vector of vectors
vector<vector<string>> HashTable::readCSV(string fname){
    vector<vector<string>> output;
    vector<string> row;
    string line, word;

    // boilerplate code to read csv file
    fstream file (fname, ios::in);
    if(file.is_open())
    {
        // get line populates the variable line with the data in the file
        while(getline(file, line))  // loops until there are no more lines
        {
            row.clear();

            stringstream str(line);
            // get line takes each comma separated word from the str(line) and copies it in word
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            output.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    return output;
}

//get data of last 30 days from the already parsed CSV
vector<vector<string>> HashTable::takeLastMonthData(vector<vector<string>> parsedCSV){

    vector<vector<string>> output;
    //to take last 30 days data
    int finalIndex = parsedCSV.size() - 30;

    for(int i = parsedCSV.size() -1; i >= finalIndex; --i){
        output.push_back(parsedCSV[i]);
    }
    return output;

}

//Functions for ADD, DEL, IMPORT, ...
void HashTable::import(){
    // 0: Ask for kuerzel and filename
    string kuerzel;
    cout<<"Enter the Kuerzel:"<<endl;
    cin >> kuerzel;
    string fname;
    cout<<"Enter the path to the file: ";
    cin>>fname;
    // 1: Get insertion index
    int insertionIndex = getInsertionIndex(fname);
    // 2: Read the relevant CSV rows
    vector<vector<string>> content = readCSV(fname);
    // 3: Insert data in the corresponding index
    insertData(insertionIndex, content);

}
//TESTING
void HashTable::readCSVdebug(string fname){

    vector<vector<string>> parsedCSV = readCSV(fname);

    vector<vector<string>> output = takeLastMonthData(parsedCSV);

    for(int i = 0; i < output.size(); ++i){

        for(int j = 0; j < output[i].size(); ++j){

            cout<<output[i][j]<<", ";
        }
        cout<<endl;
    }
}