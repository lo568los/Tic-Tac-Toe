/*this is the beginning of a new program. We'll try to make tic tac toe using cpp*/
/* we'll give options for board size from 3 to 15 and give marker len size from 3 to 5*/

#include <iostream>
#include <cstdlib>
using namespace std;
class player{
    public:
        string name;
        char symbol;
        //int movearr[225][2];
        

};
//printing out board after every move
void makeboard(int n, char **board){
   /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            cout << board[i][j] << endl;
        }
    }*/
       
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='-'){
            cout << "-" << " |";
            }
            else{
                cout << board[i][j] <<" |";

            }
            
        }
    cout << endl;
    }
}   
int makechange(int n,char **board,char symbol,int i,int j){ //for making change to the board after one move
     if(i>=0 && i<n && j>=0 && j<n){
         if(board[i][j]!='-'){
             return 0;
         }
         else{
             board[i][j]=symbol;
             return 1;
         }

     }
     else{
         return 0;
     }
}
int checkposition(int n, char **board,char symbol,int markersize){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==symbol){ //checking left and right diagonal, down and right straight
                  
                      //right diagonal check
                      //cout<< "program in right diagonal" << endl;
                      for(int k=1;k<=markersize;k++){
                          if(i+markersize<n && j+markersize<n){
                          if(board[i+k][j+k]!=symbol){
                              c=1;
                              break;
                          }
                      } 
                      else{
                          c=1;
                          break;
                      } 
                      }  
                      if(c==0){
                          return 1;
                      }
                      c=0;    
                                            

                  
                  
                  
                  //cout << "program in left diagonal" << endl;
                     for(int k=1;k<=markersize;k++){
                         if(i-markersize>=0 && j+markersize<n){
                          if(board[i-k][j+k]!=symbol){
                              c=1;
                              break;
                          }
                         }else{c=1;
                         break;}
                      }    
                      if(c==0){
                          return 1;
                      }
                      c=0;     
                  
                 
                  //down straight
                     //cout << "Program in down straight" << endl;
                     for(int k=1;k<=markersize;k++){
                         if(i+markersize<n){
                          if(board[i+k][j]!=symbol){
                              c=1;
                              break;
                          }
                         }else{c=1;
                         break;}
                      }    
                      if(c==0){
                          return 1;
                      }
                      c=0;      
                  
                  
                 
                      //cout << "program in right straight" << endl;
                      for(int k=1;k<=markersize;k++){ //right straight
                          if(j+markersize<n){
                          if(board[i][j+k]!=symbol){
                              c=1;
                              break;
                          }
                          }else{c=1;
                          break;}
                      }    
                      if(c==0){
                          return 1;
                      }
                      c=0;     
                  
            }

        }
    }
    return 0;
}


int main(){
    //firstly we'll take in name of both the players and declare boardsize
    player p1;
    player p2;
    int boardsize,markersize;
    
    cout << "Enter name for Player 1" << endl;
    cin >> p1.name;
    cout << "Hello " << p1.name << ",what is your symbol" << endl;
    cin >> p1.symbol;
    cout << "Enter name for Player 2" << endl;
    cin >> p2.name;
    do{
    cout << "Hello " << p2.name << ",what is your symbol" << endl;
    cin >> p2.symbol;}while(p1.symbol==p2.symbol);

    do{ // fixing boardsize
    cout << "How large do you want the board length to be for n by n board (pick between 3 and 15)" << endl;
    cin >> boardsize;
    }while(boardsize<3 || boardsize>15);
    
    do{ //fixing markersize
    cout << "How big due you want the winning position length to be (pick a number between 3 and 5)" << endl;
    cin >> markersize;
    }while(markersize<3 || markersize>5 || markersize>boardsize);
    char **board = new char *[boardsize]; //declaring board
    for (int i=0;i<boardsize;i++){
        board[i]= new char[boardsize];
        for(int j=0;j<boardsize;j++){
            board[i][j]='-';
        }
       
    }
    
    makeboard(boardsize,board);
    int game=0,p1_x,p1_y,p2_x,p2_y,c,d;
    while(game==0){
    
        
        cout << p1.name <<", make your move!(enter space separated x and y coordinates. Top left cell is (0,0))" << endl;
        cin >> p1_x >> p1_y;
        c=makechange(boardsize,board,p1.symbol,p1_x,p1_y);
        //cout << "c:" << c << endl;
        while(c==0){
            cout << "Invalid move,please try again" << endl;
            cin >> p1_x >> p1_y;
            c=makechange(boardsize,board,p1.symbol,p1_x,p1_y);
        }
        makeboard(boardsize,board);
        //calculation of winning position
        if(checkposition(boardsize,board,p1.symbol,markersize-1)){
            cout << p1.name <<" has won!!";
            break;
        }

        
        cout << p2.name <<", make your move!(enter space separated x and y coordinates. Top left cell is (0,0))" << endl;
        cin >> p2_x >> p2_y;
        d=makechange(boardsize,board,p2.symbol,p2_x,p2_y);
        while(d==0){
            cout << "Invalid move, please try again" << endl;
            cin >> p2_x >> p2_y;
    
            d=makechange(boardsize,board,p2.symbol,p2_x,p2_y);
        }
        makeboard(boardsize,board);
        if(checkposition(boardsize,board,p2.symbol,markersize-1)){
            cout << p2.name <<" has won!!";
            break;
        }
        
    
    }
}