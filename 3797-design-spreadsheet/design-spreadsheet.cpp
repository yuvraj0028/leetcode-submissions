class Spreadsheet {
private:
    unordered_map<char, int> colMapping;
    vector<vector<int > > grid;

    void populateColumnMap(){
        int colValue = 0;
        for(char i = 'A'; i<='Z'; i++){
            char ch = (char)i;
            colMapping[ch] = colValue;
            colValue++;
        }
    }

    bool checkOperandIsCell(string &operand){
        char ch = operand[0];
        return colMapping.find(ch) != colMapping.end();
    }

    pair<int,int> getRowColValueFromCell(string &cell){
        string rowString = cell.substr(1);
        char colLabel = cell[0];
        
        int row = stoi(rowString);
        cout<<row;
        int col = colMapping[colLabel];


        pair<int,int> rowColPair = make_pair(row, col);
        return rowColPair;
    }

    pair<int,int> parseFormulaString(string &formula){
        int value1 = 0, value2 = 0;
        int size = formula.size();
        int index = formula.find("+");

        string firstOperand = formula.substr(0,index);
        string secondOperand = formula.substr(index+1);
        
        bool isFirstOperandCell = checkOperandIsCell(firstOperand);
        bool isSecondOperandCell = checkOperandIsCell(secondOperand);

        if(isFirstOperandCell){
            pair<int,int> rowColPair = getRowColValueFromCell(firstOperand);
            int row = rowColPair.first;
            int col = rowColPair.second;

            value1 = grid[row][col];
        } else {
            value1 = stoi(firstOperand);
        }

        if(isSecondOperandCell){
            pair<int,int> rowColPair = getRowColValueFromCell(secondOperand);
            int row = rowColPair.first;
            int col = rowColPair.second;

            value2 = grid[row][col];
        } else {
            value2 = stoi(secondOperand);
        }

        pair<int,int> values = make_pair(value1, value2);
        return values;
    }
public:
    Spreadsheet(int rows) {
        populateColumnMap();
        this->grid.resize(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        pair<int,int> rowColPair = getRowColValueFromCell(cell);
        int row = rowColPair.first;
        int col = rowColPair.second;

        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        pair<int,int> rowColPair = getRowColValueFromCell(cell);
        int row = rowColPair.first;
        int col = rowColPair.second;

        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        pair<int,int> values = parseFormulaString(formula);
        return values.first + values.second;
    }
};