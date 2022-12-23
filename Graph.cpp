

//Adam Bricha (U9233-5585)
//Alyssa Brown (U27307759)
//Mahmood Sales (U81752306)
//Shahad Al-Harrasi (U410606760)

#include "Graph.hpp"
#include <limits>

using namespace std;



void Graph::make(string endtag, vector<string>& path){   // order the vector and create it 
  deque<Class_of_vertex*>::iterator i = Deq_vert.begin(); 
  while (i != Deq_vert.end()){ 
        // searching for end
        if( endtag == ( *i )->str_vertex ) { 
                quick = ( *i )->fastestpath; //update quick
                ( *i )->quickest.push_back(endtag); // treversing to find min distance
                path = ( *i )->quickest; } //store in path
                ++i; }
        }


void Graph::beginner(string starttag){

  deque<Class_of_vertex*>::  iterator i=Deq_vert.begin();
  while( i != Deq_vert.end()) { // loop to iterate in vertex deque until the end
        if (( *i )->str_vertex == starttag) {
        ( *i )->fastestpath = 0;
        ( *i )->quickest.clear();
        ( *i )->quickest.push_back(starttag); } // add the given string in the quickest edges path vertors
         ++i; }  PathList.push(make_pair( 0 , starttag ) );
          }


void Graph::reset(){ // reset the vertexs
  deque<Class_of_vertex*>::iterator i = Deq_vert.begin();
  while ( i != Deq_vert.end()){ // loop to iterate in vertex deque until the end
        (*i)->fastestpath = numeric_limits<unsigned long>::max();;
        (*i)->quickest={""};
        (*i)->visit=false; ++i; }
}

void Graph::addVertex(string tag){

  //onestring(tag);// to check if the given string is empty or not
  Class_of_vertex *verNew =new Class_of_vertex;//create new vertex 
  verNew->str_vertex= tag;
  verNew->fastestpath = numeric_limits<unsigned long>::max();
  verNew->quickest = {""}; //setting vector
  verNew->visit = false;
  Deq_vert.push_back(verNew); //insert element at end of vector

}

void Graph::removeVertex(string tag){

  //onestring(tag);
  deque<Class_of_Edge*>::iterator k=Deq_edges.begin();
  while( k!=Deq_edges.end()){ //searching for the end of edge deque
        if (((*k ) -> A == tag) || ((*k)->B == tag)) {
        Deq_edges.erase(k); }   //remove the edges
        ++k; }

  deque< Class_of_vertex* > :: iterator i=Deq_vert.begin(); 
  while(i != Deq_vert.end()){  //searching for the end of vertexes deque       
  if ((*i)->str_vertex== tag) { Deq_vert.erase(i);}   //remove the vertex
        ++i; }

       
}

void Graph::addEdge(string tag1, string tag2, unsigned long EdgeWeight) //adding edge for the tags
{
  //create new edges 
  Class_of_Edge *New1_ed= new Class_of_Edge( tag1 , tag2 , EdgeWeight ); // adding an edge between the two tags 
  Class_of_Edge* New2_ed = new Class_of_Edge( tag2 , tag1 , EdgeWeight );
  // insert the edges in the deque
  Deq_edges.push_back(New1_ed); Deq_edges.push_back(New2_ed);

}

void Graph::removeEdge(string tag1, string tag2){

  deque<Class_of_Edge*>::iterator k = Deq_edges.begin();
  while( k != Deq_edges.end())      //while not at the end of the edge
        {
        if (((*k)->A == tag1) && ((*k)->B == tag2)) { 
        Deq_edges.erase(k);} // when found , erase k
        ++k; }
}


unsigned long Graph::shortestPath(string starttag, string endtag, vector<string>& path) // finds the fastest distance between the two tags
{
  beginner(starttag);
  builder(starttag);
  make(endtag, path);
  reset();
  return quick;  //returns the quickest path
}


int Graph::finder(string& min) //find the minimum element in the vertex
{

  int j= 0;
  deque<Class_of_vertex*>::iterator i = Deq_vert.begin(); 
  while (i != Deq_vert.end()) {
        if (( *i )->str_vertex == min) {
         index_minVer = j; //update with index of min
                }
        else{ ++j; }
         ++i; }

 return 0;


}


int Graph::fastest(string starttag){


  deque<Class_of_Edge*>::iterator k = Deq_edges.begin(); //start at the begining of the deque


        while( k != Deq_edges.end()) {        //while not at the end of the deque
        if ((*k)->A == smallestElem) {    

        deque<Class_of_vertex*>::iterator i = Deq_vert.begin(); 
        while(i != Deq_vert.end()) {       
         if (((*k)->B == (*i)->str_vertex) && ((Deq_vert.at(index_minVer)->fastestpath + (*k)->EdgeWeight) < (*i)->fastestpath) && ((*i)->visit == false))  //has not been visited yet
         {       
         (*i)->fastestpath = Deq_vert.at(index_minVer)->fastestpath + (*k)->EdgeWeight;

        if (smallestElem != starttag) { (*i)->quickest.clear(); (*i)->quickest = Deq_vert.at(index_minVer)->quickest;(*i)->quickest.push_back(Deq_vert.at(index_minVer)->str_vertex);                      
        }
       
        else{(*i)->quickest.clear();(*i)->quickest.push_back(starttag); //insert element at the end of the vector    
        }

        PathList.push(make_pair((*i)->fastestpath, (*i)->str_vertex));}
                         
        ++i;  //increment
                        }
                        }
              
         ++k;   //increment
  
        }

        return 0;
}

void Graph::builder(string starttag){ //make the new path
        while(!PathList.empty()){
                smallestElem = PathList.top().second;
                PathList.pop();      //remove elem
                finder(smallestElem);  //find the smallest element 
                fastest(starttag); 
                Deq_vert.at(index_minVer)->visit = true;}
}

//destructor
Graph::~Graph(){ Deq_vert.clear(); Deq_edges.clear(); }
  //clear edges from the deque //clear verticies from the deque