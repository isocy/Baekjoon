#include <iostream>
#include <stack>


using namespace std;


int main() {
    int N;
    cin >> N;

    stack<int> inc_stack;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        
        while (!inc_stack.empty() && inc_stack.top() > num) {
            inc_stack.pop();
        }
        inc_stack.push(num);
    }

    cout << (N + 1 - inc_stack.size());

    return 0;
}