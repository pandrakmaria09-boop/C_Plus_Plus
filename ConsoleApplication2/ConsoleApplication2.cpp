#include <iostream>

using namespace std;


int** createArray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            arr[i][j] = rand() % 10;
    }
    return arr;
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void deleteArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

//1
void addRowToStart(int**& arr, int& rows, int cols) {
    int** newArr = new int* [rows + 1];
    newArr[0] = new int[cols];
    for (int j = 0; j < cols; j++)
        newArr[0][j] = rand() % 10;       
    for (int i = 0; i < rows; i++)
        newArr[i + 1] = arr[i];           
    delete[] arr;                         
    arr = newArr;
    rows++;
}

// 2
void removeRowFromStart(int**& arr, int& rows) {
    if (rows == 0) return;
    delete[] arr[0];                     
    int** newArr = new int* [rows - 1];
    for (int i = 1; i < rows; i++)
        newArr[i - 1] = arr[i];
    delete[] arr;
    arr = newArr;
    rows--;
}

// 3
void removeRowAt(int**& arr, int& rows, int pos) {
    if (pos < 0 || pos >= rows) {
        cout << "error" << endl;
        return;
    }
    delete[] arr[pos];
    int** newArr = new int* [rows - 1];
    for (int i = 0, k = 0; i < rows; i++) {
        if (i == pos) continue;
        newArr[k++] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    rows--;
}

// 4
void addColToStart(int** arr, int rows, int& cols) {
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols + 1];
        newRow[0] = rand() % 10;          
        for (int j = 0; j < cols; j++)
            newRow[j + 1] = arr[i][j];
        delete[] arr[i];
        arr[i] = newRow;
    }
    cols++;
}

// 5
void addColAt(int** arr, int rows, int& cols, int pos) {
    if (pos < 0 || pos > cols) {
        cout << "Невірна позиція!" << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols + 1];
        for (int j = 0, k = 0; j < cols + 1; j++) {
            if (j == pos)
                newRow[j] = rand() % 10;   
            else
                newRow[j] = arr[i][k++];   // коп. старі ел-нти
        }
        delete[] arr[i];
        arr[i] = newRow;
    }
    cols++;
}

// 6
void removeColAt(int** arr, int rows, int& cols, int pos) {
    if (pos < 0 || pos >= cols) {
        cout << "Невірна позиція!" << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols - 1];
        for (int j = 0, k = 0; j < cols; j++) {
            if (j == pos) continue;        
            newRow[k++] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = newRow;
    }
    cols--;
}
int main() {
    int rows = 3, cols = 4;
    int** arr = createArray(rows, cols);

    cout << "pochatcoviy masiv:" << endl;
    printArray(arr, rows, cols);

    addRowToStart(arr, rows, cols);
    cout << "1 :" << endl;
    printArray(arr, rows, cols);

    removeRowFromStart(arr, rows);
    cout << "2:" << endl;
    printArray(arr, rows, cols);

    removeRowAt(arr, rows, 1);
    cout << "3:" << endl;
    printArray(arr, rows, cols);

    addColToStart(arr, rows, cols);
    cout << "4:" << endl;
    printArray(arr, rows, cols);

    addColAt(arr, rows, cols, 2);
    cout << "5:" << endl;
    printArray(arr, rows, cols);

    removeColAt(arr, rows, cols, 1);
    cout << "6:" << endl;
    printArray(arr, rows, cols);

    deleteArray(arr, rows);   

   
}