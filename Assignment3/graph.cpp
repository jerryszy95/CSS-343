#include <queue>
#include <climits>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stack>

#include "graph.h"

/**
 * A graph is made up of vertices and edges
 * A vertex can be connected to other vertices via weighted, directed edge
 */


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


/** constructor, empty graph */
Graph::Graph() {
    numberOfEdges = 0;
    numberOfVertices = 0;
    //vertices.clear(); //probably don't need
}

/** destructor, delete all vertices and edges
 only vertices stored in map
 no pointers to edges created by graph */
Graph::~Graph() {
    // go through graph verticies and delete
    for (std::map<std::string, Vertex*>::iterator it = vertices.begin(),
         it_end = vertices.end(); it != it_end; it++) {
        delete it->second;
    }
}

/** return number of vertices */
int Graph::getNumVertices() const {
    return numberOfVertices;
}

/** return number of vertices */
int Graph::getNumEdges() const {
    return numberOfEdges;
}

/** add a new edge between start and end vertex
 if the vertices do not exist, create them
 calls Vertex::connect
 a vertex cannot connect to itself
 or have multiple edges to another vertex */
bool Graph::add(std::string start, std::string end, int edgeWeight) {
    findOrCreateVertex(end);
    Vertex * temp = findOrCreateVertex(start);
    
    if ((temp->connect(end, edgeWeight))) {
        numberOfEdges++;
        return true;
    }
    return false;
}

/** return weight of the edge between start and end
 returns INT_MAX if not connected or vertices don't exist */
int Graph::getEdgeWeight(std::string start, std::string end) const {
    return vertices.at(start)->getEdgeWeight(end);
}

/** read edges from file
 the first line of the file is an integer, indicating number of edges
 each edge line is in the form of "string string int"
 fromVertex  toVertex    edgeWeight */
void Graph::readFile(std::string filename) {
    std::ifstream toRead(filename);
    int weight = 0;
    std::string parse = " ";
    std::string startVertex = " ";
    std::string endVertex = " ";
    std::stringstream ss;
    if (toRead.is_open()) {
        std::getline(toRead, parse);
        parse = " ";
        while (std::getline(toRead, parse)) {
            ss << parse;
            ss >> startVertex >> endVertex >> weight;
            add(startVertex, endVertex, weight);
            //reset
            startVertex = " ";
            endVertex = " ";
            parse = " ";
            ss.clear();
        }
    }
    else
        std::cerr << "Can not open file: " << filename;
    toRead.close();
}

/** depth-first traversal starting from startLabel
 call the function visit on each vertex label */
void Graph::depthFirstTraversal(std::string startLabel,
                                void visit(const std::string&)) {
    std::stack<Vertex> stack;
    std::string current = " ";
    this->unvisitVertices();
    stack.push(*(vertices.at(startLabel)));
    visit(vertices.at(startLabel)->getLabel());
    vertices.at(startLabel)->visit();
    while (!stack.empty()) {
        //find unvisited neighbor
        current = UnvisitedNeighbor(stack.top().getLabel());
        if (!(vertices.at(current)->isVisited())) {
            stack.push(*(vertices.at(current)));
            vertices.at(current)->visit();
            visit(current);
        }
        else
            stack.pop();
    }
}
//return unvisited neighbor
//returns startVertex label，if no unvisited neighbor
std::string Graph::UnvisitedNeighbor(std::string startVertex) {
    std::string unvisitedN =
    vertices.at(startVertex)->getNextNeighbor();
    int neighbors = vertices.at(startVertex)->getNumberOfNeighbors();
    for (int i = 0; i < neighbors; i++) {
        if (!(vertices.at(unvisitedN)->isVisited()))
            break;
        else
            unvisitedN = vertices.at(startVertex)->getNextNeighbor();
    }
    return unvisitedN;
}

/** breadth-first traversal starting from startLabel
 call the function visit on each vertex label */
void Graph::breadthFirstTraversal(std::string startLabel,
                                  void visit(const std::string&)) {
    std::queue<Vertex> queue;
    std::string neighbor;
    std::string curVertex = startLabel;
    int size = 0;
    this->unvisitVertices();
    queue.push(*(vertices.at(startLabel)));
    vertices.at(startLabel)->visit();
    visit(startLabel);
    while (!queue.empty()) {
        curVertex = queue.front().getLabel();
        size = vertices.at(curVertex)->getNumberOfNeighbors();
        queue.pop();
        for (int i = 0; i < size; i++) {
            neighbor = vertices.at(curVertex)->getNextNeighbor();
            if (!vertices.at(neighbor)->isVisited()) {
                visit(neighbor);
                vertices.at(neighbor)->visit();
                queue.push(*(vertices.at(neighbor)));
            }
        }
    }
}

/** find the lowest cost from startLabel to all vertices that can be reached
 using Djikstra's shortest-path algorithm
 record costs in the given map weight
 weight["F"] = 10 indicates the cost to get to "F" is 10
 record the shortest path to each vertex using given map previous
 previous["F"] = "C" indicates get to "F" via "C"
 cpplint gives warning to use pointer instead of a non-const map
 which I am ignoring for readability */
void Graph::djikstraCostToAllVertices(
                                      std::string startLabel,
                                      std::map<std::string,
                                      int>& weight,
                                      std::map<std::string,
                                      std::string>& previous) {
    this->unvisitVertices();
    std::string u = " ";
    std::string v = " ";
    int numOfNeighbors = vertices.at(startLabel)->getNumberOfNeighbors();
    int VNeighbor = 0;
    int VtoUcost = 0;
    weight.clear();
    previous.clear();
    typedef std::pair<int, std::string> P;
    struct Order {
        bool operator()(P a, P b) const {
            return a.first > b.first;
        }
    };
    std::priority_queue<P,std::deque<P>, Order> Pqueue;
    std::set<std::string> verSet;
    for (int i = 0; i < numOfNeighbors; i++) { // initial weights
        u = vertices.at(startLabel)->getNextNeighbor();
        weight[u] = vertices.at(startLabel)->getEdgeWeight(u);
        previous[u] = startLabel;
        Pqueue.push(P(weight[u], u));
    }
    verSet.insert((vertices.at(startLabel)->getLabel()));
    while (!Pqueue.empty()) {
        v = Pqueue.top().second;
        verSet.insert((vertices.at(v)->getLabel()));
        Pqueue.pop();
        if (verSet.find(v) != verSet.end()) {
            VNeighbor = vertices.at(v)->getNumberOfNeighbors();
            u = vertices.at(v)->getNextNeighbor();
            for (int k = 0; k < VNeighbor; k++) {
                if (verSet.count(u) > 0) {
                    u = vertices.at(v)->getNextNeighbor();
                    continue;
                }
                VtoUcost = vertices.at(v)->getEdgeWeight(u);
                if (weight.find(u) == weight.end()) {
                    weight[u] = weight[v] + VtoUcost;
                    previous[u] = v;
                    Pqueue.push(P(weight[u], u));
                }
                else {
                    if (weight[u] > (weight[v] + VtoUcost)) {
                        weight[u] = weight[v] + VtoUcost;
                        previous[u] = v;
                        Pqueue.push(P(weight[u], u));
                    }
                }
                u = vertices.at(v)->getNextNeighbor();
            }
        }
    }
}


/** mark all verticies as unvisited */
void Graph::unvisitVertices() {
    std::map<std::string, Vertex*>::iterator it = vertices.begin();
    while (it != vertices.end()) {
        it->second->unvisit();
        it->second->resetNeighbor();
        it++;
    }
}

/** find a vertex, if it does not exist return nullptr */
Vertex* Graph::findVertex(const std::string& vertexLabel) const {
    if (vertices.find(vertexLabel) != vertices.end())
        return vertices.at(vertexLabel);
    else
        return nullptr; 
}

/** find a vertex, if it does not exist create it and return it */
Vertex* Graph::findOrCreateVertex(const std::string& vertexLabel) {
    if (findVertex(vertexLabel) == nullptr) {
        Vertex * newVer = new Vertex(vertexLabel);
        vertices[vertexLabel] = newVer;
        vertices.at(newVer->getLabel())->resetNeighbor();
        numberOfVertices++;
        return newVer;
    }
    else
        return findVertex(vertexLabel);
}

/** function for disconnect edges */
bool Graph::removeEdge(std::string start, std::string end) {
    numberOfEdges--;
    return vertices.at(start)->disconnect(end);
}
