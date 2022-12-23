#include "GraphBase.hpp"
#include <queue>
#include <iterator>
#include <vector>
#include <deque>
#include <string>
#include <vector>


using namespace std;

class Class_of_vertex {
        private:
        string str_vertex;
        unsigned long fastestpath; // fastest distance variable
        vector<string> quickest;// to store the quickest (shortest) edges in the vertexs 
        bool visit; // check if been vistied
        public:
        friend class Graph;  //vertex class comes from graph inheritance
        Class_of_vertex(){ 
        str_vertex= ""; //overwriting vertex value
        }
        ~Class_of_vertex(){} //destructor
        };


class Class_of_Edge{
        private:
        unsigned long EdgeWeight; // weight for edge
        string A; // current edge
        string B; // adjacent edge
        public:
        friend class Graph;
        Class_of_Edge(string stringA = "", 
        string stringB = "", 
        unsigned long weight = 0){ EdgeWeight = weight; A = stringA; B = stringB; } // overwriting class's elements in constructor 
        ~Class_of_Edge() {} //destructor
};




class Graph:public GraphBase{
        private:
        unsigned long quick=0; // quickest way 
        int index_minVer=0;// setting index of min vertex to 0
        string smallestElem ="";
        deque<Class_of_vertex*>Deq_vert; // deque for vertexes
        priority_queue<pair<unsigned long, string>, //  store vertexes in ascending order in queue
        vector<pair<unsigned long, string>>,
        greater<pair<unsigned long, string>>> PathList;
        deque<Class_of_Edge*> Deq_edges; // deques for the edges
        protected:
        void beginner(string starttag); // beginning path
        void builder(string starttag); // makes the beginning path
        void reset(); // used for resetting the path

        //void onestring(string string1); //check one string
        //void twostring(string string2, string string3); // check two strings
  
        int finder(string& min); // find the quickest path
        int fastest(string starttag); //find the fastest path
        void make(string endtag, vector<string>& path); //make the path
        public:
        Graph() {} //constructor
        void addEdge(string label1, string label2, unsigned long weight); // used for adding edges 
        void removeEdge(string label1, string label2); // used for removing edges
        void addVertex(string label); // used for adding vertexes
        void removeVertex(string label); // used for removing vertexes
        unsigned long shortestPath(string startLabel, string endLabel, vector<string> &path); // used for searching for the shortest path
        ~Graph(); }; //destructor
        
