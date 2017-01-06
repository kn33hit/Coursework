# author: 'Neh Patel '
# AI Homework #2
# python file takes in multiple inputs on command lines and outputs accordingly
#---------------------------------------------------------------------------
# Running the program: 
# first command -> /usr/bin/scl enable python33 bash
# then just run it using -> python hw2.py <file> ... <outfile>
#---------------------------------------------------------------------------
# Reference:
# http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
import sys
import string

def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    return visited

#-----------------------------------------------------------------
def bfs(graph, start):
    visited, queue = [], [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.append(vertex)
            queue.extend(graph[vertex] - visited)
    return visited

#----------------------------------------------------------------------
def readFile(filename):
    GraphNodeOne = []
    GraphNodeTwo = []
    GraphCost = []
    infile = open(filename, "r")
    i = 0
    for line in infile:
        data = line.split()
        GraphNodeOne.append(data[0])
        GraphNodeTwo.append(data[1])
        GraphCost.append(int(data[2]))
        i = i + 1
    infile.close()
    return GraphNodeOne, GraphNodeTwo, GraphCost
                      
def MakeGraph(GraphNodeOne,GraphNodeTwo):
    graph = {'A': set(['B', 'C']),
             'B': set(['E']),
             'C': set(['D', 'F','G']),
             'E': set(['C']),
             'F': set([ 'E', 'G'])}
    
#    graph.setdefault("",[])
#    graph[0] = GraphNodeOne[0]
#    graph[GraphNodeOne[0]].append(GraphNodeTwo[0])
#    for n in range(len(GraphNodeOne)):
#        for m in range(len(graph)):
#            if(graph[m] != GraphNodeOne[n]):
#                inGraph = true
#        if(inGraph == true):
#              graph[GraphNodeOne[n]].append(GraphNodeTwo[n])
#        else:
#            graph[len(graph) + 1 ] = GraphNodeOne[n]
#            graph[GraphNodeOne[n]].append(GraphNodeTwo[n])
    return graph


def main(argv):
    GraphNodeOne = []
    GraphNodeTwo = []
    GraphCost = []
    path = []
    # just for saving on the syntax 
    graph = {}

    if len(sys.argv) == 7:
        inFile = sys.argv[1]
        hueristicFile = sys.argv[2]
        algoSelected = sys.argv[3]
        start = sys.argv[4]
        end = sys.argv[5]
        outFile = sys.argv[6]
        # start code 
        GraphNodeOne, GraphNodeTwo, GraphCost = readFile( inFile )
        graph = MakeGraph(GraphNodeOne, GraphNodeTwo)
        if(algoSelected == "breadth"):
            path = bfs(graph, start)
            print("breadth")
        elif(algoSelected == "depth"):
            print("depth")
            path = dfs(graph, start)
        elif(algoSelected == "uniform"):
            #path = uniform(graph, start)
            print("uniform")
        elif(algoSelected == "best"):
            #path = best(graph, start)
            print("best")
        elif(algoSelected == "astar"):
            #path = astar(graph, start,end)
            print("astar")
        else:
            print("Please check the algorithm you've selected is correct")
    
        outfile = open(outFile, "w")
        for n in path:
            outfile.write(str(n))
            outfile.write("\n")
            

    else:
        print("Use: python hw2 <graphFile> <hueristicFile> <alogrithm> <startNode> <endNode> <outputFile>")
    

#=================================================================================
main(0)
