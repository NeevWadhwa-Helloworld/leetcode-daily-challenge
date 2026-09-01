struct Node {
    int val;
    struct Node* next;
};

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    struct Node** adjList = (struct Node**)calloc(numCourses, sizeof(struct Node*));
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        
        indegree[course]++;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = course;
        newNode->next = adjList[prereq];
        adjList[prereq] = newNode;
    }
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int count = 0;
    while (front < rear) {
        int curr = queue[front++];
        count++;
        struct Node* currNode = adjList[curr];
        while (currNode != NULL) {
            int neighbor = currNode->val;
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            currNode = currNode->next;
        }
    }
    for (int i = 0; i < numCourses; i++) {
        struct Node* currNode = adjList[i];
        while (currNode != NULL) {
            struct Node* temp = currNode;
            currNode = currNode->next;
            free(temp);
        }
    }
    free(adjList);
    free(indegree);
    free(queue);
    return count == numCourses;
}
