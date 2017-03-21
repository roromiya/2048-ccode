#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int board[4][4]={0};
void draw(void);
void new_num(void);
void check_game_over(void);

int main()
{
    int i, j, r;
    int key;
    int act;
    
    new_num(); 
    new_num(); 
    draw(); 
    
    while(1){ 
        key=getch(); //키입력을 받음 
        if(key==0xE0||key==0){ //방향키의 경우 키입력시 0xE0+키값이 두개 전달됨 
        key=getch(); // 처음 0xE0은 버리고 두번째 키 값만을 판별 
        switch(key){
            case LEFT:
            for(i=0,act=0;i<4;i++)
			{ 
                for(j=1;j<=3;j++)
				{ 
                    for(r=j;r>0;r--)
					{ 
                        if(board[i][r]==0||board[i][r]>10000) 
							break; 
                        if(board[i][r-1]!=0&&board[i][r-1]!=board[i][r]) 
							break;                                                          
                        if(board[i][r-1]==0) 
							board[i][r-1]=board[i][r]; 
                        else if(board[i][r] == board[i][r-1])
						{ 
                            board[i][r-1]*=2; 
                            board[i][r-1]+=10000;
                        }
                        board[i][r]=0;   
                        act++;
                    }
                }
            }
            break;
            
            case RIGHT: 
            for(i=0,act=0;i<4;i++)
			{ 
                for(j=2;j>=0;j--)
				{ 
                    for(r=j;r<3;r++)
					{
                        if(board[i][r]==0||board[i][r]>10000) 
							break;
                        if(board[i][r+1]!=0&&board[i][r+1]!=board[i][r]) 
							break;
                        if(board[i][r+1]==0) 
							board[i][r+1]=board[i][r];
                        else if(board[i][r]==board[i][r+1])
						{
                            board[i][r+1]*=2;
                            board[i][r+1]+=10000;
                        }
                        board[i][r]=0;                            
                        act++;
                    }
                }
            }
            break;
            
            case UP:
            for(j=0,act=0;j<4;j++)
			{
                for(i=1;i<=3;i++)
				{
                    for(r=i;r>0;r--)
					{
                        if(board[r][j]==0||board[r][j]>10000) 
							break;
                        if(board[r-1][j]!=0&&board[r-1][j]!=board[r][j]) 
							break;
                        if(board[r-1][j]==0) 
							board[r-1][j]=board[r][j];
                        else if(board[r][j]==board[r-1][j])
						{
                            board[r-1][j]*=2;
                            board[r-1][j]+=10000;
                        }
                        board[r][j]=0;
                        act++;
                    }
                }
            }
            break;
            case DOWN: 
            
            for(j=0,act=0;j<4;j++)
			{
                for(i=2;i>=0;i--)
				{ 
                    for(r=i;r<3;r++)
					{
                        if(board[r][j]==0||board[r][j]>10000) 
							break;
                        if(board[r+1][j]!=0&&board[r+1][j]!=board[r][j]) 
							break;
                        if(board[r+1][j]==0) 
							board[r+1][j]=board[r][j];
                        else if(board[r][j] == board[r+1][j])
						{
                            board[r+1][j]*=2;
                            board[r+1][j]+=10000;
                        }
                        board[r][j]=0;
                        act++;
                    }
                }
            }
            break;
        }
    }

    for(i=0;i<4;i++)
	{
        for(j=0;j<4;j++)
		{
            if(board[i][j]>10000)
            	board[i][j]-=10000;
        }
    }
    if(act>0)
	{ 
        new_num(); 
        draw(); 
        check_game_over(); 
    }
}
}

void draw(void)
{
    int i,j;
    system("cls");

    for(i=0;i<4;i++)
	{
        for(j=0;j<4;j++){
            if(board[i][j]==0) 
				printf("    -");
            else 
				printf("%5d", board[i][j]);
        }
        printf("\n");    
    }
    printf("\n");
}

void new_num(void)
{
    int i, j;
    int cnt;
    int* p0[16]={0};

    for(i=0, cnt=0;i<4;i++)
	{
        for(j=0;j<4;j++)
            if(board[i][j] == 0)
			{
                p0[cnt]=&board[i][j];
                cnt++;
            }
    }
    *p0[rand()%(cnt)]=(rand()%100<80)?2:4;
}

 

void check_game_over(void)
{
    int i,j;

    for(i=0;i<4;i++) 
		for(j=0;j<4;j++) 
			if(board[i][j]==0) 
				return;
    for(i=0;i<3;i++) 
		for(j=0;j<3;j++) 
			if(board[i][j]==board[i+1][j]||board[i][j]==board[i][j+1]) 
				return;
				
    printf("Game Over..");
    exit(0);
}
