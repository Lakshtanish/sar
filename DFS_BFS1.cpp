#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Graph
{
  int n;
  int** adj_matrix;

  public:
    Graph()
    {
      cout<<"\nEnter number of vertices in the graph : ";
      cin>>n;

      adj_matrix=new int*[n];
      for(int i=0;i<n;i++)
      {
        adj_matrix[i]=new int[n];
        for(int j=0;j<n;j++)
        {
          adj_matrix[i][j]=0;
        }
      }
    }

    void readGraph()
    {
      int u,v;
      cout<<"\nEnter edges or enter -1,-1 to stop : ";
      while(1)
      {
        cin>>u>>v;
        if(u==-1 && v==-1)
        {
          return;
        }
        else if(u==-1 || v==-1)
        {
          cout<<"\nInvalid vertex -1 !! Enter again !";
        }
        else if(u>n-1 || v>n-1)
        {
          cout<<"\nVertex out of range !! Enter again !";
        }
        else
        {
          adj_matrix[u][v]=1;
          adj_matrix[v][u]=1;
        }
      }
    }

    void printGraph()
    {
      for(int i=0;i<n;i++)
      {
        cout<<"\n"<<i<<" : ";
        for(int j=0;j<n;j++)
        {
          if(adj_matrix[i][j]!=0)
          {
            cout<<j<<" , ";
          }
        }
      }
    }

    void DFS_rec(int* visited,int v)
    {
      cout<<"\n"<<v<<" visited";
      visited[v]=1;
      for(int i=0;i<n;i++)
      {
        if(adj_matrix[v][i]!=0 && visited[i]==0)
        {
          DFS_rec(visited,i);
        }
      }
    }

    void DFS_rec_helper()
    {
      int source;
      cout<<"\nEnter the source vertex : ";
      cin>>source;

      int* visited;
      visited=new int[n];
      for(int i=0;i<n;i++)
      {
        visited[i]=0;
      }
      DFS_rec(visited,source);
    }

    void DFS_nonrec(int* visited,int source)
    {
      stack<int> stk;
      stk.push(source);
      while(!stk.empty())
      {
        int v=stk.top();
        stk.pop();
        if(visited[v]==0)
        {
          cout<<"\n"<<v<<" visited";
          visited[v]=1;
          for(int i=0;i<n;i++)
          {
            if(adj_matrix[v][i]!=0 && visited[i]==0)
            {
              stk.push(i);
            }
          }
        }
      }
    }

    void DFS_nonrec_helper()
    {
      int source;
      cout<<"\nEnter the source vertex : ";
      cin>>source;

      int* visited;
      visited=new int[n];
      for(int i=0;i<n;i++)
      {
        visited[i]=0;
      }
      DFS_nonrec(visited,source);
    }

    void BFS_nonrec(int* visited,int source)
    {
      queue<int> que;
      cout<<"\n"<<source<<" visited";
      visited[source]=1;
      que.push(source);
      while(!que.empty())
      {
        int v=que.front();
        que.pop();
        for(int i=0;i<n;i++)
        {
          if(adj_matrix[v][i]!=0 && visited[i]==0)
          {
            cout<<"\n"<<i<<" visited";
            visited[i]=1;
            que.push(i);
          }
        }
      }
    }

    void BFS_nonrec_helper()
    {
      int source;
      cout<<"\nEnter the source vertex : ";
      cin>>source;

      int* visited;
      visited=new int[n];
      for(int i=0;i<n;i++)
      {
        visited[i]=0;
      }
      BFS_nonrec(visited,source);
    }
};

int main()
{
  Graph g;
  g.readGraph();
  g.printGraph();
  g.DFS_rec_helper();
  g.DFS_nonrec_helper();
  g.BFS_nonrec_helper();
  return 0;
}

/*
0 1
0 2
0 3
1 4
3 4
2 4
-1 -1
*/