<<<<<<< HEAD
int AStub(int a, int b);
=======
int AStub(int a, int b){return a+b;}
>>>>>>> main
float BStub(float a, float b);

namespace RCalc{
    class RMulti{
        public:
            int x;
            int y;
            int ResultMultiple(int x, int y){ return x * y; }
            float ResultDivision(float x, float y){ return x / y; }
            int ResultADD(int x, int y){ return x + y; }
            int ResultSubract(int x, int y){ return x - y; }
    };
}

class aaa{
    protected:
        int t;
    private:
        int q;
    public:
        int r;
};