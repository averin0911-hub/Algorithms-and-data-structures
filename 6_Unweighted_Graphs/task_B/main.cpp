#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> stok;
    vector<int> istok;
    

    vector<vector<int>> matrix(n); // Матрица смежности
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            matrix[i].push_back(x);
        }
    }



    for (int i = 0; i < n; i++){
        bool is_istok = true;
        bool is_stok = true;

        // Проверка на исток
        for (int j = 0; j < n; j++){ // Столбец должен быть нулевым
            if (matrix[j][i] == 1){
                is_istok = false;
                break;
            }
        }
        if (is_istok){
            istok.push_back(i + 1);
        }
        

        // Проверка на сток
        for (int j = 0; j < n; j++){ // Строка должна быть нулевой
            if (matrix[i][j] == 1){
                is_stok = false;
                break;
            }
        }
        if (is_stok){
            stok.push_back(i + 1);
        }

    }


    cout << istok.size() << '\n';
    for (int node : istok){
        cout << node << '\n';
    }

    cout << stok.size() << '\n';
    for (int node : stok){
        cout << node << '\n';
    }



    return 0;
}