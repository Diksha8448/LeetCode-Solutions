/*
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.

*/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int l = 0 , m = 0,i = 0,j = 0;
        int count=0;
        for(int i = 0;i<board.size();i++){
            bool flag=false;
           for(int j = 0;j<board[i].size();j++){
                if(board[i][j]=='R'){
                    l=i;
                    m=j;
                    flag=true;
                    break;
            }
               
           }
           
            if(flag==true){
                break;
            }
        }
        cout<<l<<" "<<m;
        
        i = l;
        j = m;
        
       int c = 0;
       for (int k = i; k < 8;k++){
           bool whitePiece = false;
           if (board[k][j]=='p' && (whitePiece == false)){
               c++;
               break;
           }
           else if (board[k][j]=='B'){
               whitePiece = true;
               break;
           }  
       }
        
        for (int k = i; k >= 0;k--){
            bool whitePiece = false;
           if (board[k][j]=='p'&& (whitePiece == false)){
               c++;
               break;
           }else if (board[k][j]=='B'){
               break;
           }  
       }
        
        for (int k = j; k < 8;k++){
            bool whitePiece = false;
           if (board[i][k]=='p'&& (whitePiece == false)){
               c++;
               break;
           }else if (board[i][k]=='B'){
               break;
           }  
       }
        
        for (int k = j; k >= 0;k--){
            bool whitePiece = false;
           if (board[i][k]=='p' && (whitePiece == false)){
               c++;
               break;
           }else if (board[i][k]=='B'){
               break;
           }  
       }
        return c;
        
    
    }
};