class Solution {
public:
    int maxArea(vector<int>& height) {
        int Left = 0, Right = height.size() - 1, max = 0;
        while(Left < Right) {
            int Width = Right - Left;
            int Height = min(height[Left], height[Right]);
            if(Width*Height > max) max = Width*Height;
            (height[Left] < height[Right]) ? Left++ : Right--;
        }
        return max;
    }
};