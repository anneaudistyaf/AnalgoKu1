/*
Nama : Anne Audistya Fernanda
NPM : 140810180059
Kelas : A 
Deskripsi : Menentukan Stable Matching Problem 
*/

#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  
//Jumlah pria dan wanita 
#define N 5 
  
// Fungsi ini akan true jika wanita lebih menyukai pria 'm1' daripada 'm'
bool pilihPria(int pilih[2*N][N], int w, int m, int m1) 
{ 
    //Cek apakah wanita lebih suka m daripada m1 
    for (int i = 0; i < N; i++) 
    { 
        if (pilih[w][i] == m1) 
            return true; 
         
        if (pilih[w][i] == m) 
           return false; 
    } 
} 
  
// Mencetak pencocokan stabil untuk N pria dan N wanita. Pria diberi nomor 0 hingga N-1, Wanita diberi nomor N hingga 2N-1
void stableMarriage(int pilih[2*N][N]) 
{ 
    int partnerWanita[N]; 
  
    bool mLajang[N]; 
  
    memset(partnerWanita, -1, sizeof(partnerWanita)); 
    memset(mLajang, false, sizeof(mLajang)); 
    int freeCount = N; 
  
    // Jika pria ada yang Free 
    while (freeCount > 0) 
    {  
        int m; 
        for (m = 0; m < N; m++) 
            if (mLajang[m] == false) 
                break; 
  
        for (int i = 0; i < N && mLajang[m] == false; i++) 
        { 
            int w = pilih[m][i]; 
  
            if (partnerWanita[w-N] == -1) 
            { 
                partnerWanita[w-N] = m; 
                mLajang[m] = true; 
                freeCount--; 
            } 
  
            else  // Jika wanita tidak free 
            { 
                int m1 = partnerWanita[w-N]; 
  
                if (pilihPria(pilih, w, m, m1) == false) 
                { 
                    partnerWanita[w-N] = m; 
                    mLajang[m] = true; 
                    mLajang[m1] = false; 
                } 
            } 
        } 
    } 
  
  
    // Memunculkan Hasilnya
    cout << "Hasil Stable Marriage : " << endl;
    cout << "--------------------------------"<< endl;
    cout << "Man \t\tWoman" << endl; 
    cout<<endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++) {
    	  if(i<N){
		   if(partnerWanita[i]==0)
		    man="Victor";
		   if(partnerWanita[i]==1)
		    man="Wyatt ";
		   if(partnerWanita[i]==2)
		    man="Xavier";
		   if(partnerWanita[i]==3)
		    man="Yancey";
		   if(partnerWanita[i]==4)
		    man="Zeus  ";
		   if(i==0)
		    woman="Amy";
		   if(i==1)
		    woman="Bertha";
		   if(i==2)
		    woman="Clare";
		   if(i==3)
		    woman="Diane";
		   if(i==4)
		    woman="Erika";
  }
  cout << man << "\t<3\t" << woman << endl; 
	}   
} 
  
// Uji Main Program 
int main() 
{ 
   int pilih[2*N][N] = { {6, 5, 8, 9, 7}, 
        {8, 6, 5, 7, 9},
        {6, 9, 7, 8, 5},
        {5, 8, 7, 6, 9},
        {6, 8, 5, 9, 7},
        {4, 0, 1, 3, 2},
        {2, 1, 3, 0, 4},
        {1, 2, 3, 4, 0},
        {0, 4, 3, 2, 1},
        {3, 1, 4, 2, 0} 
    }; 
    stableMarriage(pilih); 
  
    return 0; 
} 
