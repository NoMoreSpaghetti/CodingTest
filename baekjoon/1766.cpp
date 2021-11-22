// 참고: https://jason9319.tistory.com/93


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int> v[32001];
priority_queue<int> pq;
int indegree[32001] = {0};

void topological_sort() {
    while(!pq.empty()) {
        int here = -pq.top();
        pq.pop();
        cout << here << ' ';
        for(int i=0; i < v[here].size(); i++) {
            int there = v[here][i];
            indegree[there]--;
            if(indegree[there] == 0) {
                pq.push(-there);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;

    cin >> N >> M;

    for(int m=0; m < M; m++) {
        cin >> A >> B;
        v[A].push_back(B);
        indegree[B]++;
    }

    for(int n=1; n <= N; n++) {
        if(indegree[n] == 0) {
            pq.push(-n);
        }
    }

    topological_sort();
}