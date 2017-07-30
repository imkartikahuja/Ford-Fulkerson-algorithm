#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
#include <graphics.h>
#include <ctype.h>
#include <dos.h>

typedef  int  bool;
const     bool true = 1;
const     bool false = 0;

template<class T>
class MyQueue
{
    class T *m_data;
    int m_numElements;

public:
    MyQueue() : m_data(NULL), m_numElements(0) { }
    ~MyQueue()
    {
      free(m_data);
      m_data = NULL;
      m_numElements = 0;
    }

    T front();
    int size()
    {
      return m_numElements;
    }

    bool push(T data);
    bool pop();
    bool Sort();
    bool empty();


};

template<class T>
bool MyQueue<class T>::Sort()
{
      for(int i = 1; i < m_numElements; i++)
      {
	  for(int j = 0; j < m_numElements - i; j++)
	  {
	    if(m_data[j] > m_data[j + 1])
	    {
		T temp = m_data[j];
		m_data[j] = m_data[j + 1];
		m_data[j + 1] = temp;
	    }
	  }
      }
      return true;
}

template<class T>
bool MyQueue<class T>::push(T data)
{
      if(m_data == NULL) // root node
      {
	  m_numElements = 1;
	  m_data = (T*) malloc(sizeof(T));
      }
      else
      {
	  m_numElements++;
	  m_data = (T*) realloc(m_data, m_numElements * sizeof(T));
      }

      m_data[m_numElements - 1] = data;
      return true;
}

template<class T>
bool MyQueue<class T>::pop()
{
      if(m_data == NULL) // root node
      {
	  return false;
	  m_numElements = 0;
      }
      else
      {
	  if(m_numElements == 1)
	  {
	    // last item
	    m_numElements = 0;
	    free(m_data);
	    m_data = NULL;
	  }
	  else
	  {
	    m_numElements--;
	    memmove(m_data, &m_data[1], m_numElements * sizeof(T));
	    m_data = (T*) realloc(m_data, m_numElements * sizeof(T));
	  }
      }
      return true;
}

template<class T>
bool MyQueue<class T>::empty()
{
      if(m_data == NULL) // root node
      {
	  return true;
	//  m_numElements = 0;
      }
      else
      {
	    return false;
      }
}

template<class T>
T MyQueue<class T>::front()
{
      if(m_numElements > 0)
	  return m_data[0];
}

int gdriver=DETECT,gmode=0,errorcode;
char element[3];
int x=1,maxx,midx,xcoord,ycoord;
bool bfs (int rGraph[6][6], int s, int t, int parent[])
{
    bool visited[6];
    memset(visited, 0, sizeof(visited));
    MyQueue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	for (int v = 0; v < 6; v++)
	{
	    if (visited[v] == false && rGraph[u][v] > 0)
	    {
		q.push(v);
		parent[v] = u;
		visited[v] = true;
	    }
	}
    }
    return (visited[t] == true);
}

void dispgraph(int rGraph[6][6],int k,int ans)
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int maxy,maxx,midx,midy,choice;
	maxx=getmaxx();
	maxy=getmaxy();
	int x=maxx/6;
	int y=maxy/4;


    clrscr();
    cleardevice();
    setbkcolor(LIGHTBLUE);
    int i;
	setcolor(LIGHTGREEN);

	//ADD delay
	for(i=5;i<=maxy-25;i=i+7)
	      {	outtextxy(0,i,"*");
		outtextxy(maxx-10,i,"*");
		//delay(10);
	       }
	for(i=5;i<=maxx;i=i+25)
	       {	outtextxy(i,0,">**<");

			outtextxy(i,maxy-28,">**<");
			//delay(100);
	       }
    settextstyle(2,0,5);
    int x0=x-50, y0=2*y, x1=2*x+25, y1=y, x2=2*x+25, y2=3*y, x3=3*x+100, y3=y, x4=3*x+100, y4=3*y, x5=4*x+150, y5=2*y;
    int xcor[6]={x0,x1,x2,x3,x4,x5};
    int ycor[6]={y0,y1,y2,y3,y4,y5};
    setfillstyle(1,BROWN);
    setcolor(LIGHTGREEN);

    for( i=0;i<6;i++)
    {
	circle(xcor[i],ycor[i],10);
    }

    /*circle(x0,y0,10);
    circle(x1,y1,10);
    circle(x2,y2,10);
    circle(x3,y3,10);
    circle(x4,y4,10);
    circle(x5,y5,10);*/

    outtextxy(x0-2,y0 - 7,"0");
    outtextxy(x1-2,y1-7,"1");
    outtextxy(x2-2,y2-7,"2");
    outtextxy(x3-2,y3-7,"3");
    outtextxy(x4-2,y4-7,"4");
    outtextxy(x5-2,y5-7,"5");

    if(k==1)
    {   settextstyle(2,HORIZ_DIR,4);
		setcolor(WHITE);
	outtextxy(100,50,"Default Graph");
    }
    if (k==2)
    {
	settextstyle(2,HORIZ_DIR,4);
		setcolor(WHITE);
		char string[100];
		sprintf(string,"The maximum possible flow is %d",ans);
		outtextxy(100,50,string);
    }

      setfillstyle(1,BROWN);
    setcolor(LIGHTGREEN);
    settextstyle(2,0,5);

    for(i=0;i<6;i++)
    {
	for(int j=0;j<6;j++)
	{
	    if(rGraph[i][j]!=0)
	    {
	    if(i<j)
	    {   setcolor(RED);
		line(xcor[i]-10,ycor[i],xcor[j]-10,ycor[j]);
		int p= (((xcor[i]+xcor[j])/2)-10)-10;
		int q= (((ycor[i]+ycor[j])/2)-30);
		char string[100];
		sprintf(string,"%d",rGraph[i][j]);
		outtextxy(p,q,string);
		//line(xcor[j]-15,ycor[j],xcor[j]-10,ycor[j]-10);
		//line(xcor[j]-15,ycor[j]-18,xcor[j]-10,ycor[j]-10);
	    }

	    else
	    {   setcolor(WHITE);
		line(xcor[i],ycor[i]+10,xcor[j],ycor[j]+10);
		int p= (((xcor[i]+xcor[j])/2)+5);
		int q= (((ycor[i]+ycor[j])/2)+20);
		char string[100];
		sprintf(string,"%d",rGraph[i][j]);
		outtextxy(p,q,string);
		//line(xcor[j]+15,ycor[j],xcor[j]+10,ycor[j]+10);
		//line(xcor[j]+15,ycor[j]+18,xcor[j]+10,ycor[j]+10);

	    }

	    }
	}
    }
    //delay(3000);
    getch();
}

int fordFulkerson(int graph[6][6], int s, int t)
{
    int u, v;
    int rGraph[6][6];
    for (u = 0; u < 6; u++)
    {
	for (v = 0; v < 6; v++)
	{
	    rGraph[u][v] = graph[u][v];
	}
    }
    int parent[6];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    {
	int path_flow = 999999;
	for (v = t; v != s; v = parent[v])
	{
	    u = parent[v];
	    //path_flow = min(path_flow, rGraph[u][v]);
	    if(path_flow > rGraph[u][v])
		path_flow=rGraph[u][v];
	}
	for (v = t; v != s; v = parent[v])
	{
	    u = parent[v];
	    rGraph[u][v] -= path_flow;
	    rGraph[v][u] += path_flow;
	}
	max_flow += path_flow;

	dispgraph(rGraph,0,1);
    }

    /*for(int i=0;i<6;i++)
    {
	for(int j=0;j<6;j++)
	{
	    cout<<rGraph[i][j]<<" ";
	}
	cout<<"\n";
    }*/

    dispgraph(rGraph,2,max_flow);
    return max_flow;
}

void mainmenu()
{
       //	 int gd=DETECT,gm;
       //	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	int maxy,maxx,midx,midy,choice;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	cleardevice();
	int i;
	setcolor(LIGHTGREEN);

	//ADD delay
	for(i=5;i<=maxy-25;i=i+7)
	      {	outtextxy(0,i,"*");
		outtextxy(maxx-10,i,"*");
		//delay(10);
	       }
	for(i=5;i<=maxx;i=i+25)
	       {	outtextxy(i,0,">**<");

			outtextxy(i,maxy-28,">**<");
			//delay(100);
	       }



		setfillstyle(XHATCH_FILL,BLUE);
		floodfill(midx-235,midy,LIGHTGREEN);
		settextstyle(10,HORIZ_DIR,4);
		setcolor(WHITE);
		outtextxy(midx-190,midy-200,"ALGO PROJECT");

		//line(midx-230,midy-75,midx+230,midy-75);
		setcolor(WHITE);
		//rectangle(midx-230,midy-75,midx+230,midy+150);
		//setfillstyle(SOLID_FILL,BLACK);
		//floodfill(midx-220,midy,BLACK);
		settextstyle(0,HORIZ_DIR,2);
		//outtextxy(midx-230,midy-75,"Choose your option!!");
		outtextxy(midx-200,midy-35,"STUDY TIME - NETWORK FLOW!");
		//outtextxy(midx-230,midy,"2) FUN TIME - GAME OF FIFTEEN!");
		//outtextxy(midx-230,midy+30,"Enter your Choice: ");
		//cin>>choice;
		//cleardevice();
		//return choice;
		delay(2000);
		//closegraph();
getch();


}



int main()
{
    clrscr();
    int graph[6][6] = { {0, 16, 13, 0, 0, 0},
			{0, 0, 10, 12, 0, 0},
			{0, 4, 0, 0, 14, 0},
			{0, 0, 9, 0, 0, 20},
			{0, 0, 0, 7, 0, 4},
			{0, 0, 0, 0, 0, 0}
		      };

    int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int maxy,maxx,midx,midy,choice;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;

    clrscr();
    cleardevice();
    mainmenu();
    cleardevice();
    settextstyle(0,0,0);
    int i;
	setcolor(LIGHTGREEN);
	setbkcolor(LIGHTBLUE);
	//ADD delay
	for(i=5;i<=maxy-25;i=i+7)
	      {	outtextxy(0,i,"*");
		outtextxy(maxx-10,i,"*");
		delay(10);
	       }
	for(i=5;i<=maxx;i=i+25)
	       {	outtextxy(i,0,">**<");

			outtextxy(i,maxy-28,">**<");
			delay(100);
	       }

	       dispgraph(graph,1,0);

    fordFulkerson(graph, 0, 5);

    //cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
    getch();
    return 0;
}
