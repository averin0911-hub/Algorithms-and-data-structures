#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> array(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            array[i].push_back(x);
        }
        
    }

    bool ans = true;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if ((array[i][j] != array[j][i]) || (i == j && array[i][j] == 1)){ // Проверка, что ребро двунаправленно и что по диагонали нет 1
                ans = false;
                break;
            }
        }
    }

    if (ans == true){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
    
    return 0;
}