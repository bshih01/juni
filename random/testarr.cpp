#include <iostream>
using namespace std;

float* averageArray(int **arr, int m, int n) {
    float *result = new float [m];
    float s;
    for (int i = 0; i < m; i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            s += arr[i][j]; 
        }
        result[i] = s / n;
    }
    return result;
}
void print(int **arr) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void print1D(float *arr) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}
int main() {
    int **arr = new int*[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = new int[5];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = (i + 1) * (j + 1);
        }
    }
    print(arr);
    print1D(averageArray(arr, 5, 5));
    return 0;
}