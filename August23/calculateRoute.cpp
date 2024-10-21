// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <limits>
// #include <algorithm>
 
// using namespace std;
 
// // Enum to define different road types and their corresponding speeds (in km/h)
// enum RoadType {
//     HIGHWAY = 120,    // Highway with speed 120 km/h
//     CITY_ROAD = 60,   // City road with speed 60 km/h
//     RURAL_ROAD = 40   // Rural road with speed 40 km/h
// };
 
// // Structure to represent an edge in the graph
// // Each edge connects two nodes (intersections) and has a road type and a distance
// struct Edge {
//     int destination;       // Destination node
//     RoadType roadType;     // Type of road
//     double distance;       // Distance between the nodes
// };
 
// // Structure to represent a node in the priority queue during Dijkstra's algorithm
// // Nodes are prioritized based on the total time taken to reach them
// struct Node {
//     int id;                // Node ID
//     double time;           // Time taken to reach this node
 
//     // Operator overload to compare nodes based on time
//     // This is needed for the priority queue to order nodes correctly
//     bool operator>(const Node& other) const {
//         return time > other.time;
//     }
// };
 
// // Function to calculate the time required to travel a given distance on a given road type
// double calculateTime(double distance, RoadType roadType) {
//     return distance / roadType;
// }
 
// // Function implementing Dijkstra's algorithm to find the shortest path between two nodes
// vector<int> dijkstra(int startNode, int endNode, const unordered_map<int, vector<Edge>>& graph) {
//     unordered_map<int, double> minTime;      // Stores the minimum time to reach each node
//     unordered_map<int, int> previousNode;    // Stores the previous node for each node on the shortest path
//     priority_queue<Node, vector<Node>, greater<Node>> pq; // Priority queue to select the next node to process
 
//     // Initialize minimum times with infinity (except the start node)
//     for (const auto& node : graph) {
//         minTime[node.first] = numeric_limits<double>::infinity();
//     }
//     minTime[startNode] = 0.0;  // Start node has a time of 0
//     pq.push({startNode, 0.0}); // Push the start node to the priority queue
 
//     // Main loop of Dijkstra's algorithm
//     while (!pq.empty()) {
// int currentNode = pq.top().id;     // Get the node with the smallest time
// double currentTime = pq.top().time;
//         pq.pop();
 
//         if (currentNode == endNode) break; // If we reached the end node, stop
 
//         // Explore all adjacent nodes (neighbors)
// for (const Edge& edge : graph.at(currentNode)) {
//             // Calculate the time to reach the neighboring node
//             double newTime = currentTime + calculateTime(edge.distance, edge.roadType);
//             // If this path is shorter, update the time and the previous node
//             if (newTime < minTime[edge.destination]) {
//                 minTime[edge.destination] = newTime;
//                 previousNode[edge.destination] = currentNode;
//                 pq.push({edge.destination, newTime}); // Push the neighbor to the queue
//             }
//         }
//     }
 
//     // Reconstruct the shortest path by backtracking from the end node to the start node
//     vector<int> route;
//     for (int at = endNode; at != startNode; at = previousNode[at]) {
//         route.push_back(at);
//     }
//     route.push_back(startNode);
//     reverse(route.begin(), route.end()); // Reverse the route to get it in the correct order
 
//     return route;  // Return the route from start to end node
// }
 
// int main() {
//     int numNodes, numEdges;
//     cout << "Enter number of nodes: ";
//     cin >> numNodes;
//     cout << "Enter number of edges: ";
//     cin >> numEdges;
 
//     unordered_map<int, vector<Edge>> graph; // Graph representation using an adjacency list
 
//     // Input the graph's edges
//     cout << "Enter edges (start end road_type distance):" << endl;
//     for (int i = 0; i < numEdges; ++i) {
//         int start, end, roadType;
//         double distance;
//         cin >> start >> end >> roadType >> distance;
//         graph[start].push_back({end, static_cast<RoadType>(roadType), distance});
//         graph[end].push_back({start, static_cast<RoadType>(roadType), distance});
//     }
 
//     int startNode, endNode;
//     cout << "Enter start node: ";
//     cin >> startNode;
//     cout << "Enter end node: ";
//     cin >> endNode;
 
//     // Find the shortest route from startNode to endNode using Dijkstra's algorithm
//     vector<int> route = dijkstra(startNode, endNode, graph);
 
//     // Output the result
//     cout << "Shortest route: ";
//     for (int node : route) {
//         cout << node << " ";
//     }
//     cout << endl;
 
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

// Enum to define different road types and their corresponding speeds (in km/h)
enum RoadType {
    HIGHWAY = 120,    // Highway with speed 120 km/h
    CITY_ROAD = 60,   // City road with speed 60 km/h
    RURAL_ROAD = 40   // Rural road with speed 40 km/h
};

// Structure to represent an edge in the graph
// Each edge connects two nodes (intersections) and has a road type and a distance
struct Edge {
    int destination;       // Destination node
    RoadType roadType;     // Type of road
    double distance;       // Distance between the nodes
};

// Structure to represent a node in the priority queue during Dijkstra's algorithm
// Nodes are prioritized based on the total time taken to reach them
struct Node {
    int id;                // Node ID
    double time;           // Time taken to reach this node

    // Operator overload to compare nodes based on time
    // This is needed for the priority queue to order nodes correctly
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

// Function to calculate the time required to travel a given distance on a given road type
double calculateTime(double distance, RoadType road) {
    // Ensure both operands are of the same essential type category (double)
    return distance / static_cast<double>(road);
}

// Function prototype for Dijkstra's algorithm
vector<int> dijkstra(int startNode, int endNode, const unordered_map<int, vector<Edge>>& graph);

int main() {
    int numNodes;
    int numEdges;
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    unordered_map<int, vector<Edge>> graph; // Graph representation using an adjacency list

    // Input the graph's edges
    cout << "Enter edges (start end road_type distance):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int start;
        int end;
        int roadType;
        double distance;
        cin >> start >> end >> roadType >> distance;
        graph[start].push_back({end, static_cast<RoadType>(roadType), distance});
        graph[end].push_back({start, static_cast<RoadType>(roadType), distance});
    }

    int startNode;
    int endNode;
    cout << "Enter start node: ";
    cin >> startNode;
    cout << "Enter end node: ";
    cin >> endNode;

    // Find the shortest route from startNode to endNode using Dijkstra's algorithm
    vector<int> route = dijkstra(startNode, endNode, graph);

    // Output the result
    cout << "Shortest route: ";
    for (size_t i = 0; i < route.size(); ++i) {
        cout << route[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function implementing Dijkstra's algorithm to find the shortest path between two nodes
vector<int> dijkstra(int startNode, int endNode, const unordered_map<int, vector<Edge>>& graph) {
    unordered_map<int, double> minTime;      // Stores the minimum time to reach each node
    unordered_map<int, int> previousNode;    // Stores the previous node for each node on the shortest path
    priority_queue<Node, vector<Node>, greater<Node>> pq; // Priority queue to select the next node to process

    // Initialize minimum times with infinity (except the start node)
    for (const auto& node : graph) {
        minTime[node.first] = numeric_limits<double>::infinity();
    }
    minTime[startNode] = 0.0;  // Start node has a time of 0
    pq.push({startNode, 0.0}); // Push the start node to the priority queue

    // Main loop of Dijkstra's algorithm
    while (!pq.empty()) {
        int currentNode = pq.top().id;     // Get the node with the smallest time
        double currentTime = pq.top().time;
        pq.pop();

        if (currentNode == endNode) {
            break; // If we reached the end node, stop
        }

        // Explore all adjacent nodes (neighbors)
        for (const Edge& edge : graph.at(currentNode)) {
            // Calculate the time to reach the neighboring node
            double newTime = currentTime + calculateTime(edge.distance, edge.roadType);
            // If this path is shorter, update the time and the previous node
            if (newTime < minTime[edge.destination]) {
                minTime[edge.destination] = newTime;
                previousNode[edge.destination] = currentNode;
                pq.push({edge.destination, newTime}); // Push the neighbor to the queue
            }
        }
    }

    // Reconstruct the shortest path by backtracking from the end node to the start node
    vector<int> route;
    for (int at = endNode; at != startNode; at = previousNode[at]) {
        route.push_back(at);
    }
    route.push_back(startNode);
    reverse(route.begin(), route.end()); // Reverse the route to get it in the correct order

    return route;  // Return the route from start to end node
}
