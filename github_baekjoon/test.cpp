#define MIN(a,b) ((a<b)?a:b)

#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair> Graph[801];
int minCost[801][801]{};

int N, E;

void init() {
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) {
                minCost[i][j] = 0;
            }
            else
                minCost[i][j] = INT_MAX;
        }
    }
}

void dijkstra(int targetNode) {
    for (auto& p : Graph[targetNode]) {
        int nextNode = p.second;
        for (auto& p2 : Graph[nextNode]) {
            int nnCost = p2.first;
            int nnNode = p2.second;

            if (minCost[targetNode][nnNode] > minCost[targetNode][nextNode] + nnCost) {
                minCost[targetNode][nnNode] = minCost[targetNode][nextNode] + nnCost;
            }
        }
    }
}

bool isPossibleWay(int START, int v1, int v2, int END) {
    return minCost[START][v1] != INT_MAX && minCost[v1][v2] != INT_MAX && minCost[v2][END] != INT_MAX;
}

int getTotalCost(int START, int v1, int v2, int END) {
    return minCost[START][v1] + minCost[v1][v2] + minCost[v2][END];
}

int main()
{
    cin >> N >> E;
    int START = 1, END = N;

    init();

    while (E--) {
        int s, e, c;
        cin >> s >> e >> c;

        minCost[s][e] = MIN(minCost[s][e], c);
        minCost[e][s] = MIN(minCost[e][s], c);

        Graph[s].push_back({ c,e });
        Graph[e].push_back({ c,s });
    }

    int v1, v2;
    cin >> v1 >> v2;

    for (int i = START; i <= N; i++) {
        dijkstra(i);
    }

    int answer = INT_MAX;

    if (isPossibleWay(START, v1, v2, END)) {
        answer = MIN(answer, getTotalCost(START, v1, v2, END));
    }

    if (isPossibleWay(START, v2, v1, END)) {
        answer = MIN(answer, getTotalCost(START, v2, v1, END));
    }

    if (answer == INT_MAX) {
        cout << -1;
    }
    else
        cout << answer;


    cout << '\n';

    for (int i = START; i <= END; i++) {
        for (int j = START; j <= END; j++)
        {
            cout << minCost[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
