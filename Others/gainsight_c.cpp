function(tree) {
    queue<pair<int, int>> q;
    int deptharray[21];
    for (int i = 0; i < 21; i++) {
        deptharray[i] = (1 << 30);
    }
    q.push(1, 10);
    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();
        if (deptharray[depth] == (1 << 30)) {
            deptharray[depth] = node;
        }
        if (node has left child) {
            q.push(node.left, depth - 1);
        }
        if (node has right child) {
            q.push(node.right, depth + 1);
        }
    }
}

dept 