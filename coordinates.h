#pragma once
#include<iostream>

/* float verticesSide[] = {
        -0.5f,0.5f,-0.5f,0.0f,1.0f,
       -0.5f,-0.5f,-0.5f,0.0f,0.0f,
       0.5f,-0.5f,-0.5f,1.0f,0.0f,
       -0.5f,0.5f,-0.5f,0.0f,1.0f,
       0.5f,-0.5f,-0.5f,1.0f,0.0f,
       0.5f,0.5f,-0.5f,1.0f,1.0f,

       0.5f,-0.5f,0.5f,0.0f,0.0f,
       0.5f,-0.5f,-0.5f,0.0f,1.0f,
       0.5f,0.5f,-0.5f,1.0f,1.0f,
       0.5f,-0.5f,0.5f,0.0f,0.0f,
       0.5f,0.5f,-0.5f,1.0f,1.0f,
       0.5f,0.5f,0.5f,1.0f,0.0f,

       -0.5f,-0.5f,0.5f,0.0f,0.0f,
       -0.5f,-0.5f,-0.5f,0.0f,1.0f,
       -0.5f,0.5f,-0.5f,1.0f,1.0f,
       -0.5f,-0.5f,0.5f,0.0f,0.0f,
       -0.5f,0.5f,-0.5f,1.0f,1.0f,
       -0.5f,0.5f,0.5f,1.0f,0.0f,

   };
   float verticesTopBottom[] = {

       0.5f,0.5f,-0.5f,1.0f,1.0f,
       -0.5f,0.5f,-0.5f,0.0f,1.0f,
       -0.5f,0.5f,0.5f,0.0f,0.0f,
       0.5f,0.5f,-0.5f,1.0f,1.0f,
       -0.5f,0.5f,0.5f,0.0f,0.0f,
       0.5f,0.5f,0.5f,1.0f,0.0f,

       0.5f,-0.5f,-0.5f,1.0f,1.0f,
       -0.5f,-0.5f,-0.5f,0.0f,1.0f,
       -0.5f,-0.5f,0.5f,0.0f,0.0f,
       0.5f,-0.5f,-0.5f,1.0f,1.0f,
       -0.5f,-0.5f,0.5f,0.0f,0.0f,
       0.5f,-0.5f,0.5f,1.0f,0.0f,
   };*/



const float verticalGap = 6.0f;
const float horizontalGap = 8.0f;
const float imageWidth = 20.0f;


float verticesSide[] = {
    /*   -50.5f,50.5f,50.5f,0.0f,1.0f,
       -50.5f,-50.5f,50.5f,0.0f,0.0f,
       50.5f,-50.5f,50.5f,1.0f,0.0f,
       -50.5f,50.5f,50.5f,0.0f,1.0f,
       50.5f,-50.5f,50.5f,1.0f,0.0f,
       50.5f,50.5f,50.5f,1.0f,1.0f,*/

       -XC, YC, -ZC, 0.0f,0.0f,1.0f, 
       -XC,-YC, -ZC,0.0f,0.0f,1.0f,
       XC, -YC, -ZC, 0.0f,0.0f,1.0f,
       -XC, YC, -ZC, 0.0f,0.0f,1.0f,
       XC, -YC, -ZC, 0.0f,0.0f,1.0f,
       XC,  YC, -ZC,  0.0f,0.0f,1.0f,

       XC, -YC,  ZC, -1.0f,0.0f,0.0f,
       XC, -YC, -ZC,-1.0f,0.0f,0.0f,
       XC,  YC, -ZC, -1.0f,0.0f,0.0f,
       XC, -YC,  ZC, -1.0f,0.0f,0.0f,
       XC,  YC, -ZC, -1.0f,0.0f,0.0f,
       XC,  YC,  ZC,  -1.0f,0.0f,0.0f,

       -XC, -YC,  ZC, 1.0f,0.0f,0.0f,
       -XC, -YC, -ZC,1.0f,0.0f,0.0f,
       -XC,  YC, -ZC, 1.0f,0.0f,0.0f,
       -XC, -YC,  ZC, 1.0f,0.0f,0.0f,
       -XC,  YC, -ZC, 1.0f,0.0f,0.0f,
       -XC,  YC,  ZC,  1.0f,0.0f,0.0f,
};
//float** getCoordinate(int count) {
//    float** verticess = new float*[4];
//    for (int i = 0;i < count;i++)
//    {
//        verticess[i] = new float[30];
//    }
//    for (int i = 0;i < count;i++){
//        verticess[i] = {
//                -XC + 0.1f, 
//                YC - verticalGap, 
//                ZC - (i + 1) * horizontalGap - (i)*imageWidth, 
//                0.0f, 
//                1.0f,
//                -XC + 0.1f,
//                -YC + verticalGap, 
//                ZC - (i + 1) * horizontalGap - (i)*imageWidth, 
//                0.0f, 
//                0.0f,
//                -XC + 0.1f, 
//                YC - verticalGap, 
//                ZC - (i + 1) * horizontalGap - (i + 1) * imageWidth, 
//                1.0f, 
//                1.0f,
//                -XC + 0.1f, 
//                -YC + verticalGap, 
//                ZC - (i + 1) * horizontalGap - (i)*imageWidth, 
//                0.0f, 
//                0.0f,
//                -XC + 0.1f, 
//                -YC + verticalGap, 
//                ZC - (i + 1) * horizontalGap - (i + 1) * imageWidth, 
//                1.0f, 
//                0.0f,
//                -XC + 0.1f, 
//                YC - verticalGap, 
//                ZC - (i + 1) * horizontalGap - (i + 1) * imageWidth, 
//                1.0f, 
//                1.0f
//        };
//    }
//    
//return verticess;
//}

//std::vector<float[]> getCoordinate(int count) {
//    std::vector <float[]> sth;
//    for (int i = 1;i <= count;i++){
//        sth.push_back({ -XC + 0.1f, YC - verticalGap, ZC - (i)*horizontalGap - (i - 1) * imageWidth, 0.0f, 1.0f,
//                -XC + 0.1f, -YC + verticalGap, ZC - (i)*horizontalGap - (i - 1) * imageWidth, 0.0f, 0.0f,
//                -XC + 0.1f, YC - verticalGap, ZC - (i)*horizontalGap - i * imageWidth, 1.0f, 1.0f,
//                -XC + 0.1f, -YC + verticalGap, ZC - (i)*horizontalGap - (i - 1) * imageWidth, 0.0f, 0.0f,
//                -XC + 0.1f, -YC + verticalGap, ZC - (i)*horizontalGap - i * imageWidth, 1.0f, 0.0f,
//                -XC + 0.1f, YC - verticalGap, ZC - (i)*horizontalGap - i * imageWidth, 1.0f, 1.0f
//    });
//    }
//    return sth;
//}
//



//float* verticesImage1=getCoordinate(1);
//float* verticesImage2=getCoordinate(2);
//float* verticesImage3=getCoordinate(3);
//float* verticesImage4=getCoordinate(4);


//float* verArray[] = {verticesImage1,verticesImage2,verticesImage3,verticesImage4,verticesImage5};


float verticesImage1[] = {
    -XC + 0.1f, YC - verticalGap,ZC - 1 * horizontalGap - 0 * imageWidth , 0.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 1 * horizontalGap - 0 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 1 * horizontalGap - 1 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 1 * horizontalGap - 0 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 1 * horizontalGap - 1 * imageWidth,1.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 1 * horizontalGap - 1 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
};

float verticesImage2[] = {
    -XC + 0.1f, YC - verticalGap,ZC - 2 * horizontalGap-   1*imageWidth , 0.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 2 * horizontalGap - 1 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 2 * horizontalGap - 2 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 2 * horizontalGap - 1 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 2 * horizontalGap - 2 * imageWidth,1.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 2 * horizontalGap - 2 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
     
};
float verticesImage3[] = {
    -XC + 0.1f, YC - verticalGap,ZC - 3 * horizontalGap - 2 * imageWidth , 0.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 3 * horizontalGap - 2 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 3 * horizontalGap - 3 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 3 * horizontalGap - 2 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 3 * horizontalGap - 3 * imageWidth,1.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 3 * horizontalGap - 3 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,


};

float verticesImage4[] = {
    -XC + 0.1f, YC - verticalGap,ZC - 4 * horizontalGap - 3* imageWidth , 0.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 4 * horizontalGap - 3 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 4 * horizontalGap - 4 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 4 * horizontalGap - 3 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 4 * horizontalGap - 4 * imageWidth,1.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 4 * horizontalGap - 4 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,


};
float verticesImage5[] = {
    -XC + 0.1f, YC - verticalGap,ZC -  5 * horizontalGap - 4 * imageWidth , 0.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 5 * horizontalGap - 4 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 5 * horizontalGap - 5 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 5 * horizontalGap - 4 * imageWidth, 0.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f, -YC + verticalGap,ZC - 5 * horizontalGap - 5 * imageWidth,1.0f,0.0f,1.0f,0.0f,0.0f,
    -XC + 0.1f,  YC - verticalGap,ZC - 5 * horizontalGap - 5 * imageWidth,1.0f,1.0f,1.0f,0.0f,0.0f,

};


//Back side
float verticesImage6[] = {
    -XC + 1*horizontalGap,            -YC + verticalGap, -ZC + 0.1f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 1 * horizontalGap + imageWidth, -YC + verticalGap, -ZC + 0.1f, 1.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 1 * horizontalGap + imageWidth,  YC - verticalGap, -ZC + 0.1f, 1.0f, 1.0f,0.0f,0.0f,1.0f,
    -XC + 1 * horizontalGap,             YC - verticalGap, -ZC + 0.1f, 0.0f, 1.0f,0.0f,0.0f,1.0f,
    -XC + 1 * horizontalGap,            -YC + verticalGap, -ZC + 0.1f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 1 * horizontalGap + imageWidth,  YC - verticalGap, -ZC + 0.1f, 1.0f, 1.0f,0.0f,0.0f,1.0f,

};
float verticesImage7[] = {
    -XC + 2 * horizontalGap+imageWidth,            -YC + verticalGap, -ZC + 0.1f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 2 * horizontalGap + 2 * imageWidth, -YC + verticalGap, -ZC + 0.1f, 1.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 2 * horizontalGap + 2 * imageWidth,  YC - verticalGap, -ZC + 0.1f, 1.0f, 1.0f,0.0f,0.0f,1.0f,
    -XC + 2 * horizontalGap + imageWidth,             YC - verticalGap, -ZC + 0.1f, 0.0f, 1.0f,0.0f,0.0f,1.0f,
    -XC + 2 * horizontalGap + imageWidth,            -YC + verticalGap, -ZC + 0.1f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 2 * horizontalGap + 2 * imageWidth,  YC - verticalGap, -ZC + 0.1f, 1.0f, 1.0f,0.0f,0.0f,1.0f,

};

float verticesImage8[] = {
    -XC + 3 * horizontalGap + 2*imageWidth,            -YC + verticalGap, -ZC + 0.1f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 3 * horizontalGap + 3 * imageWidth, -YC + verticalGap, -ZC + 0.1f, 1.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 3 * horizontalGap + 3 * imageWidth,  YC - verticalGap, -ZC + 0.1f, 1.0f, 1.0f,0.0f,0.0f,1.0f,
    -XC + 3 * horizontalGap + 2*imageWidth,             YC - verticalGap, -ZC + 0.1f, 0.0f, 1.0f,0.0f,0.0f,1.0f,
    -XC + 3 * horizontalGap + 2*imageWidth,            -YC + verticalGap, -ZC + 0.1f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
    -XC + 3 * horizontalGap + 3 * imageWidth,  YC - verticalGap, -ZC + 0.1f, 1.0f, 1.0f,0.0f,0.0f,1.0f,

};


float verticesImage9[] = {
    XC - 0.1f, YC - verticalGap,ZC - 1 * horizontalGap - 0 * imageWidth , 0.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 1 * horizontalGap - 0 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 1 * horizontalGap - 1 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 1 * horizontalGap - 0 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 1 * horizontalGap - 1 * imageWidth,1.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 1 * horizontalGap - 1 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,

};

float verticesImage10[] = {
    XC - 0.1f, YC - verticalGap,ZC - 2 * horizontalGap - 1 * imageWidth , 0.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 2 * horizontalGap - 1 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 2 * horizontalGap - 2 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 2 * horizontalGap - 1 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 2 * horizontalGap - 2 * imageWidth,1.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 2 * horizontalGap - 2 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,

};
float verticesImage11[] = {
    XC - 0.1f, YC - verticalGap,ZC - 3 * horizontalGap - 2 * imageWidth , 0.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 3 * horizontalGap - 2 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 3 * horizontalGap - 3 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 3 * horizontalGap - 2 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 3 * horizontalGap - 3 * imageWidth,1.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 3 * horizontalGap - 3 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,

};

float verticesImage12[] = {
    XC - 0.1f, YC - verticalGap,ZC - 4 * horizontalGap - 3 * imageWidth , 0.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 4 * horizontalGap - 3 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 4 * horizontalGap - 4 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 4 * horizontalGap - 3 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 4 * horizontalGap - 4 * imageWidth,1.0f,0.f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 4 * horizontalGap - 4 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,


};
float verticesImage13[] = {
    XC - 0.1f, YC - verticalGap,ZC -  5 * horizontalGap - 4 * imageWidth , 0.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 5 * horizontalGap - 4 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 5 * horizontalGap - 5 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 5 * horizontalGap - 4 * imageWidth, 0.0f,0.0f,-1.0f,0.0f,0.0f,
    XC - 0.1f, -YC + verticalGap,ZC - 5 * horizontalGap - 5 * imageWidth,1.0f,0.f,-1.0f,0.0f,0.0f,
    XC - 0.1f,  YC - verticalGap,ZC - 5 * horizontalGap - 5 * imageWidth,1.0f,1.0f,-1.0f,0.0f,0.0f,


};
float verticesTop[] = {
    XC, YC, -ZC,  0.0f,-1.0f,0.0f,
    -XC,YC, -ZC, 0.0f,-1.0f,0.0f,
    -XC,YC,  ZC,  0.0f,-1.0f,0.0f,
    XC, YC, -ZC,  0.0f,-1.0f,0.0f,
    -XC,YC,  ZC,  0.0f,-1.0f,0.0f,
    XC, YC,  ZC,   0.0f,-1.0f,0.0f,
};

float verticesBottom[]={
    XC,  -YC, -ZC,   0.0f,1.0f,0.0f,
    -XC, -YC, -ZC,   0.0f,1.0f,0.0f,
    -XC, -YC,  ZC,   0.0f,1.0f,0.0f,
    XC,  -YC, -ZC,   0.0f,1.0f,0.0f,
    -XC, -YC,  ZC,   0.0f,1.0f,0.0f,
    XC,  -YC,  ZC,     0.0f,1.0f,0.0f,
};



float verticesPillarBack[] = {
    //front
   -15.5f, 21.5f,20.5f,0.0f,0.0f,1.0f,
   -15.5f,-21.5f,20.5f,0.0f,0.0f,1.0f,
   15.5f, -21.5f,20.5f,0.0f,0.0f,1.0f,
   -15.5f, 21.5f,20.5f,0.0f,0.0f,1.0f,
   15.5f, -21.5f,20.5f,0.0f,0.0f,1.0f,
   15.5f,  21.5f,20.5f,0.0f,0.0f,1.0f,


   //back right
    -15.5f,21.5f,-20.5f,-1.0f,0.0f,0.0f,
   -15.5f,-21.5f,-20.5f,-1.0f,0.0f,0.0f,
   -5.5f,-21.5f,-20.5f,-1.0f,0.0f,0.0f,
   -15.5f,21.5f,-20.5f,-1.0f,0.0f,0.0f,
   -5.5f,-21.5f,-20.5f,-1.0f,0.0f,0.0f,
   -5.5f,21.5f,-20.5f,-1.0f,0.0f,0.0f,

   //back left
    15.5f,21.5f,-20.5f,1.0f,0.0f,0.0f,
   15.5f,-21.5f,-20.5f,1.0f,0.0f,0.0f,
   5.5f,-21.5f,-20.5f,1.0f,0.0f,0.0f,
   15.5f,21.5f,-20.5f,1.0f,0.0f,0.0f,
   5.5f,-21.5f,-20.5f,1.0f,0.0f,0.0f,
   5.5f,21.5f,-20.5f,1.0f,0.0f,0.0f,

   // dhoka mathi ko tuppo
   -5.5f,5.5f,-20.5f,0.0f,0.0f,-1.0f,
   5.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   -5.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   5.5f,5.5f,-20.5f,0.0f,0.0f,-1.0f,
   -5.5f,5.5f,-20.5f,0.0f,0.0f,-1.0f,
   5.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   
   15.5f,-21.5f,20.5f,0.0f,0.0f,-1.0f,
   15.5f,-21.5f,-20.5f,0.0f,0.0f,-1.0f,
   15.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   15.5f,-21.5f,20.5f,0.0f,0.0f,-1.0f,
   15.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   15.5f,21.5f,20.5f,0.0f,0.0f,-1.0f,

   -15.5f,-21.5f,20.5f,0.0f,0.0f,-1.0f,
   -15.5f,-21.5f,-20.5f,0.0f,0.0f,-1.0f,
   -15.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   -15.5f,-21.5f,20.5f,0.0f,0.0f,-1.0f,
   -15.5f,21.5f,-20.5f,0.0f,0.0f,-1.0f,
   -15.5f,21.5f,20.5f,0.0f,0.0f,-1.0f,
    
};

float verticesPillarImageFront[] = {
        //front
       -12.5f, 17.5f, 20.6f, 0.0f, 1.0f,0.0f,0.0f,1.0f,
       -12.5f, -17.5f, 20.6f, 0.0f, 0.0f,0.0f,0.0f,1.0f,
       12.5f, -17.5f, 20.6f, 1.0f, 0.0f,0.0f,0.0f,1.0f,
       -12.5f, 17.5f, 20.6f, 0.0f, 1.0f,0.0f,0.0f,1.0f,
       12.5f, -17.5f, 20.6f, 1.0f, 0.0f,0.0f,0.0f,1.0f,
       12.5f, 17.5f, 20.6f, 1.0f, 1.0f,0.0f,0.0f,1.0f,
    };

//float verticesPillarImageBack[] = {
    //   -12.5f, 17.5f, -20.6f, 0.0f, 1.0f,
    //   -12.5f, -17.5f, -20.6f, 0.0f, 0.0f,
    //   12.5f, -17.5f, -20.6f, 1.0f, 0.0f,
    //   -12.5f, 17.5f, -20.6f, 0.0f, 1.0f,
    //   12.5f, -17.5f, -20.6f, 1.0f, 0.0f,
    //   12.5f, 17.5f, -20.6f, 1.0f, 1.0f,
    //};

 float verticesPillarImageRight[] = {
        15.6f, -17.5f, 16.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
        15.6f, -17.5f, -16.5f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
        15.6f, 17.5f, -16.5f, 1.0f, 1.0f,1.0f,0.0f,0.0f,
        15.6f, -17.5f, 16.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
        15.6f, 17.5f, -16.5f, 1.0f, 1.0f,1.0f,0.0f,0.0f,
        15.6f, 17.5f, 16.5f, 0.0f, 1.0f,1.0f,0.0f,0.0f,
        };

float verticesPillarImageLeft[] = {
       -15.6f, -17.5f, 16.5f, 1.0f, 0.0f,-1.0f,0.0f,0.0f,
       -15.6f, -17.5f, -16.5f, 0.0f, 0.0f,-1.0f,0.0f,0.0f,
       -15.6f, 17.5f, -16.5f, 0.0f, 1.0f,-1.0f,0.0f,0.0f,
       -15.6f, -17.5f, 16.5f, 1.0f, 0.0f,-1.0f,0.0f,0.0f,
       -15.6f, 17.5f, -16.5f, 0.0f, 1.0f,-1.0f,0.0f,0.0f,
       -15.6f, 17.5f, 16.5f, 1.0f, 1.0f,-1.0f,0.0f,0.0f,
    }; 
float ShivaImg[] = {
        //front
       -16.5f, 17.5f, 19.6f, 0.0f, 1.0f,
       -16.5f, -17.5f, 19.6f, 0.0f, 0.0f,
       16.5f, -17.5f, 19.6f, 1.0f, 0.0f,
       -16.5f, 17.5f, 19.6f, 0.0f, 1.0f,
       16.5f, -17.5f, 19.6f, 1.0f, 0.0f,
       16.5f, 17.5f, 19.6f, 1.0f, 1.0f,
    };

   


