#include <iostream>
#include <string>
#include <queue> // For BFS

using namespace std;

struct ElmNode;

struct ElmEdge {
    ElmNode* dest;
    ElmEdge* next;
};

struct ElmNode {
    char info;
    bool visited;
    ElmEdge* edge;
    ElmNode* next;
};

struct Graph {
    ElmNode* first;
};

void CreateGraph(Graph& G) {
    G.first = nullptr;
}

void InsertNode(Graph& G, char V) {
    ElmNode* newNode = new ElmNode;
    newNode->info = V;
    newNode->visited = false;
    newNode->edge = nullptr;
    newNode->next = nullptr;

    if (G.first == nullptr) {
        G.first = newNode;
    } else {
        ElmNode* temp = G.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void ConnectNode(ElmNode* N1, ElmNode* N2) {
    ElmEdge* newEdge = new ElmEdge;
    newEdge->dest = N2;
    newEdge->next = N1->edge;
    N1->edge = newEdge;
}

void PrintInfoGraph(Graph G) {
    ElmNode* temp = G.first;
    while (temp != nullptr) {
        cout << temp->info << " -> ";
        ElmEdge* edgeTemp = temp->edge;
        while (edgeTemp != nullptr) {
            cout << edgeTemp->dest->info << " ";
            edgeTemp = edgeTemp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

void ResetVisited(Graph& G) {
    ElmNode* temp = G.first;
    while (temp != nullptr) {
        temp->visited = false;
        temp = temp->next;
    }
}

void PrintDFS(Graph G, ElmNode* N) {
    if (N == nullptr) {
        return;
    }
    N->visited = true;
    cout << N->info << " ";
    ElmEdge* temp = N->edge;
    while (temp != nullptr) {
        if (!temp->dest->visited) {
            PrintDFS(G, temp->dest);
        }
        temp = temp->next;
    }
}

void PrintBFS(Graph G, ElmNode* N) {
    queue<ElmNode*> q;
    q.push(N);
    N->visited = true;

    while (!q.empty()) {
        ElmNode* temp = q.front();
        q.pop();
        cout << temp->info << " ";
        ElmEdge* tempEdge = temp->edge;
        while (tempEdge != nullptr) {
            if (!tempEdge->dest->visited) {
                q.push(tempEdge->dest);
                tempEdge->dest->visited = true;
            }
            tempEdge = tempEdge->next;
        }
    }
}

int main() {
    Graph G;

    CreateGraph(G);

    // Insert nodes
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Retrieve nodes
    ElmNode* A = G.first;
    ElmNode* B = A->next;
    ElmNode* C = B->next;
    ElmNode* D = C->next;
    ElmNode* E = D->next;
    ElmNode* F = E->next;
    ElmNode* G1 = F->next;
    ElmNode* H = G1->next;

    // Connect nodes
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(A, D);
    ConnectNode(B, E);
    ConnectNode(B, F);
    ConnectNode(C, G1);

    // Print graph info
    cout << "Graph structure:" << endl;
    PrintInfoGraph(G);

    // DFS
    cout << "\nDFS Traversal:" << endl;
    ResetVisited(G);
    PrintDFS(G, A);

    // BFS
    cout << "\n\nBFS Traversal:" << endl;
    ResetVisited(G);
    PrintBFS(G, A);

    return 0;
}
