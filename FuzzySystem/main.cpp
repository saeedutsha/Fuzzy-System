#include <iostream>

using namespace std;

int main()
{
    double attendance,ttime;

    /**< Two inputs */

    cout<<"Total attendance in class(%) : ";
    cin>>attendance;
    cout<<"Total time in class(%) : ";
    cin>>ttime;


    /**< Fuzzification of total time in class */

    /**<  Let's assume the cutting points are 0,10,25,40,50,60,75,90 and 100 where
    0-40 is the range of first trapezium, 25-75 is for the second triangle and
    60-100 is for the third trapezium */

    double uInadeuate,uMarginal,uAdequate;

    if(ttime>=0 && ttime<=10){
        uInadeuate = 1;
        uMarginal = 0;
        uAdequate = 0;
    }

    if(ttime>10 && ttime<=25){
        uInadeuate = ((40-ttime)/(40-10));
        uMarginal = 0;
        uAdequate = 0;
    }

    if(ttime>25 && ttime<=40){
        uInadeuate = ((40-ttime)/(40-10));
        uMarginal = ((ttime-25)/(50-25));
        uAdequate = 0;
    }

    if(ttime>40 && ttime<=50){
        uInadeuate = 0;
        uMarginal = ((ttime-25)/(50-25));
        uAdequate = 0;
    }

    if(ttime>50 && ttime<=60){
        uInadeuate = 0;
        uMarginal = ((75-ttime)/(75-50));
        uAdequate = 0;
    }

    if(ttime>60 && ttime<=75){
        uInadeuate = 0;
        uMarginal = ((75-ttime)/(75-50));
        uAdequate = ((ttime-60)/(90-60));
    }

    if(ttime>75 && ttime<=90){
        uInadeuate = 0;
        uMarginal = 0;
        uAdequate = ((ttime-60)/(90-60));
    }

    if(ttime>90 && ttime<=100){
        uInadeuate = 0;
        uMarginal = 0;
        uAdequate = 1;
    }

    /**< End of fuzzification of ttime */

    /**< Fuzzification of total attendance in class */

    /**<  Let's assume the cutting points are 0,20,40,60,80 and 100 where 0-60 is
    the range of first trapezium and 40-100 is for the second trapezium */

    double uSmall,uLarge;

    if(attendance>=0 && attendance<=20){
        uSmall = 1;
        uLarge = 0;
    }

    if(attendance>20 && attendance<=40){
        uSmall = ((60-attendance)/(60-20));
        uLarge = 0;
    }

    if(attendance>40 && attendance<=60){
        uSmall = ((60-attendance)/(60-20));
        uLarge = ((attendance-40)/(80-40));
    }

    if(attendance>60 && attendance<=80){
        uSmall = 0;
        uLarge = ((attendance-40)/(80-40));
    }

    if(attendance>80 && attendance<=100){
        uSmall = 0;
        uLarge = 1;
    }


    /**< End of fuzzification of attendance */

    //cout<<uInadeuate<<" "<<uMarginal<<" "<<uAdequate<<" ";
    //cout<<uSmall<<" "<<uLarge<<" ";

    /**< Rules Evaluation */

    double uLow,uAverage,uHigh;

    /**< if time=inadequate or class=small then marks=low  */

    uLow = max(uInadeuate,uSmall);

    /**< if time=marginal and class=large then marks=average */

    uAverage = min(uMarginal,uLarge);

    /**< if time=adequate or class=large then marks=high */

    uHigh = max(uAdequate,uLarge);

    /**< End of Rules Evaluation */

    //cout<<uLow<<" "<<uAverage<<" "<<uHigh<<" ";

    /**< Defuzzification */

    double Marks;

    /**<  Let's assume the cutting points are 0,10,25,40,50,60,75,90 and 100 where
    0-40 is the range of first trapezium, 25-75 is for the second triangle and
    60-100 is for the third trapezium */

    double sumx=0,sumy=0,sumz=0,cx=0,cy=0,cz=0;

    for(int i=0;i<=25;i=i+10){
        sumx=sumx+i;
        cx++;
    }

    for(int i=30;i<=55;i=i+10){
        sumy=sumy+i;
        cy++;
    }

    for(int i=60;i<=100;i=i+10){
        sumz=sumz+i;
        cz++;
    }

    Marks = ((uLow*sumx+uAverage*sumy+uHigh*sumz)/(uLow*cx+uAverage*cy+uHigh*cz));

    /**< End of Defuzzification */

    cout<<"Total Mark is : "<<Marks<<"%\n";

}
