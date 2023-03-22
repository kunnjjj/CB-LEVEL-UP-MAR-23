class Solution {
public:
    int dx[4]={+1,-1,0,0};
    int dy[4]={0,0,+1,-1};


    bool is_safe(int i,int j,vector<vector<bool>> &visited,vector<vector<char>>& board,string &word,int idx)
    {
        // whether i and j are in bounds, 
        // chars are matching
        // new cell is not visited yet
        return (i>=0 && i<(int)board.size()) && 
        (j>=0 && j<(int)board[i].size()) && 
        board[i][j]==word[idx] &&
        visited[i][j]==false;
    }
    
    bool findWord(int i,int j,int idx,vector<vector<bool>>& visited,string& word,vector<vector<char>> &board)
    {
        if(idx==(int)word.size()) return true; // entire word is traversed
        if(!is_safe(i,j,visited,board,word,idx)) return false;

        visited[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int newI=i+dx[k],newJ=j+dy[k];
            bool res=findWord(newI,newJ,idx+1,visited,word,board);
            if(res==true) return true;
        }
        visited[i][j]=false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();

        vector<vector<bool>> visited(n,vector<bool> (m));
        for(int i=0;i<(int)board.size();i++)
        {
            for(int j=0;j<(int)board[i].size();j++)
            {
                if(findWord(i,j,0,visited,word,board)) return true;
            }
        }
        return false;

    }
};