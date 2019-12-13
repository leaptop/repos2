#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <math.h>
#include <vector>

struct DOT
{
    float x;
    float y;
};

struct BOX
{
    DOT a;
    DOT b;
};

DOT window;
        
class GFX
{    
    #define RESX 1600
    #define RESY  900    
    #define GRAY0 COLOR(16,16,16)
    #define GRAY1 COLOR(32,32,32)
    #define GRAY2 COLOR(160,160,160)
    #define GRAY3 COLOR(200,200,200)
    #define GRAY4 COLOR(232,232,232)
    
    private:
        float scale;
        
    public:        
        void Stop()
        {
            closegraph();
        }
        void Start()
        {
            //float l = 0.8;
            int l = 1;
            int cl[9];
            memset(cl, 0, sizeof(int)*9);
            cl[0] = COLOR( 215*l, 215*l,   0*l);  // желтый
            cl[1] = COLOR( 160*l,  90*l,   0*l);  // ?
            cl[2] = COLOR(  50*l, 205*l,  50*l);  // темно-зеленый
            cl[3] = COLOR( 186*l,  85*l, 211*l);  // фиолетовый
            cl[4] = COLOR( 255*l,   0*l,   0*l);  // красный
            cl[5] = COLOR(  30*l, 144*l, 255*l);  // голубой
            cl[6] = COLOR(  32*l, 255*l, 208*l);  // бирюзовый 
            cl[7] = COLOR( 255*l, 140*l,   0*l);  // оранжевый
            cl[8] = COLOR( 255*l, 160*l, 225*l);  // розовый
            
            window.x = GetSystemMetrics(SM_CXSCREEN) -  6;
            window.y = GetSystemMetrics(SM_CYSCREEN) - 64;
            initwindow((int)window.x,(int)window.y);
    
            float SX = (float)window.x / RESX;
            float SY = (float)window.y / RESY;
            if (SX < SY) scale = SX;
            else         scale = SY;
            
            setlinestyle(SOLID_LINE, 0, 3);
            
            setbkcolor(GRAY1);
            setcolor(BLUE);
            cleardevice();
        }
        void ClearDevice()
        {
            cleardevice();
        }
};














#define SPEED_MAX 7
#define SPEED_MIN 1
#define RAND_SIGN ((rand()%2)*2-1)
//#define RAND_COLOR (rand()%15 + 1)
#define RAND_COLOR COLOR(rand()%256,rand()%256,rand()%256)
#define SQUARE(x) x*x

class MoveableShape
{
    protected:
        DOT speed;
        DOT center;
        float rotationspeed;
        int clLine;
    
    public:
        virtual void Draw() = 0;
        virtual void Move() = 0;
        virtual void Rotate() = 0;
        virtual void Create() = 0;
        MoveableShape()
        {
            speed.x = (rand()%(SPEED_MAX-SPEED_MIN) + SPEED_MIN) * RAND_SIGN;
            speed.y = (rand()%(SPEED_MAX-SPEED_MIN) + SPEED_MIN) * RAND_SIGN;
            rotationspeed = (rand()%5+1)*RAND_SIGN * 0.01;
            //printf("Assigned speed: %3d, %3d\n",speed.x,speed.y);
        }
        ~MoveableShape(){}
};

class CPolygon : public MoveableShape
{
    protected:
        std::vector<DOT> v;
        int clDot;
               
    private:
        BOX box;
        
    public:
        CPolygon()
        {
            clDot = RAND_COLOR;
            do {clLine = RAND_COLOR; } while (clLine==clDot);
        } 
        ~CPolygon() {}
        void CalculateCenter()
        {
            center.x = 0.0f;
            center.y = 0.0f;
            for (int i=0; i<v.size(); i++)
            {
                center.x += v[i].x;
                center.y += v[i].y;
            }
            center.x /= v.size();
            center.y /= v.size();
        }
        void UpdateBox()
        {
            box.a.x = window.x;
            box.a.y = window.y;
            box.b.x = 0;
            box.b.y = 0;
            for (int i=0; i<v.size(); i++)
            {
                if (v[i].x < box.a.x) box.a.x = v[i].x;
                if (v[i].x > box.b.x) box.b.x = v[i].x;
                if (v[i].y < box.a.y) box.a.y = v[i].y;
                if (v[i].y > box.b.y) box.b.y = v[i].y;
            }
        }
        void Draw()
        {
            setcolor(clLine);
            for (int i=0; i<v.size() - 1; i++)
            {
                line((int)v[i].x, (int)v[i].y, (int)v[i+1].x, (int)v[i+1].y);
            }
            if (v.size()>=3) line((int)v.back().x, (int)v.back().y, (int)v.front().x, (int)v.front().y);
            setcolor(clDot);
            for (int i=0; i<v.size(); i++)
            {
                circle((int)v[i].x, (int)v[i].y, 3);
            }
        }
        void Move()
        {
            box.a.x += speed.x;
            box.a.y += speed.y;
            box.b.x += speed.x;
            box.b.y += speed.y;
            
            // Worst collision handling ever made.
            DOT dist;
            dist.x = speed.x;
            dist.y = speed.y;
            if (box.a.x < 0)
            {
                dist.x -= box.a.x;
                speed.x = -speed.x;
            }
            if (box.a.y < 0)
            {
                dist.y -= box.a.y;
                speed.y = -speed.y;
            }            
            DOT temp;
            temp.x = window.x - box.b.x;
            temp.y = window.y - box.b.y;
            if (temp.x < 0)
            {
                dist.x += temp.x;
                speed.x = -speed.x;
            }
            if (temp.y < 0)
            {
                dist.y += temp.y;
                speed.y = -speed.y;
            }
            
            // Apply.            
            for (int i=0; i<v.size(); i++)
            {
                v[i].x += dist.x;
                v[i].y += dist.y;
            }
            center.x += dist.x;
            center.y += dist.y;
        }
        void Rotate()
        {
            DOT vec;
            float sinr, cosr;
            sinr = sin(rotationspeed);
            cosr = cos(rotationspeed);
            
            for (int i=0; i<v.size(); i++)
            {
                vec.x = v[i].x - center.x;
                vec.y = v[i].y - center.y;
                v[i].x = (vec.x * cosr) - (vec.y * sinr) + center.x;
                v[i].y = (vec.y * cosr) + (vec.x * sinr) + center.y;
            }
            UpdateBox();
        }
};

class CPoint : public CPolygon
{
    private:
        void Create()
        {
            v.resize(1);
            
            v[0].x = rand()%(int)window.x;
            v[0].y = rand()%(int)window.y;
            
            UpdateBox();
            CalculateCenter();
        }
            
    public:
        CPoint()  { Create(); }
        ~CPoint() {}
};

class CSegment : public CPolygon
{
    private:
        void Create()
        {
            v.resize(2);
            
            v[0].x = rand()%(int)window.x;
            v[0].y = rand()%(int)window.y;
            do
            {
                v[1].x = rand()%(int)window.x;
                v[1].y = rand()%(int)window.y;
            }
            while (abs((int)v[0].x-(int)v[1].x) + abs((int)v[0].y-(int)v[1].y) > 400); 
            
            UpdateBox();
            CalculateCenter();
        }
            
    public:
        CSegment()  { Create(); }
        ~CSegment() {}
};

class CSquare : public CPolygon
{
    private:
        void Create()
        {
            v.resize(4);
            
            int sqsize = rand()%80 + 30;
            v[0].x = rand()%((int)window.x - sqsize);
            v[0].y = rand()%((int)window.y - sqsize);
            v[1].x = v[0].x + sqsize;
            v[1].y = v[0].y;
            v[2].x = v[0].x + sqsize;
            v[2].y = v[0].y + sqsize;
            v[3].x = v[0].x;
            v[3].y = v[0].y + sqsize;
            
            UpdateBox();
            CalculateCenter();
        }
        
    public:
        CSquare() { Create(); }
        ~CSquare() {}
};

class CTriangle : public CPolygon
{
    private:
        void Create()
        {
            v.resize(3);
            
            v[0].x = rand()%(int)window.x;
            v[0].y = rand()%(int)window.y;
            do
            {
                v[1].x = rand()%(int)window.x;
                v[1].y = rand()%(int)window.y;
            }
            while (abs((int)v[0].x-(int)v[1].x) + abs((int)v[0].y-(int)v[1].y) > 300);
            do
            {
                v[2].x = rand()%(int)window.x;
                v[2].y = rand()%(int)window.y;
            }
            while (abs((int)v[0].x-(int)v[1].x) + abs((int)v[0].y-(int)v[1].y) > 400 ||
                   abs((int)v[0].x-(int)v[2].x) + abs((int)v[0].y-(int)v[2].y) > 400 );
            
            
            UpdateBox();
            CalculateCenter();
        }
            
    public:
        CTriangle()  { Create(); }
        ~CTriangle() {}
};









class CCurve : public MoveableShape
{
    protected:
        int radius;
                               
    public:
        CCurve()
        {
            clLine = RAND_COLOR;
            radius = 0;
        } 
        ~CCurve() {}
        void Draw()
        {
            setcolor(clLine);
            circle((int)center.x, (int)center.y, radius);
        }
        void Move()
        {
            center.x += speed.x;
            center.y += speed.y;
            if (center.x - radius < 0 || center.x + radius > window.x) speed.x = -speed.x;
            if (center.y - radius < 0 || center.y + radius > window.y) speed.y = -speed.y;
        }
};

class CCircle : public CCurve
{
    private:
        void Create()
        {
            radius = rand()%35 + 15;
            center.x = rand()%((int)window.x-2*radius) + radius;
            center.y = rand()%((int)window.y-2*radius) + radius;
        }
        void Rotate()
        {
            // nothing. Can't rotate circles.
        }
            
    public:
        CCircle()  { Create(); }
        ~CCircle() {}
    
};










enum SHAPETYPE
{
    SH_POINT,
    SH_SEGMENT,
    SH_SQUARE,
    SH_TRIANGLE,
    SH_CIRCLE,
    SH_MAX,
};

MoveableShape* CreateShapeOfType(int type, GFX& gfx)
{
    switch (type)
    {
        case SH_POINT    : return new CPoint   ();
        case SH_SEGMENT  : return new CSegment (); 
        case SH_SQUARE   : return new CSquare  (); 
        case SH_TRIANGLE : return new CTriangle(); 
        case SH_CIRCLE   : return new CCircle  (); 
    }
}
        
int main()
{
    srand(time(NULL));
    GFX gfx;
    gfx.Start();
    
    std::vector<MoveableShape*> a;
    
    MoveableShape* temp;
    int polys[SH_MAX];
    polys[SH_POINT]    = 15;
    polys[SH_SEGMENT]  = 8;
    polys[SH_SQUARE]   = 10;
    polys[SH_TRIANGLE] = 6;
    polys[SH_CIRCLE]   = 6;
    for (int i=0; i<SH_MAX; i++)
    {
        for (int j=0; j<polys[i]; j++)
        {
            a.push_back(CreateShapeOfType(i,gfx));
        }
    }
    
    while (true)
    {
        if (kbhit()) break;
        cleardevice();
    
        for (int i=0; i<a.size(); i++)
        {
            a[i]->Draw();
            a[i]->Rotate();
            a[i]->Move();
        }
        delay(16);
    }
    
    gfx.Stop();
    return 0;
}

