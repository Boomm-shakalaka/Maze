//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Maze_Unit1.h"
#include "stdio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define possible_direction 8
#define max(x,y) (x)>(y)?(x):(y);
int maze[20][20];
int mark[20][20];
int m,p,top;
struct position *Stack;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
struct offset
{
	int dx,dy;
};
enum directions {N,NE,E,SE,S,SW,W,NW};
struct offset move[possible_direction];
struct position
{
	int x,y;
	directions dir;
};
struct position pop()
{
	if(top==-1)
    {
				Form1->Memo1->Lines->Add("堆疊已經沒有東西了");
				return Stack[0];
	}
	return Stack[top--];
}
void seekMazeGrid2()               //動畫演示，@表示路徑
{
	Form1->StringGrid2->RowCount = m;
	Form1->StringGrid2->ColCount = p;
	for(int i=0;i<top;i++)
	{
		if(mark[Stack[i].x][Stack[i].y]==3)
			Form1->StringGrid2->Cells[Stack[i].y][Stack[i].x] ="＠";
		Form1->StringGrid2->Refresh();
		Sleep(50);
	}
	Form1->StringGrid2->Cells[p-1][m-2] ="＠";
	Form1->StringGrid2->Refresh();



}
void setDirection()
{
		move[N].dx=-1;move[N].dy=0;
		move[NE].dx=-1;move[NE].dy=1;
		move[E].dx=0;move[E].dy=1;
		move[SE].dx=1;move[SE].dy=1;
		move[S].dx=1;move[S].dy=0;
		move[SW].dx=1;move[SW].dy=-1;
		move[W].dx=0;move[W].dy=-1;
		move[NW].dx=-1;move[NW].dy=-1;
}
void setMark()
{
        for(int i=0;i<m;i++)
        {
				for(int j=0;j<p;j++)
                {
						mark[i][j]=maze[i][j];
                }
        }
}
void printMark()                                //用“3”表示路徑，更新迷宮
{
	mark[1][0]=3;
	mark[m-2][p-1]=3;
	for(int i=0;i<=top;i++)
	{
		mark[Stack[i].x][Stack[i].y]=3;
	}
	for(int i=0;i<m;i++)
	{
		AnsiString out="";
		for(int j=0;j<p;j++)
		{
			out+=IntToStr(mark[i][j]) + " ";

		}
		Form1->Memo1->Lines->Add(out);
	}
}
void generateMaze(int x,int y)                           //隨機產生迷宮
{
     maze[x][y]=0;
		while(maze[x+2][y]==1 || maze[x-2][y]==1 ||
              maze[x][y+2]==1 || maze[x][y-2]==1)
        {
                int dir=rand()%4+1;
                if(dir==1 && maze[x+2][y]==1)
                {
						maze[x+1][y]=0;
                        generateMaze(x+2,y);
                }
                else if(dir==2 && maze[x-2][y]==1)
                {
                        maze[x-1][y]=0;
                        generateMaze(x-2,y);
                }
                else if(dir==3 && maze[x][y+2]==1)
                {
                        maze[x][y+1]=0;
                        generateMaze(x,y+2);
                }
                else if(dir==4 && maze[x][y-2]==1)
                {
                        maze[x][y-1]=0;
                        generateMaze(x,y-2);
                }
		}
}

void randMaze()                       //隨機產生迷宮
{
		m=StrToInt(Form1->Edit1->Text)+2;
		p=StrToInt(Form1->Edit2->Text)+2;
		for (int i=0;i<m+2;i++)
        {
				for (int j=0;j<p+2;j++)
                {
						if (i==0 || j==0 || i==m || j==p ||
							i==1 || j==1 || i==m+1 || j==p+1)
						{
                                maze[i][j]=2;
                        }
                        else
                        {
                                maze[i][j] = 1;
                        }
                }
        }
		generateMaze(m-1,p-1);
		for(int i=0;i<m;i++)
        {
				for(int j=0;j<p;j++)
                {
                        maze[i][j]=maze[i+1][j+1];
                }
        }
        maze[1][0]=0;//start
        maze[1][1]=0;
        int r1=rand()%2+1;
        int r2;
		if(r1==1)
			r2=2;
		else
			r2=1;
        maze[r1][r2]=0;
		maze[m-2][p-1]=0;//end
		setMark();
}
void printStringGrid1()               //印出迷宮
{
	Form1->StringGrid1->RowCount = m;
	Form1->StringGrid1->ColCount = p;
	int grid_size =Form1-> Edit3->Text.ToInt();
	Form1->StringGrid1->DefaultDrawing = false;
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<p; j++)
		{
			Form1->StringGrid1->Cells[j][i] = mark[i][j];
		}
	}
	for (int i=0; i<m; i++)
		Form1->StringGrid1->RowHeights[i] = grid_size;
	for (int i=0; i<p; i++)
		Form1->StringGrid1->ColWidths[i] = grid_size;
	Form1->StringGrid1->Refresh();

}
void printStringGrid2()                //印出動畫迷宮
{
	Form1->StringGrid2->RowCount = m;
	Form1->StringGrid2->ColCount = p;
	int grid_size =Form1-> Edit3->Text.ToInt();
	Form1->StringGrid2->DefaultDrawing = false;
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<p; j++)
		{
			Form1->StringGrid2->Cells[j][i] = maze[i][j];
		}
	}
	for (int i=0; i<m; i++)
		Form1->StringGrid2->RowHeights[i] = grid_size;
	for (int i=0; i<p; i++)
		Form1->StringGrid2->ColWidths[i] = grid_size;

}
void printMemo()                               //在memo1印出數字迷宮
{
	AnsiString out;
	Form1->Memo1->Lines->Add("m="+IntToStr(m-2));
	Form1->Memo1->Lines->Add("n="+IntToStr(p-2));
	Form1->Memo1->Lines->Add("-------Map("+IntToStr(m-2)+" * "+IntToStr(p-2)+")------");
    for(int i=0;i<m;i++)
	{
		String out="";
		for(int j=0;j<p;j++)
		{
			out+=IntToStr(maze[i][j]) + " ";

		}
		Form1->Memo1->Lines->Add(out);
	}
}
void readFile()                                      //readfile
{
     FILE *fp;
	 AnsiString fname;
	 int  i, j;
	 if(Form1->OpenDialog1->Execute())
	 {
		fname =Form1-> OpenDialog1->FileName;
		fp = fopen(fname.c_str(), "r+");//c_str函数的傳回值是 const char *, 即把string轉成const char *
		fscanf(fp, "%d %d", &m, &p);    // Reda in two integers m & n
		m=m+2;
		p=p+2;
		for (i=1; i<m-1; i++)      // Reda in m*n 0/1's into maze[][]
			for (j=1; j<p-1; j++)
				fscanf(fp, "%d", &maze[i][j]);
		for (i=0; i<m; i++)      // Print out maze[][] in Memo1
		{
			for (j=0; j<p; j++)
			{
				if(i==0 || j==0 || j==p-1 || i== m-1)
					maze[i][j]=2;
			}
		}
        maze[1][0]=0;//start
		maze[1][1]=0;//start
		maze[m-2][p-1]=0;//end
		setMark();
		fclose(fp);

	 }
	 else Form1-> Memo1->Lines->Add("Nothing happens.");
}
 void push(struct position data)
{
	if(top==10000)
		Form1->Memo1->Lines->Add("超過堆疊最大值");
	else
		Stack[++top]=data;
}
void printStack()
{
    String s="";
	for(int i=0;i<=top-2;i++)
	{
		position step=Stack[i];
		String d[8]={"N","NE","E","SE","S","SW","W","NW"};
		s+="("+IntToStr(step.x)+","+IntToStr(step.y)+","+ step.dir +")->";
	}
	Form1->Memo1->Lines->Add(s);
}
int path()
{
	Stack =new struct position [m*p];
	struct position step;
	int i,j,u,v,ex;
	directions d;
	top=-1;
	step.x=1;
	step.y=0;
	maze[1][0]=3;
	step.dir=N;
	push(step);
	while(top>-1)
	{
		step=pop();
		i=step.x;
		j=step.y;
		d=step.dir;
		while(d<=NW)
		{
			u=i+move[d].dx;
			v=j+move[d].dy;
			if((u==m-1)&& (v==p-1))
			{
				maze[u][v]=3;
				push(step);
				i=u;
				j=v;
				d=N;
				push(step);
				return 1;
			}
			else if(maze[u][v]==0)
			{
				maze[u][v]=3;
				step.x=i;
				step.y=j;
				step.dir=directions(d+1);
				push(step);
				i=u;
				j=v;
				d=N;
			}
			else
				d=directions(d+1);

		}
	}

	return
		Form1->Memo1->Lines->Add("此迷宮無解");
}


void __fastcall TForm1::Button3Click(TObject *Sender)   //讀檔按鈕
{
	 Form1->Memo1->Clear();
	 //struct position *Stack;
	 delete  Stack;
	 readFile();
	 setDirection();
	 printMemo();
	 printStringGrid1();
	 printStringGrid2();

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)//尋找路徑按鈕
{
		if(path()==1)
		{
				Memo1->Lines->Add("-----------------------");
				Memo1->Lines->Add("找到出口了!");
				printStack();
		}
		else
        {
				Memo1->Lines->Add("-----------------------");
                Memo1->Lines->Add("沒有出口...");
				printStack();
		}
		printMark();
		printStringGrid1();
		seekMazeGrid2();
		delete  Stack;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)    //存檔按鈕
{
		if(SaveDialog1->Execute())
		{
				FILE *fp;
				AnsiString name;
				name=Form1->SaveDialog1->FileName+".txt";
				fp = fopen(name.c_str(),"w");
				fprintf(fp,"%d %d\n",m-2,p-2);
				for(int i=1;i<m-1;i++)
				{
						for(int j=1;j<p-1;j++)
                        {
                                if(maze[i][j]==3)
								{
                                        int tmp=0;
                                        fprintf(fp,"%d ",tmp);
                                }
                                else
                                {
                                        fprintf(fp,"%d ",maze[i][j]);
                                }
                        }
                         fprintf(fp,"\n");
                }
                fclose(fp);
        }
		else  Memo1->Lines->Add("存檔失敗");
}
//---------------------------------------------------------------------------




void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{     AnsiString text = StringGrid1->Cells[ACol][ARow];
	  if (text == "0")
			StringGrid1->Canvas->Brush->Color = TColor RGB(240, 255, 240);
	  else if(text=="3")
			StringGrid1->Canvas->Brush->Color = TColor RGB(139, 26, 26);
	  else if(text=="1")
			StringGrid1->Canvas->Brush->Color = TColor  (RGB(139, 119, 101));
	  else if(text=="2")
			StringGrid1->Canvas->Brush->Color = TColor  (RGB(139, 90, 0));
	  StringGrid1->Canvas->FillRect(Rect);
	  if(CheckBox1->Checked)
	  StringGrid1->Canvas->TextRect(Rect, Rect.Left+6, Rect.Top+8, text);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) //隨機迷宮按鈕
{
	srand(time(NULL));
	Form1->Memo1->Clear();
	setDirection();
	randMaze();
	printMemo();
	printStringGrid1();
	printStringGrid2();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	 AnsiString text = StringGrid2->Cells[ACol][ARow];
	 if (text == "0")
		StringGrid2->Canvas->Brush->Color = TColor RGB(240, 255, 240);
	 else if(text=="1")
		StringGrid2->Canvas->Brush->Color = TColor  (RGB(139, 119, 101));
	 else if(text=="2")
		StringGrid2->Canvas->Brush->Color = TColor  (RGB(0, 0, 0));
	 else if(text =="＠") {
		StringGrid2->Canvas->Brush->Color = TColor(RGB(255,0,0));
	  }
	 else
		StringGrid2->Canvas->Brush->Color = TColor RGB(240, 255, 240);
	 StringGrid2->Canvas->FillRect(Rect);
	 if(CheckBox1->Checked)
		StringGrid2->Canvas->TextRect(Rect, Rect.Left+6, Rect.Top+8, text);


}
//---------------------------------------------------------------------------


