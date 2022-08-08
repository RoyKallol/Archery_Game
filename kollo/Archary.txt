# include "iGraphics.h"
#include<math.h>
int p=0,z=0,game,q,x[100],y[15],A[11]={1,2,3,4,4,4,4,3,2,1,0},g,c=0,d=0,e=1,i=0,j,total_ballon,l=0;
double s=0,ccx,ccy,cr,arclength,arcsmlength,arctime,speedwall,gap_ballon,speedballon,xio,yio,prex,prey,pox[4]={0,0,0,0},poy[4]={0,0,0,0},a,b,NM,Ex,Ey,Fx,Fy,Gx,Gy,Hx,Hy,Ix,Iy,Ia,Ib,Ic,Id,Jx,Jy,Kx,Ky,u,md,mox,moy,Xs1,Xs2,Ys1,Ys2,ux,uy,t=0,M,M1,xi,yi,m,m1,m2,X1,X2,X3,X4,X5,X6,Y1,Y2,Y3,Y4,Y5,Y6;
void changeable_value(void)
{
    ccx=50;
    ccy=50;
    cr=50;
    arctime=10;
    arclength=100;
    arcsmlength=10;
    speedwall=1;
    gap_ballon=100;
    speedballon=1;
    mox=(ccy+ccx+cr)/2;
    moy=(ccy+ccx+cr)/2;
    total_ballon=15;
    a=100;
    b=200;
}
void mousepointchange(void)
{
    md=sqrt((mox-ccx)*(mox-ccx)+(moy-ccy)*(moy-ccy));
    if(md>=cr-15)//if((mox>50&&md>=35)||(mox<50&&md>=35)) if u do not want to make the arc out of range
    {
        mox=prex;
        moy=prey;
    }
    else
    {
        prex=mox;
        prey=moy;
    }
}
double absl(double z)
{
    if(z<0)
        return -z;
    return z;
}
//does it hit the ballon
void ballon(void)
{
    s++;
    c++;//ballon calculation start
    c=c%(int)(300/speedwall);
    if(c<(150/speedwall))
    {
        a+=speedwall;
        b-=speedwall;
    }
    else
    {
        a-=speedwall;
        b+=speedwall;
    }
    d=s*speedballon/gap_ballon;
    if(e!=d)
    {
        e=d;
        x[l]=rand()%200;
        y[l++]=0;
    }
    for(i=0;i<total_ballon;i++)
        y[i]+=speedballon;
    if(l==total_ballon)
        l=0;
}
//make the circle an archer
void hiddenrectangle(void)
{
    Ex=ccx-(cr+5)/sqrt(1+M*M);
    Ey=ccy-(cr+5)*M/sqrt(1+M*M);
    Gx=ccx+(cr-20)/sqrt(1+M*M);
    Gy=ccy+(cr-20)*M/sqrt(1+M*M);
    if(M1>=0)
    {
        Fx=ccx-(cr+5)/sqrt(1+M1*M1);
        Fy=ccy-(cr+5)*M1/sqrt(1+M1*M1);
        Hx=ccx+(cr+5)/sqrt(1+M1*M1);
        Hy=ccy+(cr+5)*M1/sqrt(1+M1*M1);
    }
    else
    {
        Fx=ccx+(cr+5)/sqrt(1+M1*M1);
        Fy=ccy+(cr+5)*M1/sqrt(1+M1*M1);
        Hx=ccx-(cr+5)/sqrt(1+M1*M1);
        Hy=ccy-(cr+5)*M1/sqrt(1+M1*M1);
    }
    pox[0]=((Ey-M1*Ex)-(Hy-M*Hx))/(M-M1);
    poy[0]=Hy+M*(pox[0]-Hx);
    pox[1]=((Ey-M1*Ex)-(Fy-M*Fx))/(M-M1);
    poy[1]=Fy+M*(pox[1]-Fx);
    pox[2]=((Gy-M1*Gx)-(Fy-M*Fx))/(M-M1);
    poy[2]=Fy+M*(pox[2]-Fx);
    pox[3]=((Gy-M1*Gx)-(Hy-M*Hx))/(M-M1);
    poy[3]=Hy+M*(pox[3]-Hx);
}

//The measurement of the points of the archer
void archercalculation(void)
{
    if(t==0)
    {
        M=(moy-ccy)/(mox-ccx);
        M1=(ccx-mox)/(moy-ccy);
        if(M==0)
        {
            M=0.01;
            M1=1000;
        }
        if(M1==0)
        {
            M=1000;
            M1=0.01;
        }
        Xs2=mox+arclength/sqrt(1+M*M);
        Ys2=moy+arclength*M/sqrt(1+M*M);
        Xs1=mox;
        Ys1=moy;
        X1=mox;
        Y1=moy;
        X2=Xs2;
        Y2=Ys2;
        xio=(Xs1+Xs2)/2;
        yio=(Ys1+Ys2)/2;
        Ix=ccx+(cr-15)/sqrt(1+M*M);
        Iy=ccy+(cr-15)*M/sqrt(1+M*M);
        u=3*sqrt((Ix-mox)*(Ix-mox)+(Iy-moy)*(Iy-moy));
        ux=u*(Xs2-Xs1)/sqrt((Xs2-Xs1)*(Xs2-Xs1)+(Ys2-Ys1)*(Ys2-Ys1));
        uy=u*(Ys2-Ys1)/sqrt((Xs2-Xs1)*(Xs2-Xs1)+(Ys2-Ys1)*(Ys2-Ys1));
    }
    //baloon calculation finish and arcjher start

    else
    {
        xi=ux*t/arctime+xio;
        yi=uy*t/arctime-5*t*t/(arctime*arctime)+yio;
        NM=(Ys2-Ys1)/(Xs2-Xs1)-10*t*sqrt((Xs2-Xs1)*(Xs2-Xs1)+(Ys2-Ys1)*(Ys2-Ys1))/(u*arctime*(Xs2-Xs1));
        X1=xi-arclength/(2*sqrt(1+NM*NM));
        X2=xi+arclength/(2*sqrt(1+NM*NM));
        Y1=yi-arclength*NM/(2*sqrt(1+NM*NM));
        Y2=yi+arclength*NM/(2*sqrt(1+NM*NM));
    }

    if((X1-X2)==(Y1-Y2))
    {
        X3=X1;
        Y3=Y1-arcsmlength;
        X4=X1-arcsmlength;
        Y4=Y1;
        X5=X2;
        Y5=Y2-arcsmlength;
        X6=X2-arcsmlength;
        Y6=Y2;
    }
    else if((X1-X2)==(Y2-Y1))
    {
        X3=X1-arcsmlength;
        Y3=Y1;
        X4=X1;
        Y4=Y1+arcsmlength;
        X5=X2-arcsmlength;
        Y5=Y2;
        X6=X2;
        Y6=Y2+arcsmlength;
    }
    else
    {
        m=(Y1-Y2)/(X1-X2);
        m1=((X1-X2)+(Y1-Y2))/((X1-X2)-(Y1-Y2));
        m2=((Y1-Y2)-(X1-X2))/((X1-X2)+(Y1-Y2));
        if(m<1)
        {
            X3=X1-arcsmlength/sqrt(1+m1*m1);
            Y4=Y1+arcsmlength*absl(m2)/sqrt(1+m2*m2);
            X5=X2-arcsmlength/sqrt(1+m1*m1);
            Y6=Y2+arcsmlength*absl(m2)/sqrt(1+m2*m2);
        }
        else
        {
            X3=X1+arcsmlength/sqrt(1+m1*m1);
            Y4=Y1-arcsmlength*absl(m2)/sqrt(1+m2*m2);
            X5=X2+arcsmlength/sqrt(1+m1*m1);
            Y6=Y2-arcsmlength*absl(m2)/sqrt(1+m2*m2);
        }
        if(m>-1)
        {
            X4=X1-arcsmlength/sqrt(1+m2*m2);
            Y3=Y1-arcsmlength*absl(m1)/sqrt(1+m1*m1);
            X6=X2-arcsmlength/sqrt(1+m2*m2);
            Y5=Y2-arcsmlength*absl(m1)/sqrt(1+m1*m1);
        }
        else
        {
            X4=X1+arcsmlength/sqrt(1+m2*m2);
            Y3=Y1+arcsmlength*absl(m1)/sqrt(1+m1*m1);
            X6=X2+arcsmlength/sqrt(1+m2*m2);
            Y5=Y2+arcsmlength*absl(m1)/sqrt(1+m1*m1);
        }
    }
}

//wire drawing
void wire(void)
{
    Ic=Iy-ccy-M1*Ix;
    Ia=1+M1*M1;
    Ib=2*Ic*M1-2*ccx;
    Id=Ic*Ic+ccx*ccx-cr*cr;
    Jx=(-Ib+sqrt(Ib*Ib-4*Ia*Id))/(2*Ia);
    Jy=Iy+M1*(Jx-Ix);
    Kx=(-Ib-sqrt(Ib*Ib-4*Ia*Id))/(2*Ia);
    Ky=Iy+M1*(Kx-Ix);
    if(t)
    {
        mox=(Jx+Kx)/2;
        moy=(Jy+Ky)/2;
    }
}

//play again if the archer fall
void restart(void)
{
    if(((Y2<-100)&&(Y2>-200))||(X1>1200)||((X2>=900)&&(X2<=950)&&((Y2<a)||Y2>650-b)))
    {
        p=0;
        t=0;
        mox=(ccy+ccx+cr)/2;
        moy=(ccy+ccx+cr)/2;
    }
    for(i=0;i<15;i++)
    {
        q=sqrt((975+x[i]-X2)*(975+x[i]-X2)+(y[i]-Y2)*(y[i]-Y2));
        if(q<=25)
        {
            if(i==0)
                printf("problem\nx2: %.1lf Y2: %.1lf q:%.1lf\n",X2,Y2,q);
            y[i]=800;
            p=0;
            t=0;
            mox=(ccy+ccx+cr)/2;
            moy=(ccy+ccx+cr)/2;
            break;
        }
    }
}
/*
	function iDraw() is called again and again by the system.

	*/
void func(void)
{

    if(p)
    t++;
    ballon();
    archercalculation();
    hiddenrectangle();
    wire();
    restart();
}
void iDraw()
{
    iClear();
    iSetColor(100,100,100);
    iFilledRectangle(900,0,50,a);
    iFilledRectangle(900,650-b,50,b);
    for(i=0;i<total_ballon;i++)
    {
        g=25;
        if(!(i%3))
            iSetColor(0,50,250);
        else if(i%3==1)
            iSetColor(250,50,0);
        else
            iSetColor(25,250,25);
        iFilledCircle(975+x[i],y[i],25);
        for(j=0;j<22;j++)
        {
            if(!(j/11))
                iPoint(975+x[i]-A[j%11],y[i]-g);
            else
                iPoint(975+x[i]+A[j%11],y[i]-g);
            g++;
        }
    }
        iSetColor(100,100,0);
        iCircle(ccx,ccy,cr);
        iSetColor(0,0,0);
        iFilledPolygon(pox,poy,4);
        iSetColor(50,50,50);
        iCircle(ccx,ccy,cr-15);
        iLine(ccx,ccy-cr,ccx,ccy+cr);
        iLine(ccx-cr,ccy,ccx+cr,ccy);
        iSetColor(100,100,0);
        iLine(X1,Y1,X2,Y2);
        iLine(X1,Y1,X3,Y3);
        iLine(X1,Y1,X4,Y4);
        iLine(X2,Y2,X5,Y5);
        iLine(X2,Y2,X6,Y6);
        iLine(mox,moy,Jx,Jy);
        iLine(mox,moy,Kx,Ky);
 //   iPoint(Ix,Iy,1);
        if(game)
            iText(100,100,"Game On");
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	mox=mx;
	moy=my;
	mousepointchange();
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        p=1;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
    {
		p=1;
	}
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
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
    {
		exit(0);
	}
	if (key == GLUT_KEY_RIGHT)
	{
		mox++;
		mousepointchange();
	}
	if (key == GLUT_KEY_LEFT)
	{
		mox--;
		mousepointchange();
	}
	if (key == GLUT_KEY_DOWN)
	{
		moy--;
		mousepointchange();
	}
	if (key == GLUT_KEY_UP)
	{
		moy++;
		mousepointchange();
	}
}
int main()
{
    changeable_value();
	for(i=0;i<15;i++)
    {
        x[i]=200;
        y[i]=800;
    }
	iSetTimer(20,func);
	iInitialize(1200,650, "demo");
}
