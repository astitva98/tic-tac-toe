#include<iostream>
#include<fstream>
#include<string>
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
		cout<<"Welcome to Tic-Tac-Toe\n\nPress 1 for new game\nPress 2 for stats\nPress 3 to reset stats\nPress 4 to quit\n\n";
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
				fstream fio;
				fio.open("../data/stats.txt");
				string line1;
				string line2;
				getline(fio,line1);
				getline(fio,line2);				
				int t=stoi(line1);
				t++;
				line1=to_string(t);
				fio.seekg(0,ios::beg);
				fio<<line1<<endl;
				fio<<line2<<endl;
				fio.close();
				//write to file
			}
			if(win==2){
				cout<<"Player 2 wins\n\n!!";
				fstream fio;
				fio.open("../data/stats.txt");
				string line1;
				string line2;
				getline(fio,line1);
				getline(fio,line2);
				//cout<<"TEST"<<line2<<endl<<endl;				
				int t=stoi(line2);
				t++;
				line2=to_string(t);
				fio.seekg(0,ios::beg);
				fio<<line1<<endl;
				fio<<line2<<endl;
				fio.close();
				//write to file
	
			}
			cout<<"Play again? (y/n)";
		cin>>play;
		if(!(play=='y'||play=='n')){
					cout<<"\nWrong input\n\n";
					return 0;
				}
		}

		if(choice==2){
			ifstream fin;
			fin.open("../data/stats.txt");
			if(!fin){
				ofstream fop;
				fop.open("../data/stats.txt");
				fop<<'0'<<endl;
				fop<<'0'<<endl;
				fop.close();
				fin.open("../data/stats.txt");
			}
			string line1;
			string line2;
			
			getline(fin,line1);
			getline(fin,line2);
			cout<<"Player 1 has won "<<line1 <<" games\nPlayer 2 has won "<<line2<<" games\n\n";
			

			fin.close();
			//show stats
			cout<<"--------------------------\n\n";

		}
		if(choice==3){
			ofstream fop;
			fop.open("../data/stats.txt");
			fop<<'0'<<endl;
			fop<<'0'<<endl;
			fop.close();
			cout<<"\n\n------------------------\nStats have been reset!\n------------------------\n\n";
		}
		if(choice==4){
			play='n';
		}


	}

}