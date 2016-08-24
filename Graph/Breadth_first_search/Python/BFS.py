#******************Algorithm Part About BFS*********************

def BFS(matrix, start, end):

    size = len(matrix)
    visited = [start]
    Q = [ [start] ]
    path = [] # possible solution, @path is a nested list [[] ...]

    while len(Q) != 0:
        path = Q.pop(0)
        curNode = path[-1]

        if curNode == end:
            return path # the solution

        neighbors = []
        for i in xrange(size):
            if matrix[curNode][i] != INF:
                neighbors.append(i)

        # to find the neighbors who are unvisited
        i = 0
        while i < len(neighbors):
            if neighbors[i] in visited:
                neighbors.remove(neighbors[i])
            else:
                i += 1
        #add unvisited neighbor into visited line.
        for i in neighbors:
            visited.append(i)
            Q.append(path + [i])

    return None

#***************************************************************

def checkAdjMatrix(matrix):
    if matrix == None or not isinstance(matrix, list):
        return False

    size = len(matrix)

    for i in xrange(size):
        if size != len(matrix[i]) or not isinstance(matrix[i], list):
            return False

    return True

INF = float('inf')
graph = [
    [INF, 7, 9, INF, INF, 14],
    [7, INF, 10, 15, INF, INF],
    [9, 19, INF, 11, INF, 2],
    [INF, 15, 11, INF, 6, INF],
    [INF, INF, INF, 6, INF, 9],
    [14, INF, 2, INF, 9, INF]
]

print BFS(graph, 0, 4,)
