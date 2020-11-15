//Aitken逐步插值.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//x[n]         存放n个给定的有序结点值。
//y[n]         存放n个给定结点上的函数值。
//n            给定结点的个数。
//eps          插值的精度要求。
//t            指定插值点值。
  //函数返回指定插值点t处的函数近似值。
  double aitken(double x[], double y[], int n, double eps, double t)
  { 
	  int i,j,k,m,l;
      double z,xx[10],yy[10];
      z=0.0;
      if (n<1) return(z);
      if (n==1) { z=y[0]; return(z);}
      m=10;              //最多取前后10个点
      if (m>=n) m=n;
      if (t<=x[0]) k=1;            //起始点
      else if (t>=x[n-1]) k=n;     //起始点
      else
      { 
		  k=1; j=n;
          while ((k-j!=1)&&(k-j!=-1))
          { 
			  l=(k+j)/2;
              if (t<x[l-1]) j=l;
              else k=l;
          }
          if (fabs(t-x[l-1])>fabs(t-x[j-1])) k=j;    //起始点
      }
      j=1; l=0;
      for (i=1;i<=m;i++)    //从起始点开始轮流在前后取m个点
      { 
		  k=k+j*l;
          if ((k<1)||(k>n))
          { l=l+1; j=-j; k=k+j*l;}
          xx[i-1]=x[k-1]; yy[i-1]=y[k-1];
          l=l+1; j=-j;
      }
      i=0;
      do      //对m个点作Aitken逐步插值
      { 
		  i=i+1; z=yy[i];
          for (j=0;j<=i-1;j++)
              z=yy[j]+(t-xx[j])*(yy[j]-z)/(xx[j]-xx[i]);
          yy[i]=z;
      }while ((i!=m-1)&&(fabs(yy[i]-yy[i-1])>eps));
      return(z);
  }
/*
//Aitken逐步插值例
  #include <cmath>
  #include <iostream>
//  #include "Aitken逐步插值.cpp"
  using namespace std;
  int main()
  { 
	  double t,z,eps;
      double x[11]={-1.0,-0.8,-0.65,-0.4,-0.3,
                         0.0,0.2,0.4,0.6,0.8,1.0};
      double y[11]={0.0384615,0.0588236,0.0864865,0.2,
            0.307692,1.0,0.5,0.2,0.1,0.0588236,0.0384615};
      eps=1.0e-6;
      t=-0.75; z=aitken(x,y,11,eps,t);
      cout <<"t = " <<t <<"     z = " <<z <<endl;
      t=0.05; z=aitken(x,y,11,eps,t);
      cout <<"t = " <<t <<"     z = " <<z <<endl;
      return 0;
  }
*/