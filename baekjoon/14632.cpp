#include <iostream>
#include <vector>
using namespace std;

char paper[1000][1000];
char stamps[500][500][500];
int stamp_sizes[500][2];
int N, M;

void stamp_on_paper(int stamp_idx, int y, int x) {
    int stamp_y_max = stamp_sizes[stamp_idx][0] + min(0, N - (y + stamp_sizes[stamp_idx][0]));
    int stamp_x_max = stamp_sizes[stamp_idx][1] + min(0, M - (x + stamp_sizes[stamp_idx][1]));
    for(int i=0; i < stamp_y_max; i++) {
        for(int j=0; j < stamp_x_max; j++) {
            int paper_y = y + i;
            int paper_x = x + j;
            paper[paper_y][paper_x] = stamps[stamp_idx][i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, H, W, Q, T, Y, X;
    cin >> N >> M >> K;
    fill(&paper[0][0], &paper[999][1000], '.');
    for(int i=0; i < K; i++) {
        cin >> H >> W;
        stamp_sizes[i][0] = H;
        stamp_sizes[i][1] = W;
        for(int h=0; h < H; h++) {
            for(int w=0; w < W; w++) {
                cin >> stamps[i][h][w];
            }
        }
    }

    cin >> Q;
    for(int i=0; i < Q; i++) {
        cin >> T >> Y >> X;
        stamp_on_paper(T - 1, Y, X);
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cout << paper[i][j];
        }
        cout << '\n';
    }
}