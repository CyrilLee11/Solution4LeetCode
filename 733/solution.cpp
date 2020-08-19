class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int curpixel = image[sr][sc];
            int y_size = image[0].size();
            int x_size = image.size();
            if(newColor == curpixel) /* If the pixel doesn't change */
            {
                return image;
            }

            image[sr][sc] = newColor;

            if(sr - 1 >= 0 && sr + 1 < x_size) /* Horizontal */
            {
                if(sc - 1 >= 0 && sc + 1 < y_size) /* Vertical */
                {
                    if(image[sr-1][sc] == curpixel) /* Left */
                    {
                        floodFill(image, sr-1,sc,newColor);
                    }
                    if(image[sr+1][sc] == curpixel) /* Right */
                    {
                        floodFill(image, sr+1,sc,newColor);
                    }
                    if(image[sr][sc-1] == curpixel) /* Bottom */
                    {
                        floodFill(image, sr, sc-1, newColor);
                    }
                    if(image[sr][sc+1] == curpixel) /* Top */
                    {
                        floodFill(image, sr, sc+1, newColor);
                    }

                    //image[sr][sc] = newColor;   /* Set new Color */

                }
            }

            if(sr - 1 == -1)    /* Left Most */
            {
                if(sc - 1 >= 0)
                {
                    if(image[sr][sc-1] == curpixel)
                    {
                        floodFill(image, sr, sc-1, newColor);
                    }
                }
                if(sc + 1 < y_size)
                {
                    if(image[sr][sc+1] == curpixel)
                    {
                        floodFill(image, sr, sc+1, newColor);
                    }
                }

                if(image[sr + 1][sc] == curpixel)
                {
                    floodFill(image, sr+1, sc, newColor);

                }

                //image[sr][sc] = newColor;

            }

            if(sr + 1 == x_size) /* Right Most */
            {
                if(sc - 1 >= 0)
                {
                    if(image[sr][sc-1] == curpixel)
                    {
                        floodFill(image, sr, sc-1, newColor);
                    }
                }
                if(sc + 1 < y_size)
                {
                    if(image[sr][sc+1] == curpixel)
                    {
                        floodFill(image, sr, sc+1, newColor);
                    }
                }

                if(image[sr - 1][sc] == curpixel)
                {
                    floodFill(image, sr-1, sc, newColor);

                }

                //image[sr][sc] = newColor;
 
            }

            if(sc - 1 == -1) /* Top */
            {
                if(sr - 1>= 0)
                {
                    if(image[sr - 1][sc] == curpixel)
                    {
                        floodFill(image, sr-1, sc, newColor);
                    }  
                }
                if(sr + 1 < x_size)
                {
                    if(image[sr + 1][sc] == curpixel)
                    {
                        floodFill(image, sr+1, sc, newColor);
                    }  
                }
                if(image[sr][sc+1] == curpixel)
                {
                    floodFill(image, sr, sc+1, newColor);
                }

                //image[sr][sc] = newColor;

            }

            if(sc + 1 == y_size) /* Bottom */
            {
                if(sr - 1>= 0)
                {
                    if(image[sr - 1][sc] == curpixel)
                    {
                        floodFill(image, sr-1, sc, newColor);
                    }  
                }
                if(sr + 1 < x_size)
                {
                    if(image[sr + 1][sc] == curpixel)
                    {
                        floodFill(image, sr+1, sc, newColor);
                    }  
                }
                if(image[sr][sc-1] == curpixel)
                {
                    floodFill(image, sr, sc-1, newColor);
                }

                //image[sr][sc] = newColor;
            }

            return image;
    }
};