#include<iostream>

using namespace std;

int win2(char* arr){

	//for player 1
	//cout<<3<<endl;
	for(int i=0;i<3;i++){
		if(arr[i]== '0' && arr[i+3]== '0' && arr[i+6]=='0')
			return 1;
		if(arr[i]== '1' && arr[i+3]== '1' && arr[i+6]=='1')
			return 2;
		int y=3*i;
		if(arr[y]=='0' && arr[y+1]== '0' && arr[y+2]=='0')
			return 1;
		if(arr[y]== '1' && arr[y+1]== '1' && arr[y+2]=='1')
			return 2;
	}
	if(arr[0]=='0' && arr[4]== '0' && arr[8]=='0')
		return 1;
	if(arr[2]== '1' && arr[4]== '1' && arr[6]=='1')
		return 2;
	return 0;

}


int drawBoard(char* arr){

//draw the board here
//array is passed with 0 for O, 1 for X, and -1 for no turn 
printf(" %c | %c | %c \n ---------\n %c | %c | %c \n ---------\n %c | %c | %c \n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);
return win2(arr);

}


int main(){

	char play='y';
	while(play=='y')
	{
		cout<<"Welcome to Tic-Tac-Toe\nPress 1 for new game\nPress 2 for stats";
		int choice;
		cin>>choice;
		if(choice==1){
			char arr[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
			int win=drawBoard(arr);
			int move;
			while (!win){
	
				cout<<"Player 1 turn\n\n";
				int ui=1;
				while(ui)
				{
					cin>>move;
					if(arr[move]!=' '){
					cout<<"Wrong move!!!\nTry again\n\n";
									
					}else
					ui=0;
				}
				arr[move]='0';
				win=drawBoard(arr);
				if(win==0){
					cout<<"Player 2 turn\n\n";
					//cin>>move;
					ui=1;
					while(ui)
					{
						cin>>move;
						if(arr[move]!=' '){
						cout<<"Wrong move!!!\nTry again\n\n";
										
						}else
						ui=0;
					}
					arr[move]='1';
					win=drawBoard(arr);
				}
			}
			
			if(win==1){
				cout<<"Player 1 wins\n\n!!";
				//write to file
			}
			if(win==2){
				cout<<"Player 2 wins\n\n!!";
				//write to file
	
			}
			cout<<"Play again? (y/n)";
		cin>>play;
		if(!(play=='y'||play=='n')){
					cout<<"\nWrong input\n";
					return 0;
				}
		}

		if(choice==2){

			//show stats

		}


	}

}