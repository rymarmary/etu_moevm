#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Square{
    Square(int x = 0, int y = 0, int width = 0){
        this->x = x;
        this->y = y;
        this->w = width;
    }
    int x, y, w;
};

struct Backtracking_head{
    Backtracking_head(vector<vector<int>> base, int count, vector<Square> squares){
        this->base = base;
        this->squares = squares;
        this->count = count;
    }
    vector<vector<int>> base;
    vector<Square> squares;
    int count;
};

void New_Square(vector<vector<int>> &base, Square square){
    for (int i = square.x; i < square.x + square.w; i++){
        for (int j = square.y; j < square.y + square.w; j++)
            base[i][j] = 1;
    }
}

bool Check(int n, vector<vector<int>> base, Square square){  // if it's possible to place a square
    bool flag = true;
    if (square.x + square.w >= n || square.y + square.w >= n){
        flag = false;
    }
    if (base[square.x][square.y + square.w] != 0 || base[square.x + square.w][square.y]){
        flag = false;
    }
    if (base[square.x + square.w][square.y + square.w] != 0){
        flag = false;
    }
    if (square.x < 0 || square.y < 0){
        flag = false;
    }
    return flag;
}

void Multiple2(int n, vector<Square> &answer){
    answer = {{0, 0, n/2},
              {0, n/2, n/2},
              {n/2, 0, n/2},
              {n/2, n/2, n/2}};
}

void Multiple3(int n, vector<Square> &answer){
    answer = {{0, 0, n/3},
              {0, n/3, n/3},
              {0, 2 * (n/3), n/3},
              {2 * (n/3), 0, n/3},
              {n/3, n/3, 2 * (n/3)},
              {n/3, 0, n/3}};
}

void Multiple5(int n, vector<Square> &answer){
    answer = {{0, 0, 3 * (n/5)},
              {0, 3 * (n/5), 2 * (n/5)},
              {2 * (n/5), 3 * (n/5), n/5},
              {2 * (n/5), 4 * (n/5), n/5},
              {3 * (n/5), 0, 2 * (n/5)},
              {3 * (n/5), 3 * (n/5), 2 * (n/5)},
              {3 * (n/5), 2 * (n/5), n/5},
              {4 * (n/5), 2 * (n/5), n/5},
              };
}

void Backtracking(int n, int &count, vector<Square> &answer){
    vector<vector<int>> base(n);
    for (int i = 0; i < n; i++){
        base[i] = vector<int>(n, 0);
    }
    vector<Square> Existed_sqaures;
    New_Square(base, Square(n/2, n/2, n/2 + 1));
    Existed_sqaures.emplace_back(n/2, n/2, n/2 + 1);
    New_Square(base, Square(n-n/2, 0, n/2));
    Existed_sqaures.emplace_back(n-n/2, 0, n/2);
    New_Square(base, Square(0, n-n/2, n/2));
    Existed_sqaures.emplace_back(0, n-n/2, n/2);

    stack<Backtracking_head> Stack;
    Stack.emplace(base, 0, answer);
    while (!Stack.empty()){
        Backtracking_head last = Stack.top();
        Stack.pop();
        bool add_square = true;
        pair<int, int> point = {-1, -1};
        for (int x = 0; x < n/2 + 1; x++){
            for (int y = 0; y < n/2 + 1; y++){
                if (last.base[x][y] == 0){
                    point = {x, y};
                    add_square = false;
                    break;
                }
            }
            if (point.first > -1){
                break;
            }
        }
        if (add_square) {
            answer = last.squares;
            count = last.count;
        }
        if (count <= last.count + 1){
            continue;
        }
        for (int w = 0; w < n - 1; w++){
            pair<int, int> start = {point.first, point.second};
            if (Check(n, last.base, Square(point.first, point.second, w))){
                for (int x = start.first; x <= point.first + w; x++){
                    last.base[x][point.second + w] = last.squares.size() + 1;
                }
                for (int y = start.second; y <= point.second + w; y++){
                    last.base[point.first+w][y] = last.squares.size()+1;
                }
                start.first++;
                start.second++;
                last.squares.push_back(Square({point.first, point.second, w+1}));
                Stack.emplace(last.base, last.count+1, last.squares);
                last.squares.pop_back();
            } else break;
        }
    }
    copy(Existed_sqaures.begin(), Existed_sqaures.end(), back_inserter(answer));
}

void Output(vector<Square> answer, int ost){
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++){
        cout << (answer[i].x * ost + 1) << ' ' << (answer[i].y * ost + 1) << ' ' << (answer[i].w * ost) << '\n';
    }
}

int main(){
    int n;
    cin >> n;
    clock_t start = clock();
    vector<Square> answer;
    int count = n + 3 + 1;
    int prime = n;
    int ost = 1;
    if (n % 2 == 0){
        Multiple2(n, answer);
    } else if (n % 3 == 0){
        Multiple3(n, answer);
    } else if (n % 5 == 0){
        Multiple5(n, answer);
    } else {
        for (int i = 3; i < n; i++) {
            if (n % i == 0) {
                prime = i;
                ost = n / i;
                break;
            }
        }
        Backtracking(prime, count, answer);
    }
    Output(answer, ost);
    clock_t end = clock();
    cout << '\n' << (float)(end-start)/CLOCKS_PER_SEC << '\n';
    return 0;
}