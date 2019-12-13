#ifndef FIG_H
#define FIG_H


class fig
{
    public:
        fig(int x, int y);
        virtual ~fig();

        int Getx()
        { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
        int Getid() { return id; }
        void Setid(int val) { id = val; }
        void Randx();
        void Randy();

        virtual void desenha() = 0;

    protected:

    private:
        int x;
        int y;
        int id;
};

#endif // FIG_H
