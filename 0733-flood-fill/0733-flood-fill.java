class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {

        if (image[sr][sc] != color) {
        fill(image, sr, sc, color, image[sr][sc]);
    }
        return image;
    }


    public void fill(int[][] image, int i, int j, int color, int prev){
        if(i<0 ||j<0 || i>image.length-1 || j>image[0].length-1){
            return;
        }
        if(image[i][j]!=prev)return;
        image[i][j] = color;
        fill(image,i-1,j,color,prev); 
        fill(image,i+1,j,color,prev); 
        fill(image,i,j-1,color,prev); 
        fill(image,i,j+1,color,prev); 
    }
}