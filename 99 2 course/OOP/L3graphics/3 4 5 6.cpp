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
 
    #define BLACK1 0   
    
    private:
        float scale;//?
        
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
            cl[0] = 14 ;//COLOR( 215*l, 215*l,   0*l);  // ?желтый
            cl[1] = 3; //COLOR( 160*l,  90*l,   0*l);  // ? CYAN
            cl[2] = 2;// COLOR(  50*l, 205*l,  50*l);  // темн-зеленый
            cl[3] = 5;// COLOR( 186*l,  85*l, 211*l);  // фиолетовый MAGENTA
            cl[4] = 4; //COLOR( 255*l,   0*l,   0*l);  // красный
            cl[5] = 9; //COLOR(  30*l, 144*l, 255*l);  // голубой
            cl[6] = 13;// COLOR(  32*l, 255*l, 208*l);  // бирюзовый LIGHTMAGENTA
            cl[7] = 12;// COLOR( 255*l, 140*l,   0*l);  // оранжевый LIGHT RED
            cl[8] = 11; //COLOR( 255*l, 160*l, 225*l);  // розовый LIGHT CYAN
            
            window.x = GetSystemMetrics(SM_CXSCREEN) -  6;// winuser.h returns my screen's width and height in pixels
            window.y = GetSystemMetrics(SM_CYSCREEN) - 64;
            initwindow((int)window.x,(int)window.y);
    
            float SX = (float)window.x / RESX;//?
            float SY = (float)window.y / RESY;
            if (SX < SY) scale = SX;
            else         scale = SY;
            
            setlinestyle(SOLID_LINE, 1, 1);//setlinestyle( int linestyle, unsigned upattern, int thickness ); 
			//setlinestyle sets the style for all lines drawn by line, lineto, rectangle, drawpoly, and so on.
            
            setbkcolor(BLACK1);
            setcolor(BLUE);//устанавливает текущий цвет рисовани€ равным цвету, заданному парамет≠ром color
            cleardevice();//‘ункци€ cleardevice() очищает экран и переустанавливает текущую позицию 
			//(current position Ч CP) в 0,0. Ёта функци€ используетс€ только в графических режимах экрана.
        }
        void ClearDevice()
        {
            cleardevice();
        }
};


#define SPEED_MAX 7
#define SPEED_MIN 1
#define RAND_SIGN ((rand()%2)*2-1)
#define RAND_COLOR (rand()%15 + 1)
//#define RAND_COLOR rand()%15 //COLOR(rand()%256,rand()%256,rand()%256)
#define SQUARE(x) x*x

class MoveableShape
{
    protected:
        DOT speed;
        DOT center;
        float rotationspeed;
        int clLine;//color
    
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

class tPolygon : public MoveableShape
{
    protected:
        std::vector<DOT> v;
        int clDot; // color of the dot
               
    private:
        BOX box;
        
    public:
        tPolygon()
        {
            clDot = RAND_COLOR;
            do {clLine = RAND_COLOR; } while (clLine==clDot);
        } 
        ~tPolygon() {}
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

class tPoint : public tPolygon
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
        tPoint()  { Create(); }
        ~tPoint() {}
};

class tSegment : public tPolygon
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
        tSegment()  { Create(); }
        ~tSegment() {}
};

class tRect : public tPolygon
{
    private:
        void Create()
        {
            v.resize(4);
            
            int xRCTsize = rand()%90 + 30;
            int yRCTsize = rand()%70 + 30;
            v[0].x = rand()%((int)window.x - xRCTsize);
            v[0].y = rand()%((int)window.y - yRCTsize);
            v[1].x = v[0].x + xRCTsize;
            v[1].y = v[0].y;
            v[2].x = v[0].x + xRCTsize;
            v[2].y = v[0].y + yRCTsize;
            v[3].x = v[0].x;
            v[3].y = v[0].y + yRCTsize;
            
            UpdateBox();
            CalculateCenter();
        }
        
    public:
        tRect() { Create(); }
        ~tRect() {}
};

class tRhomb : public tPolygon
{
    private:
        void Create()
        {
            v.resize(4);
            
            int xDiag = rand()%180 + 30;//x's are y's and vice versa
            int yDiag = rand()%60 + 30;
            v[0].x = rand()%((int)window.x - xDiag);//making sure x doen't appear outside the box
            v[0].y = rand()%((int)window.y - yDiag);
            v[1].x = v[0].x - xDiag/2;
            v[1].y = v[0].y + yDiag/2;
            v[2].x = v[0].x;
            v[2].y = v[0].y + yDiag;
            v[3].x = v[0].x + xDiag/2;
            v[3].y = v[0].y + yDiag/2;
            
            UpdateBox();
            CalculateCenter();
        }
        
    public:
        tRhomb() { Create(); }
        ~tRhomb() {}
};

class tTriangle : public tPolygon
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
            }//if dots are too far, then try again
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
        tTriangle()  { Create(); }
        ~tTriangle() {}
};



class tCurve : public MoveableShape
{
    protected:
        int radius;
                               
    public:
        tCurve()
        {
            clLine = RAND_COLOR;
            radius = 0;
        } 
        ~tCurve() {}
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

class tCircle : public tCurve
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
        tCircle()  { Create(); }
        ~tCircle() {}
    
};

class tEllipse : public MoveableShape
{
    private:
    	int xradius, yradius;
    	
        void Create()
        {
            xradius = rand()%25 + 15;
            yradius = rand()%15 + 15;
            center.x = rand()%((int)window.x-2*xradius) + xradius;
            center.y = rand()%((int)window.y-2*xradius) + xradius;
        }
        void Draw()
        {
            setcolor(clLine);
            ellipse((int)center.x, (int)center.y, 0, 360, xradius, yradius);
        }
        void Rotate()        { printf("%\nrotate\n");       }
        void Move()        {  printf("%\nmove\n");      }
            
    public:
        tEllipse()  { Create(); }
        ~tEllipse() {}
    
};


enum SHAPETYPE
{
    SH_POINT,
    SH_SEGMENT,
    SH_RECTANGLE,
    SH_TRIANGLE,
    SH_CIRCLE,
    SH_RHOMB,
    SH_MAX,
  
};

MoveableShape* CreateShapeOfType(int type, GFX& gfx)
{
    switch (type)
    {
        case SH_POINT    : return new tPoint   ();
        case SH_SEGMENT  : return new tSegment (); 
        case SH_RECTANGLE: return new tRect    (); 
        case SH_TRIANGLE : return new tTriangle(); 
        case SH_CIRCLE   : return new tCircle  (); 
        case SH_RHOMB    : return new tRhomb   ();
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
    polys[SH_POINT]    = 100;
    polys[SH_SEGMENT]  = 2;
    polys[SH_RECTANGLE]= 2;
    polys[SH_TRIANGLE] = 2;
    polys[SH_CIRCLE]   = 2;
    polys[SH_RHOMB]  = 2;
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


