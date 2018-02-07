/*
AUTHORS: WILSON JAVIER PEREZ HOLGUIN  &  EDGAR ERNESTO SANCHEZ SANCHEZ
DESCRIPTION: 2-BIT MULTIPLIER SIMULATOR
DATE: OCTOBER 2017 CREATION
      JANUARY 2018 EDITION
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

  bool AND2 (bool A,bool B,int f,bool v, bool p){
    int i;
                        // Inputs               Fault Models
                        //           0      1       2       3       4      5       6
                        //         Fault   s@0     s@0     s@0     s@1    s@1     s@1
                        //  X Y    Free     X       Y       Z       X      Y       Z
    bool AND2_T[4][9] =  {{ 0,0,     0,     0,      0,      0,      0,     0,      1},
                          { 0,1,     0,     0,      0,      0,      1,     0,      1},
                          { 1,0,     0,     0,      0,      0,      0,     1,      1},
                          { 1,1,     1,     0,      0,      0,      1,     1,      1}};

    if (A==0 && B==0) i=0;
    if (A==0 && B==1) i=1;
    if (A==1 && B==0) i=2;
    if (A==1 && B==1) i=3;

    if (p==1) {
       cout << endl;
       cout << "------------------------------------------------------- " << endl;
       cout << "         AND 2 Gate Truth Table (s@0 and s@1)" << endl;
       cout << "------------------------------------------------------- " << endl;
       cout << "    Inputs   |               Output Z" << endl;
       cout << "             | Fault" << "  s@0  " << " s@0  " << "s@0 " << "  s@1  " << " s@1  " <<" s@1  " << endl;
       cout << "   X   " << "  Y  " << " | Free  " << "  X   " << "  Y " << "  Z   " << "  X   " << "  Y   " <<"  Z   " << endl;
       cout << "------------------------------------------------------- " << endl;

    for(int i=0;i<4;i++){
       cout << "   " << AND2_T[i][0] //Input X
            << "     " << AND2_T[i][1] //Input Y
            << "   |   " << AND2_T[i][2] //Fault Free Output
            << "     " << AND2_T[i][3] //Faulty Gate with s@0 at input X
            << "     " << AND2_T[i][4] //Faulty Gate with s@0 at input Y
            << "     " << AND2_T[i][5] //Faulty Gate with s@0 at output Z
            << "     " << AND2_T[i][6] //Faulty Gate with s@1 at input X
            << "     " << AND2_T[i][7] //Faulty Gate with s@1 at input Y
            << "     " << AND2_T[i][8] //Faulty Gate with s@1 at output Z
            << endl;
      }
       cout << "------------------------------------------------------- " << endl;
       cout << endl;
    }
    if (v==0)
        return AND2_T[i][2]; // Fault Free Gate
    else
        return AND2_T[i][f+2]; // Faulty Gate
  }


  bool XOR2 (bool A,bool B,int f,bool v,bool p){
    int i;
                        // Inputs               Fault Models
                        //           0      1       2       3       4      5       6
                        //         Fault   s@0     s@0     s@0     s@1    s@1     s@1
                        //  X Y    Free     X       Y       Z       X      Y       Z
    bool XOR2_T[4][9] =  {{ 0,0,     0,     0,      0,      0,      1,     1,      1},
                          { 0,1,     1,     1,      0,      0,      0,     1,      1},
                          { 1,0,     1,     0,      1,      0,      1,     0,      1},
                          { 1,1,     0,     1,      1,      0,      0,     0,      1}};

    if (A==0 && B==0) i=0;
    if (A==0 && B==1) i=1;
    if (A==1 && B==0) i=2;
    if (A==1 && B==1) i=3;

    if (p) {
       cout << endl;
       cout << "------------------------------------------------------- " << endl;
       cout << "         XOR 2 Gate Truth Table (s@0 and s@1)" << endl;
       cout << "------------------------------------------------------- " << endl;
       cout << "    Inputs   |               Output Z" << endl;
       cout << "             | Fault" << "  s@0  " << " s@0  " << " s@0 " << "  s@1  " << " s@1  " <<" s@1  " << endl;
       cout << "   X   " << "  Y  " << " | Free  " << "  X   " << "  Y  " << "  Z   " << "  X   " << "  Y   " <<"  Z   " << endl;
       cout << "------------------------------------------------------- " << endl;

       for(int i=0;i<4;i++){
         cout << "   " << XOR2_T[i][0] //Input X
              << "     " << XOR2_T[i][1] //Input Y
              << "   |   " << XOR2_T[i][2] //Fault Free Output
              << "     " << XOR2_T[i][3] //Faulty Gate with s@0 at input X
              << "     " << XOR2_T[i][4] //Faulty Gate with s@0 at input Y
              << "     " << XOR2_T[i][5] //Faulty Gate with s@0 at output Z
              << "     " << XOR2_T[i][6] //Faulty Gate with s@1 at input X
              << "     " << XOR2_T[i][7] //Faulty Gate with s@1 at input Y
              << "     " << XOR2_T[i][8] //Faulty Gate with s@1 at output Z
              << endl;
       }
       cout << "------------------------------------------------------- " << endl;
       cout << endl;
    }
    if (v==0)
        return XOR2_T[i][2]; // Fault Free Gate
    else
        return XOR2_T[i][f+2]; // Faulty Gate
}

void print_fm(int f){
    cout << endl;
    switch (f){
       case 0:
         cout << "Fault Model : Fault Free" << endl;
         break;
       case 1:
         cout << "Fault Model : S@0 at input X" << endl;
         break;
       case 2:
         cout << "Fault Model : S@0 at input Y" << endl;
         break;
       case 3:
         cout << "Fault Model : S@0 at output Z" << endl;
         break;
       case 4:
         cout << "Fault Model : S@1 at input X" << endl;
         break;
       case 5:
         cout << "Fault Model : S@1 at input Y" << endl;
         break;
       case 6:
         cout << "Fault Model : S@1 at output Z" << endl;
         break;
       default:
         cout << "Error, bad fault model selection" << endl;
         break;
      }
   }


main (){

  ofstream DataOutput;
  DataOutput.open("DataFile.txt");
  bool A[2],B[2];
  bool s[4],c[4];
  bool s_gc[4],c_gc[4];
  // Fault Model Selection
  int f;  // 0=Fault Free, 1=S@0X, 2=S@0Y, 3=S@0Z, 4=S@1X, 5=S@1Y, 6=S@1Z
  int aux;
  bool v[8];
  float e=0.0;
  int d=0;

/*
  cout << "Prueba compuerta AND2" << endl;
  for (int i=0;i<2;i++){
    for (int j=0;j<2;j++){
       Z=AND2(i,j,f,0);
       cout << "AND2 [" << i << "][" << j << "]=" << Z << endl;
    }
  }
  cout << endl;

  cout << "Prueba compuerta XOR2" << endl;
  for (int i=0;i<2;i++){
    for (int j=0;j<2;j++){
       Z=XOR2(i,j,f,0);
       cout << "XOR2 [" << i << "][" << j << "]=" << Z << endl;
    }
  }
  cout << endl;
*/

 DataOutput << "POLITECNICO DI TORINO - WJPEREZH & ESANCHEZ - 2018" << endl;
 DataOutput << "2-bit Multiplier Simulator" << endl << endl;

 for (int f=0;f<7;f++){

    DataOutput << "------------------------------------------------" << endl;
    switch (f){
       case 0:
         DataOutput << "Fault Model : Fault Free" << endl;
         break;
       case 1:
         DataOutput << "Fault Model : S@0 at input X of the faulty gate" << endl;
         break;
       case 2:
         DataOutput << "Fault Model : S@0 at input Y of the faulty gate" << endl;
         break;
       case 3:
         DataOutput << "Fault Model : S@0 at output Z of the faulty gate" << endl;
         break;
       case 4:
         DataOutput << "Fault Model : S@1 at input X of the faulty gate" << endl;
         break;
       case 5:
         DataOutput << "Fault Model : S@1 at input Y of the faulty gate" << endl;
         break;
       case 6:
         DataOutput << "Fault Model : S@1 at output Z of the faulty gate" << endl;
         break;
       default:
         DataOutput << "Error, bad fault model selection" << endl;
         break;
      }
    DataOutput << "------------------------------------------------" << endl;

    for(int l=0;l<2;l++){
       for(int k=0;k<2;k++){
          for(int j=0;j<2;j++){
            for(int i=0;i<2;i++){
               aux = 1;
                  //cout << "Faulty Gate" << endl;
                  DataOutput << endl << "Faulty Gate      Inputs        Output       Error     Golden Case" << endl;

               for(int g=0;g<8;g++){
                  A[1]=j; A[0]=i;
                  B[1]=l; B[0]=k;

                  if (aux==1)   v[0]=1; else v[0]=0;
                  if (aux==2)   v[1]=1; else v[1]=0;
                  if (aux==4)   v[2]=1; else v[2]=0;
                  if (aux==8)   v[3]=1; else v[3]=0;
                  if (aux==16)  v[4]=1; else v[4]=0;
                  if (aux==32)  v[5]=1; else v[5]=0;
                  if (aux==64)  v[6]=1; else v[6]=0;
                  if (aux==128) v[7]=1; else v[7]=0;

                  // 2-bit width multiplier circuit
                  c[0]=AND2(B[0],A[0],f,v[0],0); //G0
                  s[0]=AND2(B[0],A[1],f,v[1],0); //G1
                  s[1]=AND2(B[1],A[0],f,v[2],0); //G2
                  s[2]=AND2(B[1],A[1],f,v[3],0); //G3
                  s[3]=AND2(s[1],s[0],f,v[4],0); //G4
                  c[3]=AND2(s[2],s[3],f,v[5],0); //G5
                  c[1]=XOR2(s[1],s[0],f,v[6],0); //G6
                  c[2]=XOR2(s[2],s[3],f,v[7],0); //G7

                  if (B[1]==0 && B[0]==0 && A[1]==0 && A[0]==0) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==0 && B[0]==0 && A[1]==0 && A[0]==1) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==0 && B[0]==0 && A[1]==1 && A[0]==0) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==0 && B[0]==0 && A[1]==1 && A[0]==1) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}

                  if (B[1]==0 && B[0]==1 && A[1]==0 && A[0]==0) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==0 && B[0]==1 && A[1]==0 && A[0]==1) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=1;}
                  if (B[1]==0 && B[0]==1 && A[1]==1 && A[0]==0) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=1; c_gc[0]=0;}
                  if (B[1]==0 && B[0]==1 && A[1]==1 && A[0]==1) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=1; c_gc[0]=1;}

                  if (B[1]==1 && B[0]==0 && A[1]==0 && A[0]==0) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==1 && B[0]==0 && A[1]==0 && A[0]==1) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=1; c_gc[0]=0;}
                  if (B[1]==1 && B[0]==0 && A[1]==1 && A[0]==0) {c_gc[3]=0; c_gc[2]=1; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==1 && B[0]==0 && A[1]==1 && A[0]==1) {c_gc[3]=0; c_gc[2]=1; c_gc[1]=1; c_gc[0]=0;}

                  if (B[1]==1 && B[0]==1 && A[1]==0 && A[0]==0) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=0; c_gc[0]=0;}
                  if (B[1]==1 && B[0]==1 && A[1]==0 && A[0]==1) {c_gc[3]=0; c_gc[2]=0; c_gc[1]=1; c_gc[0]=1;}
                  if (B[1]==1 && B[0]==1 && A[1]==1 && A[0]==0) {c_gc[3]=0; c_gc[2]=1; c_gc[1]=1; c_gc[0]=0;}
                  if (B[1]==1 && B[0]==1 && A[1]==1 && A[0]==1) {c_gc[3]=1; c_gc[2]=0; c_gc[1]=0; c_gc[0]=1;}

                  //error calculation
                  if (c[0] != c_gc[0])   d=d+1;
                  if (c[1] != c_gc[1])   d=d+2;
                  if (c[2] != c_gc[2])   d=d+4;
                  if (c[3] != c_gc[3])   d=d+8;
                  float e=(float)d*100/15;

                  //cout << "G" << g << "=" <<v[7]<<v[6]<<v[5]<<v[4]<<v[3]<<v[2]<<v[1]<<v[0] <<" ";
                  //cout << "  G" << g << "  => ";
                  DataOutput << "    G" << g;
                  //cout << "          B=" <<B[1]<<B[0] << " A=" <<A[1]<<A[0]<< "     AxB=" <<c[3]<<c[2]<<c[1]<<c[0]<< endl;
                  DataOutput << "          B=" <<B[1]<<B[0] << " A="<<A[1]<<A[0] << "     AxB=" <<c[3]<<c[2]<<c[1]<<c[0] << "      " << fixed << setprecision(2) << e << "%" << "\t" << c_gc[3]<<c_gc[2]<<c_gc[1]<<c_gc[0] << endl;

                  aux = aux*2;

                  d=0;
               }
             }
           }
         }
       }
       DataOutput << endl;
     }

  DataOutput.close();
  cout << endl;
  cout << "Normal Termination!" << endl;
  cout << "POLITECNICO DI TORINO - WJPEREZH & ESANCHEZ - 2018" << endl << endl;

  return 0;
}
