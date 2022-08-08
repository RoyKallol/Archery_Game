# include "iGraphics.h"
#include<windows.h>
#include<time.h>

int x = 300, y = 300, r = 20, s=0;

double vx=10,vy=100,hx=60,hy=10;

/*
	function iDraw() is called again and again by the system.

	*/


void makepolygonv(int ax,int ay){

    ax=(double)ax;
    ay=(double)ay;

	double l[6]={ax,ax+vx/2,ax+vx,ax+vx,ax+vx/2,ax};
	double m[6]={ay,ay-vx/2,ay,ay+vy,ay+vy+vx/2,ay+vy};

	iFilledPolygon(l, m, 6);
}


void makepolygonh(int ax,int ay){

    ax=(double)ax;
    ay=(double)ay;

	double l[6]={ax,ax+hx,ax+hx+hy/2,ax+hx,ax,ax-hy/2};
	double m[6]={ay,ay,ay+hy/2,ay+hy,ay+hy,ay+hy/2};

	iFilledPolygon(l, m, 6);
}


void sbone(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    //makepolygonv(ax, ay, );
	//makepolygonv(ax, ay+vx+vy, );
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	//makepolygonh(ax+vx, ay+2*vy+hy );
	//makepolygonh(ax+vx, ay+vy );
	//makepolygonh(ax+vx, ay-hy );
}

void sbtwo(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    makepolygonv(ax, ay);
	//makepolygonv(ax, ay+vx+vy, );
	//makepolygonv(ax+vx+hx, ay, );
	makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	makepolygonh(ax+vx, ay+vy);
	makepolygonh(ax+vx, ay-hy);
}

void sbthree(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    //makepolygonv(ax, ay, );
	//makepolygonv(ax, ay+vx+vy, );
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	makepolygonh(ax+vx, ay+vy);
	makepolygonh(ax+vx, ay-hy);
}

void sbfour(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    //makepolygonv(ax, ay, );
	makepolygonv(ax, ay+vx+vy);
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	//makepolygonh(ax+vx, ay+2*vy+hy );
	makepolygonh(ax+vx, ay+vy);
	//makepolygonh(ax+vx, ay-hy );
}

void sbfive(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    //makepolygonv(ax, ay, );
	makepolygonv(ax, ay+vx+vy);
	makepolygonv(ax+vx+hx, ay);
	//makepolygonv(ax+vx+hx, ay+vx+vy, );

	makepolygonh(ax+vx, ay+2*vy+hy);
	makepolygonh(ax+vx, ay+vy);
	makepolygonh(ax+vx, ay-hy);
}

void sbsix(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    makepolygonv(ax, ay);
	makepolygonv(ax, ay+vx+vy);
	makepolygonv(ax+vx+hx, ay);
	//makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	makepolygonh(ax+vx, ay+vy);
	makepolygonh(ax+vx, ay-hy);
}

void sbseven(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    //makepolygonv(ax, ay, );
	//makepolygonv(ax, ay+vx+vy, );
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	//makepolygonh(ax+vx, ay+vy );
	//makepolygonh(ax+vx, ay-hy );
}

void sbeight(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    makepolygonv(ax, ay);
	makepolygonv(ax, ay+vx+vy);
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	makepolygonh(ax+vx, ay+vy);
	makepolygonh(ax+vx, ay-hy);
}

void sbnine(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    //makepolygonv(ax, ay, );
	makepolygonv(ax, ay+vx+vy);
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	makepolygonh(ax+vx, ay+vy);
	makepolygonh(ax+vx, ay-hy);
}

void sbzero(double ax, double ay)
{
    //int vx=10,vy=100,hx=60,hy=10;

    makepolygonv(ax, ay);
	makepolygonv(ax, ay+vx+vy);
	makepolygonv(ax+vx+hx, ay);
	makepolygonv(ax+vx+hx, ay+vx+vy);

	makepolygonh(ax+vx, ay+2*vy+hy);
	//makepolygonh(ax+vx, ay+vy );
	makepolygonh(ax+vx, ay-hy);
}

void show(int n,double ax,double ay)
{
    switch(n){
        case 0: sbzero(ax,ay);
                break;
        case 1: sbone(ax,ay);
                break;
        case 2: sbtwo(ax,ay);
                break;
        case 3: sbthree(ax,ay);
                break;
        case 4: sbfour(ax,ay);
                break;
        case 5: sbfive(ax,ay);
                break;
        case 6: sbsix(ax,ay);
                break;
        case 7: sbseven(ax,ay);
                break;
        case 8: sbeight(ax,ay);
                break;
        case 9: sbnine(ax,ay);
                break;

    }
}

void crl (void){

    double ay=80,ax=270,s1x,s2x,m1x,m2x,h1x,h2x,cr,cdy,cuy;
    h1x=ax; h2x=h1x+100;
    m1x=h2x+125; m2x=m1x+100;
    s1x=m2x+125; s2x=s1x+100;
    cr=10,cdy=ay+50,cuy=cdy+110;

    iFilledCircle(m1x-22, cuy, cr);
	iFilledCircle(m1x-22, cdy, cr);
	iFilledCircle(s1x-22, cuy, cr);
	iFilledCircle(s1x-22, cdy, cr);




}

void beeps(){
    s=(-s)+1;
}


void gettime(int t[]) {
    time_t ctime;
    struct tm * current;
    time ( &ctime );
    current = localtime ( &ctime );
    t[0] = current->tm_hour;
    t[1] = current->tm_min;
    t[2] = current->tm_sec;

}


void iDraw() {

    double ay=80,ax=270,s1x,s2x,m1x,m2x,h1x,h2x,cr,cdy,cuy;
    h1x=ax; h2x=h1x+100;
    m1x=h2x+125; m2x=m1x+100;
    s1x=m2x+125; s2x=s1x+100;
    cr=10,cdy=ay+50,cuy=cdy+110;

    int t[3];
    gettime(t);
    int s1,s2,m1,m2,h1,h2,tf;

    tf=t[0];
    if(t[0]>12)t[0]=t[0]-12;

    s1=(t[2])/10;  s2=(t[2])%10;
    m1=(t[1])/10;  m2=(t[1])%10;
    h1=(t[0])/10;  h2=(t[0])%10;


	//place your drawing codes here
	iClear();
	//iSetColor(20, 200, 200);
	//iFilledCircle(x, y, r);
	//iFilledRectangle(10, 30, 20, 20);


	iSetColor(164,165,179);
	iFilledRectangle(0, 0, 1200, 400);



    iSetColor(25,34,152);

    show(h1,h1x,ay);show(h2,h2x,ay); show(m1,m1x,ay);show(m2,m2x,ay); show(s1,s1x,ay);show(s2,s2x,ay);

    if(tf >= 12 && tf != 24){
        iText(s2x+110, ay, "PM", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else iText(s2x+110, ay, "AM", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(14, 14, 14);
    if(s) crl();


	//iSetColor(20, 200, 0);
	//iText(40, 40, "Hi, I am iGraphics");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	//int t=iSetTimer(500, iFilledCircle);

	iSetTimer(500,beeps);
	iInitialize(1200, 400, "demo");


}
