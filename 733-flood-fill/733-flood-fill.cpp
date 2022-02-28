class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        int r = image.size();
        int c = image[0].size();
        int originalColor = image[sr][sc];
        if(newColor == originalColor) return image;
        q.push({sr,sc});
        while(!q.empty()){
            int k = q.size();
            for(int i=0 ; i < k ; i++){
                int x  = q.front().first;
                int y = q.front().second;
                image[x][y] = newColor;
                q.pop();
                int dx[]={1,-1,0,0};
                int dy[]={0 , 0 ,1 ,-1};
                for(int l =0 ; l <4 ; l++){
                    int nx = x + dx[l];
                    int ny = y+dy[l];
                    if(nx>=0 && nx <=r-1 && ny >=0 && ny<=c-1 && image[nx][ny]==originalColor)
                        q.push({nx, ny});
                }
            }
        }
        return image;
    }
};