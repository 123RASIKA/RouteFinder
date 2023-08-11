#include <bits/stdc++.h>
using namespace std;
//--------------------------//



class Graph
{
	//used for adjacency list
	unordered_map<string,vector<pair<string,int>>> g;
	//for storing price
	int p=0;
	public:
    void addEdge(string start,string end,int wt);
    int ShortestPath(string dep,string des);
    void Display();
    int Price();
};

//adding edges in the graph
void Graph::addEdge(string start,string end,int wt)
{   
	g[start].push_back({end,wt});
	
	g[end].push_back({start,wt});
}

//calculating the shortest path
int Graph::ShortestPath(string dep,string des)
{
		string s=dep;
		
		unordered_map<string,int> dist;
		
		for(auto x:g)
		dist[x.first]=INT_MAX;
		
		unordered_map<string,bool> processed;
		
		for(auto x:g)
		processed[x.first]=false;
		
		dist[s]=0;
		
		priority_queue<pair<int,string> > q;
		
		q.push({0,s});
		
		while(!q.empty())
		{
			
			string a=q.top().second;
			
			q.pop();
			
			if(processed[a])
			continue;
			
			processed[a]=true;
			
			for(auto u:g[a])
			{
				string b=u.first;
				int w=u.second;
				
				if(dist[a]+w<dist[b])
				{
					dist[b]=dist[a]+w;
					q.push({-1*dist[b],b}); //multiply by -1 because default priorty queue finds max distance 
					
				}
			}
			
		}
		
		return p=dist[des];
}

void Graph::Display()
{
	for(auto x:g)
	cout<<x.first<<'\n';
}

int Graph::Price()
{
	return p*1000;
}

int main() 
{
	
	Graph g;
	
	cout<<"Input Format:"<<'\n';
	cout<<"City1  City2  Distance between 2 cities: "<<'\n'<<'\n';
	
	cout<<"Enter 0 to finish"<<'\n'<<'\n';
	
	
	string a,b;
	int w;
	
	while(true)
	{
		cin>>a;
		if(a=="0")
		break;
		cin>>b>>w;	
		g.addEdge(a,b,w);
	}
	
	int ch=1;
	do
	{	
	cout<<"\nList of all cities:"<<'\n';
	g.Display();
	
	cout<<"\nEnter Departure City: ";
	string dep;
	
	cin>>dep;
	cout<<'\n';
	
	cout<<"Enter Destination City: ";
	string des;
	
	cin>>des;
	
	cout<<"\nMinimum distance between "<<dep<<" and "<<des<<" :";
	cout<<g.ShortestPath(dep,des)<<'\n';
	
	cout<<"\nCost of travelling : "<<g.Price()<<'\n';
	
	cout<<"\nEnter 1 to for another query and 0 to exit : ";
	
	cin>>ch;	
	}
	while(ch==1);

	/*
		input-
		pune delhi 6
		delhi goa 2
		pune indore 2
		indore mumbai 5
		mumbai delhi 4
		mumbai blr 2
		blr goa 9
		0				
	*/
}
