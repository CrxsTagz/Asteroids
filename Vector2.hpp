#include <iostream>
#include <cmath>

class vector2
{
        private:
            float x;
            float y;
        
        public:
        vector2(float cx, float cy)
        {
            x = cx;
            y = cy;
        }
void print()
{
        std::cout <<x<< " \n"; std::cout <<y<< " \n";
        
}        
};