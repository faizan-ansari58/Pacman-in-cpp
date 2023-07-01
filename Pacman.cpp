#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
char arr[15][50];
int score = 0;
int life = 3;
int px=2,py=5;
int g1x=8,g1y=24;
int g2x=8,g2y=26;
void gameStructure()
{
	int i,j;
	//creating the structure
	for(i=0; i<15 ; i++)
	{
		for(j=0; j<50 ; j++)
		{
			
			//top and bottom line
			if(i==0 || i==14)
			{
				arr[i][j]='#';
			}
			//right and left
			else if (j==0 || j==49)
			{
				arr[i][j]='#';
			}
			//hurdle line on 3rd line
			else if(i==3  && j>10 && j<40)
			{
				arr[i][j]='#';
			}
			//hurdle line on 5th line
			else if(i==5  && j>20 && j<30)
			{
				arr[i][j]='#';
			}
			//hurdle line on 12th line
			else if(i==12  && j>10 && j<40)
			{
				arr[i][j]='#';
			}
			else if(j==8  && i>=5 && i<=10)
			{
				arr[i][j]='#';
			}
			else if(j==42  && i>=5 && i<=10)
			{
				arr[i][j]='#';
			}
			//creating box for ghosts
			else if (i == 7 && j > 20 && j < 30)
			{
			    if (j >= 24 && j <= 26)
			    {
			        arr[i][j] = ' ';
			    }
			    else
			    {
			        arr[i][j] = '#';
			    }
			}
			else if(i==8  && j>20 && j<30)
			{
				if (j >= 22 && j <= 28)
			    {
			        arr[i][j] = ' ';
			    }
			    else
			    {
			        arr[i][j] = '#';
			    }
			}
			else if(i==9  && j>20 && j<30)
			{
			    arr[i][j] = '#';
			}
			else
			{
				arr[i][j]='.';
			}
		}	
	}
}
void packmanControls(char move)
{
	
	
	arr[px][py]='P';
	arr[g1x][g1y]='G';
	arr[g2x][g2y]='G';
	//moving down
		if(move == 's')
		{
			arr[px][py] = ' ';
			px++;
			if(arr[px][py] == '.')
			{
				score++;
			}
			if(arr[px][py] == '#')
			{
				px--;
			}
			arr[px][py] = 'P';
			if(arr[px][py] == arr[g2x][g2y] || arr[px][py] == arr[g1x][g1y])
			{
				px=2,py=5;
				life--;
				arr[px][py]='P';
			}
			
		}
		//moving up
		else if(move == 'w')
		{
			arr[px][py] = ' ';
			px--;
			if(arr[px][py] == '.')
			{
				score++;
			}
			if(arr[px][py] == '#')
			{
				px++;
			}
			
			arr[px][py] = 'P';
			if(arr[px][py] == arr[g2x][g2y] || arr[px][py] == arr[g1x][g1y])
			{
				px=2,py=5;
				life--;
				arr[px][py]='P';
			}
			
		}
		//moving left
		else if(move == 'a')
		{
			arr[px][py] = ' ';
			py--;
			if(arr[px][py] == '.')
			{
				score++;
			}
			if(arr[px][py] == '#')
			{
				py++;
			}
			arr[px][py] = 'P';
			if(arr[px][py] == arr[g2x][g2y] || arr[px][py] == arr[g1x][g1y])
			{
				px=2,py=5;
				life--;
				arr[px][py]='P';
			}
		}
		//moving right
		else if(move == 'd')
		{
			arr[px][py] = ' ';
			py++;
			if(arr[px][py] == '.')
			{
				score++;
			}
			if(arr[px][py] == '#')
			{
				py--;
			}
			arr[px][py] = 'P';
			if(arr[px][py] == arr[g2x][g2y] || arr[px][py] == arr[g1x][g1y])
			{
				px=2,py=5;
				
				life--;
				arr[px][py]='P';
			}
		}
}


void ghostMotion(int random1, int random2)
{
	switch (random1) 
	{
	    case 0:
	        if (arr[g1x + 1][g1y] != '#' && arr[g1x + 1][g1y] != 'G') 
			{
				char temp1x_p = arr[g1x + 1][g1y];
	            arr[g1x][g1y] = temp1x_p;
	            g1x++;
	            arr[g1x][g1y] = 'G';
	        }
	        break;
	    case 1:
	        if (arr[g1x - 1][g1y] != '#' && arr[g1x - 1][g1y] != 'G') 
			{
				char temp1x_m = arr[g1x - 1][g1y];
	            arr[g1x][g1y] = temp1x_m;
	            g1x--;
	            arr[g1x][g1y] = 'G';
	        }
	        break;
	    case 2:
	        if (arr[g1x][g1y + 1] != '#' && arr[g1x][g1y + 1] != 'G') 
			{
				char temp1y_p = arr[g1x][g1y + 1];
	            arr[g1x][g1y] = temp1y_p;
	            g1y++;
	            arr[g1x][g1y] = 'G';
	        }
	        break;
	    case 3:
	        if (arr[g1x][g1y - 1] != '#' && arr[g1x][g1y - 1] != 'G') 
			{
				char temp1y_m = arr[g1x][g1y - 1];
	            arr[g1x][g1y] = temp1y_m;
	            g1y--;
	            arr[g1x][g1y] = 'G';
	        }
	        break;
	    case 4:
	        if (arr[g1x][g1y - 1] != '#' && arr[g1x][g1y - 1] != 'G') 
			{
				char temp1y_m = arr[g1x][g1y - 1];
	            arr[g1x][g1y] = temp1y_m;
	            g1y--;
	            arr[g1x][g1y] = 'G';
	        }
	        break;
	    default:
	        break;
	}
		
	switch (random2) 
	{
	    case 0:
	        if (arr[g2x + 1][g2y] != '#' && arr[g2x + 1][g2y] != 'G') 
			{
				char temp2x_p = arr[g2x + 1][g2y];
	            arr[g2x][g2y] = temp2x_p;
	            g2x++;
	            arr[g2x][g2y] = 'G';
	        }
	        break;
	    case 1:
	        if (arr[g2x - 1][g2y] != '#' && arr[g2x - 1][g2y] != 'G') 
			{
				char temp2x_m = arr[g2x - 1][g2y];
	            arr[g2x][g2y] = temp2x_m;
	            g2x--;
	            arr[g2x][g2y] = 'G';
	        }
	        break;
	    case 2:
	        if (arr[g2x][g2y + 1] != '#' && arr[g2x][g2y + 1] != 'G') 
			{
				char temp2y_p = arr[g2x][g2y + 1];
	            arr[g2x][g2y] = temp2y_p;
	            g2y++;
	            arr[g2x][g2y] = 'G';
	        }
	        break;
	    case 3:
	        if (arr[g2x][g2y + 1] != '#' && arr[g2x][g2y + 1] != 'G') 
			{
				char temp2y_p = arr[g2x][g2y + 1];
	            arr[g2x][g2y] = temp2y_p;
	            g2y++;
	            arr[g2x][g2y] = 'G';
	        }
	        break;
	    case 4:
	        if (arr[g2x][g2y - 1] != '#' && arr[g2x][g2y - 1] != 'G') 
			{
				char temp2y_m = arr[g2x][g2y - 1];
				arr[g2x][g2y] = temp2y_m;
				g2y--;
	            arr[g2x][g2y] = 'G';
	        }
	        break;
	    default:
	        break;
	}

}
void clearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

int main()
{
    gameStructure();
    // Printing the structure
    cout << "Life " << life << "\t\t\t\tScore " << score << '\n';
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    
    // Executing the inputs
    char move;
    cin >> move;
    char preInput = move;
    while (life != 0)
    {
    	int random1 = rand() % 5;
    	int random2 = rand() % 5;	    	

        if (kbhit())
        {
            move = getch();
            preInput = move;
        }
        else
        {
            move = preInput;
        }

        packmanControls(move);
        ghostMotion(random1,random2);
        clearScreen();
        cout << "Life " << life << "\t\t\t\tScore " << score << '\n';
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                cout << arr[i][j];
            }
            cout << '\n';
        }
        Sleep(10);

        if (score == 517)
        {
            break;
            cout << "Congratulations! You Win";
        }
    }
    if (life == 0)
    {
        system("cls");
        cout << "You Lost!";
    }
}

