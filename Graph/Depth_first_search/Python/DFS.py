#******************Algorithm Part About DFS*********************


def DFS(matrix, visited, start, end):

    visited.append(start) # add @start into the visited list
    if start == end:
        return True

    size = len(matrix)
    for i in xrange(size):
        if matrix[start][i] != INF and i not in visited:
            if DFS(matrix, visited, i, end) == True:
                return True

    return False

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
size = len(graph)
visited = []
DFS(graph, visited, 0, 4,)
print visited